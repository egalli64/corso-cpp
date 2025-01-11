/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: find_if
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
    std::cout << "Find first string sized 4\n";

    // loop
    std::cout << "No find_if (explicit loop): ";
    auto it = values.begin();
    while (it != values.end())
    {
        if (it->size() == 4)
        {
            std::cout << *it;
            break;
        }
        ++it;
    }
    if (it == values.end())
    {
        std::cout << "Not found!";
    }
    std::cout << '\n';

    // function
    std::cout << "By function: ";
    it = std::find_if(values.begin(), values.end(), hasSizeEqualToFour);
    std::cout << (it != values.end() ? *it : "Not found!") << '\n';

    // function object
    std::cout << "By function object: ";
    it = std::find_if(values.begin(), values.end(), HasSizeEqualTo(4));
    std::cout << (it != values.end() ? *it : "Not found!") << '\n';

    // lambda
    std::cout << "By lambda expression: ";
    it = std::find_if(values.begin(), values.end(), [](const std::string &x) { return x.size() == 4; });
    std::cout << (it != values.end() ? *it : "Not found!") << '\n';
}
