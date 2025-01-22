/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * callable: function object
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief A function object
 */
class Printer
{
  private:
    std::string prefix_;

  public:
    Printer(const std::string &prefix = "") : prefix_(prefix)
    {
    }

    void operator()(const std::string &message) const
    {
        std::cout << prefix_ << message << '\n';
    }
};

int main()
{
    Printer printer{};
    printer("A function object is a callable");

    std::vector<std::string> names{"Tom", "Bob", "Kim"};
    std::cout << "Passing a function object to a function:\n";
    std::for_each(names.begin(), names.end(), Printer{"-> "});
}
