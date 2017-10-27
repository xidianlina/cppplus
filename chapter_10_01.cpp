#include <iostream>
#include "chapter_10_bank.h"

int main()
{
	BankAccount bank = BankAccount("Lina", "12103409", 10000.00);
	bank.show();
	bank.withdraw(5000.00);
	bank.show();
	bank.deposit(3000.00);
	bank.show();
	bank.withdraw(20000.00);
	bank.show();

	return 0;
}