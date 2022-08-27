#ifndef NIL_HPP
#define NIL_HPP

namespace ft {

template <typename T>
struct map_base_node;

template<typename T>
struct map_node;

// Singleton for the NIL node 
template <typename T>
map_node<T> *get_nil();

};

#endif /* NIL_HPP */
