
#pragma once
#ifndef nRegisteredUser
#define nRegisteredUser
#include <string>
#include "User.h"
#include "book.h"

#include <iostream>

class RegisteredUser : public user
{
public:
	RegisteredUser(std::string nName, std::string nPassword, unsigned int nID);

	void setNext(RegisteredUser* nextParam);
	void setPrev(RegisteredUser* prevParam);

	void LoanBook(book* bookPrev, book* bookFirst, int bookCounter);

	book* getloanedBookPrev() const;

	RegisteredUser* getNext() const;
	RegisteredUser* getPrev() const;

	void printAllBooks();
	void removeBookName(std::string nName);
	void resetbooks();
	void addBook(std::string nAuthor, std::string nTitle, unsigned int nISBN);

private:
	RegisteredUser* next;
	RegisteredUser* prev;

	book* loanedBookFirst;
	book* loanedBookPrev;

	int loanedBookCounter;
};

#endif