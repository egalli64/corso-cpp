/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * std::string - iterators
 */
#include <algorithm>
#include <iostream>
#include <string>

int main()
{
    std::string s{"beta"};
    std::cout << "Working on " << s << '\n';

    std::cout << "First char is: " << *s.begin() << '\n';
    std::cout << "Last char is: " << *(s.end() - 1) << '\n';

    std::sort(s.begin(), s.end());
    std::cout << "After sorting: " << s << '\n';
}
