/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL string: iterators
 */
#include <iostream>
#include <string>

int main()
{
    std::string s = "hello";
    std::cout << s << '\n';

    std::string::iterator beg = s.begin();
    std::string::iterator end = s.end();

    std::cout << "Iterating on the string: [ ";
    for(std::string::iterator cur = s.begin(); cur < s.end(); ++cur) {
        std::cout << *cur << ' ';
    }
    std::cout << "]\n";

    std::cout << "Iterating backward: [ ";
    for(std::string::reverse_iterator cur = s.rbegin(); cur < s.rend(); ++cur) {
        std::cout << *cur << ' ';
    }
    std::cout << "]\n";
}
