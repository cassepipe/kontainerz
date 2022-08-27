#include "map_node.hpp"

namespace ft {

// Singleton for the NIL node 
template <typename T>
map_node<T> *get_nil()
{
	static map_base_node<T> nil; 
	return static_cast<map_node<T> *>(&nil);
}

}; //namespace ft
