#ifndef nuser
#define nuser
#include <string>
#include <iostream>

class user
{
public:
	user(std::string nName, std::string nPassword, unsigned int nID);
	std::string getName();
	void setName(std::string nName);

	std::string getPassword();
	void setPassword(std::string nName);

	void setID(unsigned int nID);
	unsigned int getID();

private:
	std::string name;
	std::string password;
	unsigned int ID;
};


#endif