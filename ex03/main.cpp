#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat first("dog");
	Bureaucrat second("cat");
	Bureaucrat third("Zafod Beeblebrox");
	
	first.Bureaucrat::setGrade(137);
	second.Bureaucrat::setGrade(45);
	third.Bureaucrat::setGrade(5);
	
	std::cout << "=== make bureaucrates ===" << std::endl;

	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << third << std::endl;

	std::cout << "\n=== make an intern ===" << std::endl;

	Intern fourth;

	std::cout << "\n=== the intern makes forms ===" << std::endl;

	Form *fifth = fourth.Intern::makeForm("robotomy request", "dog");
	Form *sixth = fourth.Intern::makeForm("shrubbery creation", "home");
	Form *seventh = fourth.Intern::makeForm("presidential pardon", "cat");
	try {
		Form *eighth;
		eighth = fourth.Intern::makeForm("bla", "bla");
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== try sign forms ===" << std::endl;

	try {
		first.Bureaucrat::signForm(*sixth);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		second.Bureaucrat::signForm(*fifth);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		third.Bureaucrat::signForm(*seventh);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== try to execute forms ===" << std::endl;

	try {
		first.Bureaucrat::executeForm(*sixth);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		second.Bureaucrat::executeForm(*fifth);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		third.Bureaucrat::executeForm(*seventh);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	delete fifth;
	delete sixth;
	delete seventh;
	return (0);
}