/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassepipe <norminet@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:43:34 by cassepipe         #+#    #+#             */
/*   Updated: 2022/07/06 13:43:34 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <cstddef>
#include <memory>

#include "iterator_traits.hpp"

namespace ft
{

template < typename Iterator >
class reverse_iterator
{
  protected:
	Iterator current_;

  public:
	/// EXPOSED TYPES

	// It is expected that iterators expose some traits for the purpose of using alogrithms that operates on them
	// They are pointers with metadata in a sort
	// We are not using iterator_traits here because T is supposed to be a pointer
	// and not an iterator, no need for forwarding anything
	typedef Iterator                                                iterator_type; // What it is for ?
	typedef typename iterator_traits< Iterator >::iterator_category iterator_category;
	typedef typename iterator_traits< Iterator >::value_type        value_type;
	typedef typename iterator_traits< Iterator >::pointer           pointer;
	typedef typename iterator_traits< Iterator >::reference         reference;
	typedef typename iterator_traits< Iterator >::difference_type   difference_type;

	/// CONSTRUCTORS

	// We must write a default ctor because we have written a value constructor

	/*defautl ctor*/ reverse_iterator() : current_() // Calling Iterator()
	{
		/**
		 *  The default constructor value-initializes member current.
		 *  If it is a pointer, that means it is zero-initialized.
		 */

		// 235 No specification of default ctor for reverse_iterator
		// 1012. reverse_iterator default ctor should value initialize
	}

	explicit /*value ctor*/ reverse_iterator(iterator_type it) : current_(it)
	{
		// It has to be explicit, we can't derive a reverse iterator from a pointer here
	}

	explicit reverse_iterator(const reverse_iterator& rev_it) : current_(rev_it.current_)
	{
	}

	template < class OtherIter >
	reverse_iterator(const reverse_iterator< OtherIter >& rev_it) : current_(rev_it.base())
	{
		/**
		 *  A reverse_iterator across other types can be copied if the
		 *  underlying iterator can be converted to the type of current_.
		 */
	}

	// Compiler will generate copy ctor and operator=()

	/// MISCELLEANOUS

	iterator_type base() const
	{
		return current_;
	}

	/// DEREFERENCING OPERATORS

	reference operator*() const
	{
		iterator_type tmp = current_;
		--tmp;
		return *tmp;
	}

	pointer operator->() const
	{
		return &(operator*());
	}

	reference operator[](difference_type i) const
	{
		return *(*this + i); // Returns a reverse iterator that we then dereference
	}

	// INCREMENT OPERATORS

	reverse_iterator& operator++()
	{
		--current_;
		return *this;
	}

	reverse_iterator operator++(int)
	{
		reverse_iterator tmp = *this;
		--current_;
		return tmp;
	}

	/// DECREMENT OPERATORS

	reverse_iterator& operator--()
	{
		++current_;
		return *this;
	}

	reverse_iterator operator--(int)
	{
		reverse_iterator tmp = *this;
		++current_;
		return tmp;
	}

	/// ARITHMETIC OPERATORS

	// We are using the underlying iterator's operators
	// A bidirectional_iterator wouldn't have those defined.
	// Try compiling :
	//  int main() { list x{1, 2, 3}; reverse_iterator(begin(x)) + 1; }

	reverse_iterator operator+(difference_type i) const
	{
		return reverse_iterator(current_ - i);
	}

	reverse_iterator operator+=(difference_type i)
	{
		current_ -= i;
		return *this;
	}

	reverse_iterator operator-(difference_type i) const
	{
		return reverse_iterator(current_ + i);
	}

	reverse_iterator operator-=(difference_type i)
	{
		current_ += i;
		return *this;
	}
};

/// NON-MEMBER RELATIONAL OPERATORS

template < typename LeftIterator, typename RightIterator >
bool operator==(const reverse_iterator< LeftIterator >& lhs, const reverse_iterator< RightIterator >& rhs)
{
	return lhs.base() == rhs.base();
}

template < typename LeftIterator, typename RightIterator >
bool operator!=(const reverse_iterator< LeftIterator >& lhs, const reverse_iterator< RightIterator >& rhs)
{
	return !(lhs == rhs);
}

// This helps define all the following ones
// Remember that reverse_iterator comparisons are the inverse of their underlying pointers'comparison
template < typename LeftIterator, typename RightIterator >
bool operator<(const reverse_iterator< LeftIterator >& lhs, const reverse_iterator< RightIterator >& rhs)
{
	return rhs.base() < lhs.base();
}

template < typename LeftIterator, typename RightIterator >
bool operator>(const reverse_iterator< LeftIterator >& lhs, const reverse_iterator< RightIterator >& rhs)
{
	return rhs < lhs;
}

template < typename LeftIterator, typename RightIterator >
bool operator<=(const reverse_iterator< LeftIterator >& lhs, const reverse_iterator< RightIterator >& rhs)
{
	return !(rhs < lhs);
}

template < typename LeftIterator, typename RightIterator >
bool operator>=(const reverse_iterator< LeftIterator >& lhs, const reverse_iterator< RightIterator >& rhs)
{
	return !(lhs < rhs);
}

/// NON-MEMBER ARITHMETIC OPERATORS

// To get the distance between to reverse iterators
template < typename LeftIterator, typename RightIterator >
typename reverse_iterator< LeftIterator >::difference_type operator-(const reverse_iterator< LeftIterator >& lhs,
                                                                 const reverse_iterator< RightIterator >& rhs)
{
	return rhs.base() - lhs.base();
}

// To support expression such as ( -n - iterator ) and have it  return an iterator
template < typename Iterator >
reverse_iterator< Iterator > operator+(typename reverse_iterator< Iterator >::difference_type n,
                                       const reverse_iterator< Iterator >&                    rev_it)
{
	return reverse_iterator< Iterator >(rev_it.base() - n);
}

template < typename Iterator >
reverse_iterator< Iterator > operator-(typename reverse_iterator< Iterator >::difference_type n,
                                       const reverse_iterator< Iterator >&                    rev_it)
{
	return reverse_iterator< Iterator >(rev_it.base() + n);
}

} // namespace ft

#endif /* REVERSE_ITERATOR_HPP */
