#include "../inc/ScalarConverter.hpp"

void ScalarConverter::printConverted() {
    std::cout << std::fixed << std::setprecision(1);
    fromChar();
    fromPseudo();
    fromInt();
    std::cout << std::endl;
}

void ScalarConverter::fromChar() {
    std::cout << "char: '";
    if (isprint(c_val) != 0)
        std::cout << c_val << "\n";
    else
        std::cout << "Non Displayable\n";
    std::cout << "int: " << static_cast<int>(c_val) << "\n";
    std::cout << "float: " << static_cast<float>(c_val) << "\n";
    std::cout << "double: " << static_cast<double>(c_val);
}

void ScalarConverter::fromPseudo() {
    std::cout << "char: impossible\nint: impossible\n";
    if (p_val == '+') {
        std::cout << "float: +" << std::numeric_limits<float>::infinity() << "f\n";
        std::cout << "double: +" << std::numeric_limits<double>::infinity();
    }
    else if (p_val == '-') {
        std::cout << "float: " << -std::numeric_limits<float>::infinity() << "f\n";
        std::cout << "double: " << -std::numeric_limits<double>::infinity();
    }
    else {
        std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f\n";
        std::cout << "double: " << std::numeric_limits<double>::quiet_NaN();
    }
}

void ScalarConverter::fromInt() {
    std::cout << "char: ";
    if (i_val >= 0 && i_val <= 127 && isprint(i_val))
        std::cout << static_cast<char>(i_val) << "\n";
    else if (i_val >= 0 && i_val <= 127)
        std::cout << "Non Displayable\n";
    else
        std::cout << "impossible\n";
    std::cout << "int: " << i_val << "\n";
    std::cout << "float: " << static_cast<float>(i_val) << "\n";
    std::cout << "double: " << static_cast<double>(i_val);
}
