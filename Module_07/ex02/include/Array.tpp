/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 21:32:29 by nnabaeei          #+#    #+#             */
/*   Updated: 2024/06/24 01:06:53 by nnavidd          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array( void ):_size(0), _arr(NULL) {}

template <typename T>
Array<T>::Array(Array const & other): _size(other._size), _arr(new T[other._size]()) {
    for (unsigned int i = 0; i < _size; i++)
        _arr[i] = other._arr[i];
}

template <typename T>
Array<T> & Array<T>::operator=(Array const & other) {
    if (this != &other){
        delete [] _arr;
        _size = other._size;
        _arr = new T[_size]();
        for (int i = 0; other._arr[i]; i++)
            _arr[i] = other._arr[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array( void ) {
    delete [] _arr;
}

template <typename T>
Array<T>::Array( unsigned int n ): _size(n), _arr(new T[n]()) {}

template <typename T>
T & Array<T>::operator[]( std::size_t const index) {
    if (index >= _size)
        throw std::out_of_range( ORG "Index out of bounds" RESET);
    return (_arr[index]);
 }

template <typename T>
T const & Array<T>::operator[]( std::size_t const index) const {
    if (index >= _size)
        throw std::out_of_range( ORG "Index out of bounds" RESET);
    return (_arr[index]);
}

template <typename T>
unsigned int Array<T>::size( ){
    return (_size);
}
template <typename T>
const char * Array<T>::Except::what() const throw() {
    return (ORG "The index out of bound!" RESET);
}
