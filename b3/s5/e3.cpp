/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * range based for
 */
#include <iostream>
using namespace std;

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6};
    for (int value : data)
    {
        cout << value << '\n';
    }
}
