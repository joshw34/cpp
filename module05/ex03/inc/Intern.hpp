#pragma once

#include "Colors.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern {
    public:
        Intern();
        Intern(const Intern& src);
        ~Intern();

        Intern& operator=(const Intern& src);

        AForm* makeForm(const std::string& formName, const std::string& target);
};
