#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Form top_secret_plan("Starting war", 1, 0);
  } catch (const Form::GradeTooHighException& e) {
    std::cout << e.what() << "\n";
  }
  try {
    Form boring_form("Making bread", 160, 160);
  } catch (const Form::GradeTooLowException& e) {
    std::cout << e.what() << "\n";
  }

  Form tax_plan("Tax Plan", 42, 5);
  std::cout << tax_plan << "\n";
  Bureaucrat himiko("Himiko", 2);
  Bureaucrat tanaka("Tanaka", 100);
  std::cout << himiko << "\n";
  std::cout << tanaka << "\n";
  himiko.signForm(tax_plan);
  tanaka.signForm(tax_plan);
}
