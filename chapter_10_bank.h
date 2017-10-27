#ifndef BANK_H_
#define BANK_H_

#include <string>

class BankAccount
{
private:
	std::string account_name;
	std::string account_id;
	double balance;
public:
	BankAccount();
	BankAccount(const std::string &client, const std::string &id, double bal = 0.0);
	void show()const;
	void deposit(double cash);
	void withdraw(double cash);
};

#endif