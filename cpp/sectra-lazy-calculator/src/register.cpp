#include <vector>
#include <string>

#include "register.h"

void Register::add(std::vector<std::string> operations) {
    expressions.push_back(operations);
}

void Register::set_in_progress(const bool progress) {
    in_progress = progress;
}

bool Register::is_in_progress() const {
    return in_progress;
}

const std::vector<std::vector<std::string>>& Register::get_expressions() const {
    return expressions;
}