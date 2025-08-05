#include "../inc/ScalarConverter.hpp"

bool (*const ScalarConverter::checks[5])(const std::string&) = {
    &isChar, &isPseudo, &isFloat, &isDouble, &isInt
};

// Checks are ordered to avoid redundant checks and catch invalid input early
void ScalarConverter::getType(const std::string& input) {
    for (size_t i = 0; i < 5; i++) {
        if (checks[i](input)) {
            input_type = i;
            return;
        }
    }
    throw InvalidType();
}

// Simplest case, checked first
bool ScalarConverter::isChar(const std::string& input) {
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        c_val = input[1];
        return true;
    }
    return false;
}

// input can be anything other than '<char>' 
bool ScalarConverter::isPseudo(const std::string& input) {
    if (input.find_first_of("+-", 1) != input.npos)
        throw InvalidType();
    if (input.find_first_not_of("-+naiff") != input.npos)
        return false;
    for (size_t i = 0; i < 6; i++) {
        if (input.compare(pseudo_types[i]) == 0) {
            p_val = pseudo_types[i].at(0);
            return true;
        }
    }
    return false;
}

// input can be: (1 + or -)+anything not accepted by previous checks
bool ScalarConverter::isFloat(const std::string& input) {
    if (!isNumberType(input))
        throw InvalidType();
    if (input.at(input.length() - 1) != 'f')
        return false;
    std::string test = input.substr(0, input.length() - 1);
    errno = 0;
    f_val = strtof(test.c_str(), NULL);
    if (errno == ERANGE)
        throw Overflow();
    return true;
}

// input can be (1 + or -)+digits+(1 .) 
bool ScalarConverter::isDouble(const std::string& input) {
    if (input.find_first_of(".") == input.npos)
        return false;
    errno = 0;
    d_val = strtod(input.c_str(), NULL);
    if (errno == ERANGE)
        throw Overflow();
    return true;
}

// input can be: (1 + or -)+digits
bool ScalarConverter::isInt(const std::string& input) {
    errno = 0;
    long test = strtol(input.c_str(), NULL, 10);
    if (errno == ERANGE || test < INT_MIN || test > INT_MAX)
        throw Overflow();
    i_val = atoi(input.c_str());
    return true;
}

bool ScalarConverter::isNumberType(const std::string& input) {
    if (input.find_first_of("1234567890") == input.npos)
        return false;
    if (input.find_first_not_of("1234567890.f+-") != input.npos)
        return false;
    if (countChar(input, '.') > 1 || countChar(input, 'f') > 1)
        return false;
    if (countChar(input, 'f') == 1 && input.at(input.length() - 1) != 'f')
        return false;
    return true;
}

size_t ScalarConverter::countChar(const std::string& input, const char c) {
    size_t count = 0;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == c)
            count++;
    }
    return count;
}

