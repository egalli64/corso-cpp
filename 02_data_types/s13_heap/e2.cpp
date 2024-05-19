/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * stack / heap
 */
#include <cstdlib>
#include <ctime>
#include <iostream>

const int MAX_VALUE{6};

namespace
{
int dieCast()
{
    return rand() % MAX_VALUE + 1;
}

double avg(int *values, int size)
{
    double result = 0;
    for (int i{0}; i < size; ++i)
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
    int size;
    std::cin >> size;

    if (size < 1 || size > 100'000'000)
    {
        std::cout << "Please, insert a reasonable value" << '\n';
        return 0;
    }

    int scores[MAX_VALUE * 2 + 1]{};
    int *casts{new int[size]};
    for (int i = 0; i < size; ++i)
    {
        casts[i] = dieCast() + dieCast();
        scores[casts[i]] += 1;
        std::cout << casts[i] << ' ';
    }
    std::cout << "\n\nAverage: " << avg(casts, size) << '\n';

    // not used anymore
    delete[] casts;

    std::cout << "Distribution" << '\n';
    for (int i{2}; i < MAX_VALUE * 2 + 1; ++i)
    {
        std::cout << '[' << i << ": " << static_cast<double>(scores[i]) / size << ']';
    }
    std::cout << '\n';
}
