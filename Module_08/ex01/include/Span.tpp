/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:45:00 by nnavidd           #+#    #+#             */
/*   Updated: 2024/06/30 14:23:29 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
	if (std::distance(begin, end) > static_cast<long>(_maxSize - _vec.size())) {
		throw std::out_of_range( ORG "Cannot add more numbers, span will exceed its maximum size." RESET);
	}
	_vec.insert(_vec.end(), begin, end);
}
