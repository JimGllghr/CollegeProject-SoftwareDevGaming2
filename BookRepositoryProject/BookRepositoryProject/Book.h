/**#ifndef nbook
#define nbook
#include <string>
#include <iostream>

class book
{
public:
	std::string getAuthor() const;
	std::string getTitle() const;
	unsigned int getISBN() const;

	void setBook(std::string nAuthor, std::string nTitle, unsigned int nISBN, book* nextParam, book* prevParam);

	void setAuthor(std::string nAuthor);
	void setTitle(std::string ntitle);
	void setISBN(unsigned int nISBN);

	void setNext(book* nextParam);
	void setPrev(book* prevParam);

	book* getNext() const;
	book* getPrev() const;

private:
	std::string author;
	std::string title;
	unsigned int ISBN;

	book* next;
	book* prev;
};

#endif**/