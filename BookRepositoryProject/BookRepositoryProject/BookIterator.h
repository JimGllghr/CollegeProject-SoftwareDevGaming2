#pragma once
#ifndef nBookIterator
#define nBookIterator

#include <iostream>
#include "book.h"

class BookIterator
{
public:
	void addBook(std::string nAuthor, std::string nTitle, unsigned int nISBN, unsigned int nQuantity);
	void removeBookName(std::string nName);
	void printAllBooks();
	void printAvailableBooks();

	book* getbookFirst();
	book* getbookPrev();

	int getbookCounter();

	void setbookFirst(book* nPtr);
	void setbookPrev(book* nPtr);

	void setbookCounter(int num);
	void searchForBook();
	void searchForBookISBN();

	void reset();

private:
	book* bookFirst;
	book* bookPrev;

	int bookCounter;
};

#endif