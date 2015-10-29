/**#include "book.h";

void book::setAuthor(std::string nAuthor)
{
	author = nAuthor;
}

void book::setTitle(std::string nTitle)
{
	title = nTitle;
}

void book::setISBN(unsigned int nISBN)
{
	ISBN = nISBN;
}

std::string book::getAuthor() const
{
	return author;
}

std::string book::getTitle() const
{
	return title;
}

unsigned int book::getISBN() const
{
	return ISBN;
}

void book::setNext(book* nextParam)
{
	next = nextParam;
}

void book::setPrev(book* prevParam)
{
	prev = prevParam;
}

book* book::getNext() const
{
	return next;
}

book* book::getPrev() const
{
	return prev;
}

void book::setAuthor(std::string nAuthor, std::string nTitle, unsigned int nISBN, book* nextParam, book* prevParam)
{
	author = nAuthor;
	title = nTitle;
	ISBN = nISBN;
	next = nextParam;
	prev = prevParam;
}**/