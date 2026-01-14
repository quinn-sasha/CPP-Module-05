#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name) {
  if (grade < kHighestGrade) {
    throw GradeTooHighException();
  }
  if (grade > kLowestGrade) {
    throw GradeTooLowException();
  }
  grade_ = grade;
}

Bureaucrat::Bureaucrat() : name_("unknown"), grade_(kLowestGrade) {}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name_(other.name_), grade_(other.grade_) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this == &other) {
    return *this;
  }
  // name_ cannot be changed
  grade_ = other.grade_;
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::incrementGrade() {
  if (grade_ == kHighestGrade) {
    throw GradeTooHighException();
  }
  grade_--;
}

void Bureaucrat::decrementGrade() {
  if (grade_ == kLowestGrade) {
    throw GradeTooLowException();
  }
  grade_++;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
  return os;
}
