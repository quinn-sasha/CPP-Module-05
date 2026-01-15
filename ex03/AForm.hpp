#ifndef EX03_AFORM_HPP_
#define EX03_AFORM_HPP_

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class AForm {
  const std::string title_;
  bool is_signed_;
  const int min_grade_to_sign_;
  const int min_grade_to_execute_;

 public:
  AForm(const std::string& title, int min_grade_to_sign,
        int min_grade_to_execute);
  AForm();
  AForm(const AForm& other);
  AForm& operator=(const AForm& other);
  virtual ~AForm();

  const std::string& title() const;
  bool isSigned() const;
  void beSigned(const Bureaucrat& other);
  int getMinGradeToSign() const;
  int getMinGradeToExecute() const;
  void execute(const Bureaucrat& executor) const;
  virtual void executeAction() const = 0;  // execute calls this

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

  class FormNotSignedException : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif  // EX03_AFORM_HPP_
