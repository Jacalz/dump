#include <iostream>
#include <istream>
#include <fstream>

#include "commands.h"
  
int main(int argc, char** argv){
    if (argc > 2) {
        std::cerr << "Invalid number of arguments.\n" 
        << "Pass none will read from stdin and passing one will read from the provided file" << std::endl;
        return 1;
    }

    CommandParser parser;

    // Check if we should read commands from a file.
    if (argc == 2) {
        std::ifstream file(argv[1]);
        if (!file.is_open()) {
            std::cerr << "Could not open file. Please check supplied file path." << std::endl;
            return 1;
        }

       parser.parse(file);
       file.close();
       return 0;
    }
    
    parser.parse(std::cin);
}