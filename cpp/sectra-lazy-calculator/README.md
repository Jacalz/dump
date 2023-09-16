# Lazily Evaluated Calculator

Lazily evaluated calculator is a calculator that evaluates commands before printing.

## Adding a new operation

The architecture of the application has been set up to make it easy to swap out or add new operators.
All the operators are added to an `unordered_map` mapping an operator name to a given function.

Adding a new operation is as simple as upating the constructor of `Calculator` in `calculator.cpp` with a new operator.
The rest of the code will then be able to use the new operator without any other modifications. See example below:

```c++
Calculator::Calculator() {
    // Set up the map of operators using lambdas.
    operators = {
        // Operator for regular addition.
        {"add",
        [](int previous, int diff) -> int {
            return previous + diff;
        }},

        // Operator for regular subtraction.
        {"subtract",
        [](int previous, int diff) -> int {
            return previous - diff;
        }},

        // Operator for regular multiplication.
        {"multiply",
        [](int previous, int diff) -> int {
            return previous * diff;
        }},
    };
}
```

## Compilation

The project can be compiled using the following command:  

```
g++ src/main.cpp src/commands.cpp src/calculator.cpp src/register.cpp -o calculator -g
```

It is also possible compile using `make` if it is installed on the computer (mostly on Linux):

```
make
```

This will build a binary called `calculator` here in the project root.

## Running

The project can be run by executing the following command:

```
./calculator
```

It is also posssible to use the `make` command if installed (this will also recompile the binary first):
```
make run
```

## Debugging

The project can be debugged by running the compiled binary using `gdb`.
This is simple to do by running the following command:

```
make gdb
```