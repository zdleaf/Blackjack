Code tested and compiled on Debian WSL using g++ compiler version 4:8.3.0-1 as below. The code was entirely written using Virtual Studio Code with C++ plugin.

To compile code run the following command or equivilent in the root directory:
g++ src/*.cpp -I. -o main -std=c++11

then run with ./main

All .cpp files to be compiled are in /src and relevant header files in /include. No configuration is required.