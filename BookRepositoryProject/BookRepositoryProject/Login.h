
#pragma once
#ifndef nLogin
#define nLogin
#include "GuestUser.h"
#include "RegisteredUser.h"
#include "Admin.h"
#include "book.h"
#include "AdminIterator.h"
#include "GuestIterator.h"
#include "BookIterator.h"
#include "RegUserIterator.h"

class Login
{
public:
	Login(AdminIterator* aAdminIterator, GuestIterator* aGuestIterator, RegUserIterator* aRegUserIterator, BookIterator* aBookIterator);

	bool login();
	void logout();

	unsigned int getUserType() const;

	RegisteredUser* getReg();
private:
	unsigned int userType;

	AdminIterator* adminIterator;
	GuestIterator* guestIterator;
	RegUserIterator* regUserIterator;
	BookIterator* bookIterator;

	RegisteredUser* Reg;
};

#endif