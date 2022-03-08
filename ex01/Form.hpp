#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				is_signed;
		const int			grade_to_sign;
		const int 			grade_to_execute;

	public:
		const std::string getName() const;
		bool getSign() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		bool beSigned(const Bureaucrat &clerk);

		const Form& operator=(const Form &to_assignation);
		Form(const Form &old);
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		~Form();

		class GradeTooHighException : public std::exception {
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Form const &source);

#endif
