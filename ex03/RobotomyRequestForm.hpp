#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string target;

	public:
		virtual bool execute(Bureaucrat const & executor) const;
		const RobotomyRequestForm &operator=(const RobotomyRequestForm &to_assignation);
		RobotomyRequestForm(const RobotomyRequestForm &old);
		RobotomyRequestForm(std::string target);
		virtual ~RobotomyRequestForm();
};

#endif