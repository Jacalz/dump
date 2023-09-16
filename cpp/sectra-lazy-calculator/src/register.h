#ifndef _register_h
#define _register_h

#include <vector>
#include <string>

class Register {
    private:
        // Keeps track of the register is in progress of evaluation.
        bool in_progress;
        
        // Expressions to be lazily evaluated on print.
        std::vector<std::vector<std::string>> expressions;
    public:
        // Returns constant reference to the expressions slice.
        // Intended for iterating through.
        const std::vector<std::vector<std::string>>& get_expressions() const;

        // Add a new operation to the register.
        void add(std::vector<std::string> operations);

        // Sets the register evaluation progress to a new value.
        void set_in_progress(const bool progress);

        // Returns true if the register already is in progress.
        bool is_in_progress() const;
};

#endif