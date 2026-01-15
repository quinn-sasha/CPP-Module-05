#include "Intern.hpp"

#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

namespace {
AForm* makeShrubberyCreationForm(const std::string& target) {
  return new ShrubberyCreationForm(target);
}

AForm* makeRobotomyRequestForm(const std::string& target) {
  return new RobotomyRequestForm(target);
}

AForm* makePresidentialPardonForm(const std::string& target) {
  return new PresidentialPardonForm(target);
}
}  // namespace

// No need to implement
Intern::Intern() {}

// No need to implement
Intern::Intern(const Intern& /* other */) {}

// No need to implement
Intern& Intern::operator=(const Intern& /* other */) { return *this; }

// No need to implement
Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& form_title,
                        const std::string& form_target) const {
  typedef AForm* (*MakeFormFuncs)(const std::string&);
  MakeFormFuncs helper_functions[] = {&makeShrubberyCreationForm,
                                      &makeRobotomyRequestForm,
                                      &makePresidentialPardonForm};
  const std::string titles[] = {"shrubbery creation", "robotomy request",
                                "presidential pardon"};

  for (unsigned int i = 0; i < sizeof(titles) / sizeof(titles[0]); i++) {
    if (titles[i] == form_title) {
      return (helper_functions[i])(form_target);
    }
  }
  std::cerr << "Error: No such form \'" << form_title << "\' exists\n";
  return 0;
}
