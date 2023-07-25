/*
 * Employee.h
 *
 *  Created on: 24 lug 2023
 *      Author: WorkStation03
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class Employee final
{

  private:
    std::string name_;
    std::string title_;
    std::vector<std::weak_ptr<Employee>> manager_;
    std::vector<std::weak_ptr<Employee>> subordinates_;

  public:
    Employee(const std::string &name, const std::string &title) : name_{name}, title_{title}
    {
        std::cout << "Employee ctor -->" << name_ << " as a/an " << title_ << '\n';
    }

    Employee(const Employee &other) = delete;
    //: name_{other.name_}
//    {
//        std::cout << "Employee copy ctor " << name_ << '\n';
//        title_ = other.title_;
//        manager_ = other.manager_;
//        subordinates_ = other.subordinates_;
//    }

    ~Employee()
    {
        std::cout << "Employee dtor " << name_ << '\n';
    }

    const std::string &name() const
    {
        return name_;
    }

    void attachToM(std::shared_ptr<Employee> p)
    {
    	manager_.push_back(p);
    }

    void attachToS(std::shared_ptr<Employee> p)
    {
    	subordinates_.push_back(p);
    }

    friend std::ostream &operator<<(std::ostream &os, const Employee &e);
};

#endif /* EMPLOYEE_H_ */
