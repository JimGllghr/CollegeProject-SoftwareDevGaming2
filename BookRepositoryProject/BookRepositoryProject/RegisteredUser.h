#ifndef nRegisteredUser
#define nRegisteredUser
#include <string>
#include "User.h"

#include <iostream>

class RegisteredUser : public user
{
public:
	RegisteredUser(std::string nName, std::string nPassword, unsigned int nID);

	void setNext(RegisteredUser* nextParam);
	void setPrev(RegisteredUser* prevParam);

	RegisteredUser* getNext() const;
	RegisteredUser* getPrev() const;

private:
	unsigned int id;

	RegisteredUser* next;
	RegisteredUser* prev;
};

#endif