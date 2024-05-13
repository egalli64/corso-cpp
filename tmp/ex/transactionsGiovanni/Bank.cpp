/*
 * Bank.cpp
 *
 *  Created on: 24 lug 2023
 *      Author: WotkStation05
 */

#include "Bank.h"
#include "Account.h"
#include "Transaction.h"

#include <algorithm>
#include <iostream>

namespace bank
{

Bank::Bank( void )
{
}

Bank::~Bank( void )
{
}

std::weak_ptr<account::Account> Bank::createAccount ( const std::string name, const double initialBalance )
{
	std::shared_ptr<account::Account> account = std::make_shared<account::Account> ( name, initialBalance );
	_accounts[ account->getId( ) ] = account;

	return account;
}

void Bank::dropAccount ( std::weak_ptr<account::Account> account )
{
	if ( !account.expired( ) )
	{
		std::shared_ptr<account::Account> spAccount{account};

		if ( _accounts.count( spAccount->getId() ) == 1 )
		{
			_accounts.erase( spAccount->getId() );
		}
	}
}

int32_t Bank::createTransaction( std::weak_ptr<account::Account> sender, std::weak_ptr<account::Account> receiver, const double amount )
{
	int32_t returnCode = -1;

	if ( !sender.expired( ) && !receiver.expired( ) )
	{
		std::shared_ptr<account::Account> senderSp{ sender.lock() };
		std::shared_ptr<account::Account> receiverSp{ receiver.lock() };

		std::unique_ptr<transaction::Transaction> transaction = std::make_unique<transaction::Transaction> ( senderSp, receiverSp, amount );

		_transactions [ transaction->getId() ].swap(transaction);

		returnCode = 0;
	}

	return returnCode;
}

void Bank::printAccountDetails( const uint32_t accountId ) const
{
	std::cout << "==> ID: " << accountId << "  ";

	if ( _accounts.count( accountId ) == 1 )
	{
		_accounts.at(accountId)->printDetails();
	}
	else
	{
		std::cout << "==> NOT FOUND\n";
	}
}

void Bank::printTransactionDetails ( const uint32_t transactionId ) const
{
	std::cout << "==> ID: " << transactionId << "  ";

	if ( _transactions.count( transactionId ) == 1 )
	{
		_transactions.at(transactionId)->printDetails();
	}
	else
	{
		std::cout << "==> NOT FOUND\n";
	}
}

void Bank::printAllAccountsDetails ( void ) const
{
	std::cout << "==== ACCOUNTS ====" << "\n";
	std::for_each( _accounts.cbegin( ), _accounts.cend( ), [this]( const auto &account ) {
		this->printAccountDetails( account.first );
	});
	std::cout << "==== END ACCOUNTS ====" << "\n";
}

void Bank::printAllTransactionsDetails ( void ) const
{
	std::cout << "==== TRANSACTIONS ====" << "\n";

	std::for_each( _transactions.cbegin( ), _transactions.cend( ), [this]( const auto &transaction ) {
		this->printTransactionDetails( transaction.first );
	});

	std::cout << "==== END TRANSACTIONS ====" << "\n";

}

} /* namespace bank */
