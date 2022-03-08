#include "Bureaucrat.hpp"

int main() {
	Bureaucrat first("cat");
	Bureaucrat second("dog");
	
	std::cout << "=== try make wrong bureaucrat ===" << std::endl;

	try {
		first.Bureaucrat::setGrade(0);
		std::cout << first << std::endl;
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		second.Bureaucrat::setGrade(151);
		std::cout << second << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== try make right bureaucrat ===" << std::endl;

	try {
		first.Bureaucrat::setGrade(2);
		std::cout << first << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		second.Bureaucrat::setGrade(149);
		std::cout << second << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== try increase bureaucrat's grade ===" << std::endl;

	while (1) {
		try {
			first.Bureaucrat::increment();
			std::cout << first << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			break ;
		}
	}

	std::cout << "\n=== try decrease bureaucrat's grade ===" << std::endl;
	
	while (1) {
		try {
			second.Bureaucrat::decrement();
			std::cout << second << std::endl;
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			break ;
		}
	}
	

	return (0);
}