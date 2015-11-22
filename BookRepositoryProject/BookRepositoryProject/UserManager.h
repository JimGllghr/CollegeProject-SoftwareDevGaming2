#pragma once
#include <iostream>
#include "GuestUser.h"
#include "RegisteredUser.h"
#include "Admin.h"
#include "book.h"
#include "Login.h"

class UserManager
{
public:
	UserManager();
	void registerNewUser(std::string nName, std::string password, unsigned int ID);
	void DeleteRegUser(std::string nName);
	void printRegisteredUsers();
	void resetRegisteredUsers();
	void registerNewAdmin(std::string nName, std::string password, unsigned int ID);
	void DeleteAdmin(std::string nName);
	void printAdmins();
	void registerNewGuest(std::string nName, std::string password, unsigned int ID);
	void DeletGuest(std::string nName);
	void printGuests();
	void addBook(std::string nAuthor, std::string nTitle, unsigned int nISBN, unsigned int nQuantity);
	void removeBookName(std::string nName);
	void printAllBooks();
	void printAvailableBooks();

	Admin* getadminFirst();
	Admin* getadminPrev();
	GuestUser* getGuestNext();
	GuestUser* getGuestPrev();
	RegisteredUser* getRegFirst();
	RegisteredUser* getRegPrev();
	book* getbookFirst();
	book* getbookPrev();

	int getRegUserCounter();
	int getGuestUserCounter();
	int getadminCounter();
	int getbookCounter();

	void setadminFirst (Admin* nPtr);
	void setadminPrev (Admin* nPtr);
	void setGuestNext (GuestUser* nPtr);
	void setGuestPrev (GuestUser* nPtr);
	void setRegFirst (RegisteredUser* nPtr);
	void setRegPrev (RegisteredUser* nPtr);
	void setbookFirst (book* nPtr);
	void setbookPrev (book* nPtr);

	void setRegUserCounter(int num);
	void setGuestUserCounter (int num);
	void setadminCounter (int num);
	void setbookCounter (int num);

	void reset();

private:
	Admin* adminFirst;
	Admin* adminPrev;
	GuestUser* GuestNext;
	GuestUser* GuestPrev;
	RegisteredUser* RegFirst;
	RegisteredUser* RegPrev;
	book* bookFirst;
	book* bookPrev;

	int RegUserCounter;
	int GuestUserCounter;
	int adminCounter;
	int bookCounter;
};