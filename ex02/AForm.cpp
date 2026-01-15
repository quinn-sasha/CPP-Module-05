#include "AForm.hpp"

#include <string>
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& title, int min_grade_to_sign,
             int min_grade_to_execute)
    : title_(title),
      is_signed_(false),
      min_grade_to_sign_(min_grade_to_sign),
      min_grade_to_execute_(min_grade_to_execute) {
  const int lowest_grade = Bureaucrat::getLowestGrade();
  const int highest_grade = Bureaucrat::getHighestGrade();

  if (min_grade_to_sign > lowest_grade) {
    throw AForm::GradeTooLowException();
  }
  if (min_grade_to_execute > lowest_grade) {
    throw AForm::GradeTooLowException();
  }
  if (min_grade_to_sign < highest_grade) {
    throw AForm::GradeTooHighException();
  }
  if (min_grade_to_execute < highest_grade) {
    throw AForm::GradeTooHighException();
  }
}

AForm::AForm()
    : title_("unknown"),
      is_signed_(false),
      min_grade_to_sign_(Bureaucrat::getHighestGrade()),
      min_grade_to_execute_(Bureaucrat::getHighestGrade()) {}

AForm::AForm(const AForm& other)
    : title_(other.title_),
      is_signed_(other.is_signed_),
      min_grade_to_sign_(other.min_grade_to_sign_),
      min_grade_to_execute_(other.min_grade_to_execute_) {}

AForm& AForm::operator=(const AForm& other) {
  if (this == &other) {
    return *this;
  }
  is_signed_ = other.is_signed_;
  return *this;
}

AForm::~AForm() {}

const std::string& AForm::title() const { return title_; }

bool AForm::isSigned() const { return is_signed_; }

void AForm::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > min_grade_to_sign_) {
    throw AForm::GradeTooLowException();
  }
  is_signed_ = true;
}

int AForm::getMinGradeToSign() const { return min_grade_to_sign_; }

int AForm::getMinGradeToExecute() const { return min_grade_to_execute_; }

void AForm::execute(const Bureaucrat& executor) const {
  if (!is_signed_) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > min_grade_to_execute_) {
    throw GradeTooLowException();
  }
  executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
  return "Form is not signed yet";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
  os << "Form information:" << "\n"
     << " Title: " << form.title() << "\n"
     << " Is signed? " << std::boolalpha << form.isSigned() << "\n"
     << " Grade required to sign: " << form.getMinGradeToSign() << "\n"
     << " Grade required to execute: " << form.getMinGradeToExecute();
  return os;
}
