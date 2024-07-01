/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * allocating objects on heap - raw pointers
 */
#include <cstdlib>
#include <ctime>
#include <iostream>

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
    char *pc = new char{'X'};
    std::cout << "A char on the heap: " << *pc << '\n';
    delete pc;

    // size for arrays
    srand(time(nullptr));
    const size_t c_size = rand() % 8 + 3;

    // when not initialized, no assumption could be done on array elements
    // sometimes the heap is "cleaned" by the environment at startup
    for (int i = 0; i < 2; ++i)
    {
        double *uninitialized = new double[c_size];
        std::cout << "An uninitialized array of double on the stack: ";
        print(uninitialized, c_size);
        std::fill(uninitialized, uninitialized + c_size, rand());
        delete[] uninitialized;
    }

    // an array on the heap with some elements explicitly initialized, the other ones are implicitly set to 0
    double *data = new double[c_size]{1.0, 2.0, 3.0};
    std::cout << "An initialized array of double on the heap: ";
    print(data, c_size);
    delete[] data;
}
