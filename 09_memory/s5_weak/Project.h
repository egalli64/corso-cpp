/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Memory: weak_ptr
 */
#ifndef CORSO_CPP_9_S5_WEAK_PROJECT
#define CORSO_CPP_9_S5_WEAK_PROJECT

#include <iostream>
#include <memory>
#include <utility>
#include <vector>

class Programmer;

class Project final
{
    friend std::ostream &operator<<(std::ostream &os, const Project &project);

  private:
    std::string name_;
    std::vector<std::weak_ptr<Programmer>> programmers_;

  public:
    Project(const std::string &name) : name_{name}
    {
        std::cout << "Project ctor " << name_ << '\n';
    }

    Project(const Project &other) : name_{other.name_}
    {
        std::cout << "Project copy ctor " << name_ << '\n';
        programmers_ = other.programmers_;
    }

    Project(Project &&other) noexcept
    {
        std::cout << "Project move ctor for " << other.name_ << '\n';

        name_ = std::move(other.name_);
        programmers_ = std::move(other.programmers_);
    }

    Project &operator=(const Project &other)
    {
        std::cout << "Project assigment for " << other.name_ << '\n';

        name_ = other.name_;
        programmers_ = other.programmers_;
        return *this;
    }

    Project &operator=(Project &&other)
    {
        std::cout << "Project move assigment for " << other.name_ << '\n';

        name_ = std::move(other.name_);
        programmers_ = std::move(other.programmers_);
        return *this;
    }

    ~Project()
    {
        std::cout << "Project dtor " << name_ << '\n';
    }

    const std::string &name() const
    {
        return name_;
    }

    void add(std::shared_ptr<Programmer> p)
    {
        programmers_.push_back(p);
    }
};

std::ostream &operator<<(std::ostream &os, const Project &project);

#endif // CORSO_CPP_B9_S5_WEAK_PROJECT
