#include <iostream>
#include <forward_list>
#include <string>
using namespace std;

void print(const forward_list<string>& data) {
    for (const string& cur : data) {
        cout << cur << ' ';
    }
    cout << '\n';
}

int main() {
    forward_list<string> data{ "tom", "bob", "kim" };
    print(data);

    data.push_front("zoe");
    data.remove("bob");
    print(data);
}
