/*
 * Employee.cpp
 *
 *  Created on: 24 lug 2023
 *      Author: WotkStation05
 */

#include "Employee.h"

namespace employee
{

Employee::Employee( const std::string &name, const ERoles &role ) : _name{name}, _role{role}
{
}

Employee::~Employee( void )
{
}

const std::weak_ptr<Employee>& Employee::getManager( void ) const
{
	return _manager;
}

const std::map<std::string, std::weak_ptr<Employee>>& Employee::getSubordinates( void ) const
{
	return _subordinates;
}

const Employee::ERoles& Employee::getRole( void ) const
{
	return _role;
}

const std::string& Employee::getName( void ) const
{
	return _name;
}

void Employee::setManager( const std::shared_ptr<employee::Employee>& manager )
{
	_manager = manager;
}

void Employee::addSubordinate( const std::shared_ptr<employee::Employee>& subordinate )
{
	_subordinates[subordinate->getName()] = subordinate;
}

void Employee::setRole( const ERoles &role )
{
	_role = role;
}

const std::string Employee::roleToString ( const Employee::ERoles& role )
{
	switch ( role )
	{
	case Employee::ERoles::CEO:
		return "CEO";
	case Employee::ERoles::Manager:
		return "Manager";
	case Employee::ERoles::Employee:
		return "Employee";
	default:
		return "Unknown";
	}
}

}
