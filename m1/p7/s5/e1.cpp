#include <iostream>
#include <list>
#include <string>
using namespace std;

void print(const list<string>& data) {
    for (const string& cur : data) {
        cout << cur << ' ';
    }
    cout << '\n';
}

int main() {
    list<string> empty;
    cout << "Size of an empty list is " << empty.size() << '\n';

    list<string> data{ "tom", "bob", "kim" };
    print(data);

    data.push_front("zoe");
    data.push_back("dick");
    data.remove("bob");
    print(data);
}
