#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespade ft {

template< class T, class Container = ft::vector<T> >
class stack
{
	public:
		stack() : stack(Container())
	{ }

		explicit stack( const Container& cont = Container() );

		stack( const stack& other );

		~stack()
		{

		}

		stack& operator=( const stack& other );

		/* Element Access */

		reference top();

		const_reference top() const;

		/* Capacity */

		bool empty() const;

		size_type size() const
		{

		}

		/* Modifiers */

		void push( const value_type& value );

		void pop();

}; // class stack
   
bool operator==( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
template< class T, class Container >
bool operator!=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
template< class T, class Container >
bool operator<( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
template< class T, class Container >
bool operator<=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
template< class T, class Container >
bool operator>( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );
template< class T, class Container >
bool operator>=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );

} // namespace ft


#endif /* STACK_HPP */
