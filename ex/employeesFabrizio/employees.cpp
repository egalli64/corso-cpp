//============================================================================
// Name        : EsercizioEmployee.cpp
// Author      : FDA
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Employee.h"
#include <memory>
#include <algorithm>

#include <iostream>



int main() {


	std::vector<std::shared_ptr<Employee>> workers = {
			std::make_shared<Employee>("Alice", employee_title_t::CEO),
			std::make_shared<Employee>("Bob", employee_title_t::MANAGER),
			std::make_shared<Employee>("Charlie", employee_title_t::MANAGER),
			std::make_shared<Employee>("David", employee_title_t::EMPLOYEE),
			std::make_shared<Employee>("Eva", employee_title_t::EMPLOYEE),
			std::make_shared<Employee>("Frank", employee_title_t::EMPLOYEE)
	};

	workers[0]->addSubordinate(workers[1]);
	workers[0]->addSubordinate(workers[2]);

	workers[1]->setManager(workers[0]);
	workers[1]->addSubordinate(workers[4]);
	workers[1]->addSubordinate(workers[5]);

	workers[2]->setManager(workers[0]);
	workers[2]->addSubordinate(workers[5]);

	workers[3]->setManager(workers[1]);
	workers[4]->setManager(workers[1]);
	workers[5]->setManager(workers[2]);


	std::cout<<"PRIMA"<<"\n";
	auto print_workers = [](std::shared_ptr<Employee> worker){
		std::cout<<"Name: "<<worker->getName();
		std::string manager = "None";
		if(!(worker->getManager().expired())){
			std::shared_ptr<Employee> shared_ = worker->getManager().lock();
			manager = shared_->getName();
		}
		std::cout<<", Manager: "<<manager;
		std::cout<<", Subordinates (";
		for(auto & s: worker->getSubordinates()){
				if(!s.expired()){
					std::shared_ptr<Employee> shared_s = s.lock();
					std::cout<<shared_s->getName()<<" ";
				}
			}
		std::cout<<")\n";
	};
	std::for_each(workers.begin(), workers.end(), print_workers);

	workers.erase(workers.begin());
	workers.erase(workers.end());

	std::cout<<"DOPO"<<"\n";
	std::for_each(workers.begin(), workers.end(), print_workers);


	return 0;
}
