#include "Login.h"

Login::Login(AdminIterator* aAdminIterator, GuestIterator* aGuestIterator, RegUserIterator* aRegUserIterator, BookIterator* aBookIterator)
{
	adminIterator = aAdminIterator;
	guestIterator = aGuestIterator;
	regUserIterator = aRegUserIterator;
	bookIterator = aBookIterator;
}
bool Login::login()
{
	(adminIterator)->setadminPrev((adminIterator)->getadminFirst());
	(guestIterator)->setGuestPrev((guestIterator)->getGuestNext());
	(regUserIterator)->setRegPrev((regUserIterator)->getRegFirst());

	std::cout << "Please enter Username: ";
	std::string username;
	std::cin >> username;
	std::cout << "Please enter Password: ";
	std::string password;
	std::cin >> password;

	for (int x = 1; x <= (regUserIterator)->getRegUserCounter(); x++)
	{
		if ((((regUserIterator)->getRegPrev())->getName()) == username)
		{
			if ((((regUserIterator)->getRegPrev())->getPassword()) == password)
			{
				userType = 2;
				std::cout << "login Successful\n" << std::endl;
				Reg = (regUserIterator)->getRegPrev();
				return true;
			}
		}
		if (x <= (regUserIterator)->getRegUserCounter())
		{
			(regUserIterator)->setRegPrev(((regUserIterator)->getRegPrev())->getNext());
		}
	}

	for (int x = 1; x <= (adminIterator)->getadminCounter(); x++)
	{
		if ((((adminIterator)->getadminPrev())->getName()) == username)
		{
			if ((((adminIterator)->getadminPrev())->getPassword()) == password)
			{
				userType = 1;
				std::cout << "login Successful\n" << std::endl;
				return true;
			}
		}
		if (x <= (adminIterator)->getadminCounter())
		{
			(adminIterator)->setadminPrev(((adminIterator)->getadminPrev())->getNext());
		}
	}

	for (int x = 1; x <= (guestIterator)->getGuestUserCounter(); x++)
	{
		if ((((guestIterator)->getGuestPrev())->getName()) == username)
		{
			if ((((guestIterator)->getGuestPrev())->getPassword()) == password)
			{
				userType = 3;
				std::cout << "login Successful\n" << std::endl;
				return true;
			}
		}
		if (x <= (guestIterator)->getGuestUserCounter())
		{
			(guestIterator)->setGuestPrev(((guestIterator)->getGuestPrev())->getNext());
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
	system("cls");
	userType = 0;
}

RegisteredUser* Login::getReg()
{
	return Reg;
}