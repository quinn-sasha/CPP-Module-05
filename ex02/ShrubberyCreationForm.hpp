#ifndef EX02_SHRUBBERYCREATIONFORM_HPP_
#define EX02_SHRUBBERYCREATIONFORM_HPP_

#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
  std::string target_;

 public:
  explicit ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
  ~ShrubberyCreationForm();

  void executeAction() const;  // override
};

#endif  // EX02_SHRUBBERYCREATIONFORM_HPP_
