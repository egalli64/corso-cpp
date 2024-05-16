/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * A HOF returning a std::function
 */
#include <functional>
#include <iostream>

namespace
{
std::function<int(int)> make_adder(int base)
{
    auto result = [base](int x) { return base + x; };

    std::cout << "Testing the generated lambda for 18: " << result(18) << '\n';

    return result;
}
} // namespace

int main()
{
    auto adder = make_adder(24);

    std::cout << "Invoking adder24 on 12: " << adder(12) << '\n';
}
