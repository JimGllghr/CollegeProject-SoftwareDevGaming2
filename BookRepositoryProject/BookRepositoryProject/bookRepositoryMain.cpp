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

RegisteredUser* Regnext;
RegisteredUser* RegPrev;
user* GuestNext;
user* GuestPrev;
user* AdminNext;
user* AdminPrev;

void registerNewUser(std::string nName, std::string password, unsigned int ID)
{
	RegisteredUser registeredNewUser(nName, password, ID);
	if (RegUserCounter > 0)
	{	
		std::cout << "Prev Set";
		registeredNewUser.setPrev(RegPrev);
		(RegPrev)->setNext(&registeredNewUser);
	}
	currentRegUser++;
	RegUserCounter++;
	RegPrev = &registeredNewUser;
}

void ResetRegisteredUsers()
{
	while (RegUserCounter < currentRegUser)
	{
		currentRegUser++;
		RegPrev = (RegPrev)->getNext();
		Regnext = (RegPrev)->getNext();
	}
}

void printRegisteredUsers()
{
	//ResetRegisteredUsers();
	std::cout << "Registered Users\n\n";
	while (currentRegUser>0)
	{
		std::cout << (RegPrev)->getName() << "\n";
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
	registerNewUser("sam", "blueberry", 12223);

	printRegisteredUsers();
}

