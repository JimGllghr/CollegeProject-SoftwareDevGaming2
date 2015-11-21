#pragma once
#include "UserManager.h"

UserManager::UserManager(Login* aLogin)
{
	mLogin = aLogin;
}

void UserManager::registerNewUser(std::string nName, std::string password, unsigned int ID)
{
	RegisteredUser* registeredNewUser = new RegisteredUser(nName, password, ID);
	if ((mLogin)->RegUserCounter > 0)
	{
		(registeredNewUser)->setPrev((mLogin)->RegPrev);
		((mLogin)->RegPrev)->setNext(registeredNewUser);
	}
	else
	{
		(mLogin)->RegFirst = registeredNewUser;
	}
	(mLogin)->RegUserCounter++;
	(mLogin)->RegPrev = registeredNewUser;
}

void UserManager::DeleteRegUser(std::string nName)
{
	int deletedUsers = 0;
	(mLogin)->RegPrev = (mLogin)->RegFirst;
	for (int x = 1; x <= (mLogin)->RegUserCounter; x++)
	{
		if ((((mLogin)->RegPrev)->getName()) == nName)
		{
			if (x == 1)
			{
				(mLogin)->RegFirst = ((mLogin)->RegFirst)->getNext();
			}
			else
			{
				(((mLogin)->RegPrev)->getPrev())->setNext(((mLogin)->RegPrev)->getNext());
			}
			if (x < ((mLogin)->RegUserCounter - deletedUsers) && x > 1)
			{
				(((mLogin)->RegPrev)->getNext())->setPrev(((mLogin)->RegPrev)->getPrev());
			}
			RegisteredUser* tempPtr = (mLogin)->RegPrev;
			if (x != 1)
			{
				(mLogin)->RegPrev = ((mLogin)->RegPrev)->getPrev();
			}
			else
			{
				(mLogin)->RegPrev = ((mLogin)->RegPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= (mLogin)->RegUserCounter - (deletedUsers + 1))
		{
			(mLogin)->RegPrev = ((mLogin)->RegPrev)->getNext();
		}
	}
	std::cout << "Registered Users Deleted: " << deletedUsers;
	(mLogin)->RegUserCounter -= deletedUsers;
}

void UserManager::printRegisteredUsers()
{
	(mLogin)->RegPrev = (mLogin)->RegFirst;
	std::cout << "Registered Users\n";
	for (int x = 1; x <= (mLogin)->RegUserCounter; x++)
	{
		std::cout << (mLogin)->RegPrev;
		if (x < (mLogin)->RegUserCounter)
		{
			(mLogin)->RegPrev = ((mLogin)->RegPrev)->getNext();
		}
	}
}

void UserManager::resetRegisteredUsers()
{
	(mLogin)->RegPrev = (mLogin)->RegFirst;
	for (int x = 1; x <= (mLogin)->RegUserCounter; x++)
	{
		if (x < (mLogin)->RegUserCounter)
		{
			(mLogin)->RegPrev = ((mLogin)->RegPrev)->getNext();
		}
	}
}

void UserManager::registerNewAdmin(std::string nName, std::string password, unsigned int ID)
{
	Admin* registeredNewAdmin = new Admin(nName, password, ID);
	if ((mLogin)->adminCounter > 0)
	{
		(registeredNewAdmin)->setPrev((mLogin)->adminPrev);
		((mLogin)->adminPrev)->setNext(registeredNewAdmin);
	}
	else
	{
		(mLogin)->adminFirst = registeredNewAdmin;
	}
	(mLogin)->adminCounter++;
	(mLogin)->adminPrev = registeredNewAdmin;
}

void UserManager::DeleteAdmin(std::string nName)
{
	int deletedUsers = 0;
	(mLogin)->adminPrev = (mLogin)->adminFirst;
	for (int x = 1; x < (mLogin)->adminCounter; x++)
	{
		if ((((mLogin)->adminPrev)->getName()) == nName)
		{
			if (x == 1)
			{
				(mLogin)->adminFirst = ((mLogin)->adminFirst)->getNext();
			}
			else
			{
				(((mLogin)->adminPrev)->getPrev())->setNext(((mLogin)->adminPrev)->getNext());
			}
			if (x < ((mLogin)->adminCounter - deletedUsers) && x > 1)
			{
				(((mLogin)->adminPrev)->getNext())->setPrev(((mLogin)->adminPrev)->getPrev());
			}
			Admin* tempPtr = (mLogin)->adminPrev;
			if (x != 1)
			{
				(mLogin)->adminPrev = ((mLogin)->adminPrev)->getPrev();
			}
			else
			{
				(mLogin)->adminPrev = ((mLogin)->adminPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= (mLogin)->adminCounter - (deletedUsers + 1))
		{
			(mLogin)->adminPrev = ((mLogin)->adminPrev)->getNext();
		}
	}
	std::cout << "\nAdmins Deleted: " << deletedUsers << std::endl;
	(mLogin)->adminCounter -= deletedUsers;
}

void UserManager::printAdmins()
{
	(mLogin)->adminPrev = (mLogin)->adminFirst;
	std::cout << "Admins\n";
	for (int x = 1; x <= (mLogin)->adminCounter; x++)
	{
		std::cout << (mLogin)->adminPrev;
		if (x <= (mLogin)->adminCounter)
		{
			(mLogin)->adminPrev = ((mLogin)->adminPrev)->getNext();
		}
	}
}

void UserManager::registerNewGuest(std::string nName, std::string password, unsigned int ID)
{
	GuestUser* registeredNewGuest = new GuestUser(nName, password, ID);
	if ((mLogin)->GuestUserCounter > 0)
	{
		(registeredNewGuest)->setPrev((mLogin)->GuestPrev);
		((mLogin)->GuestPrev)->setNext(registeredNewGuest);
	}
	else
	{
		(mLogin)->GuestNext = registeredNewGuest;
	}
	(mLogin)->GuestUserCounter++;
	(mLogin)->GuestPrev = registeredNewGuest;
}

void UserManager::DeletGuest(std::string nName)
{
	int deletedUsers = 0;
	(mLogin)->GuestPrev = (mLogin)->GuestNext;
	for (int x = 1; x < (mLogin)->GuestUserCounter; x++)
	{
		if ((((mLogin)->GuestPrev)->getName()) == nName)
		{
			if (x == 1)
			{
				(mLogin)->GuestNext = ((mLogin)->GuestNext)->getNext();
			}
			else
			{
				(((mLogin)->GuestPrev)->getPrev())->setNext(((mLogin)->GuestPrev)->getNext());
			}
			if (x < ((mLogin)->GuestUserCounter - deletedUsers) && x > 1)
			{
				(((mLogin)->GuestPrev)->getNext())->setPrev(((mLogin)->GuestPrev)->getPrev());
			}
			GuestUser* tempPtr = (mLogin)->GuestPrev;
			if (x != 1)
			{
				(mLogin)->GuestPrev = ((mLogin)->GuestPrev)->getPrev();
			}
			else
			{
				(mLogin)->GuestPrev = ((mLogin)->GuestPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= (mLogin)->GuestUserCounter - (deletedUsers + 1))
		{
			(mLogin)->GuestPrev = ((mLogin)->GuestPrev)->getNext();
		}
	}
	std::cout << "\nGuests Deleted: " << deletedUsers << std::endl;
	(mLogin)->GuestUserCounter -= deletedUsers;
}

void UserManager::printGuests()
{
	(mLogin)->GuestPrev = (mLogin)->GuestNext;
	std::cout << "\nGuest Users\n";
	for (int x = 1; x <= (mLogin)->GuestUserCounter; x++)
	{
		std::cout << (mLogin)->GuestPrev;
		if (x <= (mLogin)->GuestUserCounter)
		{
			(mLogin)->GuestPrev = ((mLogin)->GuestPrev)->getNext();
		}
	}
}

void UserManager::addBook(std::string nAuthor, std::string nTitle, unsigned int nISBN, unsigned int nQuantity)
{
	book* newBook = new book(nAuthor, nTitle, nISBN, nQuantity);
	if ((mLogin)->bookCounter > 0)
	{
		(newBook)->setPrev((mLogin)->bookPrev);
		((mLogin)->bookPrev)->setNext(newBook);
	}
	else
	{
		(mLogin)->bookFirst = newBook;
	}
	(mLogin)->bookCounter++;
	(mLogin)->bookPrev = newBook;
}

void UserManager::removeBookName(std::string nName)
{
	int deletedUsers = 0;
	(mLogin)->bookPrev = (mLogin)->bookFirst;
	for (int x = 1; x <= (mLogin)->bookCounter; x++)
	{
		if ((((mLogin)->bookPrev)->getTitle()) == nName)
		{
			if (x == 1)
			{
				(mLogin)->bookFirst = ((mLogin)->bookFirst)->getNext();
			}
			else
			{
				(((mLogin)->bookPrev)->getPrev())->setNext(((mLogin)->bookPrev)->getNext());
			}
			if (x < ((mLogin)->bookCounter - deletedUsers) && x > 1)
			{
				(((mLogin)->bookPrev)->getNext())->setPrev(((mLogin)->bookPrev)->getPrev());
			}
			book* tempPtr = (mLogin)->bookPrev;
			if (x != 1)
			{
				(mLogin)->bookPrev = ((mLogin)->bookPrev)->getPrev();
			}
			else
			{
				(mLogin)->bookPrev = ((mLogin)->bookPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= (mLogin)->bookCounter - (deletedUsers + 1))
		{
			(mLogin)->bookPrev = ((mLogin)->bookPrev)->getNext();
		}
	}
	std::cout << "books Deleted: " << deletedUsers;
	(mLogin)->bookCounter -= deletedUsers;
}

void UserManager::printAllBooks()
{
	(mLogin)->bookPrev = (mLogin)->bookFirst;
	std::cout << "Books\n";
	for (int x = 1; x <= (mLogin)->bookCounter; x++)
	{
		std::cout << (mLogin)->bookPrev;
		if (x < (mLogin)->bookCounter)
		{
			(mLogin)->bookPrev = ((mLogin)->bookPrev)->getNext();
		}
	}
}

void UserManager::printAvailableBooks()
{
	(mLogin)->bookPrev = (mLogin)->bookFirst;
	std::cout << "Books\n";
	for (int x = 1; x <= (mLogin)->bookCounter; x++)
	{
		if (((mLogin)->bookPrev)->getQuantity() > 0)
		{
			std::cout << (mLogin)->bookPrev;
			if (x < (mLogin)->bookCounter)
			{
				(mLogin)->bookPrev = ((mLogin)->bookPrev)->getNext();
			}
		}
	}
}