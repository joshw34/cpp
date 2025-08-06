#include "../inc/ScalarConverter.hpp"

void (*const ScalarConverter::printResult[5])() = {
    &fromChar, &fromPseudo, &fromFloat, &fromDouble, &fromInt
};

void ScalarConverter::fromChar() {
    if (!charError(c_val))
        std::cout << "char: \'" << c_val << "\'\n";
    std::cout << "int: " << static_cast<int>(c_val) << "\n"
              << "float: " << static_cast<float>(c_val) << "f\n"
              << "double: " << static_cast<double>(c_val) << std::endl;
}

void ScalarConverter::fromPseudo() {
    std::cout << "char: impossible\n"
              << "int: impossible\n"
              << "float: " << static_cast<float>(p_val) << "f\n"
              << "double: " << p_val << std::endl;
}

void ScalarConverter::fromInt() {
    if (!charError(i_val))
        std::cout << "char: \'" << static_cast<char>(i_val) << "\'\n";
    std::cout << "int: " << i_val << "\n"
              << "float: " << static_cast<float>(i_val) << "f\n"
              << "double: " << static_cast<double>(i_val) << std::endl;
}

void ScalarConverter::fromFloat() {
    if (!charError(f_val))
        std::cout << "char: \'" << static_cast<char>(f_val) << "\'\n";
    if (!intError(f_val))
        std::cout << "int: " << static_cast<int>(f_val) << "\n";
    std::cout << "float: " << f_val << "f\n"
              << "double: " << static_cast<double>(f_val) << std::endl;
}

void ScalarConverter::fromDouble() {
    if (!charError(d_val))
        std::cout << "char: \'" << static_cast<char>(d_val) << "\'\n";
    if (!intError(d_val))
        std::cout << "int: " << static_cast<int>(d_val) << "\n";
    if (!floatError(d_val))
        std::cout << "float: " << static_cast<float>(d_val) << "f\n";
    std::cout << "double: " << d_val << std::endl;
}

bool ScalarConverter::charError(const double value) {
    if (value < 0 || value > 127) {
        std::cout << "char: impossible\n";
        return true;
    }
    if (std::isprint(static_cast<int>(value)) == 0) {
        std::cout << "char: Non Displayable\n";
        return true;
    }
    return false;
}

bool ScalarConverter::intError(const double value) {
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible\n";
        return true;
    }
    return false;
}

bool ScalarConverter::floatError(const double value) {
    if (std::isnan(value) || std::isinf(value))
        return false;
    if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible\n";
        return true;
    }
    return false;
}

