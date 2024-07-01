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
/**
 * @brief a utility function
 */
void print(const std::vector<int> &data, const std::string &message = "")
{
    std::cout << message << ": ";
    std::copy(data.cbegin(), data.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

/**
 * @brief a function object used as sorting strategy - the odd values should be all before even values
 */
class OddFirst
{
  private:
    bool natural_;

  public:
    /**
     * @brief ctor
     * @param natural determine the sub-order for odd and even values
     */
    OddFirst(bool natural) : natural_{natural}
    {
        std::cout << "Odd first " << (natural_ ? "natural" : "inverse");
    }

    /**
     * @brief check left against right
     * @return true if both are even/odd, if left is less than right (and natural_ is true) otherwise if left is odd
     */
    bool operator()(int left, int right)
    {
        if (left % 2 == right % 2)
        {
            bool result = left < right;
            return natural_ ? result : !result;
        }
        else
        {
            return left % 2;
        }
    }
};
} // namespace

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
