#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> values;
    cout << "Empty vector" << '\n';
    cout << "Size is " << values.size() << '\n';
    cout << "Capacity is " << values.capacity() << '\n';

    values.push_back(2); // fast
    values.emplace_back(42); // usually fastest
    values.insert(values.begin(), 12); // could be very slow

    cout << "Size is " << values.size() << '\n';
    cout << "Capacity is " << values.capacity() << '\n';
    cout << "First element is " << values.front() << '\n';
    cout << "Last element is " << values.back() << '\n';
}
