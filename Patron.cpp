/*********************************************************************
** Author: Chelsea Egan
** Date: 08/08/2016
** Description: This is the function implementation section for the
** Patron class.
*********************************************************************/

#include "Patron.hpp"
#include <iostream>
#include <string>
#include <vector>

/*********************************************************************
** Description: This is the default constructor that initializes the
** patron's ID code and name; sets the fine amount to zero
*********************************************************************/
Patron::Patron(std::string idn = "", std::string n = "")
{
	idNum = idn;
	name = n;
	fineAmount = 0.0;
}

/*********************************************************************
** Description: This function returns the ID number of the patron
*********************************************************************/
std::string Patron::getIdNum()
{
	return idNum;
}

/*********************************************************************
** Description: This function returns the name of the patron
*********************************************************************/
std::string Patron::getName()
{
	return name;
}

/*********************************************************************
** Description: This function returns the vector holding pointers to
** books that have been checked out by the patron
*********************************************************************/
std::vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}

/*********************************************************************
** Description: This function adds a pointer to a book that has been
** checked out to the patron's vector of checked out books
*********************************************************************/
void Patron::addBook(Book* b)
{
	checkedOutBooks.push_back(b);
}

/*********************************************************************
** Description: This function removes a pointer to a book from the 
** patron's vector of checked out books
*********************************************************************/
void Patron::removeBook(Book* b)
{
	//validates that the vector is not empty
	if (checkedOutBooks.empty())
	{
		std::cout << "No books have been checked out. \n";
	}
	else
	{
		for (unsigned int index = 0; index < checkedOutBooks.size(); index++)
		{
			if (checkedOutBooks[index] == b)
			{
				checkedOutBooks.erase(checkedOutBooks.begin() + index);
			}
		}
	}
}

/*********************************************************************
** Description: This function returns the fine amount owed by the
** patron
*********************************************************************/
double Patron::getFineAmount()
{
	return fineAmount;
}

/*********************************************************************
** Description: This function adds or subtracts from the fine amount
*********************************************************************/
void Patron::amendFine(double amount)
{
	fineAmount += amount;
}