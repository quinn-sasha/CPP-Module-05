#ifndef EX02_BUREAUCRAT_HPP_
#define EX02_BUREAUCRAT_HPP_

#include <iostream>
#include <string>

class AForm;  // Prevent recursive include between Bureaucrat.hpp and AForm.hpp

class Bureaucrat {
  const std::string name_;
  int grade_;
  static const int kHighestGrade = 1;
  static const int kLowestGrade = 150;

 public:
  Bureaucrat(const std::string& name, int grade);
  Bureaucrat();
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other);
  ~Bureaucrat();

  const std::string& getName() const;
  int getGrade() const;
  static int getLowestGrade();
  static int getHighestGrade();
  void incrementGrade();
  void decrementGrade();

  void signForm(AForm& form) const;
  void executeForm(const AForm& form) const;

  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif  // EX02_BUREAUCRAT_HPP_
