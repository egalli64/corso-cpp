#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int x = 42;
    int y = 18;

    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';

    cout << "\nArithmetic operators\n\n";

    cout << "x + y = " << x + y << '\n';
    cout << "+x = " << +x << '\n';
    cout << "x - y = " << x - y << '\n';
    cout << "-x = " << -x << '\n';
    cout << "x * y = " << x * y << '\n';
    cout << "x / y = " << x / y << '\n';
    cout << "x % y = " << x % y << '\n';

    cout << "\nString concatenation\n\n";
    string s{ "Hello" };
    string t{ "World!" };
    cout << s + ", " + t << '\n';
}
