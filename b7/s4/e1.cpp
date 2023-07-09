/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector - basic methods
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void print(const vector<T> &values, const string &label)
{
    cout << label << ": ";
    for (const T &value : values)
    {
        cout << value << ' ';
    }
    cout << '\n';
}

int main()
{
    vector<int> empty;
    cout << "Size of an empty vector is " << empty.size() << '\n';

    vector<int> anotherEmpty{};
    cout << "Size of another empty vector is " << empty.size() << '\n';

    vector<int> filled(5, -1);
    print(filled, "A vector filled with a given value");

    // no filling for vector
    // values.fill(-1);

    vector<int> given{6, 4, 3};
    print(given, "A vector with a few given values");

    vector<string> sv{"hello", "goodbye"};
    print(sv, "A string vector");

    // increase all the elements
    for (int &cur : given)
    {
        cur += 1;
    }
    print(given, "Increased values");
}
