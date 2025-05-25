# morse
A morse en-/descryption program made in C.

# Getting started
1. Doxygen, CMake and a valid compiler must be installed.
2. Before building, delete `build/`, otherwise there may be compatibility problems between UNIX and Windows.
3. Build the project:
```sh
mkdir build
cd build
cmake ..
cmake --build .
```
The build process may ask you to specify your compiler. For Windows, use `cmake -G "MinGW Makefile" ..` if needed.

On UNIX systems, `./morse -h` will show how the program is used. Windows will work a little different.

UNIX Example: `echo "hello world" | ./morse`
Windows Example: `echo hello world| morse.exe`