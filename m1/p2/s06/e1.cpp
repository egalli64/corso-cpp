#include <iostream>
#include <string>
using namespace std;

int main() {
    // implicit narrowing
    int x = 42.7;
    // error: explicit narrowing required
    // int y {42.7};

    int y{ static_cast<int>(42.7) };
    // automatic type deduction (here: double)
    auto z = 42.7;

    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';
    cout << "z = " << z << " is sized " << sizeof(z) << '\n';

    string s = "42";
    int i = stoi(s);
    cout << "From string to int (pre-incremented): " << ++i << '\n';

    s += ".27";
    double d = stod(s);
    cout << "From string to double: " << d << '\n';

    cout << "From numeric to string, and concat: " << to_string(51) + to_string(8.931255) << '\n';
}
