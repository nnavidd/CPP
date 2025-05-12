/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPNException.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:54:48 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/12 15:54:52 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_EXCEPTION_HPP
#define RPN_EXCEPTION_HPP

#include <exception>
#include <string>

// Base RPN exception class
class RPNException : public std::exception {
	protected:
		std::string _message;
	
	public:
		RPNException(std::string const & message);
		RPNException(RPNException const & );
		RPNException& operator=(RPNException const & );
		virtual ~RPNException() throw();
		virtual const char* what() const throw();// { return _message.c_str(); }
};

#endif // RPN_EXCEPTION_HPP