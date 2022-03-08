#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &old) : Form(old) {
	this->target = old.target;
}

const RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &to_assignation) {
	if (this == &to_assignation)
		return (*this);
	Form::operator=(to_assignation);
	this->target = to_assignation.target;
	return (*this);
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->Form::getSign()) {
		std::cout << "the form isn't signed yet!" << std::endl;
		return (false);
	}
	if (executor.Bureaucrat::getGrade() <= this->Form::getGradeToExecute()) {
		std::cout << "BzZzZzZzZz..." << std::endl;
		srand((unsigned int)time(NULL));
		if (rand() % 2 == 1)
			std::cout << this->target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Robotomizing " << this->target << " was failure" << std::endl;
		return (true);
	}
	else
		throw GradeTooLowException();
}
