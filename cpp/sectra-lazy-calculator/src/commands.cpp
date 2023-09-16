#include <cctype>
#include <iostream>
#include <string>
#include <algorithm>

#include "commands.h"

void CommandParser::parse(std::istream& input) {
    std::string line;
    while (std::getline(input, line)) {
        // Transform the line to lower case characters to be case insensitive.
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);

        // Handle the quit command before passing to calculator.
        if (line == "quit") {
            return;
        }

        // Inform the calculator about the new command.
        calc.add_command(line);
    } 
}


