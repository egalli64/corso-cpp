/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 */
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    if (fork() == 0)
    {
        std::cout << "Child @work\n";
        sleep(1);
        std::cout << "Child job done\n";
        return EXIT_SUCCESS;
    }

    // Only the parent here
    std::cout << "The parent has spawned its child\n";
    int status;
    pid_t pid = wait(&status);

    std::cout << "Child ID " << pid << " has terminated with status " << status << '\n';
}
