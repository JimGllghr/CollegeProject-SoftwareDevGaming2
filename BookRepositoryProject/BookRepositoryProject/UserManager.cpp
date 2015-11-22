#pragma once
#include "UserManager.h"

void UserManager::registerNewUser(std::string nName, std::string password, unsigned int ID)
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
	RegUserCounter++;
	RegPrev = registeredNewUser;
}

void UserManager::DeleteRegUser(std::string nName)
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
		if (x <= RegUserCounter - (deletedUsers + 1))
		{
			RegPrev = (RegPrev)->getNext();
		}
	}
	std::cout << "Registered Users Deleted: " << deletedUsers;
	RegUserCounter -= deletedUsers;
}

void UserManager::printRegisteredUsers()
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

void UserManager::resetRegisteredUsers()
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

void UserManager::registerNewAdmin(std::string nName, std::string password, unsigned int ID)
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
	adminPrev = registeredNewAdmin;
}

void UserManager::DeleteAdmin(std::string nName)
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
	std::cout << "\nAdmins Deleted: " << deletedUsers << std::endl;
	adminCounter -= deletedUsers;
}

void UserManager::printAdmins()
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

void UserManager::registerNewGuest(std::string nName, std::string password, unsigned int ID)
{
	GuestUser* registeredNewGuest = new GuestUser(nName, password, ID);
	if (GuestUserCounter > 0)
	{
		(registeredNewGuest)->setPrev(GuestPrev);
		(GuestPrev)->setNext(registeredNewGuest);
	}
	else
	{
		GuestNext = registeredNewGuest;
	}
	GuestUserCounter++;
	GuestPrev = registeredNewGuest;
}

void UserManager::DeletGuest(std::string nName)
{
	int deletedUsers = 0;
	GuestPrev = GuestNext;
	for (int x = 1; x < GuestUserCounter; x++)
	{
		if (((GuestPrev)->getName()) == nName)
		{
			if (x == 1)
			{
				GuestNext = (GuestNext)->getNext();
			}
			else
			{
				((GuestPrev)->getPrev())->setNext((GuestPrev)->getNext());
			}
			if (x < (GuestUserCounter - deletedUsers) && x > 1)
			{
				((GuestPrev)->getNext())->setPrev((GuestPrev)->getPrev());
			}
			GuestUser* tempPtr = GuestPrev;
			if (x != 1)
			{
				GuestPrev = (GuestPrev)->getPrev();
			}
			else
			{
				GuestPrev = (GuestPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= GuestUserCounter - (deletedUsers + 1))
		{
			GuestPrev = (GuestPrev)->getNext();
		}
	}
	std::cout << "\nGuests Deleted: " << deletedUsers << std::endl;
	GuestUserCounter -= deletedUsers;
}

void UserManager::printGuests()
{
	GuestPrev = GuestNext;
	std::cout << "\nGuest Users\n";
	for (int x = 1; x <= GuestUserCounter; x++)
	{
		std::cout << GuestPrev;
		if (x <= GuestUserCounter)
		{
			GuestPrev = (GuestPrev)->getNext();
		}
	}
}

void UserManager::addBook(std::string nAuthor, std::string nTitle, unsigned int nISBN, unsigned int nQuantity)
{
	book* newBook = new book(nAuthor, nTitle, nISBN, nQuantity);
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

void UserManager::removeBookName(std::string nName)
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
		if (x <= bookCounter - (deletedUsers + 1))
		{
			bookPrev = (bookPrev)->getNext();
		}
	}
	std::cout << "books Deleted: " << deletedUsers;
	bookCounter -= deletedUsers;
}

void UserManager::printAllBooks()
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

void UserManager::printAvailableBooks()
{
	bookPrev = bookFirst;
	std::cout << "Books\n";
	for (int x = 1; x <= bookCounter; x++)
	{
		if ((bookPrev)->getQuantity() > 0)
		{
			std::cout << bookPrev;
			if (x < bookCounter)
			{
				bookPrev = (bookPrev)->getNext();
			}
		}
	}
}


void UserManager::reset()
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

Admin* UserManager::getadminFirst()
{
	return adminFirst;
}
Admin* UserManager::getadminPrev()
{
	return adminPrev;
}
GuestUser* UserManager::getGuestNext()
{
	return GuestNext;
}
GuestUser* UserManager::getGuestPrev()
{
	return GuestPrev;
}
RegisteredUser* UserManager::getRegFirst()
{
	return RegFirst;
}
RegisteredUser* UserManager::getRegPrev()
{
	return RegPrev;
}
book* UserManager::getbookFirst()
{
	return bookFirst;
}
book* UserManager::getbookPrev()
{
	return bookPrev;
}

int UserManager::getRegUserCounter()
{
	return RegUserCounter;
}
int UserManager::getGuestUserCounter()
{
	return GuestUserCounter;
}
int UserManager::getadminCounter()
{
	return adminCounter;
}
int UserManager::getbookCounter()
{
	return bookCounter;
}

void UserManager::setadminFirst(Admin* nPtr)
{
	adminFirst = nPtr;
}
void UserManager::setadminPrev(Admin* nPtr)
{
	adminPrev = nPtr;
}
void UserManager::setGuestNext(GuestUser* nPtr)
{
	GuestNext = nPtr;
}
void UserManager::setGuestPrev(GuestUser* nPtr)
{
	GuestPrev = nPtr;
}
void UserManager::setRegFirst(RegisteredUser* nPtr)
{
	RegFirst = nPtr;
}
void UserManager::setRegPrev(RegisteredUser* nPtr)
{
	RegPrev = nPtr;
}
void UserManager::setbookFirst(book* nPtr)
{
	bookFirst = nPtr;
}
void UserManager::setbookPrev(book* nPtr)
{
	bookPrev = nPtr;
}

void UserManager::setRegUserCounter(int num)
{
	RegUserCounter = num;
}
void UserManager::setGuestUserCounter(int num)
{
	GuestUserCounter = num;
}
void UserManager::setadminCounter(int num)
{
	adminCounter = num;
}
void UserManager::setbookCounter(int num)
{
	bookCounter = num;
}