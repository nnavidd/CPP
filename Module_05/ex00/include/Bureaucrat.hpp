/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:10:35 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/15 23:36:07 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "iostream"
# include "string"

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

class Bureaucrat{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat( void );
		Bureaucrat(std::string name, int range);
		Bureaucrat(Bureaucrat const &);
		Bureaucrat & operator=(Bureaucrat const &);
		~Bureaucrat( void );

		std::string	getName() const;
		int			getGrade() const;

		void incrementGrade(void);
		void decrementGrade(void);

		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw() {
				return (GREEN "grade is too high" RESET);}
		};
		class GradeTooLowException : public std::exception {
			virtual const char* what() const throw() {
				return (GREEN "grade is too low" RESET);}
		};

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const &);

#endif