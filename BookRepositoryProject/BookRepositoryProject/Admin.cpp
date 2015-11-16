#include <iostream>
#include "admin.h"

Admin::Admin(std::string nName, std::string nPassword, unsigned int nID) : user(nName, nPassword, nID)
{
}

void Admin::setNext(Admin* nextParam)
{
	next = nextParam;
}
void  Admin::setPrev(Admin* prevParam)
{
	prev = prevParam;
}

Admin*  Admin::getNext() const
{
	return next;
}
Admin*  Admin::getPrev() const
{
	return prev;
}