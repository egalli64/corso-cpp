#include <iostream>
using namespace std;

int main() {
    cout << "\nConstants\n\n";
    // evaluated at compile time
    constexpr auto x = 18;

    // error!
    // x += 1;

    // won't change
    const auto y = 42;
    //	y += 1; // error!

    cout << "x = " << x << '\n';
    cout << "y = " << y << '\n';

    // simple enumeration
    enum { ALPHA, BETA = 28 };

    cout << "ALPHA is " << ALPHA << " and BETA is " << BETA << '\n';

    // improved enumeration - scoped and strongly typed
    enum class GreekLetter { ALPHA = 42, BETA };
    cout << "ALPHA is " << static_cast<int>(GreekLetter::ALPHA);
    cout << " and BETA is " << static_cast<int>(GreekLetter::BETA) << '\n';

    enum class WeekendDay : bool { SAT, SUN };
    cout << "SAT is " << static_cast<int>(WeekendDay::SAT);
    cout << " and SUN is " << static_cast<int>(WeekendDay::SUN) << '\n';
}
