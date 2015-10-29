#include <iostream>
#include "User.h"

user::user(std::string nName, std::string nPassword, unsigned int nID)
{
	name = nName;
	password = nPassword;
	ID = nID;
}

std::string user::getName()
{
	return name;
}

void user::setID(unsigned int nID)
{
	ID = nID;
}

unsigned int user::getID()
{
	return ID;
}
