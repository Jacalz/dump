#ifndef _commands_h
#define _commands_h

#include <iostream>
#include <string>

#include "calculator.h"

// CommandParser parses given commands before passing down to calculator.
class CommandParser {
    private:
        // The calculator to use for evaluating register values.
        Calculator calc;

    public:
        // Parse starts the parsing of commands.
        void parse(std::istream& input);
};

#endif