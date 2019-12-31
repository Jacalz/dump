# Project Dump
A repository housing various samller projects that are too small for their own repo. Projects made in Go will still be found at [go-projects](https://github.com/Jacalz/go-projects), but projects in other languages may be found here.

## Compiling C++ Code
All C++ Code is written to comply with the latest stable specification for C++, which at the moment is C++17.
The below command can be used to compile the source files in to fast native binaries:
```bash
g++ -std=c++17 main.cpp -o output -O2 -march=native
```
