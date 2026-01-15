#ifndef EX03_INTERN_HPP_
#define EX03_INTERN_HPP_

#include <string>

#include "AForm.hpp"

class Intern {
 public:
  Intern();
  Intern(const Intern& other);
  Intern& operator=(const Intern& other);
  ~Intern();

  AForm* makeForm(const std::string& form_title,
                  const std::string& form_target) const;
};

#endif  // EX03_INTERN_HPP_
