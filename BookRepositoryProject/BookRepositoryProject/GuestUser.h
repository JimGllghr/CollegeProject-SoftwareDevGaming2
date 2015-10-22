#ifndef nGuestUSer
#define nGuestUSer
#include <string>

#include <iostream>

class GuestUSer
{
public:
	void setName(std::string nName);

	std::string getName();

private:
	std::string name;
};

#endif