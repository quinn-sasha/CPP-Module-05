#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  std::srand(std::time(NULL));  // For executing robotomy form

  Bureaucrat himiko("Himiko", 2);
  Bureaucrat tanaka("Tanaka Tarou", 100);

  ShrubberyCreationForm shrubbery_form("home");
  RobotomyRequestForm robotomy_form("Sasha");
  PresidentialPardonForm pardon_form("squinn");

  himiko.executeForm(shrubbery_form);  // Fail: need sign
  tanaka.signForm(shrubbery_form);
  tanaka.executeForm(shrubbery_form);

  himiko.signForm(robotomy_form);
  tanaka.executeForm(robotomy_form);  // Fail: too low grade
  himiko.executeForm(robotomy_form);

  himiko.signForm(pardon_form);
  himiko.executeForm(pardon_form);
}
