/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * sort as higher order function
 * function object as first class variable
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

namespace
{
void print(const std::vector<int> &data, const std::string &message = "")
{
    std::cout << message << ": ";
    std::copy(data.cbegin(), data.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}
} // namespace

class OddFirst
{
  private:
    bool natural_;

  public:
    OddFirst(bool natural) : natural_(natural)
    {
        std::cout << "Odd first " << (natural_ ? "natural" : "inverse");
    }

    bool operator()(int left, int right)
    {
        // if both even or odd
        if (!(left % 2 ^ right % 2))
        {
            bool result = left < right;
            return natural_ ? result : !result;
        }
        return left % 2;
    }
};

int main()
{
    std::vector<int> data{34, 12, 3, 8, 5, 43};
    print(data, "original data");

    // odd first natural
    std::sort(data.begin(), data.end(), OddFirst(true));
    print(data);

    // odd first inverted
    std::sort(data.begin(), data.end(), OddFirst(false));
    print(data);
}
