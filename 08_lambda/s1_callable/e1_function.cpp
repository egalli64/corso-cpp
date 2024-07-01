/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * callable: function
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace
{
/**
 * @brief a function
 */
void print(const std::string &message)
{
    std::cout << message << '\n';
}
} // namespace

int main()
{
    print("A function is a callable");

    // pf is a pointer to function returning void and accepting a const ref to string
    void (*pf)(const std::string &) = &print;
    pf("A pointer to function is commonly used in C");

    std::vector<std::string> names{"Tom", "Bob", "Kim"};
    std::cout << "Passing a function to another function:\n";
    std::for_each(names.begin(), names.end(), pf);
}
