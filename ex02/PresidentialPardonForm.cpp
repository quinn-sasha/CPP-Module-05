#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon", 25, 5), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon", 25, 5), target_("unknown") {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm("Presidential Pardon", 25, 5), target_(other.target_) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
  if (this == &other) {
    return *this;
  }
  target_ = other.target_;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {};

void PresidentialPardonForm::executeAction() const {
  std::cout << "(Trump) You are free now. God bless America!\n";
}
