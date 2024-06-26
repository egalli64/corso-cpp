/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * No need of std::ref(), std::cref() on function object
 *
 * g++ -pthread -Wall -o a.out e4b_ref_fob.cpp
 */
#include <functional>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

namespace
{
class Adder
{
  private:
    const std::vector<int> &values_;
    int &result_;

  public:
    Adder(const std::vector<int> &values, int &result) : values_(values), result_(result)
    {
    }
    void operator()() const
    {
        result_ = std::accumulate(values_.begin(), values_.end(), 0);
    }
};
} // namespace

int main()
{
    const std::vector<int> values{1, 2, 3, 4, 5, 6};
    int result;

    std::thread t{Adder(values, result)};
    t.join();

    std::cout << "Sum is " << result << '\n';
}
