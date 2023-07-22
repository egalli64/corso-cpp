/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * A HOF with a std::function param
 */
#include <functional>
#include <iostream>
#include <vector>

namespace my
{
void for_each_vi(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end, std::function<void(int)> f)
{
    for (auto it = begin; it != end; ++it)
    {
        f(*it);
    }
}

template <typename T, typename F> void for_each(const T &begin, const T &end, F f)
{
    for (auto it = begin; it != end; ++it)
    {
        f(*it);
    }
}
} // namespace my

int main()
{
    std::vector<int> data{3, 6, 2, 8};
    std::for_each(data.begin(), data.end(), [](int x) { std::cout << x << ' '; });
    std::cout << '\n';
    my::for_each(data.begin(), data.end(), [](int x) { std::cout << x << ' '; });
    std::cout << '\n';
    my::for_each_vi(data.begin(), data.end(), [](int x) { std::cout << x << ' '; });
    std::cout << '\n';
}
