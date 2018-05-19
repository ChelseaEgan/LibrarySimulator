/*********************************************************************
** Author: Chelsea Egan
** Date: 08/08/2016
** Description: This is the function implementation section for the
** Library class.
*********************************************************************/

#include "Library.hpp"
#include <iostream>
#include <vector>
#include <string>

/*********************************************************************
** Description: This is the default constructor that initializes the
** currentDate to zero
*********************************************************************/
Library::Library()
{
	currentDate = 0;
}

/*********************************************************************
** Description: This function adds a pointer to a book object to the
** vector of all books held by the Library
*********************************************************************/
void Library::addBook(Book* b)
{
	holdings.push_back(b);
}

/*********************************************************************
** Description: This function adds a pointer to a patron object to the
** vector of all members at the Library
*********************************************************************/
void Library::addPatron(Patron* p)
{
	members.push_back(p);
}

/*********************************************************************
** Description: This function tests if the book is in the library, if
** the patron is a member, and the status of the book. If the book is
** available and the patron is a member, it "checks out the book"
*********************************************************************/
std::string Library::checkOutBook(std::string pID, std::string bID)
{
	//variables to hold book and patron location
	Book *bkPtr = NULL;
	Patron *ptPtr = NULL;

	//flag for testing conditions
	bool found = false;

	//test if the book is in the library
	for (unsigned int index = 0; index < holdings.size(); index++)
	{
		if ((holdings[index]->getIdCode()) == bID)
		{
			found = true;
			bkPtr = holdings[index];
		}
	}

	if (found == false)
	{
		return "book not found \n";
	}

	//reset flag
	found = false;

	//test if the Patron is a member
	for (unsigned int index = 0; index < members.size(); index++)
	{
		if ((members[index]->getIdNum()) == pID)
		{
			found = true;
			ptPtr = members[index];
		}
	}

	if (found == false)
	{
		return "patron not found \n";
	}

	//test if book is checked out or on hold
	for (unsigned int index = 0; index < holdings.size(); index++)
	{
		if ((holdings[index]->getIdCode()) == bID)
		{
			if ((holdings[index]->getLocation()) == CHECKED_OUT)
			{
				return "book already checked out \n";
			}
			if ((holdings[index]->getLocation()) == ON_HOLD_SHELF)
			{
				if (holdings[index]->getRequestedBy() == ptPtr)
				{
					holdings[index]->setRequestedBy(NULL);
				}
				else
				{
					return "book on hold by other patron \n";
				}
			}
		}
	}

	//if book is available and patron is a member
	bkPtr->setCheckedOutBy(ptPtr);
	bkPtr->setDateCheckedOut(currentDate);
	bkPtr->setLocation(CHECKED_OUT);
	ptPtr->addBook(bkPtr);
	return "check out successful \n";
}

/*********************************************************************
** Description: This function tests if the book is in the library and 
** the status of the book. If the book was checked out by the member,
** it "returns the book"
*********************************************************************/
std::string Library::returnBook(std::string bID)
{
	//flag for testing conditions
	bool found = false;

	//variable to hold book's location
	Book *bkPtr = NULL;
	Patron *ptPtr = NULL;

	//test if the book is in the library
	for (unsigned int index = 0; index < holdings.size(); index++)
	{
		if ((holdings[index]->getIdCode()) == bID)
		{
			found = true;
			bkPtr = holdings[index];
		}
	}

	if (found == false)
	{
		return "book not found \n";
	}

	//test if book is checked out
	if (bkPtr->getLocation() != CHECKED_OUT)
	{
		return "book already in library \n";
	}
	else
	{
		//get Patron's ID Number
		std::string id;
		std::cout << "Enter patron's ID Number: \n";
		std::cin >> id;

		//reset flag
		found = false;

		//get patron
		for (unsigned int index = 0; index < members.size(); index++)
		{
			if ((members[index]->getIdNum()) == id)
			{
				found = true;
				ptPtr = members[index];
			}
		}
		//if not a patron
		if (found == false)
		{
			return "That ID number does not belong to a member. \n";
		}
		//update Patron's checkedOutBooks
		ptPtr->removeBook(bkPtr);
		
		//update book's location
		//if the book has been requested
		if (bkPtr->getRequestedBy() != NULL)
		{
			bkPtr->setLocation(ON_HOLD_SHELF);
		}
		//if it has not been requested
		else
		{
			bkPtr->setLocation(ON_SHELF);
		}
		//set checked out by to null
		bkPtr->setCheckedOutBy(NULL);
		return "return successful \n";
	}
}

/*********************************************************************
** Description: This function tests if the book is in the library, if
** the patron is a member, and if the book has already been requested.
** If the book is availbale and the patron is a member, it sets the
** book as requested by the patron
*********************************************************************/
std::string Library::requestBook(std::string pID, std::string bID)
{
	//variables to hold book and patron location
	Book *bkPtr = NULL;
	Patron *ptPtr = NULL;

	//flag for testing conditions
	bool found = false;

	//test if the book is in the library
	for (unsigned int index = 0; index < holdings.size(); index++)
	{
		if ((holdings[index]->getIdCode()) == bID)
		{
			found = true;
			bkPtr = holdings[index];
		}
	}

	if (found == false)
	{
		return "book not found \n";
	}

	//reset flag
	found = false;

	//test if the Patron is a member
	for (unsigned int index = 0; index < members.size(); index++)
	{
		if ((members[index]->getIdNum()) == pID)
		{
			found = true;
			ptPtr = members[index];
		}
	}

	if (found == false)
	{
		return "patron not found \n";
	}

	//test if book has already been requested
	if (bkPtr->getRequestedBy() != NULL || bkPtr->getLocation() == ON_HOLD_SHELF)
	{
		if (bkPtr->getRequestedBy() == ptPtr)
		{
			return "patron has already requested this book \n";
		}
		else
		{
			return "book already on hold \n";
		}
	}

	//if book has not already been requested, set requested by to patron
	bkPtr->setRequestedBy(ptPtr);
	//if location is on shelf, set to on hold shelf
	if (bkPtr->getLocation() == ON_SHELF)
	{
		bkPtr->setLocation(ON_HOLD_SHELF);
	}
	return "request successful \n";
}

/*********************************************************************
** Description: This function tests if the patron is a member and then
** amends their fine according to the amount paid
*********************************************************************/
std::string Library::payFine(std::string pID, double payment)
{
	//variables to hold patron location
	Patron *ptPtr = NULL;

	//flag for testing conditions
	bool found = false;

	//test if the Patron is a member
	for (unsigned int index = 0; index < members.size(); index++)
	{
		if ((members[index]->getIdNum()) == pID)
		{
			found = true;
			ptPtr = members[index];
		}
	}

	if (found == false)
	{
		return "patron not found \n";
	}

	//set payment to negative
	payment *= -1;

	ptPtr->amendFine(payment);

	return "payment successful \n";
}

/*********************************************************************
** Description: This function increments the current date at the
** library. It then iterates through each patron's books - if any 
** books are overdue, it adds ten cents to their fine
*********************************************************************/
void Library::incrementCurrentDate()
{
	//increment current date
	currentDate++;
	
	//iterate through each member
	for (unsigned int index = 0; index < members.size(); index++)
	{
		//vector to hold each patron's books
		std::vector<Book*>books(members[index]->getCheckedOutBooks());

		//iterate through each book
		for (unsigned int book = 0; book < books.size(); book++)
		{
			//get the day it was checked out
			int day = books[book]->getDateCheckedOut();
			//if that day was over 21 days ago
			if ((currentDate-day) > books[book]->getCheckOutLength())
			{
				//add 10 cents to the fine
				members[index]->amendFine(.10);
			}
		}
	}
}

/*********************************************************************
** Description: This function returns the pointer to the patron
*********************************************************************/
Patron* Library::getPatron(std::string pID)
{
	//flag to mark patron as found
	bool found = false;
	
	for (unsigned int index = 0; index < members.size(); index++)
	{
		if (members[index]->getIdNum() == pID)
		{
			found = true;
			return members[index];
		}
	}

	if (found == false)
	{
		return NULL;
	}
}

/*********************************************************************
** Description: This function returns the pointer to the book
*********************************************************************/
Book* Library::getBook(std::string bID)
{
	//flag to mark book as found
	bool found = false;

	for (unsigned int index = 0; index < holdings.size(); index++)
	{
		if (holdings[index]->getIdCode() == bID)
		{
			found = true;
			return holdings[index];
		}
	}

	if (found == false)
	{
		return NULL;
	}
}