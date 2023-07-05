#include <iostream>
#include <memory>
#include "Base.h"
using namespace std;

void empty() {
    cout << "An empty unique ptr\n";
    unique_ptr<Base> pEmpty;
    if (pEmpty) {
        cout << "Unexpected!\n";
    }
    cout << "---\n";
}

int main() {
    empty();

    cout << "A non-empty unique ptr\n";
    unique_ptr<Base> up = make_unique<Base>(1);
    if (!up) {
        cout << "Unexpected!\n";
    }

    cout << "Dereferencing: " << *up << '\n';
    cout << "Calling a method: ";
    up->hello();

    Base* p = up.get();
    cout << "Through a naked point: ";
    p->hello();
    cout << "DANGEROUS! The object is owned by the smart pointer!\n";
    cout << "!!! DO NOT DELETE the naked pointer !!!\n";

    cout << "---\n";
}
