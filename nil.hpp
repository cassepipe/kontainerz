#ifndef NIL_HPP
#define NIL_HPP

namespace ft {

template <typename T>
struct map_base_node;

template<typename T>
struct map_node;

// Singleton for the NIL node 
template <typename T>
map_node<T> *get_nil()
{
	static map_base_node<T> nil; 
	return static_cast<map_node<T> *>(&nil);
}

};

#endif /* NIL_HPP */
