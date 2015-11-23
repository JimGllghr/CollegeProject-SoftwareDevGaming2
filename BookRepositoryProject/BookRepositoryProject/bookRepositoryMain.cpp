#include "login.h"
#include "AdminIterator.h"
#include "GuestIterator.h"
#include "BookIterator.h"
#include "RegUserIterator.h"

int idCount;
bool loggedIn;
AdminIterator* adminIterator;
GuestIterator* guestIterator;
RegUserIterator* regUserIterator;
BookIterator* bookIterator;
Login* login;

void runAdmin()
{
	std::cout << "\nAdmin Options \n(1) Log out \n(2) Delete Admin \n(3) Add Admin\n(4) Print Admins \n(5) Delete Registered User \n(6) Register user \n(7) Print Registered users \n(8) Print Available books \n(9) Delete Book \n(10) Add Book \n(11) Register Guest user \n(12) Delete Guest user \n(13) print Guest Users";
	std::cout << std::endl << "Please enter desired option: ";
	int input;
	std::cin >> input;

	switch (input)
	{
		case 1:
		{
			(login)->logout();
			loggedIn = false;
			std::cout << "\nLogged out\n";
			break;
		}
		case 2:
		{
			std::cout << "please enter name of admin to Delete: ";
			std::string name;
			std::cin >> name;
			(adminIterator)->DeleteAdmin(name);
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
			(adminIterator)->registerNewAdmin(name, password, idCount);
			std::cout << "Admin " << name << " has been Registered\n";
			break;
		}
		case 4:
		{
			(adminIterator)->printAdmins();
			break;
		}
		case 5:
		{
			std::cout << "please enter name of Registered user to Delete: ";
			std::string name;
			std::cin >> name;
			(regUserIterator)->DeleteRegUser(name);
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
			(regUserIterator)->registerNewUser(name, password, idCount);
			std::cout << "User " << name << " has been Registered\n";
			break;
		}
		case 7:
		{
			(regUserIterator)->printRegisteredUsers();
			break;
		}
		case 8:
		{
			(bookIterator)->printAllBooks();
			break;
		}
		case 9:
		{
			std::cout << "please enter name of book to Remove: ";
			std::string name;
			std::getline(std::cin, name);
			std::getline(std::cin, name);
			(bookIterator)->removeBookName(name);
			break;
		}
		case 10:
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
			(bookIterator)->addBook(title, Author, ISBN, quantity);
			std::cout << "book " << title << " has been added\n";
			break;
		}
		case 11:
		{
			std::cout << "please enter name of Guest user to Delete: ";
			std::string name;
			std::cin >> name;
			(guestIterator)->DeletGuest(name);
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
			(guestIterator)->registerNewGuest(name, password, idCount);
			std::cout << "Guest user " << name << " has been Registered\n";
			break;
		}
		case 13:
		{
			(guestIterator)->printGuests();
		}
		std::cin.clear();
	}
}

void runRegisteredUser()
{
	std::cout << "\nRegistered Users Options \n(1) Log out \n(2) Print Available books \n(3) loan book \n(4) Return book \n(5) Print Loaned Books \n(6) Search for book by name or Author \n(7) Search for book by ISBN";
	std::cout << std::endl << "Please enter desired option: ";
	int input;
	std::cin >> input;
	switch (input)
	{
	case 1:
		(login)->logout();
		loggedIn = false;
		std::cout << "\nLogged out\n";
		break;
	case 2:
		(bookIterator)->printAvailableBooks();
		break;
	case 3:
		((login)->getReg())->loanBook(bookIterator);
		break;
	case 4:
		((login)->getReg())->returnBook(bookIterator);
		break;
	case 5:
		((login)->getReg())->printLoanedBooks();
		break;
	case 6:
		(bookIterator)->searchForBook();
		break;
	case 7:
		(bookIterator)->searchForBookISBN();
		break;
	}
}

void runGuest()
{
	std::cout << "\nRegistered Users Options \n(1) Log out \n(2) Print Available books \n(3) Search for book by name or Author \n(4) Search for book by ISBN";
	std::cout << std::endl << "Please enter desired option: ";
	int input;
	std::cin >> input;
	switch (input)
	{
	case 1:
		(login)->logout();
		loggedIn = false;
		std::cout << "\nLogged out\n";
		break;
	case 2:
		(bookIterator)->printAvailableBooks();
		break;
	case 3:
		(bookIterator)->searchForBook();
		break;
	case 4:
		(bookIterator)->searchForBookISBN();
		break;
	}
}

void initiate()
{
	adminIterator = new AdminIterator();
	guestIterator = new GuestIterator();
	regUserIterator = new RegUserIterator();
	bookIterator = new BookIterator();

	login = new Login(adminIterator, guestIterator, regUserIterator, bookIterator);
	idCount = 10000;

	(regUserIterator)->setRegUserCounter(0);
	(guestIterator)->setGuestUserCounter(0);
	(adminIterator)->setadminCounter(0);
	(bookIterator)->setbookCounter(0);

	(regUserIterator)->registerNewUser("james", "sandwich", 26622);
	(regUserIterator)->registerNewUser("Clara", "blueberry", 12233);
	(regUserIterator)->registerNewUser("Amy", "qwerty", 14563);

	(regUserIterator)->registerNewUser("Clara", "blueberry", 17823);
	(regUserIterator)->registerNewUser("Amy", "qwerty", 12223);
	(regUserIterator)->registerNewUser("James", "Sandwich", 12667);

	(adminIterator)->registerNewAdmin("jim", "qwerty", 12923);
	(adminIterator)->registerNewAdmin("sam", "qwerty", 12443);
	(adminIterator)->registerNewAdmin("owen", "qwerty", 15623);
	(adminIterator)->registerNewAdmin("admin", "admin", 12323);
	
	(bookIterator)->addBook("Andy Weir", "The Martian", 97808, 2);
	(bookIterator)->addBook("Suzanne Collins", "The Hunger Games", 23345, 1);
	(bookIterator)->addBook("Suzanne Collins", "The Hunger Games: Catching Fire", 23345, 3);
	(bookIterator)->addBook("Ernest Cline", "Ready Player one", 65321, 3);

	(guestIterator)->registerNewGuest("Tom", "qwerty", 12223);
	(guestIterator)->registerNewGuest("cian", "qwerty", 12223);
	(guestIterator)->registerNewGuest("kerry", "qwerty", 12223);
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
