/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Lambda with empty capture list
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void print(const std::vector<int> &data, const std::string &message = "")
{
    std::cout << message << ": ";
    std::copy(data.cbegin(), data.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

void increase(int &value)
{
    value += 1;
}

int main()
{
    std::vector<int> values{1, 2, 3};
    print(values, "A few values");

    std::cout << "Increase by function\n";
    for (int i = 0; i < 3; ++i)
    {
        for_each(values.begin(), values.end(), &increase);
        print(values);
    }

    std::cout << "Increase by lambda\n";
    for (int i = 0; i < 3; ++i)
    {
        for_each(values.begin(), values.end(), [](int &cur) { cur += 1; });
        print(values);
    }
}
