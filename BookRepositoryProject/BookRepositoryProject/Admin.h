#ifndef nAdmin
#define nAdmin
#include <string>

#include <iostream>

class Admin
{
public:
	void setName(std::string nName);

	std::string getName();

private:
	std::string name;
};

#endif