/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * Private memory shared between child (client) and parent (server)
 */
#include <cstring>
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

namespace
{
const int SHM_SEGMENT_SIZE = 1'024;
void *attachedMemory = nullptr;
} // namespace

int main()
{
    std::cout << "The parent creates a private shm segment\n";
    int shmid = shmget(IPC_PRIVATE, SHM_SEGMENT_SIZE, 0644 | IPC_CREAT);
    if (shmid == -1)
    {
        std::cerr << "Can't get shared memory\n";
        return EXIT_FAILURE;
    }

    // attach the shared memory segment to the address space, read/write
    attachedMemory = shmat(shmid, nullptr, 0);
    if (attachedMemory == (void *)-1)
    {
        std::cerr << "Can't attach to shared memory\n";
        return EXIT_FAILURE;
    }
    else
    { // data transfer
        char *pSharedSegment = static_cast<char *>(attachedMemory);
        strcpy(pSharedSegment, "welcome back!");
    }

    if (fork() == 0)
    {
        std::cout << "Child @work\n";
        sleep(1);

        const char *pSharedSegment = static_cast<const char *>(attachedMemory);
        std::cout << "Message read from parent: " << pSharedSegment << '\n';

        return EXIT_SUCCESS;
    }

    std::cout << "The parent has spawned its child\n";
    int status;
    pid_t pid = wait(&status);
    std::cout << "Child id " << pid << " has terminated with status " << status << '\n';

    if (shmdt(attachedMemory) == -1)
    {
        std::cerr << "Can't detach the shared memory segment\n";
    }
    if (shmctl(shmid, IPC_RMID, nullptr) == -1)
    {
        std::cerr << "Can't remove the shared memory segment\n";
    }
}
