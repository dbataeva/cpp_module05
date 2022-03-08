#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name) : name(name) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &old) {
	*this = old;
}

const Bureaucrat& Bureaucrat::operator=(const Bureaucrat &to_assignation) {
	if (this != &to_assignation) {
		this->Bureaucrat::setGrade(to_assignation.Bureaucrat::getGrade());
		(std::string)this->name = (std::string)to_assignation.Bureaucrat::getName();
	}
	return (*this);
}

int Bureaucrat::getGrade(void) const {
	return (this->grade);
}

const std::string Bureaucrat::getName(void) const {
	return (this->name);
}

void Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw () {
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &source) {
	out<< source.Bureaucrat::getName() << ", bureaucrat grade " << source.Bureaucrat::getGrade();
	return (out);
}

void Bureaucrat::increment() {
	if (this->Bureaucrat::getGrade() < 2)
		throw GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decrement() {
	if (this->Bureaucrat::getGrade() > 149)
		throw GradeTooLowException();
	else 
		this->grade++;
}
