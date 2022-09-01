#include "test.h"
#include "test_vector.hpp"
#include "test_stack.hpp"
#include "test_map.hpp"

void big_test();
int main()
{
	test_map();
	//test_vector();
	//test_stack();
	//big_test();
}


void big_test()
{
	map<char, int> tree;
	map<char, int>::iterator it;

	tree['a']=10;
	tree['b']=20;
	tree['c']=30;
	tree['d']=40;
	tree['e']=50;
	tree['f']=60;

#ifdef DEBUG
	tree.print_dot(1);
#endif
	tree.erase('b');
#ifdef DEBUG
	tree.print_dot(2);
#endif
	tree.erase('c');
#ifdef DEBUG
	tree.print_dot(2);
#endif
	tree.erase('d');
#ifdef DEBUG
	tree.print_dot(2);
#endif
	tree.erase('e');
#ifdef DEBUG
	tree.print_dot(2);
#endif
	tree.erase('f');


}
