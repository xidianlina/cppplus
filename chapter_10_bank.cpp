#include <iostream>
#include "chapter_10_bank.h"

BankAccount::BankAccount()
{
	account_name = "";
	account_id = "";
	balance = 0.0;
}

BankAccount::BankAccount(const std::string &name, const std::string &id, double bal)
{
	account_name = name;
	account_id = id;
	balance = bal;
}

void BankAccount::show()const
{
	std::cout << "Name: " << account_name << " Id: " << account_id << " Balance: " << balance << std::endl;
}

void BankAccount::deposit(double cash)
{
	balance += cash;
}

void BankAccount::withdraw(double cash)
{
	if (balance < cash)
		std::cout << "Your balance is not suffient!\n";
	else
		balance -= cash;
}