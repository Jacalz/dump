# Project Dump
A repository housing various samller projects that are too small for their own repo. Projects made in Go will still be found at [go-projects](https://github.com/Jacalz/go-projects), but projects in other languages may be found here.

## Compiling and running

### Compiling C++ Code
All C++ Code is written to comply with the latest stable specification for C++, which at the moment is C++17.

The below command can be used to compile the source files in to fast native binaries:
```bash
g++ -std=c++17 main.cpp -o output -O2 -march=native
```

### Compiling C Code
All the C code inside this repository is written to comply with the latests C standard specification, which for now is C11.

The below command can be used to compile the source files in to fast native binaries:
```bash
gcc -std=c11 -lm main.c -o output -O2 -march=native
```

### Running Python code
All python code should be compatible with the latest python releases. It can be run by using the following command:
```bash
python3 main.py
```

## License
All code in this repository is written by [Jacalz](https://github.com/Jacalz) and licensed under GPL-v3.0-or-later.
