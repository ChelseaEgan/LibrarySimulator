/*********************************************************************
** Author: Chelsea Egan
** Date: 08/08/2016
** Description: This is the function implementation section for the
** Book class.
*********************************************************************/

#include "Book.hpp"
#include <iostream>
#include <string>

/*********************************************************************
** Description: This is the default constructor that initializes the
** book's ID code, title, author; sets the checked out by, requested
** by to NULL; sets the location to on the shelf
*********************************************************************/
Book::Book(std::string idc = "", std::string t = "", std::string a = "")
{
	idCode = idc;
	title = t;
	author = a;
	setCheckedOutBy(NULL);
	setRequestedBy(NULL);
	setLocation(ON_SHELF);
}

/*********************************************************************
** Description: This function returns the number of days that a book
** can be checked out (21)
*********************************************************************/
int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}

/*********************************************************************
** Description: This function returns the ID code of the book
*********************************************************************/
std::string Book::getIdCode()
{
	return idCode;
}

/*********************************************************************
** Description: This function returns the title of the book
*********************************************************************/
std::string Book::getTitle()
{
	return title;
}

/*********************************************************************
** Description: This function returns the author of the book
*********************************************************************/
std::string Book::getAuthor()
{
	return author;
}

/*********************************************************************
** Description: This function returns the location of the book
*********************************************************************/
Locale Book::getLocation()
{
	return location;
}

/*********************************************************************
** Description: This function sets the location of the book
*********************************************************************/
void Book::setLocation(Locale current)
{
	location = current;
}

/*********************************************************************
** Description: This function returns a pointer to the patron who
** checked out the book
*********************************************************************/
Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
}

/*********************************************************************
** Description: This function sets checkedOutBy to a pointer to a 
** patron object
*********************************************************************/
void Book::setCheckedOutBy(Patron* person)
{
	checkedOutBy = person;
}

/*********************************************************************
** Description: This function returns a pointer to the patron who 
** requested the book
*********************************************************************/
Patron* Book::getRequestedBy()
{
	return requestedBy;
}

/*********************************************************************
** Description: This function sets requestedBy to a pointer to a
** patron object
*********************************************************************/
void Book::setRequestedBy(Patron* person)
{
	requestedBy = person;
}

/*********************************************************************
** Description: This function returns the date the book was checked
** out
*********************************************************************/
int Book::getDateCheckedOut()
{
	return dateCheckedOut;
}

/*********************************************************************
** Description: This function sets the date the booked was checked out
*********************************************************************/
void Book::setDateCheckedOut(int date)
{
	dateCheckedOut = date;
}