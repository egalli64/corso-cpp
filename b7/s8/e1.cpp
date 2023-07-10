/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: find, accumulate
 */
#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> values{7, 2, 12};

    // find in an interval a value
    int target{2};
    auto itTwo = find(values.begin(), values.end(), target);
    cout << target << (itTwo == values.end() ? " not " : " ") << "found\n";

    // accumulate (adding) in an interval starting from value zero
    int sum = accumulate(values.begin(), values.end(), 0);
    cout << "Sum of values is " << sum << '\n';
}
