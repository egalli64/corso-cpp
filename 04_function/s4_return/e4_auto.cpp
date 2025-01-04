/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * return - auto
 */
#include <iostream>

/**
 * @brief [BAD!] Using auto here makes the code a bit less readable 
 */
auto solution(int left, int right)
{
    auto result = left * right;
    std::cout << "The result calculated in solution() is " << result << '\n';
    return result;
}

int main()
{
    auto value = solution(6, 7);

    std::cout << "The value returned in main() is " << value << '\n';
}
