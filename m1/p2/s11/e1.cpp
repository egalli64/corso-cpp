#include <iostream>
using namespace std;

int values[10];

int main() {
    cout << "size of an int[10] " << sizeof(values) << '\n';
    cout << "size of char[3] " << sizeof(char[3]) << '\n';
    cout << "size of double[3] " << sizeof(int[3]) << '\n';
    cout << '\n';
    cout << "Non-local arrays are default-initialized: " << values[0] << ' ' << values[9] << '\n';

    int localValues[10];
    cout << "No assumption on local arrays: " << localValues[0] << ' ' << localValues[9] << '\n';

    int data[6]{ 42, 12, 18, 21, 5, 33 };
    cout << "The last value in data: " << data[5] << '\n';

    int data_len = sizeof(data) / sizeof(int);
    cout << "Length of data: " << data_len << '\n';
    cout << "The last value in data (using sizeof): " << data[data_len - 1] << '\n';
    cout << "This is a mistake: " << data[data_len] << '\n';

    int* ptr = &data[0];
    cout << "First cell in data, address and value: " << ptr << " -> " << *ptr << '\n';

    ptr = data;
    cout << "Same: " << ptr << " -> " << *ptr << '\n';

    ptr = &data[5];
    cout << "Last cell: " << ptr << " -> " << *ptr << '\n';

    int& ref = data[5];
    cout << "ref and data[5] " << ref << ' ' << data[5] << '\n';

    ref += 1;
    cout << "ref and data[5] after increasing ref " << ref << ' ' << data[5] << '\n';
}
