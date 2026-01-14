#ifndef EX01_FORM_HPP_
#define EX01_FORM_HPP_

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Form {
  const std::string title_;
  bool is_signed_;
  const int min_grade_to_sign_;
  const int min_grade_to_execute_;

 public:
  Form(const std::string& title, int min_grade_to_sign,
       int min_grade_to_execute);
  Form();
  Form(const Form& other);
  Form& operator=(const Form& other);
  ~Form();

  const std::string& title() const;
  bool isSigned() const;
  void beSigned(const Bureaucrat& other);
  int getMinGradeToSign() const;
  int getMinGradeToExecute() const;

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif  // EX01_FORM_HPP_
