#pragma once
#include <iostream>
#include "GuestUser.h"
#include "RegisteredUser.h"
#include "Admin.h"
#include "book.h"
#include "login.h"
#include "UserManager.h"

int idCount;
bool loggedIn;
Login* login;
UserManager* manager;
void runAdmin()
{
	(login)->reset();
	std::cout << "\nAdmin Options \n(1) Log out \n(2) Delete Admin \n(3) Add Admin\n(4) Print Admins \n(5) Delete Registered User \n(6) Register user \n(7) Print Registered users \n(8) View my Details \n(9) Print Available books \n(10) Delete Book \n(11) Add Book \n(12) Register Guest user \n(13) Delete Guest user \n(14) print Guest Users";
	std::cout << std::endl << "Please enter desired option: ";
	int input;
	std::cin >> input;

	switch (input)
	{
		case 1:
		{
			(login)->logout();
			loggedIn = false;
			std::cout << "\nLogged out";
			break;
		}
		case 2:
		{
			std::cout << "please enter name of admin to Delete: ";
			std::string name;
			std::cin >> name;
			(manager)->DeleteAdmin(name);
			break;
		}
		case 3:
		{
			std::cout << "please enter name of new admin: ";
			std::string name;
			std::cin >> name;
			std::cout << "please enter password of new admin: ";
			std::string password;
			std::cin >> password;
			idCount++;
			(manager)->registerNewAdmin(name, password, idCount);
			std::cout << "Admin " << name << " has been Registered\n";
			break;
		}
		case 4:
		{
			(manager)->printAdmins();
			break;
		}
		case 5:
		{
			std::cout << "please enter name of Registered user to Delete: ";
			std::string name;
			std::cin >> name;
			(manager)->DeleteRegUser(name);
			break;
		}
		case 6:
		{
			std::cout << "please enter name of new user: ";
			std::string name;
			std::cin >> name;
			std::cout << "please enter password of new user: ";
			std::string password;
			std::cin >> password;
			idCount++;
			(manager)->registerNewUser(name, password, idCount);
			std::cout << "User " << name << " has been Registered\n";
			break;
		}
		case 7:
		{
			(manager)->printRegisteredUsers();
			break;
		}
		case 8:
		{
			std::cout << (login)->getAdmin();
			break;
		}
		case 9:
		{
			(manager)->printAllBooks();
			break;
		}
		case 10:
		{
			std::cout << "please enter name of book to Remove: ";
			std::string name;
			std::cin >> name;
			(manager)->removeBookName(name);
			break;
		}
		case 11:
		{
			std::cout << "please enter title of new book: ";
			std::string title;
			std::cin >> title;
			std::cout << "please enter Author of new book: ";
			std::string Author;
			std::cin >> Author;
			std::cout << "please enter ISBN of new book: ";
			unsigned int ISBN;
			std::cin >> ISBN;
			std::cout << "please enter quantity of new book: ";
			unsigned int quantity;
			std::cin >> quantity;
			(manager)->addBook(title, Author, ISBN, quantity);
			std::cout << "book " << title << " has been added\n";
			break;
		}
		case 13:
		{
			std::cout << "please enter name of Guest user to Delete: ";
			std::string name;
			std::cin >> name;
			(manager)->DeletGuest(name);
			break;
		}
		case 12:
		{
			std::cout << "please enter name of new Guest user: ";
			std::string name;
			std::cin >> name;
			std::cout << "please enter password of new Guest user: ";
			std::string password;
			std::cin >> password;
			idCount++;
			(manager)->registerNewGuest(name, password, idCount);
			std::cout << "Guest user " << name << " has been Registered\n";
			break;
		}
		case 14:
		{
			(manager)->printGuests();
		}
		std::cin.clear();
	}
}

void runRegisteredUser()
{
	(login)->reset();
	(manager)->resetRegisteredUsers();
	std::cout << "\nRegistered Users Options \n(1) Log out \n(2) print user Details \n(3) Print Available books \n(4) View current book Loans \n(5) loan book \n(6) Return book";
	std::cout << std::endl << "Please enter desired option: ";
	std::cin.clear(); // clears the error flags
				 // this line discards all the input waiting in the stream
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl << "\nPlease enter desired option: ";
	int input;
	std::cin >> input;
	switch (input)
	{
	case 1:
		(login)->logout();
		loggedIn = false;
		std::cout << "\nLogged out";
		break;
	case 2:
		std::cout << (login)->getReg();
		break;
	case 3:
		(manager)->printAvailableBooks();
		break;
	case 4:
		((login)->getReg())->printAllBooks();
		break;
	case 5:
		(login)->bookPrev = (login)->bookFirst;
		((login)->getReg())->LoanBook((login)->bookPrev, (login)->bookFirst, (login)->bookCounter);
		break;
	}
}

void runGuest()
{
	std::cout << "\nRegistered Users Options \n(1) Log out \n(2) print user Details \n (3) Print Available books";
	std::cout << std::endl << "Please enter desired option: ";
	int input;
	std::cin >> input;
	switch (input)
	{
	case 1:
		(login)->logout();
		loggedIn = false;
		std::cout << "\nLogged out";
		break;
	case 2:
		std::cout << (login)->getGuest();
		break;
	case 3:
		(manager)->printAvailableBooks();
		break;
	}
}

void initiate()
{
	login = new Login();
	manager = new UserManager(login);
	idCount = 10000;
	(login)->RegUserCounter = 0;
	(login)->GuestUserCounter = 0;
	(login)->adminCounter = 0;

	(manager)->registerNewUser("james", "sandwich", 26622);
	(manager)->registerNewUser("Clara", "blueberry", 12233);
	(manager)->registerNewUser("Amy", "qwerty", 14563);

	(manager)->registerNewUser("Clara", "blueberry", 17823);
	(manager)->registerNewUser("Amy", "qwerty", 12223);
	(manager)->registerNewUser("James", "Sandwich", 12667);

	(manager)->registerNewAdmin("jim", "qwerty", 12923);
	(manager)->registerNewAdmin("sam", "qwerty", 12443);
	(manager)->registerNewAdmin("owen", "qwerty", 15623);
	(manager)->registerNewAdmin("admin", "admin", 12323);
	
	(manager)->addBook("Andy Weir", "The Martian", 97808, 2);
	(manager)->addBook("Susan Collins", "The Hunger Games", 23345, 1);
	(manager)->addBook("Ernest Cline", "Ready Player one", 65321, 3);
	(manager)->addBook("Ernest Cline", "Ready", 65321, 1);

	(manager)->registerNewGuest("Tom", "qwerty", 12223);
	(manager)->registerNewGuest("cian", "qwerty", 12223);
	(manager)->registerNewGuest("kerry", "qwerty", 12223);
}

int main()
{
	bool running = true;
	initiate();
	while (running)
	{
		loggedIn = false;
		while (!(loggedIn))
		{
			loggedIn = (login)->login();
		}
		while ((login)->getUserType() == 1)
		{
			runAdmin();
		}
		
		while ((login)->getUserType() == 2)
		{
			runRegisteredUser();
		}

		while ((login)->getUserType() == 3)
		{
			runGuest();
		}
	}
	system("pause");
}
