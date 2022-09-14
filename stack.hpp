/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassepipe <norminet@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:52:13 by cassepipe         #+#    #+#             */
/*   Updated: 2022/09/10 13:52:13 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{

template < typename Type, typename Container = ft::vector< Type > >
class stack
{
  protected:
	/* State */

	Container container_;

  public:
	typedef Container                           container_type;
	typedef typename Container::value_type      value_type;
	typedef typename Container::size_type       size_type;
	typedef typename Container::reference       reference;
	typedef typename Container::const_reference const_reference;

	explicit stack(const Container& cont = Container()) : container_(cont)
	{
	}

	stack(const stack& other) : container_(other.container_)
	{
	}

	stack& operator=(const stack& other)
	{
		this->container_ = other.container_;
		return *this;
	}

	/* Element Access */

	reference top()
	{
		return container_.back();
	}

	const_reference top() const
	{
		return container_.back();
	}

	/* Capacity */

	bool empty() const
	{
		return container_.empty();
	}

	size_type size() const
	{
		return container_.size();
	}

	/* Modifiers */

	void push(const value_type& value)
	{
		container_.push_back(value);
	}

	void pop()
	{
		container_.pop_back();
	}

	template < class T, class C >
	friend bool operator==(const stack< T, C >& lhs, const stack< T, C >& rhs);

	template < class T, class C >
	friend bool operator<(const stack< T, C >& lhs, const stack< T, C >& rhs);

}; // class stack

template < class T, class Container >
bool operator==(const stack< T, Container >& lhs, const stack< T, Container >& rhs)
{
	return lhs.container_ == rhs.container_;
}

template < class T, class Container >
bool operator!=(const stack< T, Container >& lhs, const stack< T, Container >& rhs)
{
	return !(lhs == rhs);
}

template < class T, class Container >
bool operator<(const stack< T, Container >& lhs, const stack< T, Container >& rhs)
{
	return lhs.container_ < rhs.container_;
}

template < class T, class Container >
bool operator<=(const stack< T, Container >& lhs, const stack< T, Container >& rhs)
{
	return !(lhs > rhs);
}

template < class T, class Container >
bool operator>(const stack< T, Container >& lhs, const stack< T, Container >& rhs)
{
	return rhs < lhs;
}

template < class T, class Container >
bool operator>=(const stack< T, Container >& lhs, const stack< T, Container >& rhs)
{
	return !(lhs < rhs);
}

} // namespace ft

#endif /* STACK_HPP */
