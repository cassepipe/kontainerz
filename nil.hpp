#ifndef NIL_HPP
#define NIL_HPP

#include <memory>
#include <stdexcept>

namespace ft {

template <typename Pair, typename Alloc = std::allocator<Pair> >
struct map_node;

// Singleton for the NIL node 

template <typename T, typename Alloc>
map_node<T, Alloc> *get_nil()
{
	static map_node<T, Alloc> nil; 
#ifdef DEBUG
	if (nil.parent != &nil)
		throw std::logic_error("NIL's parent has been modified !");
#endif
	return &nil;
}

};

#endif /* NIL_HPP */
