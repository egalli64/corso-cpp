#include <iostream>
using namespace std;

int main() {
    cout << "Null pointer\n\n";

    int* ptr = nullptr;
    cout << "An unused pointer: " << ptr << '\n';
    cout << "A null pointer can't be dereferenced ... " << '\n';

    cout << *ptr << '\n';
}
