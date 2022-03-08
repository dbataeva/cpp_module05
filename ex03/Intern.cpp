#include "Intern.hpp"

Intern::Intern() {
	std::cout << "I have no name, no grade, no defining characteristics whatsoever. I'm just a slave" << std::endl;
}

Intern::~Intern() {
	std::cout << "You don't need me more, and now you are killing me!" << std::endl;
}

Form* Intern::makeForm(std::string name_of_form, std::string target_for_form) {
	int i = 0;
	std::string forms[3];
	forms[0] = "shrubbery creation";
	forms[1] = "robotomy request";
	forms[2] = "presidential pardon";

	while ((i < 3) && (forms[i] != name_of_form))
		i++;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return new ShrubberyCreationForm(target_for_form);
		case 1:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return new RobotomyRequestForm(target_for_form);
		case 2:
			std::cout << "Intern creates " << forms[i] << std::endl;
			return new PresidentialPardonForm(target_for_form);
		default:
			std::cout << "I don't know this type of form!" << std::endl;
			break;
	}
	return (NULL);
}
	
Intern::Intern(const Intern &old) {
	*this = old;
}
	
const Intern & Intern::operator=(const Intern &to_assignation) {
	if (this != &to_assignation)
		*this = to_assignation;
	return (*this);
}
