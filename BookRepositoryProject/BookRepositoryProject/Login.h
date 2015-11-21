
#pragma once
#ifndef nLogin
#define nLogin
#include <string>
#include <iostream>
#include "GuestUser.h"
#include "RegisteredUser.h"
#include "Admin.h"

class Login
{
public:
	bool login();

	unsigned int getUserType() const;
	void setUserType(unsigned int nType);

	void logout();

	Admin* getAdmin() const;
	GuestUser* getGuest() const;
	RegisteredUser* getReg() const;

	Admin* adminFirst;
	Admin* adminPrev;
	GuestUser* GuestNext;
	GuestUser* GuestPrev;
	RegisteredUser* RegFirst;
	RegisteredUser* RegPrev;
	book* bookFirst;
	book* bookPrev;

	int RegUserCounter;
	int GuestUserCounter;
	int adminCounter;
	int bookCounter;

	void Login::reset();
private:
	unsigned int userType;
	Admin* admin;
	GuestUser* Guest;
	RegisteredUser* Reg;
};

#endif