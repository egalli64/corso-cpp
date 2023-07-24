/*
 * Account.cpp
 *
 *  Created on: 24 lug 2023
 *      Author: WotkStation05
 */

#include "Account.h"

#include <iostream>
#include <iomanip>

namespace account
{

std::atomic < uint32_t > Account::serialIdGenerator{0U};

Account::Account ( const std::string& name, const double initialBalance ) :
		_id{0U}, _name{name}, _balance{initialBalance}
{
	_id = Account::serialIdGenerator.fetch_add(1U);
}

Account::~Account( void )
{
}

double Account::getBalance ( void ) const
{
	return _balance;
}

void Account::setBalance ( const double balance )
{
	_balance = balance;
}

const uint32_t Account::getId ( void ) const
{
	return _id;
}

const std::string& Account::getName ( void ) const
{
	return _name;
}

void Account::setName ( const std::string &name )
{
	_name = name;
}

void Account::printDetails ( void ) const
{
	std::cout << std::left << "Account nr. " << std::setw(6) << _id << ". Name: " << std::setw(10) << _name << ". Actual balance: " << std::right << std::setw(10) << _balance << " €\n";
}


} /* namespace account */
