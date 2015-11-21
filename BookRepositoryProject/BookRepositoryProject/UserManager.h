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
	UserManager(Login* aLogin);
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
private:
	Login* mLogin;
};