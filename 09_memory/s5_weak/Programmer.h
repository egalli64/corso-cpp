/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Memory: weak_ptr
 */
#ifndef CORSO_CPP_9_S5_WEAK_PROGRAMMER
#define CORSO_CPP_9_S5_WEAK_PROGRAMMER

#include "Project.h"
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class Programmer final
{
    friend std::ostream &operator<<(std::ostream &os, const Programmer &programmer);

  private:
    std::string name_;
    std::vector<std::weak_ptr<Project>> projects_;

  public:
    Programmer(const std::string &name) : name_{name}
    {
        std::cout << "Programmer ctor " << name_ << '\n';
    }

    Programmer(const Programmer &other) : name_{other.name_}
    {
        std::cout << "Programmer copy ctor " << name_ << '\n';
        projects_ = other.projects_;
    }

    Programmer(Programmer &&other) noexcept
    {
        std::cout << "Programmer move ctor for " << other.name_ << '\n';

        name_ = std::move(other.name_);
        projects_ = std::move(other.projects_);
    }

    Programmer &operator=(const Programmer &other)
    {
        std::cout << "Programmer assigment for " << other.name_ << '\n';

        name_ = other.name_;
        projects_ = other.projects_;
        return *this;
    }

    Programmer &operator=(Programmer &&other)
    {
        std::cout << "Programmer move assigment for " << other.name_ << '\n';

        name_ = std::move(other.name_);
        projects_ = std::move(other.projects_);
        return *this;
    }

    ~Programmer()
    {
        std::cout << "Programmer dtor " << name_ << '\n';
    }

    const std::string &name() const
    {
        return name_;
    }

    void attachTo(std::shared_ptr<Project> p)
    {
        projects_.push_back(p);
    }
};

std::ostream &operator<<(std::ostream &os, const Programmer &programmer);

#endif // CORSO_CPP_9_S5_WEAK_PROGRAMMER
