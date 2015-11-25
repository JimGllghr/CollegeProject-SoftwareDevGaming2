#include "bookIterator.h"

std::ostream& operator<<(std::ostream& out, book* Book)
{
	std::cout << "\nTitle: " << (Book)->getTitle() << " Author: " << (Book)->getAuthor() << " ISBN: " << (Book)->getISBN() << std::endl;
	return out;
}

void BookIterator::addBook(std::string nAuthor, std::string nTitle, unsigned int nISBN, unsigned int nQuantity)
{
	reset();
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

void BookIterator::removeBookName(std::string nName)
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

void BookIterator::printAllBooks()
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

void BookIterator::printAvailableBooks()
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


book* BookIterator::getbookFirst()
{
	return bookFirst;
}
book* BookIterator::getbookPrev()
{
	return bookPrev;
}


void BookIterator::setbookFirst(book* nPtr)
{
	bookFirst = nPtr;
}
void BookIterator::setbookPrev(book* nPtr)
{
	bookPrev = nPtr;
}

void BookIterator::setbookCounter(int num)
{
	bookCounter = num;
}

int BookIterator::getbookCounter()
{
	return bookCounter;
}

void BookIterator::reset()
{
	bookPrev = bookFirst;
	for (int x = 1; x <= bookCounter; x++)
	{
		if (x < bookCounter)
		{
			bookPrev = (bookPrev)->getNext();
		}
	}
}

void BookIterator::searchForBook()
{
	bookPrev = bookFirst;
	std::cout << "Please Enter Name or Author: ";
	std::string name;
	std::getline(std::cin, name);
	std::getline(std::cin, name);

	for (int x = 1; x <= bookCounter; x++)
	{
		if ((bookPrev)->getTitle() == name)
		{
			std::cout << bookPrev;
			if (x < bookCounter)
			{
				bookPrev = (bookPrev)->getNext();
			}
		}
		if ((bookPrev)->getAuthor() == name)
		{
			std::cout << bookPrev;
			if (x < bookCounter)
			{
				bookPrev = (bookPrev)->getNext();
			}
		}
	}
}

void BookIterator::searchForBookISBN()
{
	bookPrev = bookFirst;
	std::cout << "Please Enter ISBN: ";
	int isbn;
	std::cin >> isbn;
	for (int x = 1; x <= bookCounter; x++)
	{
		if (((bookPrev)->getISBN() == isbn))
		{
			std::cout << bookPrev;
			if (x < bookCounter)
			{
				bookPrev = (bookPrev)->getNext();
			}
		}
	}
}