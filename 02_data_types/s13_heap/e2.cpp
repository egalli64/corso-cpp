/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * stack / heap
 */
#include <cstdlib>
#include <ctime>
#include <iostream>

namespace
{
constexpr int max_value = 6;

int die_cast()
{
    return rand() % max_value + 1;
}

double avg(int values[], int size)
{
    double result = 0;
    for (int i = 0; i < size; ++i)
    {
        result += values[i];
    }
    return result / size;
}
} // namespace

int main()
{
    srand(time(0));

    std::cout << "How many times? ";
    size_t c_size;
    std::cin >> c_size;

    if (c_size < 1 || c_size > 100'000'000)
    {
        std::cout << "Please, insert a reasonable value" << '\n';
        return 0;
    }

    // this array has a statically determined size, so it can be allocated on the stack
    constexpr size_t s_size = max_value * 2 + 1;
    int scores[s_size]{};

    // by the standard, an array of non-const size can't be stored in the stack
    int *casts = new int[c_size];
    for (size_t i = 0; i < c_size; ++i)
    {
        casts[i] = die_cast() + die_cast();
        scores[casts[i]] += 1;
        std::cout << casts[i] << ' ';
    }
    std::cout << "\n\nAverage: " << avg(casts, c_size) << '\n';

    // not used anymore
    delete[] casts;

    std::cout << "Distribution" << '\n';
    for (size_t i = 2; i < s_size; ++i)
    {
        std::cout << '[' << i << ": " << static_cast<double>(scores[i]) / c_size << ']';
    }
    std::cout << '\n';
}
