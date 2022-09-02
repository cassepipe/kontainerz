#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <cstddef>
#include "iterator_traits.hpp"
#include "nil.hpp"
#include "map_node.hpp"
#include "remove_cv.hpp"

#define NIL get_nil<Pair, Alloc>()

namespace ft {

template <typename Pair, typename Alloc>
class map_iterator
{
	public:
		typedef Pair                                                 value_type;
		typedef value_type&                                           reference;
		typedef value_type*                                             pointer;
		typedef ft::bidirectional_iterator_tag                iterator_category;
		typedef std::ptrdiff_t                                  difference_type;
	protected:
		typedef map_node<Pair, Alloc>                                    node_t;
		typedef node_t *                                             node_ptr_t;

		/* STATE */
		node_ptr_t             *root_ptr_;
		node_ptr_t             current_;

		/* HELPERS */

		static node_ptr_t leftmost_(node_ptr_t node)
		{
			while (node->left != NIL)
				node = node->left;
			return node;
		}

		static node_ptr_t rightmost_(node_ptr_t node)
		{
			while (node->right != NIL)
				node = node->right;
			return node;
		}

	public:
		/* Default constructor */ map_iterator()
			: root_ptr_(NULL), current_(NIL)
		{ }
		
		/* Constructor */ map_iterator(map_node<Pair, Alloc> ** root_ptr, map_node<Pair, Alloc> * current)
			: root_ptr_(root_ptr), current_(current)
		{ }

		/* Constructor */ map_iterator(map_node<const Pair> ** root_ptr, map_node<const Pair> * current)
			: root_ptr_(root_ptr), current_(current)
		{ }

		template <typename InputIt>
			/* Copy Constructor */ map_iterator(InputIt & other)
			: root_ptr_(other.get_root()), current_(other.get_current())
			{ }

		map_iterator &operator=(map_iterator const &rhs)
		{
			root_ptr_ = rhs.root_ptr_;
			current_ = rhs.current_;
			return *this;
		}

		pointer operator->() const { return &(this->operator*()); }

		reference operator*() const { return *(current_->pair); }

		template <typename It>
			bool operator==(It it) { return current_ == it.get_current(); }

		template <typename It>
			bool operator!=(It it) { return current_ != it.get_current(); }

		// iterator will cycle forward passing through an end's marker
		map_iterator &operator++()
		{
			if (root_ptr_ == NULL || *root_ptr_ == NIL) // Tree empty ?
				current_ = NIL;
			else if (current_ == NIL) 
				current_ = leftmost_(*root_ptr_); // root_ptr_ will never be NULL here
			// If has successor...
			else if (current_->right != NIL)
				current_ = leftmost_(current_->right); // ... goes to successor
		   // Else if it has no successor under itself
			else if (current_ == current_->parent->left) // If it is its parent's left child
				current_ = current_->parent; // ... it becomes its parent
			else // Then it's its parent's right child
			{
				while (current_ == current_->parent->right) // Go up the succession of right children
					current_ = current_->parent;
				if (current_ == current_->parent->left) // if it is its parent's left child
					current_ = current_->parent; // ... it becomes its parent
				else
					current_ = NIL; // ..else NIL, end is reached
			}
			return *this;
		}

		// iterator will cycle backward passing through an end's marker
		map_iterator &operator--()
		{
			if (root_ptr_ == NULL || *root_ptr_ == NIL) // Tree empty ?
				current_ = NIL;
			else if (current_ == NIL) // Reached the end ?
				current_ = rightmost_(*root_ptr_); // root_ptr_ will never be NULL here
			else if (current_->left != NIL)
				current_ = rightmost_(current_->left);
			else if (current_ == current_->parent->right)
				current_ = current_->parent;
			else 
			{
				while (current_ == current_->parent->left) // Go up the succession of left children
					current_ = current_->parent;
				if (current_ == current_->parent->right) // if it is its parent's right child
					current_ = current_->parent; // ... it becomes its parent
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

		node_ptr_t *get_root() { return root_ptr_; }
		node_ptr_t get_current() { return current_; }
}; // map_iterator
   
  
template <typename Pair, typename Alloc>
class map_const_iterator
{
	public:
		typedef Pair const                                           value_type;
		typedef value_type&                                           reference;
		typedef value_type*                                             pointer;
		typedef ft::bidirectional_iterator_tag                iterator_category;
		typedef std::ptrdiff_t                                  difference_type;
	protected:
		typedef map_node<Pair, Alloc>                                    node_t;
		typedef node_t *                                             node_ptr_t;

		/* STATE */
		map_node<Pair, Alloc>             **root_ptr_;
		node_ptr_t             current_;

		/* HELPERS */

		static node_ptr_t leftmost_(node_ptr_t node)
		{
			while (node->left != NIL)
				node = node->left;
			return node;
		}

		static node_ptr_t rightmost_(node_ptr_t node)
		{
			while (node->right != NIL)
				node = node->right;
			return node;
		}

	public:
		/* Default constructor */ map_const_iterator()
			: root_ptr_(NULL), current_(NIL)
		{ }

		/* Constructor */ map_const_iterator(map_node<Pair, Alloc> ** root_ptr, map_node<Pair, Alloc> * current)
			: root_ptr_(root_ptr), current_(current)
		{ }

		/* Constructor */ map_const_iterator(map_node<Pair, Alloc> * const* root_ptr, map_node<Pair, Alloc> * current)
			: root_ptr_(root_ptr), current_(current)
		{ }

		/* Constructor */ map_const_iterator(map_node<const Pair, Alloc> ** root_ptr, map_node<const Pair, Alloc> * current)
			: root_ptr_(root_ptr), current_(current)
		{ }

		/* Constructor */ map_const_iterator(map_node<const Pair, Alloc> * const* root_ptr, map_node<const Pair, Alloc> * current)
			: root_ptr_(root_ptr), current_(current)
		{ }

		template <typename InputIt>
			/* Copy Constructor */ map_const_iterator(InputIt & other)
			: root_ptr_(other.get_root()), current_(other.get_current())
			{ }

		map_const_iterator &operator=(map_const_iterator const &rhs)
		{
			root_ptr_ = rhs.root_ptr_;
			current_ = rhs.current_;
			return *this;
		}
		pointer operator->() const { return &(this->operator*()); }

		reference operator*() const { return *(current_->pair); }

		template <typename It>
			bool operator==(It it) { return current_ == it.get_current(); }

		template <typename It>
			bool operator!=(It it) { return current_ != it.get_current(); }

		// iterator will cycle forward passing through an end's marker
		map_const_iterator &operator++()
		{
			if (root_ptr_ == NULL || *root_ptr_ == NIL) // Tree empty ?
				current_ = NIL;
			else if (current_ == NIL) 
				current_ = leftmost_(*root_ptr_); // root_ptr_ will never NULL here
			// If tree was empty but stuff got in since last call
			// If has successor...
			else if (current_->right != NIL)
				current_ = leftmost_(current_->right); // ... goes to successor
													   // Else if it has no successor under itself
			else if (current_ == current_->parent->left) // If it is its parent's left child
				current_ = current_->parent; // ... it becomes its parent
											 // Then it's its parent's right child
			else 
			{
				while (current_ == current_->parent->right) // Go up the succession of right children
					current_ = current_->parent;
				if (current_ == current_->parent->left) // if it is its parent's left child
					current_ = current_->parent; // ... it becomes its parent
				else
					current_ = NIL; // ..else NULL, end is reached
			}
			return *this;
		}

		// iterator will cycle backward passing through an end's marker
		map_const_iterator &operator--()
		{
			if (root_ptr_ == NULL || *root_ptr_ == NIL) // Tree empty ?
				current_ = NIL;
			else if (current_ == NIL) // Reached the end ?
				current_ = rightmost_(*root_ptr_); // root_ptr_ will never be NULL here
			else if (current_->left != NIL)
				current_ = rightmost_(current_->left);
			else if (current_ == current_->parent->right)
				current_ = current_->parent;
			else 
			{
				while (current_ == current_->parent->left) // Go up the succession of left children
					current_ = current_->parent;
				if (current_ == current_->parent->right) // if it is its parent's right child
					current_ = current_->parent; // ... it becomes its parent
				else
					current_ = NIL; // ..else NULL, end is reached
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

		node_ptr_t *get_root() { return root_ptr_; }
		node_ptr_t get_current() { return current_; }
}; // map_const_iterator
   
#undef NIL
   
} // namespace ft

#endif /* MAP_ITERATOR_HPP */
