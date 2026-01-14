#include <iostream>

#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat("Itou", 0);
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cout << e.what() << std::endl;
  }

  try {
    Bureaucrat("Saigou", 151);
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cout << e.what() << std::endl;
  }

  Bureaucrat himiko("Himiko", 2);
  std::cout << himiko << std::endl;

  try {
    for (int i = 0; i < 5; i++) {
      himiko.incrementGrade();
    }
  } catch (const Bureaucrat::GradeTooHighException& e) {
    std::cout << "Himiko leveled up too much" << std::endl;
    std::cout << e.what() << std::endl;
  }

  Bureaucrat tanaka("Tanaka", 150);
  try {
    tanaka.decrementGrade();
  } catch (const Bureaucrat::GradeTooLowException& e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << tanaka << std::endl;
}
