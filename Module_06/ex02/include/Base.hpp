/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:38:43 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/18 12:20:09 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <exception>
# include <cstdlib> // For rand()
# include <ctime> // For time()



class Base{
	private:

	public:
	   virtual ~Base( void );
};

class A : public Base{};
class B : public Base{};
class C : public Base{};
#endif