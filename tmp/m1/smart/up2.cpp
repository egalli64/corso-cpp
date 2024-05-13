#include <iostream>
#include <memory>
#include "Base.h"
using namespace std;

void deleteByAssignment() {
    cout << "Unique ptr 1\n";
    unique_ptr<Base> up = make_unique<Base>(1);

    cout << "up: " << *up << '\n';

    cout << "Deleting the object owned by up\n";
    up = nullptr;
    if (up) {
        cout << "Unexpected\n";
    }
    else {
        cout << "up is empty\n";
    }
}

void deleteByReset() {
    cout << "\nUnique ptr 2\n";
    unique_ptr<Base> up = make_unique<Base>(2);

    cout << "up: " << *up << '\n';

    cout << "Deleting the object owned by up\n";
    up.reset();
    if (up) {
        cout << "Unexpected\n";
    }
    else {
        cout << "up is empty\n";
    }
}

void reassign() {
    cout << "\nUnique ptr 3\n";
    unique_ptr<Base> up = make_unique<Base>(3);

    cout << "up: " << *up << '\n';

    cout << "Reassigning the object owned by up\n";
    up.reset(new Base(4));
    cout << "up: " << *up << '\n';
}

void release() {
    cout << "\nUnique ptr 5\n";
    unique_ptr<Base> up = make_unique<Base>(5);

    cout << "up: " << *up << '\n';

    cout << "Releasing the object owned by up\n";
    Base* p = up.release();
    if(!up) {
        cout << "Now up is empty\n";
    }

    cout << "Remember to delete the object by hand!\n";
    delete p;
}

int main() {
    deleteByAssignment();
    deleteByReset();
    reassign();
    release();
}
