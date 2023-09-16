#ifndef _calculator_h
#define _calculator_h

#include <unordered_map>
#include <functional>
#include <string>
#include <vector>

#include "register.h"

// Calculator evaluates commands.
class Calculator {
    private:
        // Registers holds the register data to be lazily evaluated.
        std::unordered_map<std::string, Register> registers;

        // Check if the register map contains a specific value.
        // Would have been unnecessary if C++17 was default version.
        bool contains(const std::string& name) const;

        // Executes the print command for the given input string.
        void print(const std::string& target);

        // Evaluate a specific register and update it's contents.
        int evaluate(const std::string& name);

        // The operators and their corresponding function to do the calculation.
        std::unordered_map<std::string, std::function<int(int, int)>> operators;
    public:
        // Creates a new instance with all operators correctly set up.
        Calculator();

        // Adds a new command to the calculator.
        void add_command(const std::string& command);
};

// Splits a string into a vector of substrings separated by spaces.
std::vector<std::string> split_on_space(const std::string& command);

// Returns true if the string is a valid register name.
// A valid register name contains only alphanumerical characters.
bool is_valid_name(const std::string& register_name);

// Returns true if the string is a numbers; false otherwise.
bool is_number(const std::string& str);

#endif