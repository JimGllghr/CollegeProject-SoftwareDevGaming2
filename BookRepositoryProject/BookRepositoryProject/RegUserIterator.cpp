#include "RegUserIterator.h"

void RegUserIterator::setRegUserCounter(int num)
{
	RegUserCounter = num;
}
void RegUserIterator::setRegFirst(RegisteredUser* nPtr)
{
	RegFirst = nPtr;
}
void RegUserIterator::setRegPrev(RegisteredUser* nPtr)
{
	RegPrev = nPtr;
}
int RegUserIterator::getRegUserCounter()
{
	return RegUserCounter;
}
RegisteredUser* RegUserIterator::getRegFirst()
{
	return RegFirst;
}
RegisteredUser* RegUserIterator::getRegPrev()
{
	return RegPrev;
}

void RegUserIterator::registerNewUser(std::string nName, std::string password, unsigned int ID)
{
	reset();
	RegisteredUser* registeredNewUser = new RegisteredUser(nName, password, ID);
	if (RegUserCounter > 0)
	{
		(registeredNewUser)->setPrev(RegPrev);
		(RegPrev)->setNext(registeredNewUser);
	}
	else
	{
		RegFirst = registeredNewUser;
	}
	RegUserCounter++;
	RegPrev = registeredNewUser;
}

void RegUserIterator::DeleteRegUser(std::string nName)
{
	int deletedUsers = 0;
	RegPrev = RegFirst;
	for (int x = 1; x <= RegUserCounter; x++)
	{
		if (((RegPrev)->getName()) == nName)
		{
			if (x == 1)
			{
				RegFirst = (RegFirst)->getNext();
			}
			else
			{
				((RegPrev)->getPrev())->setNext((RegPrev)->getNext());
			}
			if (x < (RegUserCounter - deletedUsers) && x > 1)
			{
				((RegPrev)->getNext())->setPrev((RegPrev)->getPrev());
			}
			RegisteredUser* tempPtr = RegPrev;
			if (x != 1)
			{
				RegPrev = (RegPrev)->getPrev();
			}
			else
			{
				RegPrev = (RegPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= RegUserCounter - (deletedUsers + 1))
		{
			RegPrev = (RegPrev)->getNext();
		}
	}
	std::cout << "Registered Users Deleted: " << deletedUsers;
	RegUserCounter -= deletedUsers;
}

void RegUserIterator::printRegisteredUsers()
{
	RegPrev = RegFirst;
	std::cout << "Registered Users\n";
	for (int x = 1; x <= RegUserCounter; x++)
	{
		std::cout << RegPrev;
		if (x < RegUserCounter)
		{
			RegPrev = (RegPrev)->getNext();
		}
	}
}
std::ostream& operator<<(std::ostream& out, RegisteredUser* user)
{
	std::cout << "\nName: " << (user)->getName() << " ID: " << (user)->getID() << std::endl;
	return out;
}

void RegUserIterator::reset()
{
	RegPrev = RegFirst;
	for (int x = 1; x <= RegUserCounter; x++)
	{
		if (x < RegUserCounter)
		{
			RegPrev = (RegPrev)->getNext();
		}
	}
}