/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * return by value
 */
#include <iostream>

/**
 * @brief Defining a function returning an int by value
 */
int solution(int left, int right)
{
    int result = left * right;
    std::cout << "The result calculated in solution() is " << result << '\n';
    return result;
}

int main()
{
    int value = solution(6, 7);

    std::cout << "The value returned in main() is " << value << '\n';
}
