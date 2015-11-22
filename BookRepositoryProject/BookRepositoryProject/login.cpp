#include "Login.h"
Login::Login(UserManager* nManager)
{
	manager = nManager;
}
bool Login::login()
{
	(manager)->reset();
	std::cout << "Please enter Username: ";
	std::string username;
	std::cin >> username;
	std::cout << "Please enter Password: ";
	std::string password;
	std::cin >> password;

	for (int x = 1; x <= (manager)->getRegUserCounter(); x++)
	{
		if ((((manager)->getRegPrev())->getName()) == username)
		{
			if ((((manager)->getRegPrev())->getPassword()) == password)
			{
				userType = 2;
				std::cout << "login Successful\n" << std::endl;
				Reg = (manager)->getRegPrev();
				return true;
			}
		}
		if (x <= (manager)->getRegUserCounter())
		{
			(manager)->setRegPrev(((manager)->getRegPrev())->getNext());
		}
	}

	for (int x = 1; x <= (manager)->getadminCounter(); x++)
	{
		if ((((manager)->getadminPrev())->getName()) == username)
		{
			if ((((manager)->getadminPrev())->getPassword()) == password)
			{
				userType = 1;
				std::cout << "login Successful\n" << std::endl;
				admin = (manager)->getadminPrev();
				return true;
			}
		}
		if (x <= (manager)->getadminCounter())
		{
			(manager)->setadminPrev(((manager)->getadminPrev())->getNext());
		}
	}

	for (int x = 1; x <= (manager)->getGuestUserCounter(); x++)
	{
		if ((((manager)->getGuestPrev())->getName()) == username)
		{
			if ((((manager)->getGuestPrev())->getPassword()) == password)
			{
				userType = 3;
				std::cout << "login Successful\n" << std::endl;
				Guest = (manager)->getGuestPrev();
				return true;
			}
		}
		if (x <= (manager)->getGuestUserCounter())
		{
			(manager)->setGuestPrev(((manager)->getGuestPrev())->getNext());
		}
	}
	std::cout << "login Failed" << std::endl;
	return false;
}

unsigned int Login::getUserType() const
{
	return userType;
}

void Login::logout()
{
	userType = 0;
}

Admin* Login::getAdmin() const
{
	return admin;
}
GuestUser* Login::getGuest() const
{
	return Guest;
}
RegisteredUser* Login::getReg() const
{
	return Reg;
}

