#include <iostream>
using namespace std;

int main() {
    int x = 42;
    int y = 18;

    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';


    cout << "\nAssignment operators\n\n";
    cout << "x += y -> x = " << (x += y) << '\n';
    cout << "x -= y -> x = " << (x -= y) << '\n';
    cout << "++x -> x = " << ++x << '\n';
    cout << "--x -> x = " << --x << '\n';
}
