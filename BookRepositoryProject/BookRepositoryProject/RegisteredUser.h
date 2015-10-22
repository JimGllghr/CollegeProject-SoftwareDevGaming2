#ifndef nRegisteredUser
#define nRegisteredUser
#include <string>

#include <iostream>

class RegisteredUser
{
public:
	void setName(std::string nName);

	std::string getName();

private:
	std::string name;
};

#endif