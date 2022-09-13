/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassepipe <norminet@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:51:44 by cassepipe         #+#    #+#             */
/*   Updated: 2022/09/10 13:51:44 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "map_node.hpp"
#include "remove_cv.hpp"
#include <cstddef>

namespace ft
{

template < typename Pair, typename Alloc >
class map_iterator
{
  public:
	typedef Pair                            value_type;
	typedef value_type&                     reference;
	typedef value_type*                     pointer;
	typedef std::bidirectional_iterator_tag iterator_category;
	typedef std::ptrdiff_t                  difference_type;

  protected:
	typedef map_node< Pair, Alloc > node_t;

	/* STATE */
	const node_t* current_;
	const node_t* nil_;

	/* HELPERS */

	node_t* leftmost_(node_t* node)
	{
		while (node->left != nil_)
			node = node->left;
		return node;
	}

	node_t* rightmost_(node_t* node)
	{
		while (node->right != nil_)
			node = node->right;
		return node;
	}

  public:
	/* Default constructor */ map_iterator() : current_(NULL), nil_(NULL)
	{
	}

	/* Constructor */ map_iterator(map_node< Pair, Alloc >* current, map_node< Pair, Alloc >* nil)
	    : current_(current), nil_(nil)
	{
	}

	/* Constructor */ map_iterator(map_node< const Pair, Alloc >* current, map_node< const Pair, Alloc >* nil)
	    : current_(current), nil_(nil)
	{
	}

	//[> Constructor <] map_iterator(const map_node<Pair, Alloc> * current, const map_node<Pair, Alloc> * nil)
	//    : current_(current), nil_(nil)
	//{ }

	//[> Constructor <] map_iterator(const map_node<const Pair> * current, const map_node<const Pair> * nil)
	//    : current_(current), nil_(nil)
	//{ }

	template < typename InputIt >
	/* Copy Constructor */ map_iterator(InputIt& other) : current_(other.get_current()), nil_(other.get_nil())
	{
	}

	pointer operator->() const
	{
		return &(this->operator*());
	}

	reference operator*() const
	{
		return *(current_->pair);
	}

	template < typename It >
	bool operator==(It it)
	{
		return current_ == it.get_current();
	}

	template < typename It >
	bool operator!=(It it)
	{
		return current_ != it.get_current();
	}

	// iterator will cycle forward passing through an end's marker
	map_iterator& operator++()
	{
		if (nil_->parent == nil_) // Tree empty ?
			current_ = nil_;
		else if (current_ == nil_)
			current_ = leftmost_(nil_->parent);
		// If has successor...
		else if (current_->right != nil_)
			current_ = leftmost_(current_->right);   // ... goes to successor
			                                         // Else if it has no successor under itself
		else if (current_ == current_->parent->left) // If it is its parent's left child
			current_ = current_->parent;             // ... it becomes its parent
		else                                         // Then it's its parent's right child
		{
			while (current_ == current_->parent->right) // Go up the succession of right children
				current_ = current_->parent;
			if (current_ == current_->parent->left) // if it is its parent's left child
				current_ = current_->parent;        // ... it becomes its parent
			else
				current_ = nil_; // ..else nil_, end is reached
		}
		return *this;
	}

	// iterator will cycle backward passing through an end's marker
	map_iterator& operator--()
	{
		if (nil_->parent == nil_) // Tree empty ?
			current_ = nil_;
		else if (current_ == nil_)               // Reached the end ?
			current_ = rightmost_(nil_->parent); // root_ref_ will never be NULL here
		else if (current_->left != nil_)
			current_ = rightmost_(current_->left);
		else if (current_ == current_->parent->right)
			current_ = current_->parent;
		else
		{
			while (current_ == current_->parent->left) // Go up the succession of left children
				current_ = current_->parent;
			if (current_ == current_->parent->right) // if it is its parent's right child
				current_ = current_->parent;         // ... it becomes its parent
			else
				current_ = NULL; // ..else NULL, end is reached
		}
		return *this;
	}

	map_iterator operator++(int)
	{
		map_iterator tmp = *this;
		             operator++();
		return tmp;
	}

	map_iterator operator--(int)
	{
		map_iterator tmp = *this;
		             operator--();
		return tmp;
	}

	const node_t* get_current()
	{
		return current_;
	}
	const node_t* get_nil()
	{
		return nil_;
	}
}; // map_iterator

template < typename Pair, typename Alloc >
class map_const_iterator
{
  public:
	typedef Pair const                      value_type;
	typedef value_type&                     reference;
	typedef value_type*                     pointer;
	typedef std::bidirectional_iterator_tag iterator_category;
	typedef std::ptrdiff_t                  difference_type;

  protected:
	typedef map_node< Pair, Alloc >         node_t;
	typedef map_iterator<Pair, Alloc>       non_const_iterator_t;

	/* STATE */
	const node_t* current_;
	const node_t* nil_;

	/* HELPERS */

	node_t* leftmost_(node_t* node)
	{
		while (node->left != nil_)
			node = node->left;
		return node;
	}

	node_t* rightmost_(node_t* node)
	{
		while (node->right != nil_)
			node = node->right;
		return node;
	}

  public:
	/* Default constructor */ map_const_iterator() : current_(nil_)
	{
	}

	/* Constructor */ map_const_iterator(map_node< Pair, Alloc >* current, map_node< Pair, Alloc >* nil)
	    : current_(current), nil_(nil)
	{
	}

	/* Constructor */ map_const_iterator(map_node< const Pair, Alloc >* current, map_node< const Pair, Alloc >* nil)
	    : current_(current), nil_(nil)
	{
	}

	//[> Constructor <] map_const_iterator(const map_node<Pair, Alloc> * current, const map_node<Pair, Alloc> * nil)
	//    :  current_(current), nil_(nil)
	//{ }

	//[> Constructor <] map_const_iterator( const map_node<const Pair, Alloc> * current, const map_node<const Pair,
	// Alloc> * nil)
	//    :  current_(current), nil_(nil)
	//{ }

	template < typename InputIt >
	/* Copy Constructor */ map_const_iterator(InputIt& other) : current_(other.get_current()), nil_(other.get_nil())
	{
	}

	map_const_iterator(non_const_iterator_t it)
		: current_(it.get_current()), nil_(it.get_nil())
	{
	}

	pointer operator->() const
	{
		return &(this->operator*());
	}

	reference operator*() const
	{
		return *(current_->pair);
	}

	template < typename It >
	bool operator==(It it)
	{
		return current_ == it.get_current();
	}

	template < typename It >
	bool operator!=(It it)
	{
		return current_ != it.get_current();
	}

	// iterator will cycle forward passing through an end's marker
	map_const_iterator& operator++()
	{
		if (nil_->parent == nil_) // Tree empty ?
			current_ = nil_;
		else if (current_ == nil_)
			current_ = leftmost_(nil_->parent);
		// If tree was empty but stuff got in since last call
		// If has successor...
		else if (current_->right != nil_)
			current_ = leftmost_(current_->right);   // ... goes to successor
			                                         // Else if it has no successor under itself
		else if (current_ == current_->parent->left) // If it is its parent's left child
			current_ = current_->parent;             // ... it becomes its parent
			                                         // Then it's its parent's right child
		else
		{
			while (current_ == current_->parent->right) // Go up the succession of right children
				current_ = current_->parent;
			if (current_ == current_->parent->left) // if it is its parent's left child
				current_ = current_->parent;        // ... it becomes its parent
			else
				current_ = nil_; // ..else nil_, end is reached
		}
		return *this;
	}

	// iterator will cycle backward passing through an end's marker
	map_const_iterator& operator--()
	{
		if (nil_->parent == nil_) // Tree empty ?
			current_ = nil_;
		else if (current_ == nil_) // Reached the end ?
			current_ = rightmost_(nil_->parent);
		else if (current_->left != nil_)
			current_ = rightmost_(current_->left);
		else if (current_ == current_->parent->right)
			current_ = current_->parent;
		else
		{
			while (current_ == current_->parent->left) // Go up the succession of left children
				current_ = current_->parent;
			if (current_ == current_->parent->right) // if it is its parent's right child
				current_ = current_->parent;         // ... it becomes its parent
			else
				current_ = nil_; // ..else nil_, end is reached
		}
		return *this;
	}

	map_const_iterator operator++(int)
	{
		map_const_iterator tmp = *this;
		                   operator++();
		return tmp;
	}

	map_const_iterator operator--(int)
	{
		map_const_iterator tmp = *this;
		                   operator--();
		return tmp;
	}

	const node_t* get_current()
	{
		return current_;
	}
	const node_t* get_nil()
	{
		return nil_;
	}
}; // map_const_iterator

} // namespace ft

#endif /* MAP_ITERATOR_HPP */
