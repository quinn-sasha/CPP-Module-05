#include <cstdlib>
#include <ctime>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
  std::srand(std::time(NULL));

  Bureaucrat himiko("Himiko", 2);
  Intern sasha;
  AForm* shrubbery_form = sasha.makeForm("shrubbery creation", "home");
  AForm* robotomy_form = sasha.makeForm("robotomy request", "me");
  AForm* pardon_form = sasha.makeForm("presidential pardon", "squinn");
  AForm* tmp = sasha.makeForm("super cool form", "everyone");  // No such form
  (void)tmp;

  himiko.signForm(*shrubbery_form);
  himiko.signForm(*robotomy_form);
  himiko.signForm(*pardon_form);

  himiko.executeForm(*shrubbery_form);
  himiko.executeForm(*robotomy_form);
  himiko.executeForm(*pardon_form);

  delete shrubbery_form;
  delete robotomy_form;
  delete pardon_form;
}
