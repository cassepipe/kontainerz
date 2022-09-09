#ifndef MAP_NODE_HPP
#define MAP_NODE_HPP

#include <cstddef>
#include <memory>

#include "pair.hpp"
#include "nil.hpp"

namespace ft {

template <typename Pair, typename Alloc > // Alloc = std::allocator<Pair>
struct map_node
{
	map_node<Pair, Alloc> *parent;
	map_node<Pair, Alloc> *left;
	map_node<Pair, Alloc> *right;
	int             level;
	Pair           *pair;
	Alloc			allocator;

	// To make the the nil node in get_nil()
	/*Default Constructor*/ map_node() :
		parent(this),
		left(this),
		right(this),
		level(0),
		pair(NULL)
	{ }

	/*Constructor*/ map_node(
			typename Pair::first_type k,
			typename Pair::second_type v,
			map_node<Pair, Alloc> *prt,
			map_node<Pair, Alloc> *l,
			map_node<Pair, Alloc> *r,
			int lvl = 1) :
		parent(prt),
		left(l),
		right(r),
		level(lvl),
		pair(NULL)
	{
		pair = allocator.allocate(1);
		allocator.construct(pair, Pair(k,v));
	}

	/* Copy Constructor */ 
	map_node(map_node const& other) :
		parent(other.parent),
		left(other.left),
		right(other.right),
		level(other.level),
		pair(NULL),
		allocator(other.allocator)
	{
		if (other.pair)
		{
			pair = allocator.allocate(1);
			allocator.construct(pair, *other.pair);
		}
	}

	~map_node()
	{
		if (pair)
		{
			allocator.destroy(pair);
			allocator.deallocate(pair, 1);
		}
	}

	// Null protect ?
	typename Pair::first_type & key() { return pair->first; }
	typename Pair::second_type & value() { return pair->second; }

}; // map_node

} // namespace ft

#endif /* MAP_NODE_HPP */
