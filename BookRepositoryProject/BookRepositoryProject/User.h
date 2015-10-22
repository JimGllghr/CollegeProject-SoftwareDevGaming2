#ifndef nGuestUser
#define nGuestUser
#include <string>

#include <iostream>

class GuestUser
{
public:
	void setID(unsigned int nID);

	unsigned int getID();

	void setNext(GuestUser* nextParam);
	void setPrev(GuestUser* prevParam);

	GuestUser* getNext() const;
	GuestUser* getPrev() const;

private:
	unsigned int id;

	GuestUser* next;
	GuestUser* prev;
};

#endif