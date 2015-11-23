#include "GuestIterator.h"
std::ostream& operator<<(std::ostream& out, GuestUser* user)
{
	std::cout << "\nName: " << (user)->getName() << " ID: " << (user)->getID() << std::endl;
	return out;
}
void GuestIterator::registerNewGuest(std::string nName, std::string password, unsigned int ID)
{
	reset();
	GuestUser* registeredNewGuest = new GuestUser(nName, password, ID);
	if (GuestUserCounter > 0)
	{
		(registeredNewGuest)->setPrev(GuestPrev);
		(GuestPrev)->setNext(registeredNewGuest);
	}
	else
	{
		GuestNext = registeredNewGuest;
	}
	GuestUserCounter++;
	GuestPrev = registeredNewGuest;
}

void GuestIterator::DeletGuest(std::string nName)
{
	int deletedUsers = 0;
	GuestPrev = GuestNext;
	for (int x = 1; x < GuestUserCounter; x++)
	{
		if (((GuestPrev)->getName()) == nName)
		{
			if (x == 1)
			{
				GuestNext = (GuestNext)->getNext();
			}
			else
			{
				((GuestPrev)->getPrev())->setNext((GuestPrev)->getNext());
			}
			if (x < (GuestUserCounter - deletedUsers) && x > 1)
			{
				((GuestPrev)->getNext())->setPrev((GuestPrev)->getPrev());
			}
			GuestUser* tempPtr = GuestPrev;
			if (x != 1)
			{
				GuestPrev = (GuestPrev)->getPrev();
			}
			else
			{
				GuestPrev = (GuestPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= GuestUserCounter - (deletedUsers + 1))
		{
			GuestPrev = (GuestPrev)->getNext();
		}
	}
	std::cout << "\nGuests Deleted: " << deletedUsers << std::endl;
	GuestUserCounter -= deletedUsers;
}

void GuestIterator::printGuests()
{
	GuestPrev = GuestNext;
	std::cout << "\nGuest Users\n";
	for (int x = 1; x <= GuestUserCounter; x++)
	{
		std::cout << GuestPrev;
		if (x <= GuestUserCounter)
		{
			GuestPrev = (GuestPrev)->getNext();
		}
	}
}
GuestUser* GuestIterator::getGuestNext()
{
	return GuestNext;
}
GuestUser* GuestIterator::getGuestPrev()
{
	return GuestPrev;
}
int GuestIterator::getGuestUserCounter()
{
	return GuestUserCounter;
}

void GuestIterator::setGuestNext(GuestUser* nPtr)
{
	GuestNext = nPtr;
}
void GuestIterator::setGuestPrev(GuestUser* nPtr)
{
	GuestPrev = nPtr;
}
void GuestIterator::setGuestUserCounter(int num)
{
	GuestUserCounter = num;
}

void GuestIterator::reset()
{
	GuestPrev = GuestNext;
	for (int x = 1; x <= GuestUserCounter; x++)
	{
		if (x < GuestUserCounter)
		{
			GuestPrev = (GuestPrev)->getNext();
		}
	}
}