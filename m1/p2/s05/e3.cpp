#include <iostream>
#include <bitset>
using namespace std;

int main() {
    unsigned int x = 42;
    unsigned int y = 18;

    cout << "\nBitwise operators\n\n";
    cout << "x = " << x << " (" << bitset<8>(x) << ')' << '\n';
    cout << "y = " << y << " (" << bitset<8>(y) << ')' << '\n';
    cout << '\n';

    cout << "x & y = " << bitset<8>(x & y) << '\n';
    cout << "x | y = " << bitset<8>(x | y) << '\n';
    cout << "x ^ y = " << bitset<8>(x ^ y) << '\n';
    // '~' topleft on US keyboard, or alt-126, or altGr-ì
    cout << "~x = " << bitset<8>(~x) << '\n'; 
}
