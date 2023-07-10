/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL iterator
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int raw[]{5, 6, 42};

    cout << "Range for on a raw array: ";
    for (int value : raw)
    {
        cout << value << ' ';
    }
    cout << '\n';

    cout << "Iterating by pointer on a raw array: ";
    for (int *ptr = raw; ptr != raw + (sizeof(raw) / sizeof(int)); ++ptr)
    {
        cout << *ptr << ' ';
    }
    cout << '\n';

    vector<string> values{"tom", "bob", "kim"};

    cout << "Range for on an vector: ";
    for (const auto &value : values)
    {
        cout << value << ' ';
    }
    cout << '\n';

    cout << "Iterating by const_iterator on a vector: ";
    for (auto it = values.cbegin(); it != values.cend(); ++it)
    {
        cout << *it << ' ';
    }
    cout << '\n';
}
