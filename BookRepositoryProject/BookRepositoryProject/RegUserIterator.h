#pragma once
#ifndef nRegUserIterator
#define nRegUserIterator

#include <iostream>
#include "RegisteredUser.h"

class RegUserIterator
{
public:
	void registerNewUser(std::string nName, std::string password, unsigned int ID);
	void DeleteRegUser(std::string nName);
	void printRegisteredUsers();

	RegisteredUser* getRegFirst();
	RegisteredUser* getRegPrev();

	int getRegUserCounter();

	void setRegFirst(RegisteredUser* nPtr);
	void setRegPrev(RegisteredUser* nPtr);

	void setRegUserCounter(int num);
	void setGuestUserCounter(int num);

	void reset();

private:
	RegisteredUser* RegFirst;
	RegisteredUser* RegPrev;

	int RegUserCounter;
};

#endif