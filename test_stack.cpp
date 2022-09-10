#include "test.hpp"

void test_stack_constructor()
{
	vector<int>      my_vector(2, 200);
	std::vector<int> my_std_vector(2, 200);

	stack<int>              first;
	stack<int, vector<int> > second(my_vector);

	stack<int, std::vector<int> > third;
	stack<int, std::vector<int> > fourth(my_std_vector);

	cout << "size of first: " << first.size() << endl;
	cout << "size of second: " << second.size() << endl;
	cout << "size of third: " << third.size() << endl;
	cout << "size of fourth: " << fourth.size() << endl;
}

void test_stack_empty()
{
	stack<int> myStack;
	int                   sum = 0;
	for (int i = 1; i <= 10; i++)
		myStack.push(i);
	while (!myStack.empty())
	{
		sum += myStack.top();
		myStack.pop();
	}
	cout << "total: " << sum << endl;
}

void test_stack_pop()
{
	stack<int> myStack;

	for (int i = 0; i < 5; ++i)
		myStack.push(i);

	cout << "Popping out elements...";
	while (!myStack.empty())
	{
		cout << ' ' << myStack.top();
		myStack.pop();
	}
	cout << endl;
}

void test_stack_push()
{
	stack<int> myStack;

	for (int i = 0; i < 5; ++i)
		myStack.push(i);
	cout << "Popping out elements...";
	while (!myStack.empty())
	{
		cout << ' ' << myStack.top();
		myStack.pop();
	}
	cout << endl;
}

void test_stack_relationalOperators()
{

	std::vector<int> fooVec(3, 100);
	std::vector<int> barVec(5, 200);

	stack< int, std::vector<int> > foo(fooVec);
	stack< int, std::vector<int> > bar(barVec);

	if (foo == bar)
		cout << "foo and bar are equal" << endl;
	if (foo != bar)
		cout << "foo and bar are not equal" << endl;
	if (foo < bar)
		cout << "foo is less than bar" << endl;
	if (foo > bar)
		cout << "foo is greater than bar" << endl;
	if (foo <= bar)
		cout << "foo is less than or equal to bar" << endl;
	if (foo >= bar)
		cout << "foo is greater than or equal to bar" << endl;
}

void test_stack_size()
{
	stack<int> myInts;
	cout << "0. size: " << myInts.size() << endl;
	for (int i=0; i<5; i++) myInts.push(i);
	cout << "1. size: " << myInts.size() << endl;
	myInts.pop();
	cout << "2. size: " << myInts.size() << endl;
}

void test_stack_top()
{
	stack<int> myStack;

	myStack.push(10);
	myStack.push(20);
	myStack.top() -= 5;
	cout << "myStack.top() is now " << myStack.top() << endl;
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
