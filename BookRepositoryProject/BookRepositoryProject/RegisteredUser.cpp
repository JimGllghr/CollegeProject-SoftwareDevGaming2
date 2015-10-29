#include <iostream>
#include "RegisteredUser.h"

RegisteredUser::RegisteredUser(std::string nName, std::string nPassword, unsigned int nID) : user(nName, nPassword, nID)
{
}

void RegisteredUser::setNext(RegisteredUser* nextParam)
{
	next = nextParam;
}
void  RegisteredUser::setPrev(RegisteredUser* prevParam)
{
	prev = prevParam;
}

RegisteredUser*  RegisteredUser::getNext() const
{
	return next;
}
RegisteredUser*  RegisteredUser::getPrev() const
{
	return prev;
}