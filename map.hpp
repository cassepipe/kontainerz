/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassepipe <norminet@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:51:41 by cassepipe         #+#    #+#             */
/*   Updated: 2022/09/10 13:51:41 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <cstddef>
#include <exception>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <utility>

#include "algorithm.hpp"
#include "map_iterator.hpp"
#include "map_node.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"

namespace ft
{

template < typename Key, typename Value, typename KeyCmpFn = std::less< Key >,
           typename Alloc = std::allocator< ft::pair< const Key, Value > > >
class map
{
  public:
	typedef Key                                         key_type;
	typedef Value                                       mapped_type;
	typedef ft::pair< const Key, Value >                value_type;
	typedef std::size_t                                 size_type;
	typedef std::ptrdiff_t                              difference_type;
	typedef Alloc                                       allocator_type;
	typedef KeyCmpFn                                    key_compare;
	typedef value_type&                                 reference;
	typedef value_type const&                           const_reference;
	typedef typename Alloc::pointer                     pointer;
	typedef typename Alloc::const_pointer               const_pointer;
	typedef ft::map_iterator< value_type, Alloc >       iterator;
	typedef ft::map_const_iterator< value_type, Alloc > const_iterator;
	typedef ft::reverse_iterator< iterator >            reverse_iterator;
	typedef ft::reverse_iterator< const_iterator >      const_reverse_iterator;

  protected:
	typedef ft::pair< const Key, Value >  pair_type_t;
	typedef map_node< value_type, Alloc > node_t;
	typedef node_t*                       node_ptr_t;
	typedef typename
	    // the template keyword is only here so that the < can be correctly parsed
	    Alloc::template rebind< node_t >::other node_alloc_t;

	/* STATE */
	node_alloc_t node_alloc_;
	node_ptr_t   nil_;
	node_ptr_t   root_;
	size_type    size_;
	key_compare  compare_func_;

	/* HELPERS */
	node_ptr_t in_order_successor_(node_ptr_t node)
	{
		if (node->right == nil_)
			return node;
		else
			node = node->right;
		while (node->left != nil_)
			node = node->left;
		return node;
	}

	node_ptr_t in_order_predecessor_(node_ptr_t node)
	{
		if (node->left == nil_)
			return node;
		else
			node = node->left;
		while (node->right != nil_)
			node = node->right;
		return node;
	}

	/*TREE BALANCING*/

	node_ptr_t skew_(node_ptr_t root)
	{
		if (root->level && root->left->level == root->level) // red node to our left?
			return rotate_right_(root);
		else
			return root; // else no change neeeded
	}

	node_ptr_t rotate_right_(node_ptr_t oldroot)
	{
		// Right rotation
		node_ptr_t newroot = oldroot->left;

		newroot->parent = oldroot->parent; // Parenting
		oldroot->parent = newroot;
		if (newroot->right != nil_)
			newroot->right->parent = oldroot;

		oldroot->left  = newroot->right;
		newroot->right = oldroot;

		// return pointer of the node that came out on top
		return newroot;
	}

	node_ptr_t split_(node_ptr_t root)
	{
		if (root->level && root->right->right->level == root->level) // 2 red nodes on our right ?
			return rotate_left_(root);
		else
			return root; // else no change needed
	}

	node_ptr_t rotate_left_(node_ptr_t oldroot)
	{
		// Left rotation
		node_ptr_t newroot = oldroot->right;

		newroot->parent = oldroot->parent; // Parenting
		oldroot->parent = newroot;
		if (newroot->left != nil_)
			newroot->left->parent = oldroot;

		oldroot->right = newroot->left;
		newroot->left  = oldroot;

		// promote newroot to next higher level
		newroot->level += 1;

		// return pointer of the node that came out on top
		return newroot;
	}

	void update_level_(node_ptr_t node)
	{
		int ideal_level = 1 + std::min(node->left->level, node->right->level);
		// node's level above ideal ?
		if (node->level > ideal_level) // necessary test bc must not be touched if below ideal level (red node)
		{
			node->level = ideal_level;
			if (node->right->level > ideal_level) // node's right child red ?
				node->right->level = ideal_level;
		}
	}

	// Update node's level and then three skews and two splits do the trick
	node_ptr_t fixup_after_delete_(node_ptr_t node)
	{
		update_level_(node);
		node               = skew_(node);
		node->right        = skew_(node->right);
		node->right->right = skew_(node->right->right);
		node               = split_(node);
		node->right        = split_(node->right);
		return (node);
	}

	/*INSERTION & DELETION*/

	// insert a key and value
	iterator insert_(Key const& k, Value const& v)
	{
		node_ptr_t ret = NULL;
		;

		root_         = insert_rec_(k, v, nil_, root_, &ret);
		root_->parent = root_;
		nil_->parent  = root_;
		return iterator(ret, nil_);
	}

	node_ptr_t insert_rec_(Key const& k, Value const& v, node_ptr_t parent, node_ptr_t current_node, node_ptr_t* ret)
	{
		if (current_node == nil_) // fell out of the tree?
		{
			++size_;
			current_node = node_alloc_.allocate(1);
			node_alloc_.construct(current_node, node_t(k, v, parent, nil_, nil_));
			// new (current_node) node_t(k, v, parent); // Placement new does not allocate and temp object
			*ret = current_node;
		}
		else if (compare_func_(k, current_node->key()))                                      // key is smaller?
			current_node->left = insert_rec_(k, v, current_node, current_node->left, ret);   // ->insert left
		else if (compare_func_(current_node->key(), k))                                      // key is larger?
			current_node->right = insert_rec_(k, v, current_node, current_node->right, ret); // ->insert right
		else
		{
			// current_node->value() = v; // To replace the node value
			*ret = current_node;
		}
		return split_(skew_(current_node)); // restructure and return result
	}

#define LEFT -1
#define RIGHT 1
#define ROOT 0

	// This implementation does not bother with special cases that do not need rebalancing
	node_ptr_t remove_rec_(Key k, node_ptr_t node, int child_status)
	{
		if (node == nil_) // Fell out of tree, key does not exist
			return node;  // No-op
		else if (compare_func_(k, node->key()))
			node->left = remove_rec_(k, node->left, -1); // Look in left subtree
		else if (compare_func_(node->key(), k))
			node->right = remove_rec_(k, node->right, 1); // Look in right subtree
		else                                              // Found it !
		{
			if (node->right == nil_ && node->left == nil_) // It's a leaf node, remove it
			{
				node_alloc_.destroy(node);
				node_alloc_.deallocate(node, 1);
				--size_;
				return nil_;
			}
			else if (node->left == nil_) // No left child ? Means it is a black leaf node. Replace with its red child
			{
				node_ptr_t right_child = node->right;

				if (child_status == LEFT)
				{
					node->parent->left  = right_child;
					right_child->parent = node->parent;
				}
				else if (child_status == RIGHT)
				{
					node->parent->right = right_child;
					right_child->parent = node->parent;
				}
				else
					right_child->parent = right_child;

				node_alloc_.destroy(node);
				node_alloc_.deallocate(node, 1);
				--size_;

				return (right_child);
			}
			else // Find successor, swap the node positions
			{
				using std::swap;
				node_ptr_t successor          = in_order_successor_(node);
				bool       successor_is_child = (node->right->left == nil_);

				swap(node->level, successor->level);
				swap(node->left, successor->left);
				if (!successor_is_child)
				{
					swap(node->right, successor->right);
					swap(node->parent, successor->parent);
				}
				else
				{
					node->right      = successor->right;
					successor->right = node;
				}

				if (child_status == LEFT)
					successor->parent->left = successor;
				if (child_status == RIGHT)
					successor->parent->left = successor;
				if (child_status == ROOT)
					successor->parent = successor;
				if (!successor_is_child)
					node->parent->left = node;
				successor->right->parent = successor;
				successor->left->parent  = successor;
				if (node->right != nil_)
					node->right->parent = node;

				node        = successor;
				node->right = remove_rec_(k, node->right, 1);
			}
		}
		return fixup_after_delete_(node);
	}

#undef LEFT
#undef RIGHT
#undef ROOT

	node_ptr_t clear_(node_ptr_t node)
	{
		if (node->left != nil_)
			node->left = clear_(node->left);
		if (node->right != nil_)
			node->right = clear_(node->right);
		// If both have returned nil_, our node is now a leaf node
		if (node != nil_ && node->right == nil_ && node->left == nil_) // It's a leaf node, remove it
		{
			delete node;
			--size_;
			return nil_;
		}
		return nil_;
	}

	node_ptr_t init_NIL()
	{
		nil_         = node_alloc_.allocate(1);
		nil_->parent = nil_;
		nil_->left   = nil_;
		nil_->right  = nil_;
		nil_->level  = 0;
		nil_->pair   = NULL;
		return nil_;
	}

	/* INTERFACE */

  public:
	explicit /*Constructor*/ map(const KeyCmpFn& comp_fn = KeyCmpFn(), const Alloc& alloc = Alloc())
	    : node_alloc_(alloc), // node_alloc_ and alloc are different types, implicit conversion thanks to allocator's
	                          // special ctor
	      nil_(init_NIL()), root_(nil_), size_(0), compare_func_(comp_fn)
	{
	}

	template < class InputIt >
	/* Range Constructor */ map(InputIt first, InputIt last, const KeyCmpFn& comp_fn = KeyCmpFn(),
	                            const Alloc& alloc = Alloc())
	    : node_alloc_(alloc), // node_alloc_ and alloc are different types, implicit conversion thanks to allocator's
	                          // special ctor
	      nil_(init_NIL()), root_(nil_), size_(0), compare_func_(comp_fn)
	{
		insert(first, last);
	}

	/* Copy Constructor */ map(map const& other)
	    : node_alloc_(other.get_allocator()), nil_(init_NIL()), root_(nil_), size_(0),
	      compare_func_(other.key_comp()) // Is this necessary ?
	{
		if (other.empty() == false)
			insert(other.begin(), other.end()); // There must be a better way though
	}

	/*Destructor*/ ~map()
	{
		this->clear();
		node_alloc_.destroy(nil_);
		node_alloc_.deallocate(nil_, 1);
	}

	map& operator=(map const& rhs)
	{
		this->clear();
		if (rhs.empty() == false)
			insert(rhs.begin(), rhs.end()); // There must be a better way though
		return *this;
	}

	// Element Access

	mapped_type& operator[](const Key& key)
	{
		// Using operator[] requires that the mapped type be default constructible
		// If that is not the case use this->at() or in C++11 this->emplace()
		iterator it = lower_bound(key); // (*it).first is *not less* than key
		if (it == this->end() ||
		    compare_func_(key, (*it).first)) // if (*i).first is greater than key i.e key does not exist
			it = insert(it, pair_type_t(key, mapped_type())); // Insert default value with that key
		return (*it).second;
	}

	mapped_type& at(const Key& key)
	{
		iterator it = find(key);
		if (it == this->end())
			throw std::out_of_range("ft::map::at() : Invalid key");
		else
			return (*it).second;
	}

	mapped_type const& at(const Key& key) const
	{
		const_iterator it = find(key);
		if (it == this->end())
			throw std::out_of_range("ft::map::at() : Invalid key");
		else
			return (*it).second;
	}

	// Modifiers

	void clear()
	{
		root_ = clear_(root_);
		root_->parent = nil_;
	}

	// Insert Key Value pair
	template < typename P >
	ft::pair< iterator, bool > insert(P const& pair)
	{
		size_type size_before = size_;
		iterator  it          = insert_(pair.first, pair.second);

		if (size_before == size_)
			return ft::make_pair(it, false);
		else
			return ft::make_pair(it, true);
	}

	// Insert range
	template < typename InputIt >
	void insert(InputIt first, InputIt last)
	{
		for (; first != last; ++first)
			insert(*first);
	}

	template < typename It, typename P >
	iterator insert(It, P const& new_val)
	{
		return insert(new_val).first;
	}

	size_type erase(Key const& k)
	{
		size_type size_before = size_;
		root_                 = remove_rec_(k, root_, 0);
		root_->parent         = root_;
		nil_->parent          = root_;
		if (size_before == size_)
			return 0;
		return 1;
	}

	void erase(iterator it)
	{
		this->erase((*it).first);
	}

	void erase(iterator first, iterator last)
	{
		while (first != last)
		{
			key_type key_to_delete = (*first).first;
			// Need to increment first else erase would invalidate our operator
			++first;
			this->erase(key_to_delete);
		}
	}

	void swap(map& other)
	{
		if (this != &other)
		{
			std::swap(root_, other.root_);
			std::swap(size_, other.size_);
			std::swap(nil_, other.nil_);
		}
	}

	/* CAPACITY */

	bool empty() const
	{
		if (size_ == 0)
			return true;
		else
			return false;
	}

	size_type size() const
	{
		return size_;
	}

	size_type max_size() const
	{
		return node_alloc_.max_size();
	}

	/* LOOKUP */

	size_type count(const Key& key) const
	{
		if (find(key) == this->end())
			return 0;
		return 1;
	}

	iterator find(const Key& key)
	{
		node_ptr_t current;
		bool       searched_is_strictly_less;
		bool       searched_is_strictly_greater;

		current = root_;
		while (current != nil_)
		{
			searched_is_strictly_less    = compare_func_(key, current->key());
			searched_is_strictly_greater = compare_func_(current->key(), key);
			if (searched_is_strictly_less)
				current = current->left;
			else if (searched_is_strictly_greater)
				current = current->right;
			else // they're equal
				return iterator(current, nil_);
		}
		return this->end();
	}

	const_iterator find(const Key& key) const
	{
		node_ptr_t current;
		bool       searched_is_strictly_less;
		bool       searched_is_strictly_greater;

		current = root_;
		while (current != nil_)
		{
			searched_is_strictly_less    = compare_func_(key, current->key());
			searched_is_strictly_greater = compare_func_(current->key(), key);
			if (searched_is_strictly_less)
				current = current->left;
			else if (searched_is_strictly_greater)
				current = current->right;
			else // they're equal
				return const_iterator(current, nil_);
		}
		return this->end();
	}

	ft::pair< iterator, iterator > equal_range(const Key& key)
	{
		return ft::make_pair(lower_bound(key), upper_bound(key));
	}

	ft::pair< const_iterator, const_iterator > equal_range(const Key& key) const
	{
		return ft::make_pair(lower_bound(key), upper_bound(key));
	}

	/* Returns lower bound not less than key */
	iterator lower_bound(const Key& key)
	{
		bool       searched_is_strictly_less;
		bool       searched_is_strictly_greater;
		node_ptr_t current;
		node_ptr_t parent;

		if (root_ == nil_) // Empty tree
			return this->end();
		parent  = NULL;
		current = root_;
		while (current != nil_)
		{
			searched_is_strictly_less    = compare_func_(key, current->key());
			searched_is_strictly_greater = compare_func_(current->key(), key);

			parent = current;
			if (searched_is_strictly_less) // than current's key
				current = current->left;
			else if (searched_is_strictly_greater) // than current's key
				current = current->right;
			else // searched and current kes are equal
				return iterator(current, nil_);
		}
		return ++iterator(parent, nil_);
	}

	/* Returns lower bound not less than key */
	const_iterator lower_bound(const Key& key) const
	{
		bool       searched_is_strictly_less;
		bool       searched_is_strictly_greater;
		node_ptr_t current;
		node_ptr_t parent;

		if (root_ == nil_) // Empty tree
			return this->end();
		parent  = NULL;
		current = root_;
		while (current != nil_)
		{
			searched_is_strictly_less    = compare_func_(key, current->key());
			searched_is_strictly_greater = compare_func_(current->key(), key);

			parent = current;
			if (searched_is_strictly_less) // than current's key
				current = current->left;
			else if (searched_is_strictly_greater) // than current's key
				current = current->right;
			else // searched and current kes are equal
				return iterator(current, nil_);
		}
		return ++iterator(parent, nil_);
	}

	/* Returns iterator to the first element greater than key */
	iterator upper_bound(const Key& key)
	{
		bool       searched_is_strictly_less;
		bool       searched_is_strictly_greater;
		node_ptr_t current;
		node_ptr_t best_predecessor;

		if (root_ == nil_) // Empty tree
			return this->end();
		best_predecessor = NULL;
		current          = root_;
		while (current != nil_)
		{
			searched_is_strictly_less    = compare_func_(key, current->key());
			searched_is_strictly_greater = compare_func_(current->key(), key);

			if (searched_is_strictly_less) // than current's key
			{
				current          = current->left;
				best_predecessor = current;
			}
			else if (searched_is_strictly_greater) // than current's key
			{
				current          = current->right;
				best_predecessor = current;
			}
			else
			{
				best_predecessor = current;
				break;
			}
		}
		return ++iterator(best_predecessor, nil_);
	}

	/* Returns iterator to the first element greater than key */
	const_iterator upper_bound(const Key& key) const
	{
		bool       searched_is_strictly_less;
		bool       searched_is_strictly_greater;
		node_ptr_t current;
		node_ptr_t best_predecessor;

		if (root_ == nil_) // Empty tree
			return this->end();
		best_predecessor = NULL;
		current          = root_;
		while (current != nil_)
		{
			searched_is_strictly_less    = compare_func_(key, current->key());
			searched_is_strictly_greater = compare_func_(current->key(), key);

			if (searched_is_strictly_less) // than current's key
			{
				current          = current->left;
				best_predecessor = current;
			}
			else if (searched_is_strictly_greater) // than current's key
			{
				current          = current->right;
				best_predecessor = current;
			}
			else
			{
				best_predecessor = current;
				break;
			}
		}
		return ++iterator(best_predecessor, nil_);
	}

	/* OBSERVERS */

	allocator_type get_allocator() const
	{
		return allocator_type(node_alloc_); // Implicit conversion
	}

	key_compare key_comp() const
	{
		return compare_func_;
	}

  protected:
	node_ptr_t leftmost_(node_ptr_t node)
	{
		while (node->left != nil_)
			node = node->left;
		return node;
	}

  public:
	iterator begin()
	{
		return ++iterator(nil_, nil_);
	}

	iterator end()
	{
		return iterator(nil_, nil_);
	}

	const_iterator begin() const
	{
		return ++const_iterator(nil_, nil_);
	}

	const_iterator end() const
	{
		return const_iterator(nil_, nil_);
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(this->end());
	}

	reverse_iterator rend()
	{
		return reverse_iterator(this->begin());
	}

	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(this->end());
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(this->begin());
	}

	/* VALUE COMPARE */

	/* This exists only for forwarding the key_comp function*/
	struct value_compare : public std::binary_function< pair_type_t, pair_type_t, bool >
	{
		friend class map;

		KeyCmpFn comp;
		value_compare(KeyCmpFn c) : comp(c)
		{
		}

		value_compare() : comp()
		{
		}
		bool operator()(pair_type_t const& x, pair_type_t const& y) const
		{
			return comp(x.first, y.first);
		}
	};

	typename map< Key, Value, KeyCmpFn, Alloc >::value_compare value_comp() const
	{
		return value_compare(compare_func_);
	}

#ifdef DEBUG
	/* DEBUG */

	void print_node(std::stringstream& ss, node_ptr_t node)
	{
		if (node != nil_)
		{
			ss << node->key() << " [label=< <b>" << node->key() << "</b><br/> <sub>" << node->parent->key()
			   << "</sub>>]\n\t";
			if (node->left != nil_)
			{
				if (node->left->level == node->level)
				{
					ss << "{rank=same; " << node->key() << "; " << node->left->key() << "}\n\t";
					ss << node->left->key() << " [color=red]\n\t";
				}
				ss << node->key() << " -> " << node->left->key() << "\n\t";
				print_node(ss, node->left);
			}
			if (node->right != nil_)
			{
				if (node->right->level == node->level)
				{
					ss << "{rank=same; " << node->key() << "; " << node->right->key() << "}\n\t";
					ss << node->right->key() << " [color=red]\n\t";
				}
				ss << node->key() << " -> " << node->right->key() << "\n\t";
				print_node(ss, node->right);
			}
		}
	}

#define DEFAULT_FILENAME "tree"
	void print_dot()
	{
		static int n;
		print_dot(++n);
	}

	void print_dot(int n)
	{
		std::stringstream ss;
		print_node(ss, root_);

		std::stringstream title;
		title << DEFAULT_FILENAME << n << ".dot";
		std::ofstream file(title.str().c_str());
		file << "digraph {\n\n\t";
		file << ss.str();
		file << "\n}";
	}
#undef DEFAULT_FILENAME
#endif /* ifdef DEBUG */
};     // class AA_tree

template < class Key, class T, class Compare, class Allocator >
bool operator==(map< Key, T, Compare, Allocator > const& x, map< Key, T, Compare, Allocator > const& y)
{
	if (x.size() != y.size())
		return false;
	return ft::equal(x.begin(), x.end(), y.begin());
}

template < class Key, class T, class Compare, class Allocator >
bool operator<(map< Key, T, Compare, Allocator > const& x, map< Key, T, Compare, Allocator > const& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template < class Key, class T, class Compare, class Allocator >
bool operator!=(map< Key, T, Compare, Allocator > const& x, map< Key, T, Compare, Allocator > const& y)
{
	return !(x == y);
}

template < class Key, class T, class Compare, class Allocator >
bool operator>(map< Key, T, Compare, Allocator > const& x, map< Key, T, Compare, Allocator > const& y)
{
	return !(x <= y);
}

template < class Key, class T, class Compare, class Allocator >
bool operator>=(map< Key, T, Compare, Allocator > const& x, map< Key, T, Compare, Allocator > const& y)
{
	return !(x < y);
}

template < class Key, class T, class Compare, class Allocator >
bool operator<=(map< Key, T, Compare, Allocator > const& x, map< Key, T, Compare, Allocator > const& y)
{
	return !(y < x);
}

} // namespace ft

// specialized algorithms
namespace std
{

template < class Key, class T, class Compare, class Allocator >
void swap(ft::map< Key, T, Compare, Allocator >& x, ft::map< Key, T, Compare, Allocator >& y)
{
	x.swap(y);
	return;
}

} // namespace std

#endif /* MAP_HPP */
