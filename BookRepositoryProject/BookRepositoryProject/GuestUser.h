#ifndef nGuestUSer
#define nGuestUSer
#include <string>
#include "User.h"

#include <iostream>

class GuestUser : public user
{
public:
	void setID(unsigned int nID);

	unsigned int getID();

	void setNext(user* nextParam);
	void setPrev(user* prevParam);

	GuestUser* getNext() const;
	GuestUser* getPrev() const;

private:
	unsigned int id;

	GuestUser* next;
	GuestUser* prev;
};
#endif