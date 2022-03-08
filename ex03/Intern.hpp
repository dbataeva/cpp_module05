#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Form* makeForm(std::string name_of_form, std::string target_for_form);
		Intern(const Intern &old);
		const Intern &operator=(const Intern &to_assignation);
		Intern();
		~Intern();
};

#endif