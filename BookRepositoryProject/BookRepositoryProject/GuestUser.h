#ifndef nGuestUSer
#define nGuestUSer
#include <string>
#include "User.h"

#include <iostream>

class GuestUser : public user
{
public:
	void setID(unsigned int nID);

	GuestUser(std::string nName, std::string nPassword, unsigned int nID);

	void setNext(GuestUser* nextParam);
	void setPrev(GuestUser* prevParam);

	GuestUser* getNext() const;
	GuestUser* getPrev() const;

private:
	GuestUser* next;
	GuestUser* prev;
};
#endif