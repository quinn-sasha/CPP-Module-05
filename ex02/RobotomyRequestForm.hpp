#ifndef EX02_ROBOTOMYREQUESTFORM_HPP_
#define EX02_ROBOTOMYREQUESTFORM_HPP_

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
  std::string target_;

 public:
  explicit RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm& other);
  RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
  ~RobotomyRequestForm();

  void executeAction() const;  // override
};

#endif  // EX02_ROBOTOMYREQUESTFORM_HPP_
