/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * allocating objects on stack
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

namespace
{
/**
 * @brief a utility function
 */
void print(const double array[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}
} // namespace

int main()
{
    char c = 'X';
    std::cout << "A char on the stack: " << c << '\n';

    // size for arrays
    constexpr int c_size = 6;

    // when not initialized, no assumption could be done on array elements
    double uninitialized[c_size];
    std::cout << "An uninitialized array of double on the stack: ";
    print(uninitialized, c_size);

    // create an int array on the stack
    // some elements explicitly initialized, the other ones are implicitly initialized to 0
    double data[c_size]{1.0, 2.0, 3.0};
    std::cout << "An initialized array of double on the stack: ";
    print(data, c_size);

#ifdef __GNUC__
    // this works for GCC, but it is not standard C++!
    srand(time(nullptr));
    int size = rand() % c_size;
#else
    constexpr int size = 5;
#endif
    std::cout << "A zero-initialized array on the stack sized " << size << ": ";

    // all implicitly initialized to 0
    double zeroes[size]{};
    print(zeroes, size);
}
