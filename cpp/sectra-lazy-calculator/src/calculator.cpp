#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>

#include "calculator.h"
#include "register.h"

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

void Calculator::add_command(const std::string &command) {
    auto arguments = split_on_space(command);
    if (arguments.size() == 1 || arguments.size() > 3) {
        std::cerr << "Invalid number of command arguments: " << arguments.size() << std::endl;
        return;
    }

    if (arguments[0] == "print") {
        print(arguments[1]);
        return;
    }

    // Check for valid register so we can insert the register in the right place.
    if (!is_valid_name(arguments[0])) {
        std::cerr << "Invalid register name: " << arguments[0] << std::endl;
        return;
    }

    const auto without_name = std::vector<std::string>(arguments.cbegin()+1, arguments.cend());
    registers[arguments[0]].add(without_name);
}

void Calculator::print(const std::string& target) {
    if (!is_valid_name(target)) {
            std::cerr << "Invalid register name: " << target << std::endl;
            return;
        }

        if (!is_number(target) && !contains(target)) {
            std::cerr << "Register does not exist: " << target << std::endl;
            return;
        }

        std::cout << evaluate(target) << std::endl;
}

int Calculator::evaluate(const std::string& name) {
    // We want to return the value if it is not a register.
    if (is_number(name)) {
        return std::atoi(name.c_str());
    }
    
    // Check that we don't re-evaluate indefinatelly.
    if (registers[name].is_in_progress()) {
        std::cerr << "Register values depend on each other. Bailing." << std::endl;
        return 0;
    }
    
    // Set register to being in progress. Avoid infinite cycle of recursion. 
    registers[name].set_in_progress(true);

    int result = 0;
    
    for (const auto& args : registers[name].get_expressions()) {
        if (operators.find(args[0]) == operators.end()) {
            std::cerr << "Ignoring invalid command: " << args[0] << std::endl;
            continue;
        }

        // Call the corresponding function for the given operator.
        result = operators[args[0]](result, evaluate(args[1]));
    }

    // Reset status of being in progress.
    // Can be re-evaluated again if necessary.
    registers[name].set_in_progress(false);

    return result;
}

bool Calculator::contains(const std::string& name) const {
    return registers.find(name) != registers.end();
}

std::vector<std::string> split_on_space(const std::string& text) {
    std::vector<std::string> output;
    output.reserve(3);

    int start = 0, end = 0;
    while ((start = text.find_first_not_of(' ', end)) != std::string::npos) {
        end = text.find(' ', start);
        output.push_back(text.substr(start, end - start));
    }

    return output;
}

bool is_valid_name(const std::string& register_name) {
    for (const char letter : register_name) {
        if ((letter < 'a' || letter > 'z') && (letter < '0' || letter > '9')) {
            return false;
        }
    }

    return true;
}

bool is_number(const std::string& str) {
    for (char const c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}