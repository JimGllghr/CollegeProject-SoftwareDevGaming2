
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
	Login(UserManager* nManager);

	bool login();
	void logout();

	unsigned int getUserType() const;
	Admin* getAdmin() const;
	GuestUser* getGuest() const;
	RegisteredUser* getReg() const;

private:
	unsigned int userType;
	Admin* admin;
	GuestUser* Guest;
	RegisteredUser* Reg;
	UserManager* manager;
};

#endif