#define NDEBUG

#include <iostream>
#include <cassert>
using namespace std;

void print(const char* text) {
    assert(text != nullptr);

    cout << text << '\n';
}

int main() {
    print("hello");

    print(nullptr);
}
