#include <iostream>
#include "GuestUser.h"

GuestUser::GuestUser(std::string nName, std::string nPassword, unsigned int nID) : user(nName, nPassword, nID)
{
}

void GuestUser::setNext(GuestUser* nextParam)
{
	next = nextParam;
}
void  GuestUser::setPrev(GuestUser* prevParam)
{
	prev = prevParam;
}

GuestUser*  GuestUser::getNext() const
{
	return next;
}
GuestUser*  GuestUser::getPrev() const
{
	return prev;
}