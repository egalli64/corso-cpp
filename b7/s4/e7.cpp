/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL vector - achieving polymorphism by smart pointers (shared)
 */
#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

#include "ExtendedEntry.h"

int main()
{
    cout << "*** Shared Smart Pointer Vector\n";
    vector<shared_ptr<Entry>> values{make_shared<Entry>(1, "Tom"), make_shared<Entry>(2, "Bob")};
    values.push_back(make_shared<Entry>(3, "Kim"));
    values.push_back(make_shared<ExtendedEntry>(4, "Wim", "!!!"));

    cout << "*** All entries say hello\n";
    for (const auto &cur : values)
    {
        cout << "Use count is " << cur.use_count() << " ... ";
        cur->sayHello();
    }

    for (auto cur : values)
    {
        cout << "Use count is " << cur.use_count() << " ... ";
        cur->sayHello();
    }

    cout << "*** Vector is about to going out of scope\n";
}