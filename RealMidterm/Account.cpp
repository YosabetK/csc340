// Account.cpp
#include "TIC_B_Account.h"
#include <string>

// Constructors
Account::Account() {
	this->balance = new int{ 340 };
	this->record = new string{ "cs" };
}

// The BIG FIVE -------------------------------------------
// Copy Constructor
Account::Account(const Account& account)
{
	this->balance = new int{ *account.getBalance() };
	this->record = new string{ *account.getRecord() };
}

// Move Constructor
Account::Account(Account&& account) {

	// New
	this->balance = new int{ *account.getBalance() };
	this->record = new string{ *account.getRecord() };

	/* OR New
	this->balance = new int{};
	this->record = new string{};
	swap(*this->balance, *account.getBalance());
	swap(*this->record, *account.getRecord());
	*/
}

// Copy Assignment Operator
const Account& Account::operator= (const Account& account) {
	if (this != &account) {

		// Reuse
		*this->balance = *account.getBalance();
		*this->record = *account.getRecord();

		/* OR New
		if (this->balance != nullptr) {
			delete this->balance;
		}
		this->balance = new int{ *account.getBalance() };

		if (this->record != nullptr) {
			delete this->record;
		}
		this->record = new string{ *account.getRecord() };
		*/
	}
	return *this;
}

// Move Assignment Operator
const Account& Account::operator= (Account&& account) {
	if (this != &account) {

		// Reuse
		swap(*this->balance, *account.getBalance());
		swap(*this->record, *account.getRecord());

		/* OR Reuse
		*this->balance = *account.getBalance();
		*this->record = *account.getRecord();
		*/

		/* OR New
		if (this->balance != nullptr) {
			delete this->balance;
		}
		this->balance = new int{ *account.getBalance() };

		if (this->record != nullptr) {
			delete this->record;
		}
		this->record = new string{ *account.getRecord() };
		*/
	}
	return *this;
}

// Destructor
Account::~Account() {
	if (this->balance != nullptr) {
		delete this->balance;
		this->balance = nullptr;
	}

	if (this->record != nullptr) {
		delete this->record;
		this->record = nullptr;
	}
}

// FUNCTIONS -------------------------------------------
