/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:45:14 by nnabaeei          #+#    #+#             */
/*   Updated: 2025/05/22 15:29:09 by nnabaeei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <string>
#include <stdexcept>
#include <functional> // For std::bind

class PmergeMe {
	private:
		std::vector<int>	_vecData;
		std::deque<int>		_dequeData;

		std::vector<size_t> generateJacobsthalIndices(size_t size);

		PmergeMe & operator=( PmergeMe const & );
		PmergeMe( PmergeMe const & );

	public:
		PmergeMe();
		~PmergeMe();

		void setVectorData( int const value );
		void setDequeData( int const value );

		void clearData();
		
		void setVectorData(const std::vector<int>& values);
        void setDequeData(const std::deque<int>& values);

		void reserveInput(size_t size);

		std::vector<int> const & getVectorData() const;
		std::deque<int> const & getDequeData() const;

		void fordJohnsonSortVector(std::vector<int>& container);
		void fordJohnsonSortDeque(std::deque<int>& container);
};

#endif // PMERGEME_HPP