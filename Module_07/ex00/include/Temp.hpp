/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Temp.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 12:08:30 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/23 13:07:18 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMP_HPP
# define TEMP_HPP

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

# include <iostream>
# include <string>

template <typename T>

void swap( T & x, T & y){
    T   tmp = x;
    x = y;
    y = tmp;
}

template <typename T>
T const & min(T const & x, T const & y) {
    return (x < y ? x : y);
}

template <typename T>
T const & max(T const & x, T const & y) {
    return (x < y ? y : x);
}

#endif