#include "Form.hpp"

const std::string Form::getName() const {
	return (this->name);
}

bool Form::getSign() const {
	return (this->is_signed);
}
	
int Form::getGradeToSign() const {
	return (this->grade_to_sign);
}
	
int Form::getGradeToExecute() const {
	return (this->grade_to_execute);
}

bool Form::beSigned(const Bureaucrat &clerk) {	
	if (clerk.Bureaucrat::getGrade() <= this->Form::getGradeToSign()) {
		this->is_signed = true;
		return (true);
	}
	else {
		throw GradeTooLowException();
	}
	return (false);
}

const Form& Form::operator=(const Form &to_assignation) {
	if (this != &to_assignation) {
		(std::string)this->name = to_assignation.Form::getName();
		this->is_signed = to_assignation.Form::getSign();
	}
	return (*this);
}
	
Form::Form(const Form &old) : name(old.getName()), grade_to_sign(old.getGradeToSign()), grade_to_execute(old.Form::getGradeToExecute())
{
	this->is_signed = old.Form::getSign();
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) : name(name), is_signed(0), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) {
	if (this->Form::getGradeToSign() < 1)
		throw GradeTooHighException();
	else if (this->Form::getGradeToSign() > 150)
		throw GradeTooLowException();
}
	
Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high for the form!");
};
	
const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low for the form!");
}

std::ostream &operator<<(std::ostream &out, Form const &source) {
	std::string status;

	status = source.Form::getSign() ? " is signed" : " isn't signed";
	out << "The form " << source.Form::getName() << " with grade to sign = " << source.Form::getGradeToSign() << " and grade to execute = " << source.Form::getGradeToExecute() << status;
	return (out);
}
