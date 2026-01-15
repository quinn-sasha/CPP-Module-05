#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>
#include <string>

#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), target_("nowhere") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm("Shrubbery Creation", 145, 137), target_(other.target_) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
  if (this == &other) {
    return *this;
  }
  target_ = other.target_;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
  std::string filename(target_ + "_shrubbery");
  std::ofstream outfile(filename.c_str(),
                        std::ios::out | std::ios::trunc);
  if (!outfile.is_open()) {
    std::cerr << "Couldn't open file" << "\n";
    return;
  }
  outfile << "              _{\\ _{\\{\\/}/}/}__" << "\n"
          << "             {/{/\\}{/{/\\}(\\}{/\\} _" << "\n"
          << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << "\n"
          << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << "\n"
          << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << "\n"
          << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << "\n"
          << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << "\n"
          << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << "\n"
          << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << "\n"
          << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << "\n"
          << "       {/{\\{\\ /}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << "\n"
          << "      {/{\\{\\ /}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << "\n"
          << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << "\n"
          << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << "\n"
          << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << "\n"
          << "            {/{/{\\{\\ /}{/{\\{\\{\\(_)/}" << "\n"
          << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << "\n"
          << "              {){/ {\\/}{\\/} \\}\\}" << "\n"
          << "              (_)  \\.-'.-/" << "\n"
          << "          __...--- |'-.-'| --...__" << "\n"
          << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << "\n"
          << " -\"    ' .  . '    |.'-._| '  . .  '   jro" << "\n"
          << " .  '-  '    .--'  | '-.'|    .  '  . '" << "\n"
          << "          ' ..     |'-_.-|" << "\n"
          << "  .  '  .       _.-|-._ -|-._  .  '  ." << "\n"
          << "              .'   |'- .-|   '." << "\n"
          << "  ..-'   ' .  '.   `-._.-  .'  '  - ." << "\n"
          << "   .-' '        '-._______.-'     '  ." << "\n"
          << "        .      ~," << "\n"
          << "    .       .   |\\   .    ' '-." << "\n"
          << "    ___________/  \\____________" << "\n"
          << "   /  Why is it, when you want \\" << "\n"
          << "  |  something, it is so damn   |" << "\n"
          << "  |    much work to get it?     |" << "\n"
          << "   \\___________________________/" << "\n";
}
