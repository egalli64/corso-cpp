/*
 * Transaction.cpp
 *
 *  Created on: 24 lug 2023
 *      Author: WotkStation05
 */

#include "Transaction.h"

#include "Account.h"

#include <iostream>
#include <iomanip>

namespace transaction
{

std::atomic < uint32_t > Transaction::serialIdGenerator{0U};

Transaction::Transaction(
		std::shared_ptr<account::Account> sender,
		std::shared_ptr<account::Account> receiver,
		const double amount ) :
	_id{0U}, _senderAccount{sender}, _receiverAccount{receiver}, _amount{amount}
{
	_id = Transaction::serialIdGenerator.fetch_add(1U);

	const double senderBalance   = sender->getBalance( );
	const double receiverBalance = receiver->getBalance( );

	sender->setBalance( senderBalance - amount );
	receiver->setBalance( receiverBalance + amount );
}

Transaction::~Transaction ( void )
{
}

const std::weak_ptr < account::Account >& Transaction::getSenderAccount ( void ) const
{
	return _senderAccount;
}
const std::weak_ptr < account::Account >& Transaction::getReceiverAccount ( void ) const
{
	return _receiverAccount;
}

const uint32_t Transaction::getId ( void ) const
{
	return _id;
}
const double Transaction::getAmount ( void ) const
{
	return _amount;
}

void Transaction::printDetails ( void ) const
{
	auto accountName = [] ( const std::weak_ptr<account::Account>& acc )
	{
		std::string name{"Expired"};
		if ( !acc.expired( ) )
		{
			std::shared_ptr < account::Account > spAccount{acc.lock()};
			name = "ID(" + std::to_string(spAccount->getId()) + ") " + spAccount->getName( );
		}
		return name;
	};

	const std::string senderName   = accountName(_senderAccount  );
	const std::string receiverName = accountName(_receiverAccount);

	std::cout << std::left << "Transaction nr. " << std::setw(6) << _id  << ". "
			  << "From: " << std::setw(15) << senderName   << " "
			  << "To: "   << std::setw(15) << receiverName << " "
			  << "of "    << std::right << std::setw(6) << _amount      << " €\n";
}

} /* namespace transaction */
