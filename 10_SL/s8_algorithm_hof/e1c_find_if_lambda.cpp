/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: find_if by lambda
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> values{"Tom", "Kim", "Tony", "Liza"};

    std::cout << "Find first string sized 4: ";
    auto it = find_if(values.begin(), values.end(), [](const std::string &x) { return x.size() == 4; });
    if (it != values.end())
    {
        std::cout << *it << '\n';
    }
    else
    {
        std::cout << "unexpected\n";
    }
}
