#include <iostream>
using namespace std;

int main() {
    cout << "char* " << sizeof(char*) << '\n';
    cout << "double* " << sizeof(double*) << '\n';
    cout << '\n';

    char c = 'x';
    char* pc = &c;

    cout << c << ' ' << *pc << ' ' << static_cast<void*>(pc) << '\n';
    *pc = 'z';
    cout << c << ' ' << *pc << '\n';
}
