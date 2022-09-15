/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassepipe <norminet@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:39:18 by cassepipe         #+#    #+#             */
/*   Updated: 2022/07/07 15:39:18 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "algorithm.hpp"
#include "distance.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"
#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iterator>
#include <limits>
#include <memory>
#include <sstream>

namespace ft
{
template < typename T, typename Alloc = std::allocator< T > > // Space is actually required I think
class vector
{
  public:
	/// EXPOSED TYPES
	typedef T                                        value_type;
	typedef Alloc                                    allocator_type;
	typedef typename allocator_type::reference       reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer         pointer;
	typedef typename allocator_type::const_pointer   const_pointer;

	// What if value_type is already const ? Well the compiler is smart enough
	// to remove the extra const. Note that vector<const T> still won't compile
	// because of that leads std::allocator to having two functions with the
	// same type signature. Writing our own const-friendly allocator would work
	typedef vector_iterator< value_type >          iterator;
	typedef vector_iterator< const value_type >    const_iterator;
	typedef ft::reverse_iterator< iterator >       reverse_iterator;
	typedef ft::reverse_iterator< const_iterator > const_reverse_iterator; // Why do I need ft:: ?

	// Why ptrdiff_t ? Because it is the signed equivalent of size_t.
	// Good for pointer arithmetics
	typedef std::ptrdiff_t difference_type;
	typedef std::size_t    size_type;

  protected:
	/** STATE **/
	// We need to store an allocator inside our instance in order to call its
	// methods to, you know, allocate.
	allocator_type allocator_;

	// The underlying data we are operating on
	pointer data_;

	// The number of stored elements
	size_type size_;

	// Allocated memory
	size_type capacity_;

	/** HELPER FUNCTIONS **/

	size_type range_check_(size_type n) const
	{
		if (n >= size_)
		{
			std::stringstream stream;
			stream << "ft::vector::range_check_\nTried to access element at index ";
			stream << n;
			stream << " while maximum addressable index is ";
			if (size_ == 0)
				stream << "none\n";
			else
				stream << size_ - 1 << '\n';
			throw std::out_of_range(stream.str());
		}
		return n;
	}

	void destroy_data_()
	{
		if (data_)
			for (size_type i = 0; i < size_; ++i)
				allocator_.destroy(data_ + i);
	}

	void deallocate_data_()
	{
		if (data_)
			allocator_.deallocate(data_, capacity_);
	}

	void shift_elements_right_by_(T* elements, size_type n)
	{
		if (this->empty() == false && n != 0)
		{
			pointer end = &(*this->end());
			if (elements < end)
			{
				for (--end, --elements; end != elements; --end)
				{
					allocator_.construct(end + n, *end); // If vector is empty this will blow up
					allocator_.destroy(end);
				}
			}
		}
	}

	void shift_elements_left_by_(T* elements, size_type n)
	{
		if (this->empty() == false && n != 0)
		{
			pointer end = &*this->end();
			for (; elements != end; ++elements)
			{
				allocator_.construct(elements - n, *elements); // If vector is empty this will blow up
				allocator_.destroy(elements);
			}
		}
	}

	void check_alloc_len_(size_type n)
	{
		if (n > this->max_size() - this->size())
			throw std::length_error("vector::reserve");
	}

	void check_overflow_(size_type n)
	{
		if (n > n * 2)
			throw std::length_error("size_type overflow");
	}


  public:
	/** INTERFACE **/

	// Default constructor.
	// It is explicit because we won't allow anything to be converted implicity to an allocator
	// to an allocator.
	explicit vector(const allocator_type& alloc = allocator_type())
	    : allocator_(alloc), data_(NULL), size_(0), capacity_(0)
	{
	}

	// Fill constructor
	// If a call is like "vector<Obj>(5));" and passes then the value of Obj() is passed by default
	explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	    : allocator_(alloc), data_(NULL), size_(0), capacity_(0)
	{
		assign(n, val);
	}

	// Range constructor
	// Do some enable_if<> = 0 wizardry to ensure InputIterator is not a number
	// For an explanation of the use of enable_if ->
	// https://www.fluentcpp.com/2018/05/15/make-sfinae-pretty-1-what-value-sfinae-brings-to-code/
	template < class InputIterator >
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
	       typename enable_if< !is_integral< InputIterator >::value, void* >::type = 0)
	    : allocator_(alloc), data_(NULL), size_(0), capacity_(0)
	{
		assign(first, last, typename ft::iterator_traits< InputIterator >::iterator_category());
	}

	// Copy constructor. Shall perform deep copy using operator=
	vector(const vector& other) : allocator_(other.allocator_), data_(NULL), size_(0), capacity_(0)
	{
		this->operator=(other);
	}

	// Destructor.
	~vector()
	{
		destroy_data_();
		deallocate_data_();
	}

	/* CONVERSION OPERATOR */

	vector& operator=(const vector& rhs) // Performs deep copy
	{
		if (this != &rhs)
		{
			destroy_data_();

			if (rhs.size_ > capacity_) // If we don't have enough room, let's make some
			{
				deallocate_data_();
				data_     = allocator_.allocate(rhs.size_);
				capacity_ = rhs.size_;
			}
			size_ = rhs.size_;
			for (size_type i = 0; i < size_; ++i)
			{
				allocator_.construct(data_ + i, *(rhs.data_ + i));
			}
		}
		return *this;
	}

	/* Iterators */

	// The reason why we have const versions is because we can't return a plain iterator from a const vector !
	iterator begin()
	{
		return iterator(data_); // Calls our iterator's constructor !
	}

	const_iterator begin() const
	{
		return const_iterator(data_);
	}

	iterator end()
	{
		return iterator(data_ + size_); // Points to one past our storage
	}

	const_iterator end() const
	{
		return const_iterator(data_ + size_);
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(this->end());
	}

	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(this->end());
	}

	reverse_iterator rend()
	{
		return reverse_iterator(this->begin());
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(this->begin());
	}

	/* Capacity */

	size_type size() const
	{
		return size_;
	}

	size_type max_size() const
	{
		// std::distance(begin(), end()) cannot be greater than PTRDIFF_MAX,
		// and realistically we can't store more than PTRDIFF_MAX/sizeof(T)
		// (even if std::allocator_traits::max_size says we can).
		const size_t diffmax = std::numeric_limits<difference_type>::max() / sizeof(value_type);
		return (std::min)(diffmax, allocator_.max_size());
	}

	// Resize to a specific size
	void resize(size_type n, value_type val = value_type()) // No deallocation here. This is not shrink_to_fit()
	{
		if (n > size_)
		{
			if (n > capacity_)
				reserve(n);
			for (; size_ < n; ++size_)
				allocator_.construct(data_ + size_, val);
		}
		else if (size_ != 0)
		{
			for (--size_; size_ > n; --size_)
				allocator_.destroy(data_ + size_);
			allocator_.destroy(data_ + size_--);
			++size_;
			capacity_ = size_;
		}
	}

	size_type capacity() const
	{
		return capacity_;
	}

	bool empty() const
	{
		if (size_ == 0)
			return true;
		else
			return false;
	}

	void reserve(size_type n)
	{
		check_alloc_len_(n); // May throw
		if (n > capacity_)
		{
			pointer tmp = allocator_.allocate(n);
			if (data_)
			{
				for (size_type i = 0; i < size_; ++i)
					allocator_.construct(tmp + i, data_[i]);
				for (size_type i = 0; i < size_; ++i)
					allocator_.destroy(data_ + i);
				deallocate_data_();
			}
			data_     = tmp;
			capacity_ = n;
		}
	}

	/* Element access */

	// The reason we need const_reference versions is to be able to access
	// elements in case the vector itself is declared as const.
	// Reminder : In the case where an instance is declared const, having a func
	// that returns a simple reference version is not an issue as long we are not
	// using that function which polypmorphism prevents here.
	reference operator[](size_type n)
	{
		return data_[n];
	}

	const_reference operator[](size_type n) const
	{
		return data_[n];
	}

	reference at(size_type n)
	{
		return data_[range_check_(n)];
	}

	const_reference at(size_type n) const
	{
		return data_[range_check_(n)];
	}

	reference front() // I don't care if vector is empty because then it is UB
	{
		return data_[0];
	}

	const_reference front() const
	{
		return data_[0];
	}

	reference back() // I don't care if vector is empty because then it is UB
	{
		return data_[size_ - 1];
	}

	const_reference back() const
	{
		return data_[size_ - 1];
	}

	allocator_type get_allocator() const
	{
		return allocator_;
	}

	/* Modifiers */

  protected:

	void reserve_(pointer& old_data, size_type new_capacity, size_type& old_capacity)
	{
		check_alloc_len_(new_capacity);
		if (new_capacity > old_capacity)
		{
			pointer new_data = allocator_.allocate(new_capacity);
			if (old_data)
			{
				for (size_type i = 0; i < old_capacity; ++i) // Since we're calling because old buffer is full then old_capacity == old_data
				{
					allocator_.construct(new_data + i, *(old_data + i));
					allocator_.destroy(old_data + i);
				}
				allocator_.deallocate(old_data, old_capacity);
			}
			old_data     = new_data;
			old_capacity = new_capacity;
		}
	}

	template < class InputIterator >
	void assign(InputIterator first, InputIterator last, std::input_iterator_tag)
	{
		pointer   tmp          = NULL;
		size_type new_size     = 0;
		size_type new_capacity = 0;
		if (first != last)
		{
			reserve_(tmp, 1, new_capacity);
			allocator_.construct(tmp, *first);
			++new_size;
			++first;
			for (; first != last; ++first)
			{
				if (new_capacity == new_size)
					reserve_(tmp, new_size * 2, new_capacity);
				allocator_.construct(tmp + new_size, *first);
				++new_size;
			}
		}

		destroy_data_();
		deallocate_data_();

		size_     = new_size;
		capacity_ = new_capacity;
		data_     = tmp;
	}

	template < class RandomAccessIterator >
	void assign(RandomAccessIterator first, RandomAccessIterator last, std::random_access_iterator_tag)
	{
		size_type new_size = ft::distance(first, last);
		if (new_size > this->max_size())
			throw std::length_error("vector::assign");
		pointer tmp = allocator_.allocate(new_size);

		for (size_type i = 0; i < new_size; ++i)
			allocator_.construct(tmp + i, *(first + i));

		destroy_data_();
		deallocate_data_();
		size_     = new_size;
		capacity_ = size_;
		data_     = tmp;
	}

  public:
	template < class InputIterator >
	void assign(InputIterator first, InputIterator last,
	            typename enable_if< !is_integral< InputIterator >::value, int >::type =
	                0) // Unnamed default parameter, weird, I know
	{
		assign(first, last, typename ft::iterator_traits< InputIterator >::iterator_category());
	}

	void assign(size_type n, const value_type& val)
	{
		// Clear, deallocate, allocate, copy data
		destroy_data_();
		deallocate_data_();
		if (n > this->max_size())
			throw std::length_error("ft::vector::assign");
		size_     = n;
		data_     = allocator_.allocate(size_);
		capacity_ = size_;
		;
		for (size_type i = 0; i < size_; ++i)
			allocator_.construct(data_ + i, val);
	}

	void push_back(const value_type& val)
	{
		if (capacity_ == size_)
		{
			check_overflow_(size_);
			reserve(size_ ? size_ * 2 : 1);
		}
		allocator_.construct(data_ + size_, val);
		++size_;
	}

	void pop_back()
	{
		--size_;
		allocator_.destroy(data_ + size_);
	}

	iterator insert(iterator position, const value_type& val)
	{

		T*              pos;
		difference_type idx      = &*position - data_;
		size_type       new_size = size_ + 1;

		if (new_size > capacity_)
		{
			check_overflow_(new_size);
			reserve(new_size * 2);
		}
		pos = data_ + idx;
		shift_elements_right_by_(pos, 1);
		for (; size_ < new_size; ++size_, ++pos)
		{
			allocator_.construct(pos, val);
		}
		return iterator(data_ + idx);
	}

	void insert(iterator position, size_type n, const value_type& val)
	{
		T*              pos;
		difference_type idx      = &*position - data_;
		size_type       new_size = size_ + n;

		if (new_size > capacity_)
		{
			check_overflow_(new_size);
			reserve(new_size * 2);
		}
		pos = data_ + idx;
		shift_elements_right_by_(pos, n);
		for (; size_ < new_size; ++size_, ++pos)
		{
			allocator_.construct(pos, val);
		}
	}

  protected:
	template < typename InputIterator >
	void insert(iterator position, InputIterator first, InputIterator last, std::input_iterator_tag)
	{
		vector tmp(first, last);
		insert(position, tmp.begin(), tmp.end());
	}

	template < typename RandomAccessIterator >
	void insert(iterator position, RandomAccessIterator first, RandomAccessIterator last,
	            std::bidirectional_iterator_tag)
	{
		T*              pos;
		difference_type n        = ft::distance(first, last);
		difference_type idx      = &*position - data_;
		size_type       new_size = size_ + n;

		if (new_size > capacity_)
		{
			check_overflow_(new_size);
			reserve(new_size * 2);
		}
		pos = data_ + idx;
		shift_elements_right_by_(pos, n);
		for (; size_ < new_size; ++size_, ++pos, ++first)
		{
			allocator_.construct(pos, *first);
		}
	}

  public:
	template < typename Iterator >
	void insert(iterator position, Iterator first, Iterator last,
	            typename enable_if< !is_integral< Iterator >::value, int >::type = 0)
	{
		insert(position, first, last, typename ft::iterator_traits< Iterator >::iterator_category());
	}

	iterator erase(iterator position)
	{
		return erase(position, position + 1);
	}

	// No need for reallocation
	// The behaviour for last < first is not specified
	iterator erase(iterator first, iterator last)
	{
		iterator end = this->end();
		if (first >= end)
			return end;
		if (first == last)
			return last;
		size_type distance = ft::distance(first, last);

		iterator it = first;
		for (; it != last; ++it)
			allocator_.destroy(&(*it));
		shift_elements_left_by_(&(*it), distance); // Depends on size_
		size_ -= distance;
		return (first);
	}

	template <typename A>
	void swap(vector<T, A>& x)
	{
		vector< T > tmp = *this;
		*this           = x;
		x               = tmp;
	}

	void clear()
	{
		while (size_--)
		{
			allocator_.destroy(data_ + size_);
		}
		++size_;
	}
};

template < typename T, typename Allocator >
bool operator==(vector< T, Allocator > const& lhs, vector< T, Allocator > const& rhs)
{

	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template < typename T, typename Alloc >
bool operator!=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs)
{
	return !(lhs == rhs);
}

template < typename T, typename Allocator >
bool operator<(vector< T, Allocator > const& lhs, vector< T, Allocator > const& rhs)
{

	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template < typename T, typename Alloc >
bool operator>=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs)
{
	return !(lhs < rhs);
}

template < typename T, typename Alloc >
bool operator>(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs)
{
	// We just swap the order of ther args to use operator<
	return rhs < lhs;
}

template < typename T, typename Alloc >
bool operator<=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs)
{
	return !(lhs > rhs);
}

//template <typename T, typename Alloc>
//void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs)
//{
//    lhs.swap(rhs);
//}

} // namespace ft

namespace std
{

template < typename T, typename Alloc >
void swap(ft::vector< T, Alloc >& lhs, ft::vector< T, Alloc >& rhs)
{
	lhs.swap(rhs);
	return;
}

} // namespace std

#endif /* VECTOR_HPP */
