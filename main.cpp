#include "test.h"
#include "test_vector.hpp"
#include "test_stack.hpp"
#include "test_map.hpp"

void big_test();
int main()
{
	//test_map();
	//test_vector();
	//test_stack();
	big_test();
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

	tree.print_dot(1);
	tree.erase('b');
	tree.print_dot(2);
	tree.erase('c');
	tree.print_dot(2);
	tree.erase('d');
	tree.print_dot(2);
	tree.erase('e');
	tree.print_dot(2);
	tree.erase('f');


}
