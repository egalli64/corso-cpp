/*
 * Ex_2407.cpp
 *
 *  Created on: 24 lug 2023
 *      Author: WorkStation03
 */

#include "Employee.h"
#include <iostream>
#include <memory>
#include <vector>

std::ostream &operator<<(std::ostream &os, const Employee &e)
{
    os << '{' << e.name_ << ", " << e.title_ << ", ";
    os << "[ Manager: ";
    for (auto p : e.manager_)
    {
        std::shared_ptr<Employee> sp = p.lock();
        if (sp)
        {
            os << sp->name() << ' ';
        }
        else
        {
            os << "No manager founded ";
        }
    }

    os << "], [ Subordinates: ";
    for (auto p : e.subordinates_)
    {
        std::shared_ptr<Employee> sp = p.lock();
        if (sp)
        {
            os << sp->name() << ' ';
        }
        else
        {
            os << "No subordinates founded ";
        }
    }

    return os << "]}\n";
}


namespace
{
void linkManager(std::shared_ptr<Employee> employeeA, std::shared_ptr<Employee> employeeB)
{
    employeeA->attachToM(employeeB);
    employeeB->attachToS(employeeA);
}

//void linkSubordinate(std::shared_ptr<Employee> employeeA, std::shared_ptr<Employee> employeeB)
//{
//    std::cout << employeeA->name() << " -> " << employeeB->name() << '\n';
//    employeeA->attachToS(employeeB);
//}

void dump(const std::vector<std::shared_ptr<Employee>> &employees)
{
    for (const auto employee : employees)
    {
        std::cout << *employee<< ' ';
    }
    std::cout << '\n';
}
}

int main()
{
    std::vector<std::shared_ptr<Employee>> employees;
    employees.push_back(std::make_shared<Employee>("Alice",   "CEO"));
    employees.push_back(std::make_shared<Employee>("Bob",     "Manager"));
    employees.push_back(std::make_shared<Employee>("Charlie", "Manager"));
    employees.push_back(std::make_shared<Employee>("David",   "Employee"));
    employees.push_back(std::make_shared<Employee>("Eva",     "Employee"));
    employees.push_back(std::make_shared<Employee>("Frank",   "Employee"));
    std::cout<<"\n";

    linkManager(employees[1], employees[0]);
    linkManager(employees[2], employees[0]);
    linkManager(employees[3], employees[1]);
    linkManager(employees[4], employees[1]);
    linkManager(employees[5], employees[2]);

//    linkSubordinate(employees[0], employees[1]);
//    linkSubordinate(employees[0], employees[2]);
//    linkSubordinate(employees[1], employees[3]);
//    linkSubordinate(employees[1], employees[4]);
//    linkSubordinate(employees[2], employees[5]);

    dump(employees);

    employees.erase(employees.begin());
    employees.erase(employees.end());
    std::cout<<"\n";

    dump(employees);

}




