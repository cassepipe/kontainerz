#include "test.hpp"

void test_stack_constructor()
{
	vector<int> my_vector (2, 200);
	std::vector<int> my_std_vector (2, 200);

	stack<int> first;
	stack<int, vector<int> > second (my_vector);

	stack<int, std::vector<int> > third;
	stack<int, std::vector<int> > fourth (my_std_vector);

	std::cout << "size of first: " << first.size() << std::endl;
	std::cout << "size of second: " << second.size() << std::endl;
	std::cout << "size of third: " << third.size() << std::endl;
	std::cout << "size of fourth: " << fourth.size() << std::endl;
}

void test_stack_empty()
{
}

void test_stack_pop()
{
}

void test_stack_push()
{
}

void test_stack_relationalOperators()
{
}

void test_stack_size()
{
}

void test_stack_top()
{
}

void test_stack()
{
	test_stack_constructor();
	test_stack_empty();
	test_stack_pop();
	test_stack_push();
	test_stack_relationalOperators();
	test_stack_size();
	test_stack_top();
}
