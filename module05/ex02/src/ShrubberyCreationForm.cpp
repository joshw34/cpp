#include "../inc/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default_target") {
    std::cout << BOLD << "Default ShrubberyCreationForm Constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
    std::cout << BOLD << "ShrubberyCreationForm Constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), target(src.getTarget()) {
    std::cout << BOLD << "ShrubberyCreationForm Copy Constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << BOLD << "ShrubberyCreationForm Destructor called" << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src) {
    if (this != &src) {
        this->AForm::operator=(src);
        this->target = src.getTarget();
    }
    return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const {
    return this->target;
}

void ShrubberyCreationForm::executeAction() const{
    std::string filename = target + "_shrubbery";
    std::ofstream output_file(filename.c_str());

    if (!output_file.is_open())
        throw FileOpenException();

    printTrees(output_file);

    output_file.close();
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
    return "Error: Could not create output file";
}

void ShrubberyCreationForm::printTrees(std::ofstream& output_file) const {
    output_file << "            ,@@@@@@@,                             ,@@@@@@@,                 " << "\n"
                << "    ,,,.   ,@@@@@@/@@,  .oo8888o.         ,,,.   ,@@@@@@/@@,  .oo8888o.     " << "\n"
                << " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o   " << "\n"
                << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88',%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << "\n"
                << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' " << "\n"
                << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'  " << "\n"
                << "`&%\\ ` /%&'    |.|        \\ '|8'    `&%\\ ` /%&'    |.|        \\ '|8'    " << "\n"
                << "    |o|        | |         | |            |o|        | |         | |        " << "\n"
                << "    |.|        | |         | |            |.|        | |         | |        " << "\n"
                << " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.     \\\\/ ._\\//_/__/  ,\\_//__\\\\/.    " << std::endl;
}
