/*
 * Corso C++ https://github.com/egalli64/corso-cpp
 *
 * c++ -Wall b3_write.cpp -lrt -o b3.exe
 */
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <cstring>
#include <iostream>

namespace bi = boost::interprocess;

namespace
{
const char *SHMEM_NAME = "MySharedMemory";
}

int main()
{
    try
    {
        bi::shared_memory_object smo{bi::open_only, SHMEM_NAME, bi::read_write};
        bi::mapped_region region{smo, bi::read_write};
        char *data = static_cast<char *>(region.get_address());
        strcpy(data, "Hello Shared Memory!");
        std::cout << "Message written to " << SHMEM_NAME << '\n';
    }
    catch (bi::interprocess_exception &ex)
    {
        std::cout << "Can't open shared memory: " << ex.what() << '\n';
    }
}
