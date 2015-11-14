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

RegisteredUser* RegFirst;
RegisteredUser* RegPrev;
user* GuestNext;
user* GuestPrev;
user* AdminNext;
user* AdminPrev;

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

void DeleteRegUserName(std::string nName)
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
			((RegPrev)->getPrev())->setNext((RegPrev)->getNext());
			((RegPrev)->getNext())->setPrev((RegPrev)->getPrev());
			RegisteredUser* tempPtr = RegPrev;
			RegPrev = (RegPrev)->getPrev();
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= RegUserCounter)
		{
			RegPrev = (RegPrev)->getNext();
		}
	}
	std::cout <<"Registered Users Deleted: "<< deletedUsers;
	RegUserCounter -= deletedUsers;
}

void printRegisteredUsers()
{
	RegPrev = RegFirst;
	std::cout << "Registered Users\n\n";
	for (int x = 1; x <= RegUserCounter; x++)
	{
		std::cout << "Name: "<<(RegPrev)->getName() <<" - ID: "<< (RegPrev)->getID()<< "\n";
		if (x <= RegUserCounter)
		{
			RegPrev = (RegPrev)->getNext();
		}
	}
}
int main()
{
	RegUserCounter = 0;
	GuestUserCounter = 0;
	adminCounter = 0;
	currentAdmin = 0;
	currentRegUser = 0;
	currentGuestUser = 0;

	registerNewUser("James", "Sandwich", 12223);
	registerNewUser("Clara", "blueberry", 12223);
	registerNewUser("Amy", "qwerty", 12223);
	registerNewUser("Clara", "blueberry", 12223);
	registerNewUser("Amy", "qwerty", 12223);
	registerNewUser("Rory", "qwerty", 12223);

	printRegisteredUsers();
	DeleteRegUserName("Amy");
	printRegisteredUsers();

	system("pause");
}

