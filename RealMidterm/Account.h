#pragma once

// Account.h

#include <iostream>
using namespace std;

class Account {

public:
	Account();

	// Big Five
	explicit Account(const Account& account);		// Copy Constructor
	explicit Account(Account&& account);			// Move Constructor
	const Account& operator= (const Account& account);	// Copy Assignment Operator
	const Account& operator= (Account&& account);		// Move Assignment Operator
	~Account();						// Destructor

	// Functions

private:
	int* balance{ nullptr };
	string* record{ nullptr };
};





