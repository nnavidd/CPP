/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPNException.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:19:44 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/12 14:48:36 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RPNException.hpp"

RPNException::RPNException(const std::string& message) : _message(message) {}

RPNException::~RPNException() throw() {}

RPNException::RPNException(const RPNException& other) : _message(other._message) {}

RPNException& RPNException::operator=(const RPNException& other) {
	if (this != &other) {
		_message = other._message;
	}
	return *this;
}

char const * RPNException::what() const throw() {
	return _message.c_str();
}
