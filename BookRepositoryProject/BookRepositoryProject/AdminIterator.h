#pragma once
#ifndef nAdminIterator
#define nAdminIterator

#include <iostream>
#include "Admin.h"

class AdminIterator
{
public:
	void registerNewAdmin(std::string nName, std::string password, unsigned int ID);
	void DeleteAdmin(std::string nName);
	void printAdmins();

	Admin* getadminFirst();
	Admin* getadminPrev();

	int getadminCounter();

	void setadminFirst(Admin* nPtr);
	void setadminPrev(Admin* nPtr);

	void setadminCounter(int num);

	void reset();

private:
	Admin* adminFirst;
	Admin* adminPrev;

	int adminCounter;
};

#endif