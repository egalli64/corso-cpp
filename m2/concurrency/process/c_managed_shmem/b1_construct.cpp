/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * c++ -Wall b1_construct.cpp -lrt -pthread -o b1.exe
 */
#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>

namespace bi = boost::interprocess;

namespace
{
const char *SHMEM_NAME = "MySharedMemory";
const int SHMEM_SIZE = 1'024;

const char *COUNTER_NAME = "MyCounter";
const char *AMOUNT_NAME = "MyAmount";
const char *VALUES_NAME = "MyValues";
} // namespace

int main()
{
    // ensure shared memory is not already set
    bi::shared_memory_object::remove(SHMEM_NAME);

    // instead of create_only the less restrictive open_or_create could be used
    bi::managed_shared_memory msm{bi::create_only, SHMEM_NAME, SHMEM_SIZE};

    int *pCounter = msm.construct<int>(COUNTER_NAME)(42);
    std::cout << COUNTER_NAME << " placed in shared memory: " << *pCounter << '\n';

    double *pAmount = msm.construct<double>(AMOUNT_NAME)(42.24);
    std::cout << AMOUNT_NAME << " placed in shared memory: " << *pAmount << '\n';

    double *pValues = msm.construct<double>(VALUES_NAME)[10]();
    // set just the last value
    pValues[9] = *pAmount / 3;
    std::cout << VALUES_NAME << " placed in shared memory: ";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << ' ' << pValues[i];
    }
    std::cout << '\n';

    try
    {
        msm.construct<double>("TooBig")[SHMEM_SIZE * 2]();
    }
    catch (bi::bad_alloc &ex)
    {
        std::cout << "Out of memory in the shared memory -> " << ex.what() << '\n';
    }
}
