#ifndef EX02_PRESIDENTIALPARDONFORM_HPP_
#define EX02_PRESIDENTIALPARDONFORM_HPP_

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
  std::string target_;

 public:
  explicit PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm& other);
  PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
  ~PresidentialPardonForm();

  void executeAction() const;  // override
};

#endif  // EX02_PRESIDENTIALPARDONFORM_HPP_
