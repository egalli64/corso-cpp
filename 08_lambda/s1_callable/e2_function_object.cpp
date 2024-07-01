/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * callable: function object
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace
{
/**
 * @brief a function object
 */
class Printer
{
  private:
    const std::string prefix_;

  public:
    /**
     * @brief ctor with default argument
     */
    Printer(const std::string &prefix = "") : prefix_{prefix}
    {
    }

    /**
     * @brief the operator() on Printer requires a const ref to string
     */
    void operator()(const std::string &message) const
    {
        std::cout << prefix_ << message << '\n';
    }
};
} // namespace

int main()
{
    Printer printer;
    printer("A function object is a callable");

    std::vector<std::string> names{"Tom", "Bob", "Kim"};
    std::cout << "Passing a function object to a function:\n";

    // given a prefix provided elsewhere
    std::string prefix{"-> "};
    // create a function object that uses the prefix
    Printer p{prefix};
    // pass the function object to a HOF that uses it
    std::for_each(names.begin(), names.end(), p);
}
