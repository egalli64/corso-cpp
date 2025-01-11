/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: count_if
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class HasSizeEqualTo
{
  private:
    const size_t size_;

  public:
    HasSizeEqualTo(const int size) : size_(size)
    {
    }

    bool operator()(const std::string &other) const
    {
        return other.size() == size_;
    }
};

bool hasSizeEqualToFour(const std::string &s)
{
    return s.size() == 4;
}

int main()
{
    std::vector<std::string> values{"Tom", "Kim", "Tony", "Liza"};
    std::cout << "Count the strings sized 4\n";

    // loop
    std::cout << "No count_if (explicit loop): ";
    int count = 0;
    for (const std::string &cur : values)
    {
        if (cur.size() == 4)
        {
            count += 1;
        }
    }
    std::cout << count << '\n';

    // function
    std::cout << "By function: ";
    std::cout << std::count_if(values.begin(), values.end(), hasSizeEqualToFour) << '\n';

    // function object
    std::cout << "By function object: ";
    std::cout << std::count_if(values.begin(), values.end(), HasSizeEqualTo(4)) << '\n';

    // lambda
    std::cout << "By lambda expression: ";
    std::cout << std::count_if(values.begin(), values.end(), [](const std::string &x) { return x.size() == 4; })
              << '\n';
}
