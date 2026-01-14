#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form(const std::string& title, int min_grade_to_sign,
           int min_grade_to_execute)
    : title_(title),
      is_signed_(false),
      min_grade_to_sign_(min_grade_to_sign),
      min_grade_to_execute_(min_grade_to_execute) {
  const int lowest_grade = Bureaucrat::getLowestGrade();
  const int highest_grade = Bureaucrat::getHighestGrade();

  if (min_grade_to_sign > lowest_grade) {
    throw Form::GradeTooLowException();
  }
  if (min_grade_to_execute > lowest_grade) {
    throw Form::GradeTooLowException();
  }
  if (min_grade_to_sign < highest_grade) {
    throw Form::GradeTooHighException();
  }
  if (min_grade_to_execute < highest_grade) {
    throw Form::GradeTooHighException();
  }
}

Form::Form()
    : title_("unknown"),
      is_signed_(false),
      min_grade_to_sign_(Bureaucrat::getHighestGrade()),
      min_grade_to_execute_(Bureaucrat::getHighestGrade()) {}

Form::Form(const Form& other)
    : title_(other.title_),
      is_signed_(other.is_signed_),
      min_grade_to_sign_(other.min_grade_to_sign_),
      min_grade_to_execute_(other.min_grade_to_execute_) {}

Form& Form::operator=(const Form& other) {
  if (this == &other) {
    return *this;
  }
  is_signed_ = other.is_signed_;
  return *this;
}

Form::~Form() {}

const std::string& Form::title() const { return title_; }

bool Form::isSigned() const { return is_signed_; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > min_grade_to_sign_) {
    throw Form::GradeTooLowException();
  }
  is_signed_ = true;
}

int Form::getMinGradeToSign() const { return min_grade_to_sign_; }

int Form::getMinGradeToExecute() const { return min_grade_to_execute_; }

const char* Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  os << "Form information:" << "\n"
     << " Title: " << form.title() << "\n"
     << " Is signed? " << std::boolalpha << form.isSigned() << "\n"
     << " Grade required to sign: " << form.getMinGradeToSign() << "\n"
     << " Grade required to execute: " << form.getMinGradeToExecute();
  return os;
}
