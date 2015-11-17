#include <iostream>
#include "GuestUser.h"
#include "RegisteredUser.h"
#include "Admin.h"
#include "bookRepositoryMain.h"

int RegUserCounter;
int currentRegUser;
int GuestUserCounter;
int currentGuestUser;
int adminCounter;
int currentAdmin;

int idCount;
int userType;

Admin* adminFirst;
Admin* adminPrev;
GuestUser* GuestNext;
GuestUser* GuestPrev;
RegisteredUser* RegFirst;
RegisteredUser* RegPrev;

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
		if (x <= RegUserCounter)
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
	for (int x = 1; x <= adminCounter; x++)
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

int main()
{
	idCount = 10000;
	RegUserCounter = 0;
	GuestUserCounter = 0;
	adminCounter = 0;
	currentAdmin = 0;
	currentRegUser = 0;
	currentGuestUser = 0;

	registerNewUser("james", "sandwich", 12223);
	registerNewUser("Clara", "blueberry", 12223);
	registerNewUser("Amy", "qwerty", 12223);
	registerNewUser("Clara", "blueberry", 12223);
	registerNewUser("Amy", "qwerty", 12223);
	registerNewUser("James", "Sandwich", 12223);

	registerNewAdmin("jim", "qwerty", 12223);
	registerNewAdmin("sam", "qwerty", 12223);
	registerNewAdmin("owen", "qwerty", 12223);
	registerNewAdmin("admin", "admin", 12223);
	/**
	newGuest("Tom", "qwerty", 12223);
	newGuest("cian", "qwerty", 12223);
	newGuest("kerry", "qwerty", 12223);**/

	bool running = true;
	while (running)
	{
		bool loggedIn = false;
		while (!(loggedIn))
		{
			loggedIn = login();
		}
		while (userType == 1)
		{
			std::cout << "\nAdmin Options \n(1) Log out \n(2) Delete Admin \n(3) Add Admin\n(4) Print Admins \n(5) Delete Registered User \n(6) Register user \n(7) Print Registered users";
			std::cout << std::endl <<"Please enter desired option: ";
			int input;
			std::cin >> input;
			if (input == 1)
			{
				userType = 0;
				loggedIn = false;
			}
			if (input == 2)
			{
				std::cout << "please enter name of admin to Delete: ";
				std::string name;
				std::cin >> name;
				DeleteAdmin(name);
			}
			if (input == 3)
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
			}
			if (input == 4)
			{
				printAdmins();
			}
			if (input == 5)
			{
				std::cout << "please enter name of Registered user to Delete: ";
				std::string name;
				std::cin >> name;
				DeleteRegUser(name);
			}
			if (input == 6)
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
			}
			if (input == 7)
			{
				printRegisteredUsers();
			}
		}
	}

	system("pause");
}

