/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * A simple print function for elements in a container
 */
#ifndef CORSO_CPP_7_EX_MY_PRINT_H
#define CORSO_CPP_7_EX_MY_PRINT_H

#include <iostream>
#include <string>

template <typename IT> void print(IT first, IT last, const std::string &label)
{
    std::cout << label << ": [ ";

    while (first != last)
    {
        std::cout << *first << ' ';
        ++first;
    }

    std::cout << "]\n";
}

#endif // CORSO_CPP_7_EX_MY_PRINT_H
