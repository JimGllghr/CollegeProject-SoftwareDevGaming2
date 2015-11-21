#pragma once
#ifndef nbook
#define nbook
#include <string>
#include <iostream>

class book
{
public:
	book(std::string nAuthor, std::string nTitle, unsigned int nISBN, unsigned int nQuantity);

	std::string getAuthor() const;
	std::string getTitle() const;
	unsigned int getISBN() const;

	
	void setAuthor(std::string nAuthor);
	void setTitle(std::string ntitle);
	void setISBN(unsigned int nISBN);

	void setQuantity(unsigned int num);
	unsigned int getQuantity() const;

	void setNext(book* nextParam);
	void setPrev(book* prevParam);

	book* getNext() const;
	book* getPrev() const;

private:
	std::string author;
	std::string title;
	unsigned int ISBN;
	unsigned int quantity;

	book* next;
	book* prev;

};

#endif