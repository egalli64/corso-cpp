#include <iostream>
#include <memory>
#include "Base.h"
using namespace std;

int main() {
    cout << "A shared ptr\n";
    shared_ptr<Base> sp = make_shared<Base>(1);

    cout << "\nReset the shared ptr with a new object\n";
    sp.reset(new Base(2));

    cout << "\nReset the shared ptr to empty\n";
    sp.reset();
    if (!sp) {
        cout << "The sp now is empty\n";
    }

    cout << "\nReset the shared ptr with a new object\n";
    sp.reset(new Base(3));

    cout << "\nReset the shared ptr to empty by assigment\n";
    sp = nullptr;
    if (!sp) {
        cout << "The sp now is empty\n";
    }
}
