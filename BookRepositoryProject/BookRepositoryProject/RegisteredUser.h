#pragma once
#ifndef nRegisteredUser
#define nRegisteredUser
#include <iostream>
#include <string>
#include "user.h"
#include "book.h"
#include "BookIterator.h"

class RegisteredUser : public user
{
public:
	RegisteredUser(std::string nName, std::string nPassword, unsigned int nID);

	void setNext(RegisteredUser* nextParam);
	void setPrev(RegisteredUser* prevParam);

	RegisteredUser* getNext() const;
	RegisteredUser* getPrev() const;

	void loanBook(BookIterator* library);
	void returnBook(BookIterator* library);
	void printLoanedBooks();

private:
	RegisteredUser* next;
	RegisteredUser* prev;

	BookIterator* loanedBooks;
};

#endif