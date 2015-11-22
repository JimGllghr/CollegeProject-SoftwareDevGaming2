#include "RegisteredUser.h"

RegisteredUser::RegisteredUser(std::string nName, std::string nPassword, unsigned int nID) : user(nName, nPassword, nID)
{
	loanedBookCounter = 0;
}

void RegisteredUser::setNext(RegisteredUser* nextParam)
{
	next = nextParam;
}
void  RegisteredUser::setPrev(RegisteredUser* prevParam)
{
	prev = prevParam;
}

RegisteredUser*  RegisteredUser::getNext() const
{
	return next;
}
RegisteredUser*  RegisteredUser::getPrev() const
{
	return prev;
}

book*  RegisteredUser::getloanedBookPrev() const
{
	return loanedBookPrev;
}

void RegisteredUser::addBook(std::string nAuthor, std::string nTitle, unsigned int nISBN)
{
	book* newBook = new book(nAuthor, nTitle, nISBN, 0);
	if (loanedBookCounter > 0)
	{
		(newBook)->setPrev(loanedBookPrev);
		(loanedBookPrev)->setNext(newBook);
	}
	else
	{
		loanedBookFirst = newBook;
	}
	loanedBookCounter++;
	loanedBookPrev = newBook;
}

void RegisteredUser::removeBookName(std::string nName)
{
	int deletedUsers = 0;
	loanedBookPrev = loanedBookFirst;
	for (int x = 1; x <= loanedBookCounter; x++)
	{
		if (((loanedBookPrev)->getTitle()) == nName)
		{
			if (x == 1)
			{
				loanedBookFirst = (loanedBookFirst)->getNext();
			}
			else
			{
				((loanedBookPrev)->getPrev())->setNext((loanedBookPrev)->getNext());
			}
			if (x < (loanedBookCounter - deletedUsers) && x > 1)
			{
				((loanedBookPrev)->getNext())->setPrev((loanedBookPrev)->getPrev());
			}
			book* tempPtr = loanedBookPrev;
			if (x != 1)
			{
				loanedBookPrev = (loanedBookPrev)->getPrev();
			}
			else
			{
				loanedBookPrev = (loanedBookPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= loanedBookCounter - (deletedUsers + 1))
		{
			loanedBookPrev = (loanedBookPrev)->getNext();
		}
	}
	std::cout << "books Deleted: " << deletedUsers;
	loanedBookCounter -= deletedUsers;
}

void RegisteredUser::printAllBooks()
{
	loanedBookPrev = loanedBookFirst;
	std::cout << "Books\n";
	for (int x = 1; x <= loanedBookCounter; x++)
	{
		std::cout << loanedBookPrev;
		if (x < loanedBookCounter)
		{
			loanedBookPrev = (loanedBookPrev)->getNext();
		}
	}
}

void RegisteredUser::resetbooks()
{
	loanedBookPrev = loanedBookFirst;
	for (int x = 1; x <= loanedBookCounter; x++)
	{
		if (x < loanedBookCounter)
		{
			loanedBookPrev = (loanedBookPrev)->getNext();
		}
	}
}

void RegisteredUser::LoanBook(UserManager* manager)
{
	int deletedUsers = 0;

	std::cin.clear(); // clears the error flags
					  // this line discards all the input waiting in the stream
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "\nplease enter name of The book you want to loan: ";
	std::string name;
	std::cin >> name;
	for (int x = 1; x <= ((manager)->getbookCounter()); x++)
	{
		if ((((manager)->getbookPrev())->getTitle()) == name && ((manager)->getbookPrev())->getQuantity()>0)
		{
			book* newBook = new book(((manager)->getbookPrev())->getAuthor(), ((manager)->getbookPrev())->getTitle(), ((manager)->getbookPrev())->getISBN(), 0);
			if (loanedBookCounter > 0)
			{
				(newBook)->setPrev(loanedBookPrev);
				(loanedBookPrev)->setNext(newBook);
			}
			else
			{
				loanedBookFirst = newBook;
			}
			loanedBookCounter++;
			loanedBookPrev = newBook;
			
			((manager)->getbookPrev())->setQuantity((((manager)->getbookPrev())->getQuantity()) - 1);
			std::cout << "Book "<<((manager)->getbookPrev())->getTitle() <<" has been taken out on loan.\n";
		}
		if (x <= ((manager)->getbookCounter()) - (deletedUsers + 1))
		{
			(manager)->setbookPrev(((manager)->getbookPrev())->getNext());
		}
	}
	if (deletedUsers == 0)
	{
		std::cout << "Book not available";
	}
	((manager)->setbookCounter((manager)->getbookCounter() - deletedUsers));
}