/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: for_each
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace
{
void printToCoutSizedThree(const std::string &s)
{
    if (s.size() == 3)
    {
        std::cout << s << ' ';
    }
}
} // namespace

int main()
{
    std::vector<std::string> values{"Tom", "Kim", "Tony", "Liza"};

    std::cout << "Print all string sized 3: ";
    for_each(values.begin(), values.end(), printToCoutSizedThree);
    std::cout << '\n';
}
