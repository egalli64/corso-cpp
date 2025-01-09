/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL string: a few mwthods
 */
#include <iostream>
#include <string>

int main()
{
    std::string s = "hello";
    std::cout << s << " has size " << s.size() << '\n';

    std::string t = s.substr(1, 2);
    std::cout << "Substring from 1, sized 2: " << t << '\n';

    s.replace(1, 1, "aaa");
    std::cout << "Replace 1 char starting from 1 with 'aaa': " << s << '\n';

    const char* rs = s.c_str();
    std::cout << "Extracting the c-string from the string: " << rs << '\n';
}
