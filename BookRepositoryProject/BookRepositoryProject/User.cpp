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

void user::setName(std::string nName)
{
	name = nName;
}

void user::setID(unsigned int nID)
{
	ID = nID;
}

unsigned int user::getID()
{
	return ID;
}

std::string user::getPassword()
{
	return password;
}

void user::setPassword(std::string nPassword)
{
	password = nPassword;
}


