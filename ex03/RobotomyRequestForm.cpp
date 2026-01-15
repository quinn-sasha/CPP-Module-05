#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request", 72, 45), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request", 72, 45), target_("unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm("Robotomy Request", 72, 45), target_(other.target_) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
  if (this == &other) {
    return *this;
  }
  target_ = other.target_;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {};

// Need to call srand() in main()
void RobotomyRequestForm::executeAction() const {
  std::cout << "Bzzzzzzz!! (drilling noises)\n";
  if (rand() % 2 == 0) {
    std::cout << "Wow! succeeded!\n";
  } else {
    std::cout << "Sorry... it failed\n";
  }
}
