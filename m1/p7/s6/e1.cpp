#include <iostream>
#include <map>
#include <string>
using namespace std;

void print(const map<string, double>& items) {
    for (const auto& item : items) {
        cout << item.first << ' ' << item.second << '\n';
    }
    cout << '\n';
}

int main() {
    map<string, double> data{ {"tom", 32.18}, {"bob", 44.11}, {"kim", 98.03} };
    data.insert({"mia", 91.12});
    data.emplace("jim", 12.23);
    print(data);

    // -std=c++17
    // if(auto it = data.find("bob"); it != data.end()) {
    //     cout << "bob value is: " << it->second << '\n';
    // }

    auto it = data.find("bob");
    if (it != data.end()) {
        cout << "find bob: " << it->second << '\n';
    }

    cout << "at tom: " << data.at("tom") << '\n';

    try {
        double joe = data.at("joe");
        cout << joe << '\n';
    }
    catch (const out_of_range& ex) {
        cout << "Out of range calling " << ex.what() << " on joe" << '\n';
    }
}
