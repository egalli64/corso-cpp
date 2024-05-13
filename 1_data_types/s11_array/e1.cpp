/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * array
 */
#include <iostream>

int values[10];

int main()
{
    std::cout << "size of an int[10] " << sizeof(values) << '\n';
    std::cout << "size of char[10] " << sizeof(char[10]) << '\n';
    std::cout << "size of double[10] " << sizeof(double[10]) << '\n';
    std::cout << '\n';
    std::cout << "Non-local arrays are default-initialized: " << values[0] << ' ' << values[9] << '\n';

    // g++ -Wall warning for possible uninitialized use
    int localValues[10];
    std::cout << "No assumption on local arrays: " << localValues[0] << ' ' << localValues[9] << '\n';

    int data[6]{42, 12, 18, 21, 5, 33};
    std::cout << "The last value in data: " << data[5] << '\n';

    int data_len = sizeof(data) / sizeof(int);
    std::cout << "Length of data: " << data_len << '\n';
    std::cout << "The last value in data: " << data[data_len - 1] << '\n';
    std::cout << "This is a dangerous mistake: " << data[data_len] << '\n';

    int *ptr{&data[0]};
    std::cout << "First cell in data, address and value: " << ptr << " -> " << *ptr << '\n';

    ptr = data;
    std::cout << "Same: " << ptr << " -> " << *ptr << '\n';

    ptr = &data[5];
    std::cout << "Last cell: " << ptr << " -> " << *ptr << '\n';

    int &ref{data[5]};
    std::cout << "ref and data[5] " << ref << ' ' << data[5] << '\n';

    ref += 1;
    std::cout << "ref and data[5] after increasing ref " << ref << ' ' << data[5] << '\n';
}
