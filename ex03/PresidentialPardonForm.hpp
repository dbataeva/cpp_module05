#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		std::string target;
		
	public:
		virtual bool execute(Bureaucrat const & executor) const;
		const PresidentialPardonForm & operator=(const PresidentialPardonForm &to_assignation);
		PresidentialPardonForm(const PresidentialPardonForm &old);
		PresidentialPardonForm(std::string target);
		virtual ~PresidentialPardonForm();
};

#endif