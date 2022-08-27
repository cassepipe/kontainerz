#ifndef MAP_NODE_HPP
#define MAP_NODE_HPP

#include "pair.hpp"
#include "nil.hpp"

namespace ft {

template <typename Pair>
struct map_base_node;

template<typename Pair>
struct map_node;

// Separation between base node and node allows us to use our tree with non default-constructible Key and Value in map
// because having the KV Pair as member would force the call to Pair() - who in turn calls Key() and Value() - at the
// time of creation of the NIL node

template <typename Pair>
struct map_base_node
{
	map_node<Pair> *left;
	map_node<Pair> *right;
	map_node<Pair> *parent;
	int      level;

	// To make the the nil node in get_nil()
	/*Default Constructor*/ map_base_node() :
		left(static_cast<map_node<Pair> *>(this)),
		right(static_cast<map_node<Pair> *>(this)),
		parent(static_cast<map_node<Pair> *>(this)),
		level(0)
	{ }

	/*Constructor*/ map_base_node(map_node<Pair> *l, map_node<Pair> *r, map_node<Pair> *p, int lvl) :
		left(l),
		right(r),
		parent(p),
		level(lvl)
	{ }
}; // map_base_node

template<typename Pair>
struct map_node : public map_base_node<Pair>
{
	 Pair pair;

	/*Constructor*/ map_node(typename Pair::first_type k, typename Pair::second_type  v, map_node *p) :
		map_base_node<Pair>(get_nil<Pair>(), get_nil<Pair>(), p, 1),
		pair(k, v)
	{ }

	typename Pair::first_type & key() { return pair.first; }
	typename Pair::second_type & value() { return pair.second; }

}; // map_node

}; // namespace ft

#endif /* MAP_NODE_HPP */
