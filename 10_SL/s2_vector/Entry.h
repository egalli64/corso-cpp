/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector: a class meant to be derived
 */
#ifndef CORSO_CPP_10_ENTRY_H
#define CORSO_CPP_10_ENTRY_H

#include <iostream>
#include <string>
#include <utility>

class Entry
{
  private:
    int key_;
    std::string value_;

  public:
    Entry(int key, const std::string &value) : key_(key), value_(value)
    {
        std::cout << "Plain ctor for " << value_ << '\n';
    }

    Entry(const Entry &other) : key_(other.key_), value_(other.value_)
    {
        std::cout << "Copy ctor for " << value_ << '\n';
    }

    Entry(Entry &&other) noexcept
    {
        std::cout << "Move ctor for " << other.value_ << '\n';

        key_ = std::exchange(other.key_, 0);
        value_ = std::move(other.value_);
    }

    Entry &operator=(const Entry &other)
    {
        std::cout << "Assigment for " << other.value_ << '\n';

        key_ = other.key_;
        value_ = other.value_;
        return *this;
    }

    Entry &operator=(Entry &&other)
    {
        std::cout << "Move assigment for " << other.value_ << '\n';

        key_ = std::exchange(other.key_, 0);
        value_ = std::move(other.value_);
        return *this;
    }

    int key() const
    {
        return key_;
    }
    const std::string &value() const
    {
        return value_;
    }

    void setKey(int key)
    {
        key_ = key;
    };
    void setValue(const std::string &value)
    {
        value_ = value;
    }

    virtual void sayHello() const
    {
        std::cout << "Hello " << value() << '\n';
    }

    virtual ~Entry()
    {
        std::cout << "dtor " << key_ << ' ' << value_ << '\n';
    }
};

inline std::ostream &operator<<(std::ostream &os, const Entry &entry)
{
    return os << '{' << entry.key() << ", " << entry.value() << '}';
}

#endif // CORSO_CPP_10_ENTRY_H
