#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	Bureaucrat first("dog");
	Bureaucrat second("cat");
	Bureaucrat sixth("Zafod Beeblebrox");
	
	first.Bureaucrat::setGrade(138);
	second.Bureaucrat::setGrade(46);
	sixth.Bureaucrat::setGrade(6);

	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << sixth << std::endl;

	Form *third = new PresidentialPardonForm("cat");
	Form *fourth = new RobotomyRequestForm("dog");
	Form *fifth = new ShrubberyCreationForm("home");

	std::cout << *third << std::endl;
	std::cout << *fourth << std::endl;
	std::cout << *fifth << std::endl;

	std::cout << "\n=== try sign forms ===" << std::endl;

	try {
		first.Bureaucrat::signForm(*fifth);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		second.Bureaucrat::signForm(*fourth);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		sixth.Bureaucrat::signForm(*third);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== try to execute forms ===" << std::endl;

	try {
		first.Bureaucrat::executeForm(*fifth);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		second.Bureaucrat::executeForm(*fourth);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		sixth.Bureaucrat::executeForm(*third);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== increase bureaucrats' grades ===" << std::endl;

	try {
		first.Bureaucrat::increment();
		std::cout << first << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		second.Bureaucrat::increment();
		std::cout << second << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		sixth.Bureaucrat::increment();	
		std::cout << sixth << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== try to execute forms again ===" << std::endl;

	try {
		sixth.Bureaucrat::executeForm(*third);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		second.Bureaucrat::executeForm(*fourth);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		first.Bureaucrat::executeForm(*fifth);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	delete third;
	delete fourth;
	delete fifth;
	return (0);
}