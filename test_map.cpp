#include "test.hpp"

void visual_test()
{
	map<char, int>           tree;
	map<char, int>::iterator it;

	tree['a'] = 10;
	tree['b'] = 20;
	tree['c'] = 30;
	tree['d'] = 40;
	tree['e'] = 50;
	tree['f'] = 60;

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

void test_map_begin()
{
	map<char, int> tree;

	tree['b'] = 100;
	tree['a'] = 200;
	tree['c'] = 300;

	// tree.print_dot();

	for (map<char, int>::iterator it = tree.begin(); it != tree.end(); ++it)
		std::cout << it->first << "=>" << it->second << std::endl;
}

void test_map_clear()
{
	map<char, int> my_map;

	my_map['x'] = 100;
	my_map['y'] = 200;
	my_map['z'] = 300;

	std::cout << "my_map contains:" << std::endl;
	for (map<char, int>::iterator it = my_map.begin(); it != my_map.end(); ++it)
		std::cout << it->first << "=>" << it->second << std::endl;

	my_map.clear();
	my_map['a'] = 1101;
	my_map['b'] = 2202;

	std::cout << "my_map contains:" << std::endl;
	for (map<char, int>::iterator it = my_map.begin(); it != my_map.end(); ++it)
		std::cout << it->first << "=>" << it->second << std::endl;
}

static bool fncomp(const char lhs, const char rhs)
{
	return lhs < rhs;
}

struct classcomp
{

	bool operator()(const char& lhs, const char& rhs) const
	{
		return lhs < rhs;
	}
};

template <typename T, typename U, typename Comp>
static void printMap(map<T, U, Comp> const& toPrint, std::string const& name)
{

	std::cout << name << ":" << std::endl;
	for (typename map<T, U>::const_iterator it = toPrint.begin(); it != toPrint.end(); it++)
	{
		std::cout << "\tfirst: " << it->first << " second: " << it->second << std::endl;
	}
	std::cout << std::endl;
}

void test_map_constructor()
{
	map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;
	printMap(first, "First map");

	map<char, int> second(first.begin(), first.end());
	printMap(second, "Second map");

	map<char, int> third(second);
	printMap(third, "Third map");

	map<char, int, classcomp> fourth;

	bool (*fn_pt)(char, char) = fncomp;
	map<char, int, bool (*)(char, char)> fifth(fn_pt);

	fourth.insert(first.begin(), first.end());
	printMap<char, int, classcomp>(fourth, "Fourth map");

	for (char c = 0; c <= 10; c++)
		fifth['a' + c] = c * 10;
	printMap<char, int, bool (*)(char, char)>(fifth, "Fifth map");
}

void test_map_count()
{
	map<char, int> my_map;
	char           c;

	my_map['a'] = 101;
	my_map['c'] = 202;
	my_map['f'] = 303;

	for (c = 'a'; c < 'h'; c++)
	{

		std::cout << c << " is ";
		if (my_map.count(c) == 0)
			std::cout << "not ";
		std::cout << "an element of my_map" << std::endl;
	}
}

void test_map_empty()
{
	map<char, int> my_map;

	my_map['a'] = 10;
	my_map['b'] = 20;
	my_map['c'] = 30;

	while (!my_map.empty())
	{

		std::cout << my_map.begin()->first << "=>" << my_map.begin()->second << std::endl;
		my_map.erase(my_map.begin());
	}
}

void test_map_end()
{

	map<char, int> my_map;

	my_map['b'] = 100;
	my_map['a'] = 200;
	my_map['c'] = 300;

	for (map<char, int>::iterator it = my_map.begin(); it != my_map.end(); ++it)
		std::cout << it->first << "=>" << it->second << std::endl;
}

void test_map_equal_range()
{

	map<char, int> my_map;

	my_map['a'] = 10;
	my_map['b'] = 20;
	my_map['c'] = 30;

#ifdef DEBUG
	my_map.print_dot(1);
#endif

	pair<map<char, int>::iterator, map<char, int>::iterator> ret;
	ret = my_map.equal_range('b');

	std::cout << "lower_bound points to ";
	std::cout << ret.first->first << "=> " << ret.first->second << std::endl;

	std::cout << "upper_bound points to ";
	std::cout << ret.second->first << "=> " << ret.second->second << std::endl;
}

void test_map_erase()
{
	map<char, int>           my_map;
	map<char, int>::iterator it;

	my_map['a'] = 10;
	my_map['b'] = 20;
	my_map['c'] = 30;
	my_map['d'] = 40;
	my_map['e'] = 50;
	my_map['f'] = 60;

	it = my_map.find('b');
	my_map.erase(it);

	my_map.erase('c');

#ifdef DEBUG
	my_map.print_dot(1);
#endif

	it = my_map.find('e');
	my_map.erase(it, my_map.end());

#ifdef DEBUG
	my_map.print_dot(2);
#endif

	for (it = my_map.begin(); it != my_map.end(); ++it)
		std::cout << it->first << "=>" << it->second << std::endl;
}

void test_map_find()
{
	map<char, int>           my_map;
	map<char, int>::iterator it;

	my_map['a'] = 50;
	my_map['b'] = 100;
	my_map['c'] = 150;
	my_map['d'] = 200;

	it = my_map.find('b');
	if (it != my_map.end())
		my_map.erase(it);

	std::cout << "elements in my_map:" << std::endl;
	std::cout << "a =>" << my_map.find('a')->second << std::endl;
	std::cout << "c =>" << my_map.find('c')->second << std::endl;
	std::cout << "d =>" << my_map.find('d')->second << std::endl;
}

void test_map_get_allocator()
{
	int                    psize;
	map<char, int>         my_map;
	pair<const char, int>* p;

	// allocate an array of 5 elements using my_map's allocator:
	p = my_map.get_allocator().allocate(5);

	// assing some values to array
	psize = sizeof(map<char, int>::value_type) * 5;

	std::cout << "The allocated array has a size of " << psize << " bytes" << std::endl;

	my_map.get_allocator().deallocate(p, 5);
}

void test_map_insert()
{
	map<char, int> my_map;

	my_map.insert(pair<char, int>('a', 100));
	my_map.insert(pair<char, int>('z', 200));

	pair<map<char, int>::iterator, bool> ret;

	ret = my_map.insert(pair<char, int>('z', 500));
	if (ret.second == false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << std::endl;
	}

	map<char, int>::iterator it = my_map.begin();
	my_map.insert(it, pair<char, int>('b', 300));
	my_map.insert(it, pair<char, int>('c', 400));

	map<char, int> anotherMap;
	anotherMap.insert(my_map.begin(), my_map.find('c'));

	std::cout << "my_map contains:" << std::endl;
	for (it = my_map.begin(); it != my_map.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "anotherMap contains:" << std::endl;
	for (it = anotherMap.begin(); it != anotherMap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

void test_map_key_comp()
{
	map<char, int> my_map;

	map<char, int>::key_compare myComp = my_map.key_comp();

	my_map['a'] = 100;
	my_map['b'] = 200;
	my_map['c'] = 300;

	std::cout << "my_map contains" << std::endl;

	char highest = my_map.rbegin()->first;

	map<char, int>::iterator it = my_map.begin();
	do
	{

		std::cout << it->first << " => " << it->second << std::endl;
	} while (myComp((*it++).first, highest));

	std::cout << std::endl;
}

void test_map_lower_bound()
{
	map<char, int>           my_map;
	map<char, int>::iterator itlow, itup;

	my_map['a'] = 20;
	my_map['b'] = 40;
	my_map['c'] = 60;
	my_map['d'] = 80;
	my_map['e'] = 100;

	itlow = my_map.lower_bound('b');
	itup  = my_map.upper_bound('d');
#ifdef DEBUG
	my_map.print_dot(1);
#endif

	my_map.erase(itlow, itup);

	for (map<char, int>::iterator it = my_map.begin(); it != my_map.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

void test_map_operator_bracket()
{
	map<char, std::string> my_map;

	my_map['a'] = "an element";
	my_map['b'] = "another element";
	my_map['c'] = my_map['b'];

	std::cout << "my_map['a'] is " << my_map['a'] << std::endl;
	std::cout << "my_map['b'] is " << my_map['b'] << std::endl;
	std::cout << "my_map['c'] is " << my_map['c'] << std::endl;
	std::cout << "my_map['d'] is " << my_map['d'] << std::endl;

	std::cout << "my_map now contains " << my_map.size() << " elements" << std::endl;
}

void test_map_operator_equal()
{
	map<char, int> first;
	map<char, int> second;

	first['x'] = 8;
	first['y'] = 16;
	first['z'] = 32;

	second = first;
	first  = map<char, int>();

	std::cout << "Size of first: " << first.size() << std::endl;
	std::cout << "Size of second: " << second.size() << std::endl;
}

void test_map_rbegin()
{

	map<char, int> my_map;

	my_map['x'] = 100;
	my_map['y'] = 200;
	my_map['z'] = 300;

	map<char, int>::reverse_iterator rit;
	for (rit = my_map.rbegin(); rit != my_map.rend(); ++rit)
		std::cout << rit->first << "=>" << rit->second << std::endl;
}

void test_map_relational_operators()
{

	map<char, int> foo, bar;

	foo['a'] = 100;
	foo['b'] = 200;

	bar['a'] = 10;
	bar['z'] = 1000;

	if (foo == bar)
	{
		std::cout << "foo and bar are equal" << std::endl;
	}
	if (foo != bar)
	{
		std::cout << "foo and bar are not equal" << std::endl;
	}
	if (foo < bar)
	{
		std::cout << "foo is less than bar" << std::endl;
	}
	if (foo > bar)
	{
		std::cout << "foo is greater than bar" << std::endl;
	}
	if (foo <= bar)
	{
		std::cout << "foo is less than or equal to bar" << std::endl;
	}
	if (foo >= bar)
	{
		std::cout << "foo is greater than or equal to bar" << std::endl;
	}
}

void test_map_rend()
{

	map<char, int> my_map;

	my_map['x'] = 100;
	my_map['y'] = 200;
	my_map['z'] = 300;

	map<char, int>::reverse_iterator rit;
	for (rit = my_map.rbegin(); rit != my_map.rend(); ++rit)
		std::cout << rit->first << "=>" << rit->second << std::endl;
}

void test_map_size()
{

	map<char, int> my_map;

	my_map['a'] = 101;
	my_map['b'] = 202;
	my_map['c'] = 302;

	std::cout << "my_map.size() is " << my_map.size() << std::endl;
}

void test_map_swap()
{

	map<char, int> foo, bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	foo.swap(bar);

	std::cout << "foo contains:" << std ::endl;
	for (map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "bar contains:" << std ::endl;
	for (map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

void test_map_swap_overload()
{

	map<char, int> foo, bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	std::swap(foo, bar);

	std::cout << "foo contains:" << std ::endl;
	for (map<char, int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "bar contains:" << std ::endl;
	for (map<char, int>::iterator it = bar.begin(); it != bar.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

void test_map_upper_bound()
{
	map<char, int>           my_map;
	map<char, int>::iterator itlow, itup;

	my_map['a'] = 20;
	my_map['b'] = 40;
	my_map['c'] = 60;
	my_map['d'] = 80;
	my_map['e'] = 100;

	itlow = my_map.lower_bound('b');
	itup  = my_map.upper_bound('d');

	my_map.erase(itlow, itup);

	for (map<char, int>::iterator it = my_map.begin(); it != my_map.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

void test_map_value_comp()
{
	map<char, int> my_map;

	my_map['x'] = 1001;
	my_map['y'] = 2002;
	my_map['z'] = 3003;

	std::cout << "my_map contains" << std::endl;

	pair<char, int> highest = *my_map.rbegin();

	map<char, int>::iterator it = my_map.begin();
	do
	{

		std::cout << it->first << " => " << it->second << std::endl;
	} while (my_map.value_comp()(*it++, highest));
}

void test_map()
{
	//visual_test();
	//test_map_begin();
	//test_map_clear();
	test_map_constructor();
	//test_map_count();
	//test_map_empty();
	//test_map_end();
	//test_map_equal_range();
	test_map_erase();
	//test_map_find();
	//test_map_get_allocator();
	//test_map_insert();
	//test_map_key_comp();
	//test_map_lower_bound();
	//test_map_operator_bracket();
	//test_map_operator_equal();
	//test_map_rbegin();
	//test_map_relational_operators();
	//test_map_rend();
	//test_map_size();
	//test_map_swap();
	//test_map_swap_overload();
	//test_map_upper_bound();
	//test_map_value_comp();
}
