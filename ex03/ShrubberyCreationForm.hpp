#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
	private:
		std::string target;
		
	public:
		virtual bool execute(Bureaucrat const & executor) const;
		const ShrubberyCreationForm &operator=(const ShrubberyCreationForm &to_assignation);
		ShrubberyCreationForm(const ShrubberyCreationForm &old);
		ShrubberyCreationForm(std::string target);
		virtual ~ShrubberyCreationForm();
};

#endif