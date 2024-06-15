/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:41:08 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/14 22:45:26 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
# define EXCEPTION_HPP

# include <iostream>
# include <exception>
# include <string>

class Exception : public std::exception{
	public:
		virtual const char* what() const throw(){}
};


#endif