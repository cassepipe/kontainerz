#ifndef NIL_HPP
#define NIL_HPP

#include <memory>

namespace ft {

template <typename Pair, typename Alloc = std::allocator<Pair> >
struct map_node;

// Singleton for the NIL node 

template <typename T, typename Alloc>
map_node<T, Alloc> *get_nil()
{
	static map_node<T, Alloc> nil; 
	return &nil;
}

};

#endif /* NIL_HPP */
