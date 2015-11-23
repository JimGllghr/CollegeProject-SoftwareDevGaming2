#include "RegisteredUser.h"

RegisteredUser::RegisteredUser(std::string nName, std::string nPassword, unsigned int nID) : user(nName, nPassword, nID)
{
	loanedBooks = new BookIterator();
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

void RegisteredUser::loanBook(BookIterator* library)
{
	(library)->setbookPrev((library)->getbookFirst());
	(loanedBooks)->reset();
	std::cout << "please enter title of book to take on loan: ";
	std::string name;
	std::cin >> name;
	for (int x = 1; x <= (library)->getbookCounter(); x++)
	{
		if ((((library)->getbookPrev())->getTitle()) == name)
		{
			if ((((library)->getbookPrev())->getQuantity()) > 0)
			{
				(loanedBooks)->addBook(((library)->getbookPrev())->getAuthor(), ((library)->getbookPrev())->getTitle(), ((library)->getbookPrev())->getISBN(), 1);
				((library)->getbookPrev())->setQuantity(((library)->getbookPrev()->getQuantity())-1);
				std::cout << "Book Taken on Loan";
				return;
			}
		}
		if (x <= (library)->getbookCounter())
		{
			(library)->setbookPrev(((library)->getbookPrev())->getNext());
		}
	}
	std::cout << "Book Not found\n";
}

void RegisteredUser::returnBook(BookIterator* library)
{
	(library)->setbookPrev((library)->getbookFirst());
	(loanedBooks)->setbookPrev((loanedBooks)->getbookFirst());
	std::cout << "please enter title of book to Return: ";
	std::string name;
	std::cin >> name;
	for (int x = 1; x <= (loanedBooks)->getbookCounter(); x++)
	{
		if ((((loanedBooks)->getbookPrev())->getTitle()) == name)
		{
			for (int x = 1; x <= (library)->getbookCounter(); x++)
			{
				if ((((library)->getbookPrev())->getTitle()) == name)
				{
					((library)->getbookPrev())->setQuantity(((library)->getbookPrev()->getQuantity()) + 1);
				}
				if (x <= (library)->getbookCounter())
				{
					(library)->setbookPrev(((library)->getbookPrev())->getNext());
				}
			}
			(loanedBooks)->removeBookName(name);
			std::cout << "\n Book Returned\n";
			return;
		}
		if (x <= (loanedBooks)->getbookCounter())
		{
			(loanedBooks)->setbookPrev(((loanedBooks)->getbookPrev())->getNext());
		}
	}

	std::cout << "no books Returned\n";
}

void RegisteredUser::printLoanedBooks()
{
	(loanedBooks)->printAllBooks();
}
