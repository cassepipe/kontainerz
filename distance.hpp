/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassepipe <norminet@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:51:24 by cassepipe         #+#    #+#             */
/*   Updated: 2022/09/10 13:51:24 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISTANCE_HPP
#define DISTANCE_HPP

#include "iterator_traits.hpp"

namespace ft
{

template < typename It >
typename ft::iterator_traits< It >::difference_type distance(It first, It last, ft::input_iterator_tag)
{
	typename ft::iterator_traits< It >::difference_type result = 0;
	while (first != last)
	{
		++first;
		++result;
	}
	return result;
}

template < typename It >
typename ft::iterator_traits< It >::difference_type distance(It first, It last, ft::random_access_iterator_tag)
{
	return last - first;
}

template < typename It >
typename ft::iterator_traits< It >::difference_type distance(It first, It last)
{
	return distance(first, last, typename ft::iterator_traits< It >::iterator_category());
}

} // namespace ft

#endif /* DISTANCE_HPP */
