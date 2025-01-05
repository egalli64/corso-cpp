#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

int main()
{
    // given a map
    std::map<std::string, int> values{{"tom", 42}, {"bob", 34}};

    // 1) print each value in it
    std::for_each(values.begin(), values.end(), [](const auto &x) { std::cout << x.second << '\n'; });

    // 2) get the sum of each value in it
    int result = std::accumulate(values.begin(), values.end(), 0, //
                                 [](int sum, const auto &x) { return sum + x.second; });
    std::cout << result << '\n';

    // 2) alternative
    std::vector<int> buffer;
    // std::for_each(values.begin(), values.end(), [&buffer](const auto &x) { buffer.push_back(x.second); });

    for (const auto &x : values)
    {
        buffer.push_back(x.second);
    }
    std::cout << std::accumulate(buffer.begin(), buffer.end(), 0) << '\n';
}