#include "Library.hpp"
#include <iostream>

int main()
{
	Book b1("123", "War and Peace", "Tolstoy");
	Book b2("234", "Moby Dick", "Melville");
	Book b3("345", "Phantom Tollbooth", "Juster");
	Book test("", "", "");
	Patron p1("abc", "Felicity");
	Patron p2("bcd", "Waldo");
	Patron test2("", "");
	Library lib;

	lib.addBook(&b1);
	lib.addBook(&b2);
	lib.addBook(&b3);
	lib.addPatron(&p1);
	lib.addPatron(&p2);

	lib.incrementCurrentDate();

	std::cout << lib.checkOutBook("bcd", "123") << std::endl;
	
	std::cout << lib.returnBook("456") << std::endl;
	std::cout << lib.returnBook("234") << std::endl;
	std::cout << lib.returnBook("123") << std::endl;


	/*std::cout << lib.returnBook("123") << std::endl;
	std::cout << "Book location: " << b1.getLocation() << std::endl;

	/*lib.addBook(&b1);
	lib.addBook(&b2);
	lib.addBook(&b3);
	lib.addPatron(&p1);
	lib.addPatron(&p2);
	std::cout << lib.checkOutBook("bcd", "234") << std::endl;
	for (int i = 0; i<7; i++)
		lib.incrementCurrentDate();
	std::cout << lib.checkOutBook("bcd", "123") << std::endl;
	std::cout << lib.checkOutBook("abc", "345") << std::endl;
	for (int i = 0; i<24; i++)
		lib.incrementCurrentDate();
	std::cout << lib.payFine("bcd", 0.4) << std::endl;
	double p1Fine = p1.getFineAmount();
	std::cout << p1Fine << std::endl;
	double p2Fine = p2.getFineAmount();
	std::cout << p2Fine << std::endl;*/

	return 0;
}