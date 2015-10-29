#ifndef nAdmin
#define nAdmin
#include <string>
#include "User.h"

#include <iostream>

class Admin : public user
{
public:
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