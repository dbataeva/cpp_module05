#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &old) : Form(old) {
	this->target = old.target;
}

const PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &to_assignation) {
	if (this == &to_assignation)
		return (*this);
	Form::operator=(to_assignation);
	this->target = to_assignation.target;
	return (*this);
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->Form::getSign()) {
		std::cout << "the form isn't signed yet!" << std::endl;
		return (false);
	}
	if (executor.Bureaucrat::getGrade() <= this->Form::getGradeToExecute()) {
		std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
		return (true);
	}
	else
		throw GradeTooLowException();
}
