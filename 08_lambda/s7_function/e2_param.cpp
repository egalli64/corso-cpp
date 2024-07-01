/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * HOF with a std::function param
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

namespace my
{
/**
 * @brief a non-template HOF
 * @param begin iterator to the first element to work on
 * @param end iterator to the last plus one element to work on
 * @param lambda the lambda that should operate on the elements in the passed interval
 */
void for_each_vi(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::function<void(int)> &&lambda)
{
    for (auto it = begin; it != end; ++it)
    {
        lambda(*it);
    }
}

/**
 * @brief a template HOF
 * @param begin iterator to the first element to work on
 * @param end iterator to the last plus one element to work on
 * @param lambda the lambda that should operate on the elements in the passed interval
 */
template <typename T, typename F> void for_each(T begin, T end, F&& lambda)
{
    for (auto it = begin; it != end; ++it)
    {
        lambda(*it);
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
