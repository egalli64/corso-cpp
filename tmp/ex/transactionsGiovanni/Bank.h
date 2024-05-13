/*
 * Bank.h
 *
 *  Created on: 24 lug 2023
 *      Author: WotkStation05
 */

#ifndef BANK_H_
#define BANK_H_

#include <map>
#include <memory>

namespace account
{
class Account;
}

namespace transaction
{
class Transaction;
}

namespace bank
{

class Bank final
{
public:
	Bank ( void );
	~Bank ( void );

	std::weak_ptr<account::Account> createAccount ( const std::string name, const double initialBalance  );
	void dropAccount ( std::weak_ptr<account::Account> account );

	int32_t createTransaction ( std::weak_ptr<account::Account> sender, std::weak_ptr<account::Account> receiver, const double amount );

	void printAccountDetails ( const uint32_t accountId ) const;
	void printTransactionDetails ( const uint32_t transactionId ) const;

	void printAllAccountsDetails ( void ) const;
	void printAllTransactionsDetails ( void ) const;

private:

	Bank ( const Bank& ) = delete;
	Bank& operator= ( const Bank& ) = delete;

	std::map < uint32_t, std::shared_ptr<account::Account> > _accounts;
	std::map < uint32_t, std::unique_ptr<transaction::Transaction> > _transactions;
};

} /* namespace bank */

#endif /* BANK_H_ */
