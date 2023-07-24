/*
 * Employee.h
 *
 *  Created on: 24 lug 2023
 *      Author: WotkStation05
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <map>
#include <string>
#include <memory>

namespace employee
{

class Employee
{
public:

	enum class ERoles
	{
		Manager,
		CEO,
		Employee
	};

	Employee ( const std::string &name, const ERoles& role );
	~Employee ( void );

	const std::weak_ptr<Employee>& getManager ( void ) const;
	const std::map<std::string, std::weak_ptr<Employee>>&  getSubordinates ( void ) const;
	const ERoles& getRole ( void ) const;
	const std::string& getName ( void ) const;

	void setManager ( const std::shared_ptr<employee::Employee>& manager );
	void addSubordinate ( const std::shared_ptr<employee::Employee>& subordinate );
	void setRole ( const ERoles & role );

	static const std::string roleToString ( const ERoles& role );

private:

	std::string _name;
	ERoles _role;

	std::weak_ptr<Employee> _manager;
	std::map< std::string, std::weak_ptr<Employee> > _subordinates;

};

}

#endif /* EMPLOYEE_H_ */
