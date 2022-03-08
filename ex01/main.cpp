#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat first("cat");
	Bureaucrat second("dog");
	
	first.Bureaucrat::setGrade(3);
	second.Bureaucrat::setGrade(150);

	std::cout << first << std::endl;
	std::cout << second << std::endl;

	std::cout << "\n=== try make wrong form ===" << std::endl;

	try {
		Form third("cat's form", 0, 1);
		std::cout << third << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Form fourth("dog's form", 151, 150);
		std::cout << fourth << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== try make right forms ===" << std::endl;

	try {
		Form third("cat's form", 2, 1);
		std::cout << third << std::endl;

		Form fourth("dog's form", 149, 150);
		std::cout << fourth << std::endl;

		std::cout << "\n=== try to sign forms with low grade ===" << std::endl;

		try {
			first.signForm(third);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			second.signForm(fourth);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\n=== increase bureaucrats' grades ===" << std::endl;

		try {
			first.Bureaucrat::increment();
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			second.Bureaucrat::increment();
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << first << std::endl;
		std::cout << second << std::endl;

		std::cout << "\n=== try to sign forms again ===" << std::endl;

		try {
			first.signForm(third);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}

		try {
			second.signForm(fourth);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}	

	return (0);
}