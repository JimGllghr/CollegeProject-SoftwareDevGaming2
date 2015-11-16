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
	std::cout << "Registered Users\n\n";
	for (int x = 1; x <= RegUserCounter; x++)
	{
		std::cout << RegPrev;
		if (x <= RegUserCounter)
		{
			RegPrev = (RegPrev)->getNext();
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
				std::cout << "login Successful\n";
				return true;
			}
		}
		if (x <= RegUserCounter)
		{
			RegPrev = (RegPrev)->getNext();
		}
	}
	std::cout << "login Failed";
	return false;
}

int main()
{
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

	/**
	newAdmin("jim", "qwerty", 12223);
	newAdmin("sam", "qwerty", 12223);
	newAdmin("owen", "qwerty", 12223);

	newGuest("Tom", "qwerty", 12223);
	newGuest("cian", "qwerty", 12223);
	newGuest("kerry", "qwerty", 12223);**/

	printRegisteredUsers();
	DeleteRegUser("James");
	printRegisteredUsers();

	bool log = login();

	system("pause");
}

