/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * catch all
 */
#include <iostream>
using namespace std;

namespace
{
void risky_1()
{
    throw "Not yet implemented";
}

void risky_2()
{
    throw 1;
}

void risky_3()
{
    throw 42.24;
}
} // namespace

int main()
{
    try
    {
        risky_1();
        risky_2();
        risky_3();
    }
    catch (int ex)
    {
        cout << "An int exception: " << ex << "\n";
    }
    catch (double ex)
    {
        cout << "A double exceptiion: " << ex << "\n";
    }
    catch (...)
    {
        cout << "Something went wrong\n";
    }

    cout << "Bye\n";
}
