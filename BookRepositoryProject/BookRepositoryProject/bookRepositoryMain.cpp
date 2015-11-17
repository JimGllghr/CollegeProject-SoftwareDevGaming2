#include <iostream>
#include "GuestUser.h"
#include "RegisteredUser.h"
#include "Admin.h"
#include "bookRepositoryMain.h"
#include "book.h"

int RegUserCounter;
int currentRegUser;
int GuestUserCounter;
int currentGuestUser;
int adminCounter;
int currentAdmin;
int bookCounter;

int idCount;
int userType;

bool loggedIn;

Admin* adminFirst;
Admin* adminPrev;
GuestUser* GuestNext;
GuestUser* GuestPrev;
RegisteredUser* RegFirst;
RegisteredUser* RegPrev;
book* bookFirst;
book* bookPrev;

Admin* admin;
GuestUser* Guest;
RegisteredUser* Reg;

void registerNewUser(std::string nName, std::string password, unsigned int ID)
{
	RegisteredUser* registeredNewUser = new RegisteredUser(nName, password, ID);
	if (RegUserCounter > 0)
	{
		(registeredNewUser)->setPrev(RegPrev);
		(RegPrev)->setNext(registeredNewUser);
	}
	else
	{
		RegFirst = registeredNewUser;
	}
	currentRegUser++;
	RegUserCounter++;
	RegPrev = registeredNewUser;
}

void DeleteRegUser(std::string nName)
{
	int deletedUsers = 0;
	RegPrev = RegFirst;
	for (int x = 1; x <= RegUserCounter; x++)
	{
		if (((RegPrev)->getName()) == nName)
		{
			if (x == 1)
			{
				RegFirst = (RegFirst)->getNext();
			}
			else
			{
				((RegPrev)->getPrev())->setNext((RegPrev)->getNext());
			}
			if (x < (RegUserCounter - deletedUsers) && x > 1)
			{
				((RegPrev)->getNext())->setPrev((RegPrev)->getPrev());
			}
			RegisteredUser* tempPtr = RegPrev;
			if (x != 1)
			{
				RegPrev = (RegPrev)->getPrev();
			}
			else
			{
				RegPrev = (RegPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= RegUserCounter- (deletedUsers+1))
		{
			RegPrev = (RegPrev)->getNext();
		}
	}
	std::cout << "Registered Users Deleted: " << deletedUsers;
	RegUserCounter -= deletedUsers;
}

std::ostream& operator<<(std::ostream& out, RegisteredUser* user)
{
	std::cout << "\nName: " << (user)->getName() << " ID: " << (user)->getID() << std::endl;
	return out;
}

void printRegisteredUsers()
{
	RegPrev = RegFirst;
	std::cout << "Registered Users\n";
	for (int x = 1; x <= RegUserCounter; x++)
	{
		std::cout << RegPrev;
		if (x < RegUserCounter)
		{
			RegPrev = (RegPrev)->getNext();
		}
	}
}

void resetRegisteredUsers()
{
	RegPrev = RegFirst;
	for (int x = 1; x <= RegUserCounter; x++)
	{
		if (x < RegUserCounter)
		{
			RegPrev = (RegPrev)->getNext();
		}
	}
}

void registerNewAdmin(std::string nName, std::string password, unsigned int ID)
{
	Admin* registeredNewAdmin = new Admin(nName, password, ID);
	if (adminCounter > 0)
	{
		(registeredNewAdmin)->setPrev(adminPrev);
		(adminPrev)->setNext(registeredNewAdmin);
	}
	else
	{
		adminFirst = registeredNewAdmin;
	}
	adminCounter++;
	currentAdmin++;
	adminPrev = registeredNewAdmin;
}

void DeleteAdmin(std::string nName)
{
	int deletedUsers = 0;
	adminPrev = adminFirst;
	for (int x = 1; x < adminCounter; x++)
	{
		if (((adminPrev)->getName()) == nName)
		{
			if (x == 1)
			{
				adminFirst = (adminFirst)->getNext();
			}
			else
			{
				((adminPrev)->getPrev())->setNext((adminPrev)->getNext());
			}
			if (x < (adminCounter - deletedUsers) && x > 1)
			{
				((adminPrev)->getNext())->setPrev((adminPrev)->getPrev());
			}
			Admin* tempPtr = adminPrev;
			if (x != 1)
			{
				adminPrev = (adminPrev)->getPrev();
			}
			else
			{
				adminPrev = (adminPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= adminCounter - (deletedUsers + 1))
		{
			adminPrev = (adminPrev)->getNext();
		}
	}
	std::cout << "\nAdmins Deleted: " << deletedUsers<<std::endl;
	adminCounter -= deletedUsers;
}

std::ostream& operator<<(std::ostream& out, Admin* user)
{
	std::cout << "\nName: " << (user)->getName() << " ID: " << (user)->getID() << std::endl;
	return out;
}

void printAdmins()
{
	adminPrev = adminFirst;
	std::cout << "Admins\n";
	for (int x = 1; x <= adminCounter; x++)
	{
		std::cout << adminPrev;
		if (x <= adminCounter)
		{
			adminPrev = (adminPrev)->getNext();
		}
	}
}

void resetAdmins()
{
	adminPrev = adminFirst;
	for (int x = 1; x <= adminCounter; x++)
	{
		if (x < adminCounter)
		{
			adminPrev = (adminPrev)->getNext();
		}
	}
}

void addBook(std::string nAuthor, std::string nTitle, unsigned int nISBN)
{
	book* newBook = new book(nAuthor, nTitle, nISBN);
	if (bookCounter > 0)
	{
		(newBook)->setPrev(bookPrev);
		(bookPrev)->setNext(newBook);
	}
	else
	{
		bookFirst = newBook;
	}
	bookCounter++;
	bookPrev = newBook;
}

void removeBookName(std::string nName)
{
	int deletedUsers = 0;
	bookPrev = bookFirst;
	for (int x = 1; x <= bookCounter; x++)
	{
		if (((bookPrev)->getTitle()) == nName)
		{
			if (x == 1)
			{
				bookFirst = (bookFirst)->getNext();
			}
			else
			{
				((bookPrev)->getPrev())->setNext((bookPrev)->getNext());
			}
			if (x < (bookCounter - deletedUsers) && x > 1)
			{
				((bookPrev)->getNext())->setPrev((bookPrev)->getPrev());
			}
			book* tempPtr = bookPrev;
			if (x != 1)
			{
				bookPrev = (bookPrev)->getPrev();
			}
			else
			{
				bookPrev = (bookPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= bookCounter - (deletedUsers+1))
		{
			bookPrev = (bookPrev)->getNext();
		}
	}
	std::cout << "books Deleted: " << deletedUsers;
	bookCounter -= deletedUsers;
}

std::ostream& operator<<(std::ostream& out, book* Book)
{
	std::cout << "\nTitle: " << (Book)->getTitle() << " Author: " << (Book)->getAuthor() << " ISBN: " << (Book)->getISBN() << std::endl;
	return out;
}

void printAllBooks()
{
	bookPrev = bookFirst;
	std::cout << "Books\n";
	for (int x = 1; x <= bookCounter; x++)
	{
		std::cout << bookPrev;
		if (x < bookCounter)
		{
			bookPrev = (bookPrev)->getNext();
		}
	}
}

void resetbooks()
{
	bookPrev = bookFirst;
	for (int x = 1; x <= RegUserCounter; x++)
	{
		if (x < bookCounter)
		{
			bookPrev = (bookPrev)->getNext();
		}
	}
}

bool login()
{
	RegPrev = RegFirst;
	std::cout << "Please enter Username: ";
	std::string username;
	std::cin >> username;
	std::cout << "Please enter Password: ";
	std::string password;
	std::cin >> password;

	for (int x = 1; x <= RegUserCounter; x++)
	{
		if (((RegPrev)->getName()) == username)
		{
			if (((RegPrev)->getPassword()) == password)
			{
				userType = 2;
				std::cout << "login Successful\n"<< std::endl;
				Reg = RegPrev;
				return true;
			}
		}
		if (x <= RegUserCounter)
		{
			RegPrev = (RegPrev)->getNext();
		}
	}

	adminPrev = adminFirst;
	for (int x = 1; x <= adminCounter; x++)
	{
		if (((adminPrev)->getName()) == username)
		{
			if (((adminPrev)->getPassword()) == password)
			{
				userType = 1;
				std::cout << "login Successful\n" << std::endl;
				admin = adminPrev;
				return true;
			}
		}
		if (x <= adminCounter)
		{
			adminPrev = (adminPrev)->getNext();
		}
	}

	std::cout << "login Failed" << std::endl;
	return false;
}

void runAdmin()
{
	resetAdmins();
	resetRegisteredUsers();
	std::cout << "\nAdmin Options \n(1) Log out \n(2) Delete Admin \n(3) Add Admin\n(4) Print Admins \n(5) Delete Registered User \n(6) Register user \n(7) Print Registered users \n(8) View my Details \n(9) Print Available books \n(10) Delete Book \n(11) Add Book";
	std::cout << std::endl << "Please enter desired option: ";
	int input;
	std::cin >> input;

	switch (input)
	{
	case 1:
	{
		userType = 0;
		loggedIn = false;
		std::cout << "\nLogged out";
		break;
	}
	case 2:
	{
		std::cout << "please enter name of admin to Delete: ";
		std::string name;
		std::cin >> name;
		DeleteAdmin(name);
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
		registerNewAdmin(name, password, idCount);
		std::cout << "Admin " << name << " has been Registered\n";
		break;
	}
	case 4:
	{
		printAdmins();
		break;
	}
	case 5:
	{
		std::cout << "please enter name of Registered user to Delete: ";
		std::string name;
		std::cin >> name;
		DeleteRegUser(name);
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
		registerNewUser(name, password, idCount);
		std::cout << "User " << name << " has been Registered\n";
		break;
	}
	case 7:
	{
		printRegisteredUsers();
		break;
	}
	case 8:
	{
		std::cout << admin;
		break;
	}
	case 9:
	{
		printAllBooks();
		break;
	}
	case 10:
	{
		std::cout << "please enter name of book to Remove: ";
		std::string name;
		std::cin >> name;
		removeBookName(name);
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
		registerNewAdmin(title, Author, ISBN);
		std::cout << "book " << title << " has been added\n";
		break;
	}
}
}

void runRegisteredUser()
{
	resetAdmins();
	resetRegisteredUsers();
	std::cout << "\nRegistered Users Options \n(1) Log out \n(2) print user Details \n (3)Print Available books";
	std::cout << std::endl << "Please enter desired option: ";
	int input;
	std::cin >> input;
	switch (input) 
	{
	case 1:
		userType = 0;
		loggedIn = false; 
		std::cout << "\nLogged out";
		break;
	case 2:
		std::cout << Reg;
		break;
	case 3:
		printAllBooks();
		break;
	}
}

void runGuest()
{

}

void initiate()
{
	idCount = 10000;
	RegUserCounter = 0;
	GuestUserCounter = 0;
	adminCounter = 0;
	currentAdmin = 0;
	currentRegUser = 0;
	currentGuestUser = 0;

	registerNewUser("james", "sandwich", 26622);
	registerNewUser("Clara", "blueberry", 12233);
	registerNewUser("Amy", "qwerty", 14563);

	registerNewUser("Clara", "blueberry", 17823);
	registerNewUser("Amy", "qwerty", 12223);
	registerNewUser("James", "Sandwich", 12667);

	registerNewAdmin("jim", "qwerty", 12923);
	registerNewAdmin("sam", "qwerty", 12443);
	registerNewAdmin("owen", "qwerty", 15623);
	registerNewAdmin("admin", "admin", 12323);
	
	addBook("The Martian", "Andy Weir", 97808);
	addBook("The Hunger Games", "Susan Collins", 23345);
	addBook("Ready Player one", "Ernest Cline", 65321);
	addBook("The Martian", "Andy Weir", 97808);
	addBook("The Martian", "Andy Weir", 97808);
	addBook("The Martian", "Andy Weir", 97808);
	addBook("The Martian", "Andy Weir", 97808);
	addBook("The Martian", "Andy Weir", 97808);
	addBook("The Martian", "Andy Weir", 97808);
	addBook("The Martian", "Andy Weir", 97808);

	/**
	newGuest("Tom", "qwerty", 12223);
	newGuest("cian", "qwerty", 12223);
	newGuest("kerry", "qwerty", 12223);**/
}

int main()
{
	initiate();

	bool running = true;
	while (running)
	{
		loggedIn = false;
		while (!(loggedIn))
		{
			loggedIn = login();
		}
		while (userType == 1)
		{
			runAdmin();
		}
		
		while (userType == 2)
		{
			runRegisteredUser();
		}

		while (userType == 3)
		{
			runGuest();
		}
	}

	system("pause");
}
