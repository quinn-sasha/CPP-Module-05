#ifndef EX02_INTERN_HPP
#define EX02_INTERN_HPP

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

#endif  // EX02_INTERN_HPP
