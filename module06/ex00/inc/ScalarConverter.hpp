#pragma once

#include "Colors.hpp" // IWYU pragma: keep
#include <string>
#include <iostream> // IWYU pragma: keep
#include <exception>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cerrno>
#include <cctype>
#include <iomanip> // IWYU pragma: keep
#include <limits> // IWYU pragma: keep

class ScalarConverter {
    public:
        static void convert(const std::string&);

        class InvalidType : public std::exception {
            public:
                const char* what() const throw();
        };

        class Overflow : public std::exception {
            public:
                const char* what() const throw();
        };

    private:
        ScalarConverter();

        static int input_type;
    
        static char c_val;
        static double p_val;
        static float f_val;
        static double d_val;
        static int i_val;

        enum types {
            CHAR,
            PSEUDO,
            FLOAT,
            DOUBLE,
            INT,
        };

        static const std::string pseudo_types[6];

        // ScalarConverter_getType.cpp
        static void getInputType(const std::string&);
        static bool isChar(const std::string&); 
        static bool isPseudo(const std::string&);
        static bool isFloat(const std::string&);
        static bool isDouble(const std::string&);
        static bool isInt(const std::string&);
        static bool (*const checks[5])(const std::string&);
        static void getDecPrecision(const std::string&);
        static bool isNumberType(const std::string&);
        static void setPseudoValue(const std::string&);
        static size_t countChar(const std::string&, const char c);

        // ScalarConverter_print.cpp
        static void fromChar();
        static void fromPseudo();
        static void fromFloat();
        static void fromDouble();
        static void fromInt();
        static void (*const printResult[5])();
        static bool charError(const double value);
        static bool intError(const double value);
        static bool floatError(const double value);

};
