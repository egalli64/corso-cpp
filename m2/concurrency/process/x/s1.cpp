/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 */
#include <iostream>
#include <signal.h>
#include <unistd.h>

using namespace std;

static int my_internal_status = 0;

void signal_manager(int id)
{
    switch (id)
    {
    case SIGUSR1:
        cout << "SIGUSR1 trapped\n";
        my_internal_status += 1;
        break;
    case SIGUSR2:
        cout << "SIGUSR2 trapped\n";
        my_internal_status += 2;
        break;
    default:
        cout << "signal " << id << " was not expected!\n";
        break;
    }
}

int main()
{
    if (signal(SIGUSR1, signal_manager) == SIG_ERR)
    {
        cout << "Can't manage SIGUSR1!\n";
        return 1;
    }
    if (signal(SIGUSR2, signal_manager) == SIG_ERR)
    {
        cout << "Can't manage SIGUSR1!\n";
        return 1;
    }

    cout << "\nSIGINT (" << SIGINT << ") is for terminal interrupt character\n";
    cout << "SIGUSR1 and SIGUSR2 (" << SIGUSR1 << ", " << SIGUSR2
         << ") are for user-defined signals, by default terminate the app, here are trapped\n";

    while (true)
    {
        pause();
        cout << "\nA signal awakened the process, status is " << my_internal_status << '\n';
    }
}
