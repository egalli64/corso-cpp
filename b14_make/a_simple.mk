##
# Corso C++ https://github.com/egalli64/corso-cpp
#
# A simple makefile: make -f <filename> <target>
#

# the first target is the default one
# it is traditional to have an "all" target that just forward to the main target

all: hello

# a target with its dependencies, cpp files and includes (other target could be placed here)
# notice a TAB on the second line, providing the recipe to build hello up
hello: main.cpp other.cpp other.h sub/another.cpp sub/another.h
	g++ -o hello main.cpp other.cpp sub/another.cpp

# clean up target, remove executable and object files
clean:
	rm -rf hello *.o sub/*.o
