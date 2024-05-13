/*
 * Transaction.h
 *
 *  Created on: 24 lug 2023
 *      Author: WotkStation05
 */

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <memory>
#include <cstdint>
#include <atomic>

namespace account
{
class Account;
}

namespace transaction
{

class Transaction
{
public:
	explicit Transaction (
			std::shared_ptr<account::Account> sender,
			std::shared_ptr<account::Account> receiver,
			const double amount
	);

	virtual ~Transaction ( void );

	const std::weak_ptr < account::Account >& getSenderAccount ( void ) const;
	const std::weak_ptr < account::Account >& getReceiverAccount ( void ) const;

	const uint32_t getId ( void ) const;
	const double getAmount ( void ) const;

	void printDetails ( void ) const;

private:
	Transaction ( void ) = delete;
	Transaction ( const Transaction & t ) = delete;
	Transaction& operator=( const Transaction & t ) = delete;

	uint32_t _id;
	std::weak_ptr< account::Account > _senderAccount;
	std::weak_ptr< account::Account > _receiverAccount;
	double _amount;

	static std::atomic < uint32_t > serialIdGenerator;
};

} /* namespace transaction */

#endif /* TRANSACTION_H_ */
