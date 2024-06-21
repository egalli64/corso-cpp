/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * SL algorithm: find_if by function object
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace
{
class HasSizeEqualTo
{
  private:
    const size_t size_;

  public:
    HasSizeEqualTo(const int size) : size_(size)
    {
    }

    bool operator()(const std::string &s) const
    {
        return s.size() == size_;
    }
};
} // namespace

int main()
{
    std::vector<std::string> values{"Tom", "Kim", "Tony", "Liza"};

    std::cout << "Find first string sized 4: ";
    if (auto it = find_if(values.begin(), values.end(), HasSizeEqualTo(4)); it != values.end())
    {
        std::cout << *it << '\n';
    }
    else
    {
        std::cout << "unexpected\n";
    }
}
