/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:45:00 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/30 12:02:01 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
	if (std::distance(begin, end) > static_cast<long>(_maxSize - _vec.size())) {
		throw std::out_of_range("Cannot add more numbers, span will exceed its maximum size.");
	}
	_vec.insert(_vec.end(), begin, end);
}
