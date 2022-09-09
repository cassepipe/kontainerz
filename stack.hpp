#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespade ft {

template< class T, class Container = ft::vector<T> >
class stack
{
	typedef container_type    Container
	typedef value_type        Container::value_type
	typedef size_type         Container::size_type
	typedef reference         Container::reference
	typedef const_reference   Container::const_reference

	/* State */

  protected:

	Container	container_;

  public:

	stack() :
		stack(Container())
	{ }

	explicit stack( const Container& cont = Container() ) :
		container_(cont)
	{ }

	stack( const stack& other ) :
		container_(other.container_)
	{ }

	~stack()
	{
		~Container();
	}

	stack& operator=( const stack& other )
	{
		*this = other.container_;
	}

	/* Element Access */

	reference top()
	{
		return container_.back();
	}

	const_reference top() const
	{
		return container_.back();
	}

	/* Capacity */

	bool empty() const
	{
		return container_.empty();
	}

	size_type size() const
	{
		return container_.size();
	}

	/* Modifiers */

	void push( const value_type& value )
	{
		container_.push_back(value)
	}

	void pop()
	{
		container_.pop_back()
	}

	template< class T, class Container >
	friend bool operator==( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );

	template< class T, class Container >
	friend bool operator<( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs );

}; // class stack
   
template< class T, class Container >
bool operator==( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
{
	return lhs.container_ == rhs.container_;
}

template< class T, class Container >
bool operator!=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
{
	return !(lhs == rhs);
}

template< class T, class Container >
bool operator<( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
{
	return lhs.container_ < rhs.container_;
}

template< class T, class Container >
bool operator<=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
{
	return !(lsh > rhs)
}

template< class T, class Container >
bool operator>( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
{
	return rhs < lhs;
}

template< class T, class Container >
bool operator>=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
{
	return !(lhs < rhs);
}

} // namespace ft


#endif /* STACK_HPP */
