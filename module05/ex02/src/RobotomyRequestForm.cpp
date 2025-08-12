#include "../inc/RobotomyRequestForm.hpp"

bool RobotomyRequestForm::seeded = false;

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), target("default_target") {
  std::cout << BOLD << "Default RobotomyRequestForm Constructor called" << RESET
            << std::endl;
  seedRand();
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {
  std::cout << BOLD << "RobotomyRequestForm Constructor called" << RESET
            << std::endl;
  seedRand();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
    : AForm(src), target(src.getTarget()) {
  std::cout << BOLD << "RobotomyRequestForm Copy Constructor called" << RESET
            << std::endl;
  seedRand();
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << BOLD << "RobotomyRequestForm Destructor called" << RESET
            << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& src) {
  if (this != &src) {
    this->AForm::operator=(src);
    this->target = src.getTarget();
  }
  return *this;
}

const std::string& RobotomyRequestForm::getTarget() const {
  return this->target;
}

void RobotomyRequestForm::executeAction() const {
  std::cout << ITALIC << "* BZZZZT DRILL DRILL BZZZZT * " << RESET;
  if (std::rand() % 2 == 0)
    std::cout << GREEN << target << " has been robotomized" << RESET
              << std::endl;
  else
    std::cout << YELLOW << "Robotomy failed on " << target << RESET
              << std::endl;
}

// Static Function - shared between all instances. Only seeds once
void RobotomyRequestForm::seedRand() {
  if (!seeded) {
    std::srand(std::time(0));
    seeded = true;
  }
}
