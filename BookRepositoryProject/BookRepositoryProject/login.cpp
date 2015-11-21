#include "Login.h"

bool Login::login()
{
	RegisteredUser* RegPrev = RegFirst;
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
				std::cout << "login Successful\n" << std::endl;
				Reg = RegPrev;
				return true;
			}
		}
		if (x <= RegUserCounter)
		{
			RegPrev = (RegPrev)->getNext();
		}
	}

	Admin* adminPrev = adminFirst;
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

	GuestUser* GuestPrev = GuestNext;
	for (int x = 1; x <= GuestUserCounter; x++)
	{
		if (((GuestPrev)->getName()) == username)
		{
			if (((GuestPrev)->getPassword()) == password)
			{
				userType = 3;
				std::cout << "login Successful\n" << std::endl;
				Guest = GuestPrev;
				return true;
			}
		}
		if (x <= GuestUserCounter)
		{
			GuestPrev = (GuestPrev)->getNext();
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



void Login::reset()
{
	bookPrev = bookFirst;
	for (int x = 1; x <= RegUserCounter; x++)
	{
		if (x < bookCounter)
		{
			bookPrev = (bookPrev)->getNext();
		}
	}

	GuestPrev = GuestNext;
	for (int x = 1; x <= GuestUserCounter; x++)
	{
		if (x < GuestUserCounter)
		{
			GuestPrev = (GuestPrev)->getNext();
		}
	}

	adminPrev = adminFirst;
	for (int x = 1; x <= adminCounter; x++)
	{
		if (x < adminCounter)
		{
			adminPrev = (adminPrev)->getNext();
		}
	}

	RegPrev = RegFirst;
	for (int x = 1; x <= RegUserCounter; x++)
	{
		if (x < RegUserCounter)
		{
			RegPrev = (RegPrev)->getNext();
		}
	}
}