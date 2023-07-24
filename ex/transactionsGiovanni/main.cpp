/*
 * main.cpp
 *
 *  Created on: 24 lug 2023
 *      Author: WotkStation05
 */

#include <iostream>
#include <cstdint>

#include "Bank.h"

int main ( void )
{
	int32_t transactionSuccessful { 0 };

	bank::Bank bank{};

	auto accountFabrizio = bank.createAccount( "Fabrizio", 512.22  );
	auto accountGiovanni = bank.createAccount( "Giovanni", 1512.22 );
	auto accountMatteo   = bank.createAccount( "Matteo"  , 548.34  );

	bank.printAllAccountsDetails();
	std::cout << "\n";
	bank.printAllTransactionsDetails();

	std::cout << "\n\n";
	transactionSuccessful = bank.createTransaction( accountFabrizio, accountGiovanni, 100.0 );
	if ( transactionSuccessful != 0 )
	{
		std::cout << "Transaction FAILED\n";
	}
	transactionSuccessful = bank.createTransaction( accountMatteo, accountGiovanni, 400.0 );
	if ( transactionSuccessful != 0 )
	{
		std::cout << "Transaction FAILED\n";
	}

	bank.printAllAccountsDetails();
	std::cout << "\n";
	bank.printAllTransactionsDetails();

	std::cout << "\n\n";


	bank.dropAccount( accountFabrizio );

	bank.printAllAccountsDetails();
	std::cout << "\n";
	bank.printAllTransactionsDetails();

	std::cout << "\n\n";

	return 0;
}
