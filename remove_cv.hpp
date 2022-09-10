/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_cv.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassepipe <norminet@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:52:08 by cassepipe         #+#    #+#             */
/*   Updated: 2022/09/10 13:52:08 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REMOVE_CV_HPP
#define REMOVE_CV_HPP

template < typename T >
struct remove_cv
{
	typedef T type;
};

template < typename T >
struct remove_cv< const T >
{
	typedef T type;
};

#endif /* REMOVE_CV_HPP */
