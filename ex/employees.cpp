/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * exercise
 */
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

class Employee final
{
  private:
    std::string name_;
    std::string title_;
    std::weak_ptr<Employee> manager_;
    std::vector<std::weak_ptr<Employee>> subordinates_;

  public:
    Employee(const std::string &name, const std::string &title) : name_(name), title_(title)
    {
        std::cout << "Ctor for " << name_ << '\n';
    }

    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;
    Employee(const Employee &&) = delete;
    Employee &operator=(const Employee &&) = delete;

    ~Employee()
    {
        std::cout << "Dtor for " << name_ << '\n';
    }

    void manager(const std::weak_ptr<Employee> &manager)
    {
        manager_ = manager;
    }

    void subordinate(const std::shared_ptr<Employee> &subordinate)
    {
        subordinates_.push_back(subordinate);
    }

    std::string name() const
    {
        return name_;
    }

    std::string title() const
    {
        return title_;
    }

    std::weak_ptr<Employee> manager() const
    {
        return manager_;
    }

    const std::vector<std::weak_ptr<Employee>> &subordinates() const
    {
        return subordinates_;
    }
};

std::ostream &operator<<(std::ostream &os, const Employee &e)
{
    os << e.name() << " (" << e.title() << ") ";
    if (auto m = e.manager().lock(); m)
    {
        os << "refers to " << m->name() << ". ";
    }
    else
    {
        os << "has no manager. ";
    }

    std::cout << "Subordinates: ";
    bool empty = false;
    for (const auto &we : e.subordinates())
    {
        if (auto cur = we.lock(); cur)
        {
            empty = true;
            std::cout << cur->name() << " ";
        }
    }
    if (!empty)
    {
        std::cout << "(none)";
    }

    return os;
}

int main()
{
    std::vector<std::shared_ptr<Employee>> employees{
        std::make_shared<Employee>("Alice", "CEO"),       //
        std::make_shared<Employee>("Bob", "Manager"),     //
        std::make_shared<Employee>("Charlie", "Manager"), //
        std::make_shared<Employee>("David", "Employee"),  //
        std::make_shared<Employee>("Eva", "Employee"),    //
        std::make_shared<Employee>("Frank", "Employee"),  //
    };

    employees[0]->subordinate(employees[1]);
    employees[0]->subordinate(employees[2]);

    employees[1]->manager(employees[0]);
    employees[1]->subordinate(employees[3]);
    employees[1]->subordinate(employees[4]);

    employees[2]->manager(employees[0]);
    employees[2]->subordinate(employees[5]);

    employees[3]->manager(employees[1]);
    employees[4]->manager(employees[1]);
    employees[5]->manager(employees[2]);

    std::for_each(employees.begin(), employees.end(), [](auto e) { std::cout << *e << '\n'; });
    std::cout << '\n';

    employees.erase(employees.begin());
    employees.erase(employees.end());
    std::cout << "After erasing Alice and Frank:\n";
    std::for_each(employees.begin(), employees.end(), [](auto e) { std::cout << *e << '\n'; });
    std::cout << '\n';
}
