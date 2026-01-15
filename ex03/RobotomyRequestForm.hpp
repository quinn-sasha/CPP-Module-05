#ifndef EX03_ROBOTOMYREQUESTFORM_HPP_
#define EX03_ROBOTOMYREQUESTFORM_HPP_

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  std::string target_;

 public:
  RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& other);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
  ~RobotomyRequestForm();

  void executeAction() const;  // override
};

#endif  // EX03_ROBOTOMYREQUESTFORM_HPP_
