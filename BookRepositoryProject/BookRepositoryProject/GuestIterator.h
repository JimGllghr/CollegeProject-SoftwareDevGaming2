#pragma once
#ifndef nGuestIterator
#define nGuestIterator

#include <iostream>
#include "GuestUser.h"

class GuestIterator
{
public:
	void registerNewGuest(std::string nName, std::string password, unsigned int ID);
	void DeletGuest(std::string nName);
	void printGuests();
	GuestUser* getGuestNext();
	GuestUser* getGuestPrev();

	int getGuestUserCounter();

	void setGuestNext(GuestUser* nPtr);
	void setGuestPrev(GuestUser* nPtr);

	void setGuestUserCounter(int num);

	void reset();

private:
	GuestUser* GuestNext;
	GuestUser* GuestPrev;

	int GuestUserCounter;
};

#endif