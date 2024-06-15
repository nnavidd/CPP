/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:26:59 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 14:25:19 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FROM_HPP

# include <iostream>
# include <string>
# include <exception>


# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

class Bureaucrat;

class Form {
	private:
		std::string	const	_name;
		bool				_signed_at_construct;
		int			const	_sing_grade;
		int			const	_exec_grade;
	
	public:
		Form( void );
		Form(std::string name, int sgrade, int egrade);
		Form(Form const &);
		Form & operator=(Form const &);
		~Form( void );

		std::string	getName() const;
		bool	getSignedAtConstruct() const;
		int		getSignGrade() const;
		int		getExecGrade() const;

		void	beSigned(Bureaucrat const &);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {return (GREEN "Form Grade is to high!" RESET);}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {return (GREEN "Form Grade is to low!" RESET);}
		};
};

std::ostream & operator<<(std::ostream &, Form const &);

#endif