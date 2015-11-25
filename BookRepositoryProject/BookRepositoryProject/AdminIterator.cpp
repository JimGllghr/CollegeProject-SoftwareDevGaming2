#include "AdminIterator.h"

void AdminIterator::registerNewAdmin(std::string nName, std::string password, unsigned int ID)
{
	reset();
	Admin* registeredNewAdmin = new Admin(nName, password, ID);
	if (adminCounter > 0)
	{
		(registeredNewAdmin)->setPrev(adminPrev);
		(adminPrev)->setNext(registeredNewAdmin);
	}
	else
	{
		adminFirst = registeredNewAdmin;
	}
	adminCounter++;
	adminPrev = registeredNewAdmin;
}

std::ostream& operator<<(std::ostream& out, Admin* user)
{
	std::cout << "\nName: " << (user)->getName() << " ID: " << (user)->getID() << std::endl;
	return out;
}

void AdminIterator::DeleteAdmin(std::string nName)
{
	int deletedUsers = 0;
	adminPrev = adminFirst;
	for (int x = 1; x < adminCounter; x++)
	{
		if (((adminPrev)->getName()) == nName)
		{
			if (x == 1)
			{
				adminFirst = (adminFirst)->getNext();
			}
			else
			{
				((adminPrev)->getPrev())->setNext((adminPrev)->getNext());
			}
			if (x < (adminCounter - deletedUsers) && x > 1)
			{
				((adminPrev)->getNext())->setPrev((adminPrev)->getPrev());
			}
			Admin* tempPtr = adminPrev;
			if (x != 1)
			{
				adminPrev = (adminPrev)->getPrev();
			}
			else
			{
				adminPrev = (adminPrev)->getNext();;
			}
			delete tempPtr;
			deletedUsers += 1;
		}
		if (x <= adminCounter - (deletedUsers + 1))
		{
			adminPrev = (adminPrev)->getNext();
		}
	}
	std::cout << "\nAdmins Deleted: " << deletedUsers << std::endl;
	adminCounter -= deletedUsers;
}

void AdminIterator::printAdmins()
{
	adminPrev = adminFirst;
	std::cout << "Admins\n";
	for (int x = 1; x <= adminCounter; x++)
	{
		std::cout << adminPrev;
		if (x <= adminCounter)
		{
			adminPrev = (adminPrev)->getNext();
		}
	}
}

Admin* AdminIterator::getadminFirst()
{
	return adminFirst;
}
Admin* AdminIterator::getadminPrev()
{
	return adminPrev;
}
int AdminIterator::getadminCounter()
{
	return adminCounter;
}
void AdminIterator::setadminFirst(Admin* nPtr)
{
	adminFirst = nPtr;
}
void AdminIterator::setadminPrev(Admin* nPtr)
{
	adminPrev = nPtr;
}
void AdminIterator::setadminCounter(int num)
{
	adminCounter = num;
}


void AdminIterator::reset()
{
	adminPrev = adminFirst;
	for (int x = 1; x <= adminCounter; x++)
	{
		if (x < adminCounter)
		{
			adminPrev = (adminPrev)->getNext();
		}
	}
}