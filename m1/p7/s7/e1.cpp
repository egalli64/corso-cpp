#include<algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int raw[]{ 5, 6, 42 };
    for (int value : raw) {
        cout << value << ' ';
    }
    cout << '\n';

    for (int* ptr = raw; ptr != raw + (sizeof(raw) / sizeof(int)); ++ptr) {
        cout << *ptr << ' ';
    }
    cout << '\n';

    vector<string> values{ "tom", "bob", "kim" };
    for (const auto& value : values) {
        cout << value << ' ';
    }
    cout << '\n';

    for (auto it = values.cbegin(); it != values.cend(); ++it) {
        cout << *it << ' ';
    }
    cout << '\n';
}
