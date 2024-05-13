#include <iostream>
#include <memory>
#include "Base.h"
using namespace std;

void direct() {
    cout << "A shared ptr by explicit new\n";
    shared_ptr<Base> sp{ new Base(1) };

    cout << "Dereferencing the sp: " << *sp << '\n';
    cout << "---\n";
}

int main() {
    direct();

    cout << "\nA shared ptr\n";
    shared_ptr<Base> sp = make_shared<Base>(2);

    if (sp.unique()) {
        cout << "It is unique, reference count is " << sp.use_count() << '\n';

        cout << "A copy of the original shared ptr\n";
        shared_ptr<Base> sp2(sp);

        if (!sp.unique()) {
            cout << "It is not anymore unique, reference count is " << sp.use_count() << '\n';
        }
    }

    cout << "Copy out of scope, reference count is " << sp.use_count() << '\n';
    cout << "---\n";
}
