#include <exception>
#include <iostream>

#include "test.h"
#include "test_map.hpp"

int test_map()
{
	test_map_begin() ;
	test_map_clear() ;
	test_map_constructor() ;
	test_map_count() ;
	//test_map_empty() ;
	//test_map_end() ;
	//test_map_equal_range() ;
	//test_map_erase() ;
	//test_map_find() ;
	//test_map_get_allocator() ;
	//test_map_insert() ;
	//test_map_key_comp() ;
	//test_map_lower_bound() ;
	//test_map_operator_bracket() ;
	//test_map_operator_equal() ;
	//test_map_rbegin() ;
	//test_map_relational_operators() ;
	//test_map_rend() ;
	//test_map_size() ;
	//test_map_swap() ;
	//test_map_swap_overload() ;
	//test_map_tags() ;
	//test_map_upper_bound() ;
	//test_map_value_comp() ;
	return 0;
}

int	test_map_begin()
{
	map<char, int> tree;

	tree['b'] = 100;
	tree['a'] = 200;
	tree['c'] = 300;

	//tree.print_dot();

	for ( map<char, int>::iterator it = tree.begin(); it != tree.end(); ++it)
		std::cout << it->first << "=>" << it->second << std::endl;

	return 0;
}

int	test_map_clear()
{
	map<char, int> myMap;

	myMap['x']=100;
	myMap['y']=200;
	myMap['z']=300;

	std::cout << "myMap contains:" << std::endl;
	for ( map<char, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
		std::cout << it->first << "=>" << it->second << std::endl;

	myMap.clear();
	myMap['a']=1101;
	myMap['b']=2202;

	std::cout << "myMap contains:" << std::endl;
	for ( map<char, int>::iterator it = myMap.begin(); it != myMap.end(); ++it)
		std::cout << it->first << "=>" << it->second << std::endl;

	return 0;
}

static bool fncomp (const char lhs, const char rhs) {return lhs<rhs;}

struct classcomp {

	bool	operator() (const char & lhs, const char & rhs) const {return lhs<rhs;}
};

template <typename T, typename U, typename Comp>
static void	printMap( map<T, U, Comp> const & toPrint, std::string const & name ) {

	std::cout << name << ":" << std::endl;
	for ( typename map<T, U>::const_iterator it = toPrint.begin() ; it != toPrint.end() ; it ++ ) {
		std::cout << "\tfirst: "<< it->first << " second: " << it->second << std::endl;
	}
	std::cout << std::endl;
}

int	test_map_constructor()
{
	map<char, int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;
	printMap(first, "First map");

	map<char, int> second(first.begin(), first.end());
	printMap(second, "Second map");

	map<char, int> third (second);
	printMap(third, "Third map");

	map<char, int, classcomp> fourth;

	bool(*fn_pt)(char,char) = fncomp;
	map<char, int, bool(*)(char,char)> fifth (fn_pt);


	fourth.insert( first.begin(), first.end() );
	printMap<char, int, classcomp>(fourth, "Fourth map");

	for ( char c = 0 ; c <= 10 ; c++)
		fifth['a' + c]=c*10;
	printMap< char, int, bool(*)(char, char) >(fifth, "Fifth map");

	return 0;
}

int	test_map_count()
{
	map<char, int> myMap;
	char	c;

	myMap['a']=101;
	myMap['c']=202;
	myMap['f']=303;

	for ( c = 'a'; c < 'h'; c++) {

		std::cout << c << " is ";
		if ( myMap.count(c) == 0 )
			std::cout << "not ";
		std::cout << "an element of myMap" << std::endl;
	}
	return 0;
}

int	test_map_empty()
{

	return 0;
}

int	test_map_end()
{

	return 0;
}

int	test_map_equal_range()
{

	return 0;
}

int	test_map_erase()
{

	return 0;
}

int	test_map_find()
{

	return 0;
}

int	test_map_get_allocator()
{

	return 0;
}

int	test_map_insert()
{

	return 0;
}

int	test_map_key_comp()
{

	return 0;
}

int	test_map_lower_bound()
{

	return 0;
}

int	test_map_operator_bracket()
{

	return 0;
}

int	test_map_operator_equal()
{

	return 0;
}

int	test_map_rbegin()
{

	return 0;
}

int	test_map_relational_operators()
{

	return 0;
}

int	test_map_rend()
{

	return 0;
}

int	test_map_size()
{

	return 0;
}

int	test_map_swap()
{

	return 0;
}

int	test_map_swap_overload()
{

	return 0;
}

int	test_map_tags()
{

	return 0;
}

int	test_map_upper_bound()
{

	return 0;
}

int	test_map_value_comp()
{
	return 0;
}
