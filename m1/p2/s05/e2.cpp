#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int y = 18;

    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';

    cout << "\nComparison operators\n\n";

    cout << "x == y = " << (x == y) << '\n';
    cout << "x != y = " << (x != y) << '\n';
    cout << "x < y = " << (x < y) << '\n';
    cout << "x <= y = " << (x <= y) << '\n';
    cout << "x > y = " << (x > y) << '\n';
    cout << "x >= y = " << (x >= y) << '\n';

    cout << "\nLogical operators\n\n";
    cout << "x && y = " << (x && y) << '\n';
    cout << "x || y = " << (x || y) << '\n';
    cout << "!x = " << !x << '\n';
}
