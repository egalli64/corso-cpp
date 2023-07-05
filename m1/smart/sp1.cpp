#include <iostream>
#include <memory>
#include "Base.h"
using namespace std;

void empty() {
    cout << "An empty shared ptr\n";
    shared_ptr<Base> pEmpty;
    if (pEmpty) {
        cout << "Unexpected!\n";
    }
    cout << "---\n";
}

int main() {
    empty();

    cout << "A non-empty shared ptr\n";
    shared_ptr<Base> sp = make_shared<Base>(1);
    if (!sp) {
        cout << "Unexpected!\n";
    }

    cout << "Dereferencing: " << *sp << '\n';
    cout << "Calling a method: ";
    sp->hello();

    Base* p = sp.get();
    cout << "Through a naked point: ";
    p->hello();
    cout << "DANGEROUS! The object is owned by the smart pointer!\n";
    cout << "!!! DO NOT DELETE the naked pointer !!!\n";

    cout << "---\n";
}
