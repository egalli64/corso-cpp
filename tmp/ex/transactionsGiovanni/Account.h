/*
 * Account.h
 *
 *  Created on: 24 lug 2023
 *      Author: WotkStation05
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <cstdint>
#include <string>
#include <atomic>

namespace account
{

class Account final
{
public:
	Account( const std::string& name, const double initialBalance = 0.0 );
	~Account ( void );

	double getBalance ( void ) const;
	void setBalance ( const double balance );

	const uint32_t getId ( void ) const;

	const std::string& getName ( void ) const;
	void setName ( const std::string &name );

	void printDetails ( void ) const;

private:
	uint32_t _id;
	std::string _name;
	double _balance;

	static std::atomic < uint32_t > serialIdGenerator;
};

} /* namespace account */

#endif /* ACCOUNT_H_ */
