/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassepipe <norminet@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:52:22 by cassepipe         #+#    #+#             */
/*   Updated: 2022/09/10 13:52:22 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"
#include "test.hpp"

void visual_test()
{
	map< char, int >           tree;
	map< char, int >::iterator it;

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
	tree.print_dot(1);
#endif
	tree.erase('c');
#ifdef DEBUG
	tree.print_dot(1);
#endif
	tree.erase('d');
#ifdef DEBUG
	tree.print_dot(1);
#endif
	tree.erase('e');
#ifdef DEBUG
	tree.print_dot(1);
#endif
	tree.erase('f');
#ifdef DEBUG
	tree.print_dot(1);
#endif
}

void map_begin()
{
	map< char, int > tree;

	tree['b'] = 100;
	tree['a'] = 200;
	tree['c'] = 300;

	for (map< char, int >::iterator it = tree.begin(); it != tree.end(); ++it)
		cout << it->first << "=>" << it->second << endl;
}

void map_clear()
{
	map< char, int > my_map;

	my_map['x'] = 100;
	my_map['y'] = 200;
	my_map['z'] = 300;

	cout << "my_map contains:" << endl;
	for (map< char, int >::iterator it = my_map.begin(); it != my_map.end(); ++it)
		cout << it->first << "=>" << it->second << endl;

	my_map.clear();
	my_map['a'] = 1101;
	my_map['b'] = 2202;

	cout << "my_map contains:" << endl;
	for (map< char, int >::iterator it = my_map.begin(); it != my_map.end(); ++it)
		cout << it->first << "=>" << it->second << endl;

	SETUP_ARRAYS();
	{
		strmap m;
		PRINT_ALL(m);
		m.clear();
		PRINT_ALL(m);
		m.insert(strstr_arr, strstr_arr + 16);
		PRINT_ALL(m);
		m.clear();
		PRINT_LINE("Size:", m.size());
		cout << "\nMap content:\n";
		print_map(m.begin(), m.end());
		cout << endl;
	}
}

void map_constructor()
{
	map< char, int > first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;
	printMap(first, "First map");

	map< char, int > second(first.begin(), first.end());
	printMap(second, "Second map");

	map< char, int > third(second);
	printMap(third, "Third map");

	map< char, int, classcomp > fourth;

	bool (*fn_pt)(char, char) = fncomp;
	map< char, int, bool (*)(char, char) > fifth(fn_pt);

	fourth.insert(first.begin(), first.end());
	printMap< char, int, classcomp >(fourth, "Fourth map");

	for (char c = 0; c <= 10; c++)
		fifth['a' + c] = c * 10;
	printMap< char, int, bool (*)(char, char) >(fifth, "Fifth map");
}

void map_count()
{
	map< char, int > my_map;
	char             c;

	my_map['a'] = 101;
	my_map['c'] = 202;
	my_map['f'] = 303;

	for (c = 'a'; c < 'h'; c++)
	{
		cout << c << " is ";
		if (my_map.count(c) == 0)
			cout << "not ";
		cout << "an element of my_map" << endl;
	}
	SETUP_ARRAYS();
	{
		intmap            m(intstr_arr, intstr_arr + intstr_size);
		intmap::size_type c = m.count(64);

		PRINT_LINE("Count:", c);
		c = m.count(145);
		PRINT_LINE("Count:", c);
		c = m.count(11);
		PRINT_LINE("Count:", c);
		m.insert(make_pair(34, "aaaaaaaaaaaaa"));
		m.insert(make_pair(2, "bbbbbbbbbbbbbbbbbbbbbbbbbbb"));
		m.insert(make_pair(9, ""));
		m.insert(make_pair(3, "i"));
		m.insert(make_pair(22, "sadfkjndskfjn"));
		m.insert(make_pair(10, "ccccccccccccccccccccccccccccccccccccccccccccc"));
		c = m.count(34);
		PRINT_LINE("Count:", c);
		c = m.count(2);
		PRINT_LINE("Count:", c);
		c = m.count(9);
		PRINT_LINE("Count:", c);
		m.erase(9);
		c = m.count(9);
		PRINT_LINE("Count:", c);
		c = m.count(10);
		PRINT_LINE("Count:", c);
		c = m.count(22);
		PRINT_LINE("Count:", c);
	}
}

void map_empty()
{
	map< char, int > my_map;

	my_map['a'] = 10;
	my_map['b'] = 20;
	my_map['c'] = 30;

	while (!my_map.empty())
	{
		cout << my_map.begin()->first << "=>" << my_map.begin()->second << endl;
		my_map.erase(my_map.begin());
	}
	SETUP_ARRAYS();
	{
		strmap m;
		PRINT_LINE("Empty:", m.empty() ? "true" : "false");
		m.insert(make_pair("Hello", "World"));
		PRINT_LINE("Empty:", m.empty() ? "true" : "false");
		m.erase(m.begin());
		PRINT_LINE("Empty:", m.empty() ? "true" : "false");
	}
	{
		intmap m(intstr_arr, intstr_arr + intstr_size);
		PRINT_LINE("Empty:", m.empty() ? "true" : "false");
	}
}

void map_end()
{
	map< char, int > my_map;

	my_map['b'] = 100;
	my_map['a'] = 200;
	my_map['c'] = 300;

	for (map< char, int >::iterator it = my_map.begin(); it != my_map.end(); ++it)
		cout << it->first << "=>" << it->second << endl;
}

void map_equal_range()
{
	map< char, int > my_map;

	my_map['a'] = 10;
	my_map['b'] = 20;
	my_map['c'] = 30;

#ifdef DEBUG
	my_map.print_dot(1);
#endif

	pair< map< char, int >::iterator, map< char, int >::iterator > ret;
	ret = my_map.equal_range('b');

	cout << "lower_bound points to ";
	cout << ret.first->first << "=> " << ret.first->second << endl;

	cout << "upper_bound points to ";
	cout << ret.second->first << "=> " << ret.second->second << endl;

	SETUP_ARRAYS();

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);

		m.insert(make_pair(34, "a"));
		m.insert(make_pair(3468, "bb"));
		m.insert(make_pair(96533, "ccc"));
		m.insert(make_pair(1954894589, "eeee"));
		m.insert(make_pair(7754322, "fffffff"));
		m.insert(make_pair(3632, "gggggggggg"));
		m.insert(make_pair(3, "hhhhhhhhhhhhhhh"));
		m.insert(make_pair(4, "iiiiiiiiiiiiiiiiii"));
		m.insert(make_pair(-873487, "jjjjjjjjjjjjjjjjjjjj"));
		m.insert(make_pair(-95763433, "kkkkkkkkkkkkkkkkkkkkkkkkk"));
		m.insert(make_pair(453834782, "lllllllllllllllllllllllllllllll"));
		m.insert(make_pair(19458942, "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"));
		m.insert(make_pair(1245689793, "nn"));

#ifdef DEBUG
		m.print_dot(1);
#endif

		pair< intmap::iterator, intmap::iterator > eq = m.equal_range(98583944);
		PRINT_EQ_RANGE(eq, m.end());

		eq = m.equal_range(209485948);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(19458942);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(19458941);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(19458943);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(-1);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(3);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(4);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(5);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(0);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(std::numeric_limits< int >::max());
		PRINT_EQ_RANGE(eq, m.end());

		m.insert(make_pair(std::numeric_limits< int >::max(), "max"));

		eq = m.equal_range(std::numeric_limits< int >::max());
		PRINT_EQ_RANGE(eq, m.end());
	}
	{
		intmap temp(intstr_arr, intstr_arr + intstr_size);

		temp.insert(make_pair(34, "aaaaaaaaaaaaaaaa"));
		temp.insert(make_pair(3468, "bbbbbbbbbbbbbbbbbbbbbbbbbbbbb"));
		temp.insert(make_pair(96533, "cccccccccccccccc"));
		temp.insert(make_pair(1954894589, "eeeeeeeeeeeeeeeeeee"));
		temp.insert(make_pair(7754322, "ffffffffffffffffffff"));
		temp.insert(make_pair(3632, "gggggggggggggggggg"));
		temp.insert(make_pair(3, "hhhhhhhhhhhh"));
		temp.insert(make_pair(4, "iiiiiiiiiiiiii"));
		temp.insert(make_pair(-873487, "jjjjjjjjjjjjjjjjjjjjjjjjjjjjjj"));
		temp.insert(make_pair(-95763433, "kkkk"));
		temp.insert(make_pair(453834782, "lllll"));
		temp.insert(make_pair(19458942, "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"));
		temp.insert(make_pair(1245689793, "nnnnnnnnn"));

		const intmap m(temp);

		pair< intmap::const_iterator, intmap::const_iterator > eq = m.equal_range(98583944);
		PRINT_EQ_RANGE(eq, m.end());

		eq = m.equal_range(209485948);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(19458942);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(19458941);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(19458943);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(-1);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(3);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(4);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(5);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(0);
		PRINT_EQ_RANGE(eq, m.end());
		eq = m.equal_range(std::numeric_limits< int >::max());
		PRINT_EQ_RANGE(eq, m.end());
	}
	{
		const intmap m;

		pair< intmap::const_iterator, intmap::const_iterator > eq = m.equal_range(std::numeric_limits< int >::max());

		PRINT_EQ_RANGE(eq, m.end());
	}
}

void map_erase()
{
	map< char, int >           my_map;
	map< char, int >::iterator it;

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
		cout << it->first << "=>" << it->second << endl;

	SETUP_ARRAYS();
	{
		intmap           m(intstr_arr, intstr_arr + 25);
		intmap::iterator it = m.begin();

		m.erase(it);
		PRINT_ALL(m);

		it = m.begin();
		std::advance(it, 21);
		m.erase(it);
		PRINT_ALL(m);

		it = m.end();
		std::advance(it, -10);
		m.erase(it);
		PRINT_ALL(m);
		it = m.end();

#ifdef DEBUG
		m.print_dot(1);
#endif

		std::advance(it, -3);
		m.erase(it);
		PRINT_ALL(m);

		it = m.end();
		std::advance(it, -1);
		m.erase(it);
		PRINT_ALL(m);

		it = m.begin();
		std::advance(it, 1);
		m.erase(it);
		PRINT_ALL(m);

		for (it = m.begin(); it != m.end(); it = m.begin())
		{
			m.erase(it);
			PRINT_ALL(m);
		}
	}
}

void map_find()
{
	map< char, int >           my_map;
	map< char, int >::iterator it;

	my_map['a'] = 50;
	my_map['b'] = 100;
	my_map['c'] = 150;
	my_map['d'] = 200;

	it = my_map.find('b');
	if (it != my_map.end())
		my_map.erase(it);

	cout << "elements in my_map:" << endl;
	cout << "a =>" << my_map.find('a')->second << endl;
	cout << "c =>" << my_map.find('c')->second << endl;
	cout << "d =>" << my_map.find('d')->second << endl;

	SETUP_ARRAYS();
	{
		strmap           m(strstr_arr, strstr_arr + strstr_size);
		strmap::iterator it = m.find("ABCD");

		if (it != m.end())
		{
			PRINT_PAIR_REF(*it);
		}

		m.insert(make_pair("12345", "etsriueruy394w"));
		m.insert(make_pair("abcd", "sfdge4ta4tqtawefa"));
		m.insert(make_pair("123", "adfgagrawetawtawef"));
		m.insert(make_pair("1234", "asdfgaetfawfasdf"));
		m.insert(make_pair("ab", "adfawtawefgzsdfg"));
		m.insert(make_pair("yz", "gftrjr5y4agwe3ta"));
		m.insert(make_pair("64", "mhj,i;y9o67eysetrgerg"));

		it = m.find("12345");

		if (it != m.end())
		{
			PRINT_PAIR_REF(*it);
		}

		it = m.find("1234");

		if (it != m.end())
		{
			PRINT_PAIR_REF(*it);
		}

		it = m.find("123");

		if (it != m.end())
		{
			PRINT_PAIR_REF(*it);
		}

		it = m.find("123");

		if (it != m.end())
		{
			PRINT_PAIR_REF(*it);
		}

		it = m.find("z");

		if (it != m.end())
		{
			PRINT_PAIR_REF(*it);
		}

		const strmap           cm(m);
		strmap::const_iterator cit = cm.find("ABCD");

		if (cit != cm.end())
		{
			PRINT_PAIR_REF(*cit);
		}

		cit = cm.find("64");

		if (cit != cm.end())
		{
			PRINT_PAIR_REF(*cit);
		}

		cit = m.find("12345");

		if (cit != m.end())
		{
			PRINT_PAIR_REF(*cit);
		}

		cit = m.find("1234");

		if (cit != m.end())
		{
			PRINT_PAIR_REF(*cit);
		}

		cit = m.find("123");

		if (cit != m.end())
		{
			PRINT_PAIR_REF(*cit);
		}

		cit = m.find("123");

		if (cit != m.end())
		{
			PRINT_PAIR_REF(*cit);
		}

		cit = m.find("z");

		if (cit != m.end())
		{
			PRINT_PAIR_REF(*cit);
		}
	}
	{
		const intmap cm;

		if (cm.find(0) != cm.end())
		{
			PRINT_PAIR_PTR(cm.find(0));
		}

		intmap m;

		m.insert(make_pair(123, "Hello"));

		if (m.find(0) != m.end())
		{
			PRINT_PAIR_PTR(m.find(0));
		}
		if (m.find(123) != m.end())
		{
			PRINT_PAIR_PTR(m.find(123));
		}
	}
}

void map_get_allocator()
{
	{
		int                      psize;
		map< char, int >         my_map;
		pair< const char, int >* p;

		p = my_map.get_allocator().allocate(5);

		psize = sizeof(map< char, int >::value_type) * 5;

		cout << "The allocated array has a size of " << psize << " bytes" << endl;

		my_map.get_allocator().deallocate(p, 5);
	}
	{
		intmap m;

		std::allocator< pair< const int, std::string > > alloc = m.get_allocator();

		pair< const int, std::string >* buff = alloc.allocate(64);

		alloc.deallocate(buff, 64);
	}
}

void map_insert()
{
	map< char, int > my_map;

	my_map.insert(pair< char, int >('a', 100));
	my_map.insert(pair< char, int >('z', 200));

	pair< map< char, int >::iterator, bool > ret;

	ret = my_map.insert(pair< char, int >('z', 500));
	if (ret.second == false)
	{
		cout << "element 'z' already existed";
		cout << " with a value of " << ret.first->second << endl;
	}

	map< char, int >::iterator it = my_map.begin();
	my_map.insert(it, pair< char, int >('b', 300));
	my_map.insert(it, pair< char, int >('c', 400));

	map< char, int > anotherMap;
	anotherMap.insert(my_map.begin(), my_map.find('c'));

	cout << "my_map contains:" << endl;
	for (it = my_map.begin(); it != my_map.end(); ++it)
		cout << it->first << " => " << it->second << endl;

	cout << "anotherMap contains:" << endl;
	for (it = anotherMap.begin(); it != anotherMap.end(); ++it)
		cout << it->first << " => " << it->second << endl;

	SETUP_ARRAYS();
	{
		typedef pair< intmap::iterator, bool > ins_pair;
		intmap                                 m;

		ins_pair p = m.insert(make_pair(64, "64str"));
		PRINT_INS_PAIR(p);
		p = m.insert(make_pair(64, "Double"));
		PRINT_INS_PAIR(p);
		p = m.insert(make_pair(0, "0str"));
		PRINT_INS_PAIR(p);
		p = m.insert(make_pair(-23, "-23str"));
		PRINT_INS_PAIR(p);
		p = m.insert(make_pair(64, "dfgs"));
		PRINT_INS_PAIR(p);
	}
	{
		typedef pair< strmap::iterator, bool > ins_pair;
		strmap                                 m;

		ins_pair p = m.insert(make_pair("64", "64str"));
		PRINT_INS_PAIR(p);
		p = m.insert(make_pair("64n", "Double"));
		PRINT_INS_PAIR(p);
		p = m.insert(make_pair("0n", "0str"));
		PRINT_INS_PAIR(p);
		p = m.insert(make_pair("-23n", "-23str"));
		PRINT_INS_PAIR(p);
		p = m.insert(make_pair("64n", "dfgs"));
		PRINT_INS_PAIR(p);
	}
}

void map_key_comp()
{
	map< char, int > my_map;

	map< char, int >::key_compare myComp = my_map.key_comp();

	my_map['a'] = 100;
	my_map['b'] = 200;
	my_map['c'] = 300;

	cout << "my_map contains" << endl;

	char highest = my_map.rbegin()->first;

	map< char, int >::iterator it = my_map.begin();
	do
	{

		cout << it->first << " => " << it->second << endl;
	} while (myComp((*it++).first, highest));

	cout << endl;

	SETUP_ARRAYS();
	{
		strmap m(strstr_arr, strstr_arr + strstr_size);

		strmap::iterator it = m.begin();

		strmap::const_iterator cit  = m.begin();
		strmap::key_compare    comp = m.key_comp();

		if (comp(it->first, cit->first))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(cit, 5);
		std::advance(it, 14);

		if (comp(it->first, cit->first))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, 7);
		std::advance(cit, 3);

		if (comp(it->first, cit->first))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, -3);
		std::advance(cit, 12);

		if (comp(it->first, cit->first))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, -1);
		std::advance(cit, 1);

		if (comp(it->first, cit->first))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}
	}

	{
		intmap                 m(intstr_arr, intstr_arr + intstr_size);
		intmap::iterator       it  = m.begin();
		intmap::const_iterator cit = m.begin();

		intmap::key_compare comp = m.key_comp();

		if (comp(it->first, cit->first))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, 14);
		std::advance(cit, 5);

		if (comp(it->first, cit->first))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, 7);
		std::advance(cit, 3);

		if (comp(it->first, cit->first))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, -3);
		std::advance(cit, 12);

		if (comp(it->first, cit->first))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, -1);
		std::advance(cit, 1);

		if (comp(it->first, cit->first))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}
	}
}

void map_lower_bound()
{
	map< char, int >           my_map;
	map< char, int >::iterator itlow, itup;

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

	for (map< char, int >::iterator it = my_map.begin(); it != my_map.end(); ++it)
		cout << it->first << " => " << it->second << endl;

	SETUP_ARRAYS();
	{
		intmap m(intstr_arr, intstr_arr + intstr_size);

		m.insert(make_pair(34, "kljd9834iuhwet"));
		m.insert(make_pair(3468, "dfghe45sywu4hsr"));
		m.insert(make_pair(96533, "sdfghthrdfg5456ik"));
		m.insert(make_pair(89548945894, "jtt5454wujtjse"));
		m.insert(make_pair(7754322, "w4wt5u4wjhstrhj"));
		m.insert(make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
		m.insert(make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
		m.insert(make_pair(4, "asdfhfjgh54w3ag"));
		m.insert(make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
		m.insert(make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
		m.insert(make_pair(453834782, "juytje54yaerdrj"));
		m.insert(make_pair(19458942, "j567uysdts56y6uj5r"));
		m.insert(make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));

		intmap::iterator b = m.lower_bound(98583944);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(239485948);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(19458942);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(19458941);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(19458943);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(-1);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(3);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(4);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(5);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(0);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(std::numeric_limits< int >::max());
		PRINT_BOUND(b, m.end());

		m.insert(make_pair(std::numeric_limits< int >::max(), "max"));

		b = m.lower_bound(std::numeric_limits< int >::max());
		PRINT_BOUND(b, m.end());
	}

	{
		intmap temp(intstr_arr, intstr_arr + intstr_size);

		temp.insert(make_pair(34, "kljd9834iuhwet"));
		temp.insert(make_pair(3468, "dfghe45sywu4hsr"));
		temp.insert(make_pair(96533, "sdfghthrdfg5456ik"));
		temp.insert(make_pair(89548945894, "jtt5454wujtjse"));
		temp.insert(make_pair(7754322, "w4wt5u4wjhstrhj"));
		temp.insert(make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
		temp.insert(make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
		temp.insert(make_pair(4, "asdfhfjgh54w3ag"));
		temp.insert(make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
		temp.insert(make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
		temp.insert(make_pair(453834782, "juytje54yaerdrj"));
		temp.insert(make_pair(19458942, "j567uysdts56y6uj5r"));
		temp.insert(make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));

		const intmap m(temp);

		intmap::const_iterator b = m.lower_bound(98583944);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(239485948);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(19458942);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(19458941);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(19458943);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(-1);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(3);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(4);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(5);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(0);
		PRINT_BOUND(b, m.end());

		b = m.lower_bound(std::numeric_limits< int >::max());
		PRINT_BOUND(b, m.end());
	}
	{
		const intmap m;

		intmap::const_iterator b = m.lower_bound(5);
		PRINT_BOUND(b, m.end());
	}
}

void map_operator_bracket()
{
	map< char, std::string > my_map;

	my_map['a'] = "an element";
	my_map['b'] = "another element";
	my_map['c'] = my_map['b'];

	cout << "my_map['a'] is " << my_map['a'] << endl;
	cout << "my_map['b'] is " << my_map['b'] << endl;
	cout << "my_map['c'] is " << my_map['c'] << endl;
	cout << "my_map['d'] is " << my_map['d'] << endl;

	cout << "my_map now contains " << my_map.size() << " elements" << endl;
}

void map_operator_equal()
{
	map< char, int > first;
	map< char, int > second;

	first['x'] = 8;
	first['y'] = 16;
	first['z'] = 32;

	second = first;
	first  = map< char, int >();

	cout << "Size of first: " << first.size() << endl;
	cout << "Size of second: " << second.size() << endl;
}

void map_rbegin()
{

	map< char, int > my_map;

	my_map['x'] = 100;
	my_map['y'] = 200;
	my_map['z'] = 300;

	map< char, int >::reverse_iterator rit;
	for (rit = my_map.rbegin(); rit != my_map.rend(); ++rit)
		cout << rit->first << "=>" << rit->second << endl;
}

void map_relational_operators()
{

	map< char, int > foo, bar;

	foo['a'] = 100;
	foo['b'] = 200;

	bar['a'] = 10;
	bar['z'] = 1000;

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

void map_rend()
{

	map< char, int > my_map;

	my_map['x'] = 100;
	my_map['y'] = 200;
	my_map['z'] = 300;

	map< char, int >::reverse_iterator rit;
	for (rit = my_map.rbegin(); rit != my_map.rend(); ++rit)
		cout << rit->first << "=>" << rit->second << endl;
}

void map_size()
{

	map< char, int > my_map;

	my_map['a'] = 101;
	my_map['b'] = 202;
	my_map['c'] = 302;

	cout << "my_map.size() is " << my_map.size() << endl;
}

void map_swap()
{
	map< char, int > foo, bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	foo.swap(bar);

	cout << "foo contains:" << std ::endl;
	for (map< char, int >::iterator it = foo.begin(); it != foo.end(); ++it)
		cout << it->first << " => " << it->second << endl;

	cout << "bar contains:" << std ::endl;
	for (map< char, int >::iterator it = bar.begin(); it != bar.end(); ++it)
		cout << it->first << " => " << it->second << endl;

	SETUP_ARRAYS();
	{
		intmap m1(intstr_arr, intstr_arr + 32);
		intmap m2;

		swap(m1, m2);

		PRINT_ALL(m1);
		PRINT_ALL(m2);

		m1.clear();
		m1.swap(m2);

		PRINT_ALL(m1);
		PRINT_ALL(m2);

		m1.clear();
		m2.swap(m1);

		PRINT_ALL(m1);
		PRINT_ALL(m2);

		m1.insert(make_pair(64, "N64"));
		swap(m1, m2);

		PRINT_ALL(m1);
		PRINT_ALL(m2);

		m2.insert(intstr_arr, intstr_arr + intstr_size);
		m1.swap(m2);

		PRINT_ALL(m1);
		PRINT_ALL(m2);

		m1.clear();
		m1.swap(m2);
		m1.clear();
		m1.swap(m2);

		PRINT_ALL(m1);
		PRINT_ALL(m2);
	}
}

void map_swap_overload()
{

	map< char, int > foo, bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	std::swap(foo, bar);

	cout << "foo contains:" << std ::endl;
	for (map< char, int >::iterator it = foo.begin(); it != foo.end(); ++it)
		cout << it->first << " => " << it->second << endl;

	cout << "bar contains:" << std ::endl;
	for (map< char, int >::iterator it = bar.begin(); it != bar.end(); ++it)
		cout << it->first << " => " << it->second << endl;
}

void map_upper_bound()
{
	map< char, int >           my_map;
	map< char, int >::iterator itlow, itup;

	my_map['a'] = 20;
	my_map['b'] = 40;
	my_map['c'] = 60;
	my_map['d'] = 80;
	my_map['e'] = 100;

	itlow = my_map.lower_bound('b');
	itup  = my_map.upper_bound('d');

	my_map.erase(itlow, itup);

	for (map< char, int >::iterator it = my_map.begin(); it != my_map.end(); ++it)
		cout << it->first << " => " << it->second << endl;

	SETUP_ARRAYS();
	{
		intmap m(intstr_arr, intstr_arr + intstr_size);

		m.insert(make_pair(34, "kljd9834iuhwet"));
		m.insert(make_pair(3468, "dfghe45sywu4hsr"));
		m.insert(make_pair(96533, "sdfghthrdfg5456ik"));
		m.insert(make_pair(89548945894, "jtt5454wujtjse"));
		m.insert(make_pair(7754322, "w4wt5u4wjhstrhj"));
		m.insert(make_pair(3632, "dfgjjkuy56ue5uwyhry5yeh"));
		m.insert(make_pair(3, "rtjey5w4u4u5e6kjwj5w4"));
		m.insert(make_pair(4, "asdfhfjgh54w3ag"));
		m.insert(make_pair(-873487, "jw56jw45jsryjsrt5u4w5"));
		m.insert(make_pair(-95763433, "ws45uhsrtjnsrths54yh"));
		m.insert(make_pair(453834782, "juytje54yaerdrj"));
		m.insert(make_pair(19458942, "j567uysdts56y6uj5r"));
		m.insert(make_pair(3245689793, "jr67e5674574668679789ruyerdtadh"));

		intmap::iterator b = m.upper_bound(98583944);
		PRINT_BOUND(b, m.end());

		b = m.upper_bound(239485948);
		PRINT_BOUND(b, m.end());

		b = m.upper_bound(19458942);
		PRINT_BOUND(b, m.end());

		b = m.upper_bound(19458941);
		PRINT_BOUND(b, m.end());

		b = m.upper_bound(19458943);
		PRINT_BOUND(b, m.end());

		b = m.upper_bound(-1);
		PRINT_BOUND(b, m.end());

		b = m.upper_bound(3);
		PRINT_BOUND(b, m.end());

		b = m.upper_bound(4);
		PRINT_BOUND(b, m.end());

		b = m.upper_bound(5);
		PRINT_BOUND(b, m.end());

		b = m.upper_bound(0);
		PRINT_BOUND(b, m.end());

		b = m.upper_bound(std::numeric_limits< int >::max());
		PRINT_BOUND(b, m.end());

		m.insert(make_pair(std::numeric_limits< int >::max(), "max"));

		b = m.upper_bound(std::numeric_limits< int >::max());
		PRINT_BOUND(b, m.end());
	}
	{
		const intmap m;

		intmap::const_iterator b = m.upper_bound(5);

		PRINT_BOUND(b, m.end());
	}
}

void map_value_comp()
{
	map< char, int > my_map;

	my_map['x'] = 1001;
	my_map['y'] = 2002;
	my_map['z'] = 3003;
	cout << "my_map contains" << endl;

	pair< char, int >          highest = *my_map.rbegin();
	map< char, int >::iterator it      = my_map.begin();
	do
	{
		cout << it->first << " => " << it->second << endl;
	} while (my_map.value_comp()(*it++, highest));

	SETUP_ARRAYS();
	{
		strmap m(strstr_arr, strstr_arr + strstr_size);

		strmap::iterator       it   = m.begin();
		strmap::const_iterator cit  = m.begin();
		strmap::value_compare  comp = m.value_comp();

		if (comp(*it, *cit))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(cit, 5);
		std::advance(it, 14);

		if (comp(*it, *cit))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, 7);
		std::advance(cit, 3);

		if (comp(*it, *cit))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, -3);
		std::advance(cit, 12);

		if (comp(*it, *cit))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, -1);
		std::advance(cit, 1);

		if (comp(*it, *cit))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);

		intmap::iterator      it   = m.begin();
		intmap::iterator      it2  = m.begin();
		intmap::value_compare comp = m.value_comp();

		if (comp(*it, *it2))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, 14);
		std::advance(it2, 5);

		if (comp(*it, *it2))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, 7);
		std::advance(it2, 3);

		if (comp(*it, *it2))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, -3);
		std::advance(it2, 12);

		if (comp(*it, *it2))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}

		std::advance(it, -1);
		std::advance(it2, 1);

		if (comp(*it, *it2))
		{
			PRINT_MSG("Less");
		}
		else
		{
			PRINT_MSG("Not Less");
		}
	}
}

// DANGER ZONE

#include <stdexcept>

void map_at()
{
	SETUP_ARRAYS();

	{
		intmap m;

		try
		{
			std::string& x = m.at(6);

			PRINT_LINE("At:", x);
		}
		catch (std::out_of_range& e)
		{
			PRINT_LINE("Out of range exception", 6);
		}
		CATCH_UNHANDLED_EX();
	}

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);

		m.insert(make_pair(64, "64"));

		try
		{
			std::string& x = m.at(64);

			PRINT_LINE("At:", x);
		}
		catch (std::out_of_range& e)
		{
			PRINT_LINE("Wrong out of range exception", 64);
		}
		CATCH_UNHANDLED_EX();
	}

	{
		strmap m(strstr_arr, strstr_arr + strstr_size);

		m.insert(make_pair("Hello", "World"));

		try
		{
			std::string& x = m.at("Hello");

			PRINT_LINE("At:", x);
		}
		catch (std::out_of_range& e)
		{
			PRINT_LINE("Wrong out of range exception", "Hello");
		}
		CATCH_UNHANDLED_EX();
	}

	{
		strmap m(strstr_arr, strstr_arr + 1);

		try
		{
			std::string& x = m.at("");

			PRINT_LINE("At:", x);
		}
		catch (std::out_of_range& e)
		{
			PRINT_LINE("Out of range exception", "");
		}
		CATCH_UNHANDLED_EX();
	}

	{
		const intmap m;

		try
		{
			const std::string& x = m.at(6);

			PRINT_LINE("At:", x);
		}
		catch (std::out_of_range& e)
		{
			PRINT_LINE("Out of range exception", 6);
		}
		CATCH_UNHANDLED_EX();
	}

	{
		intmap temp(intstr_arr, intstr_arr + intstr_size);

		temp.insert(make_pair(64, "64"));

		const intmap m(temp);

		try
		{
			const std::string& x = m.at(64);

			PRINT_LINE("At:", x);
		}
		catch (std::out_of_range& e)
		{
			PRINT_LINE("Wrong out of range exception", 64);
		}
		CATCH_UNHANDLED_EX();
	}

	{
		strmap temp(strstr_arr, strstr_arr + strstr_size);

		temp.insert(make_pair("Hello", "World"));

		const strmap m(temp);

		try
		{
			const std::string& x = m.at("Hello");

			PRINT_LINE("At:", x);
		}
		catch (std::out_of_range& e)
		{
			PRINT_LINE("Wrong out of range exception", "Hello");
		}
		CATCH_UNHANDLED_EX();
	}

	{
		const strmap m(strstr_arr, strstr_arr + 1);

		try
		{
			const std::string& x = m.at("");

			PRINT_LINE("At:", x);
		}
		catch (std::out_of_range& e)
		{
			PRINT_LINE("Out of range exception", "");
		}
		CATCH_UNHANDLED_EX();
	}
}

void map_assignment()
{
	SETUP_ARRAYS();

	{
		intmap m1;
		intmap m2;

		m1 = m2;

		PRINT_ALL(m1);

		m2 = intmap(intstr_arr, intstr_arr + intstr_size);

		PRINT_ALL(m2);

		m1 = m2;

		PRINT_ALL(m1);

		m1 = intmap(intstr_arr, intstr_arr + 10);

		PRINT_ALL(m1);

		m2 = m1;

		PRINT_ALL(m2);
	}

	{
		strmap m1;
		strmap m2;

		m1 = m2;

		PRINT_ALL(m1);

		m2 = strmap(strstr_arr, strstr_arr + strstr_size);

		PRINT_ALL(m2);

		m1 = m2;

		PRINT_ALL(m1);

		m1 = strmap(strstr_arr, strstr_arr + 10);

		PRINT_ALL(m1);

		m2 = m1;

		PRINT_ALL(m2);
	}
}

void map_compare()
{
	SETUP_ARRAYS();

	{
		map< int, std::string, std::greater< int >, std::allocator< pair< const int, std::string > > > m(
		    intstr_arr, intstr_arr + intstr_size);

		PRINT_ALL(m);
	}
}

void map_comparisons_eq()
{
	SETUP_ARRAYS();

	{
		intmap m;
		intmap n;

		if (m == n)
		{
			PRINT_MSG("Equal");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (m == n)
		{
			PRINT_MSG("Equal.");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (n == m)
		{
			PRINT_MSG("Equal..");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n(intstr_arr, intstr_arr + 1);

		if (n == m)
		{
			PRINT_MSG("Equal...");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);
		intmap n(intstr_arr, intstr_arr + intstr_size);

		if (n == m)
		{
			PRINT_MSG("Equal....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n;

		n.insert(make_pair(5, "Hello"));
		n.insert(make_pair(7, "Hello"));
		n.insert(make_pair(8, "Hello"));
		n.insert(make_pair(1, "Hello"));
		n.insert(make_pair(0, "Hello"));

		if (n == m)
		{
			PRINT_MSG("Equal.....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n(intstr_arr, intstr_arr + 4);

		n.insert(make_pair(5, "Hello"));

		if (n == m)
		{
			PRINT_MSG("Equal......");
		}
	}
}

void map_comparisons_ge()
{
	SETUP_ARRAYS();

	{
		intmap m;
		intmap n;

		if (m > n)
		{
			PRINT_MSG("Greater");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (m > n)
		{
			PRINT_MSG("Greater.");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (n > m)
		{
			PRINT_MSG("Greater..");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n(intstr_arr, intstr_arr + 1);

		if (n > m)
		{
			PRINT_MSG("Greater...");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);
		intmap n(intstr_arr, intstr_arr + intstr_size);

		if (n > m)
		{
			PRINT_MSG("Greater....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n;

		n.insert(make_pair(5, "Hello"));
		n.insert(make_pair(7, "Hello"));
		n.insert(make_pair(8, "Hello"));
		n.insert(make_pair(1, "Hello"));
		n.insert(make_pair(0, "Hello"));

		if (n > m)
		{
			PRINT_MSG("Greater.....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n(intstr_arr, intstr_arr + 4);

		n.insert(make_pair(5, "Hello"));

		if (n > m)
		{
			PRINT_MSG("Greater......");
		}
	}
}

void map_comparisons_gt()
{
	SETUP_ARRAYS();

	{
		intmap m;
		intmap n;

		if (m >= n)
		{
			PRINT_MSG("Greater or Equal");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (m >= n)
		{
			PRINT_MSG("Greater or Equal.");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (n >= m)
		{
			PRINT_MSG("Greater or Equal..");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n(intstr_arr, intstr_arr + 1);

		if (n >= m)
		{
			PRINT_MSG("Greater or Equal...");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);
		intmap n(intstr_arr, intstr_arr + intstr_size);

		if (n >= m)
		{
			PRINT_MSG("Greater or Equal....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n;

		n.insert(make_pair(5, "Hello"));
		n.insert(make_pair(7, "Hello"));
		n.insert(make_pair(8, "Hello"));
		n.insert(make_pair(1, "Hello"));
		n.insert(make_pair(0, "Hello"));

		if (n >= m)
		{
			PRINT_MSG("Greater or Equal.....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n(intstr_arr, intstr_arr + 4);

		n.insert(make_pair(5, "Hello"));

		if (n >= m)
		{
			PRINT_MSG("Greater or Equal......");
		}
	}
}

void map_comparisons_le()
{
	SETUP_ARRAYS();

	{
		intmap m;
		intmap n;

		if (m <= n)
		{
			PRINT_MSG("Less or Equal");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (m <= n)
		{
			PRINT_MSG("Less or Equal.");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (n <= m)
		{
			PRINT_MSG("Less or Equal..");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n(intstr_arr, intstr_arr + 1);

		if (n <= m)
		{
			PRINT_MSG("Less or Equal...");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);
		intmap n(intstr_arr, intstr_arr + intstr_size);

		if (n <= m)
		{
			PRINT_MSG("Less or Equal....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n;

		n.insert(make_pair(std::numeric_limits< int >::max(), "zxcvzx"));
		n.insert(make_pair(7, "Hello"));
		n.insert(make_pair(8, "Hello"));
		n.insert(make_pair(1, "Hello"));
		n.insert(make_pair(0, "Hello"));

		if (n <= m)
		{
			PRINT_MSG("Less or Equal.....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n(intstr_arr, intstr_arr + 4);

		n.insert(make_pair(5, "zxcvxz"));

		if (n <= m)
		{
			PRINT_MSG("Less or Equal......");
		}
	}
}

void map_comparisons_lt()
{
	SETUP_ARRAYS();

	{
		intmap m;
		intmap n;

		if (m < n)
		{
			PRINT_MSG("Less");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (m < n)
		{
			PRINT_MSG("Less.");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (n < m)
		{
			PRINT_MSG("Less..");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n(intstr_arr, intstr_arr + 1);

		if (n < m)
		{
			PRINT_MSG("Less...");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);
		intmap n(intstr_arr, intstr_arr + intstr_size);

		if (n < m)
		{
			PRINT_MSG("Less....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n;

		n.insert(make_pair(5, "Hello"));
		n.insert(make_pair(7, "Hello"));
		n.insert(make_pair(8, "Hello"));
		n.insert(make_pair(1, "Hello"));
		n.insert(make_pair(0, "Hello"));

		if (n < m)
		{
			PRINT_MSG("Less.....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n(intstr_arr, intstr_arr + 4);

		n.insert(make_pair(5, "Hello"));

		if (n < m)
		{
			PRINT_MSG("Less......");
		}
	}
}

void map_comparisons_ne()
{
	SETUP_ARRAYS();

	{
		intmap m;
		intmap n;

		if (m != n)
		{
			PRINT_MSG("Not Equal");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (m != n)
		{
			PRINT_MSG("Not Equal.");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n;

		if (n != m)
		{
			PRINT_MSG("Not Equal..");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 1);
		intmap n(intstr_arr, intstr_arr + 1);

		if (n != m)
		{
			PRINT_MSG("Not Equal...");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);
		intmap n(intstr_arr, intstr_arr + intstr_size);

		if (n != m)
		{
			PRINT_MSG("Not Equal....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n;

		n.insert(make_pair(5, "Hello"));
		n.insert(make_pair(7, "Hello"));
		n.insert(make_pair(8, "Hello"));
		n.insert(make_pair(1, "Hello"));
		n.insert(make_pair(0, "Hello"));

		if (n != m)
		{
			PRINT_MSG("Not Equal.....");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + 5);
		intmap n(intstr_arr, intstr_arr + 4);

		n.insert(make_pair(5, "Hello"));

		if (n != m)
		{
			PRINT_MSG("Not Equal......");
		}
	}
}

void map_ctor()
{
	// Default
	{
		intmap m;

		PRINT_ALL(m);
	}

	// Compare/Allocator
	{
		std::allocator< pair< const std::string, std::string > > alloc;
		strmap                                                   m(std::less< std::string >(), alloc);

		PRINT_ALL(m);
	}
}

void map_ctor_copy()
{
	SETUP_ARRAYS();

	{
		intmap m1(intstr_arr, intstr_arr + intstr_size);

		PRINT_ALL(m1);

		intmap m2(m1);

		PRINT_ALL(m2);
	}

	{
		strmap m1(strstr_arr, strstr_arr + strstr_size);

		PRINT_ALL(m1);

		strmap m2(m1);

		PRINT_ALL(m2);
	}
}

void map_ctor_range()
{
	SETUP_ARRAYS();

	{
		std::allocator< pair< const int, std::string > > alloc;
		intmap m(intstr_arr, intstr_arr + intstr_size, std::less< int >(), alloc);

		PRINT_ALL(m);

		intmap m2(m.begin(), m.end());

		PRINT_ALL(m);
		PRINT_ALL(m2);
	}

	{
		strmap m1(strstr_arr, strstr_arr + strstr_size);

		PRINT_ALL(m1);

		strmap m2(strstr_arr, strstr_arr + strstr_size);

		PRINT_ALL(m1);
		PRINT_ALL(m2);
	}
}

void map_erase_key()
{
	SETUP_ARRAYS();

	{
		intmap m;

		intmap::size_type size = m.erase(64);

		PRINT_LINE("Erased?:", size);
	}

	{
		intmap m(intstr_arr, intstr_arr + 16);

		intmap::size_type size = m.erase(64);

		PRINT_LINE("Erased?:", size);

		m.erase(m.begin(), m.end());

		m.insert(make_pair(23, "23n"));
		m.insert(make_pair(25, "asdasdfsdfsafdsf"));
		m.insert(make_pair(1, "asdssdfdfdffffff"));
		m.insert(make_pair(2, "dsfdffffdfdfdsdfdffa"));
		m.insert(make_pair(3, "sssdfs"));
		m.insert(make_pair(75, "dfse"));
		m.insert(make_pair(30, "sefsadfasdfasdfsadfasdfsf"));
		m.insert(make_pair(-22, "dfhkihgbnfbcx5reterjhd"));
		m.insert(make_pair(-23, "sdffgdfgrefet34thfgheewt"));
		m.insert(make_pair(0, "98y4rtuohwidsjusdossefsse"));

		size = m.erase(64);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(0);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(75);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(1);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(2);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(3);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(23);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(23);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(30);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(-22);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(-23);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(-23);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(25);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(-23);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase(25);

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);
	}

	{
		strmap m;

		strmap::size_type size = m.erase("");
		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		m.insert(make_pair("", ""));
		m.insert(make_pair("123", "kjhgfdsdffghsfghdfgh"));
		m.insert(make_pair("1234", "gfdsadgg"));
		m.insert(make_pair("123456789123456789123456789", "49857459898674568464"));
		m.insert(make_pair("0", "2345456456456456"));
		m.insert(make_pair("", ""));
		m.insert(make_pair("", "9459845984598498"));
		m.insert(make_pair("000000000000000000000000", "1111111111111111111111111111"));

		size = m.erase("1");

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase("123");

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase("123");

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase("");

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase("1234");

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase("123456789123456789123456789");

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase("000000000000000000000000");

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase("0");

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);

		size = m.erase("000000000000000000000000");

		PRINT_LINE("Erased?:", size);
		PRINT_ALL(m);
	}
}

void map_erase_range()
{
	SETUP_ARRAYS();

	{
		strmap m;

		m.erase(m.begin(), m.end());

		PRINT_ALL(m);

		m.insert(strstr_arr, strstr_arr + strstr_size);

#ifdef DEBUG
		m.print_dot(1);
#endif

		m.erase(m.begin(), m.end());

#ifdef DEBUG
		m.print_dot(1);
#endif

		PRINT_ALL(m);
	}

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);

		intmap::iterator it(m.begin());
		intmap::iterator end(it);

		std::advance(end, 1);

#ifdef DEBUG
		m.print_dot(1);
#endif

		m.erase(it, end);

#ifdef DEBUG
		m.print_dot(1);
#endif

		PRINT_ALL(m);

		it  = m.begin();
		end = it;
		std::advance(it, 24);
		std::advance(end, 30);

		m.erase(it, end);

#ifdef DEBUG
		m.print_dot(1);
#endif

		PRINT_ALL(m);

		it  = m.begin();
		end = it;
		std::advance(it, 34);
		std::advance(end, 55);

		m.erase(it, end);

#ifdef DEBUG
		m.print_dot(1);
#endif

		PRINT_ALL(m);

		it  = m.begin();
		end = it;
		std::advance(end, 1);

		m.erase(it, end);

		PRINT_ALL(m);

		m.erase(m.begin(), m.end());

		PRINT_ALL(m);
	}
}

void map_index_operator()
{
	SETUP_ARRAYS();

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);

		PRINT_SIZE(m);
		PRINT_LINE("Value:", m[64]);
		PRINT_SIZE(m);

		m[64] = "Hello";

		PRINT_SIZE(m);
		PRINT_LINE("Value:", m[64]);
		PRINT_SIZE(m);

		PRINT_SIZE(m);
		PRINT_LINE("Value:", m[0]);
		PRINT_SIZE(m);

		m[0] = "ABCDEF";

		PRINT_SIZE(m);
		PRINT_LINE("Value:", m[0]);
		PRINT_SIZE(m);
	}

	{
		strmap m(strstr_arr, strstr_arr + strstr_size);

		PRINT_SIZE(m);
		PRINT_LINE("Value:", m["Index"]);
		PRINT_SIZE(m);

		m["Index"] = "World";

		PRINT_SIZE(m);
		PRINT_LINE("Value:", m["Index"]);
		PRINT_SIZE(m);

		m["abcd"] = "World";

		PRINT_SIZE(m);
		PRINT_LINE("Value:", m["abcd"]);
		PRINT_SIZE(m);
	}
}

void map_insert_hint()
{
	SETUP_ARRAYS();
	{
		intmap m;

		intmap::iterator it = m.insert(m.end(), make_pair(64, "Gamepak"));
		PRINT_PAIR_REF(*it);
		it = m.insert(m.end(), make_pair(64, "Test"));
		PRINT_PAIR_REF(*it);
		it = m.insert(m.end(), make_pair(100, "100$"));
		PRINT_PAIR_REF(*it);

		it = m.end();
		--it;

		it = m.insert(it, make_pair(100, "12345"));
		PRINT_PAIR_REF(*it);
		it = m.insert(it, make_pair(69, "420"));
		PRINT_PAIR_REF(*it);
	}
}

void map_insert_range()
{
	SETUP_ARRAYS();
	{
		strmap m;
		PRINT_ALL(m);

		m.insert(strstr_arr, strstr_arr + 5);
		PRINT_ALL(m);

		m.insert(strstr_arr + 5, strstr_arr + 14);
		PRINT_ALL(m);

		m.insert(strstr_arr, strstr_arr + 9);
		PRINT_ALL(m);

		m.insert(strstr_arr + 26, strstr_arr + strstr_size);
		PRINT_ALL(m);

		m.insert(strstr_arr + 14, strstr_arr + 26);
		PRINT_ALL(m);
	}
	{
		intmap m;
		PRINT_ALL(m);

		m.insert(intstr_arr + 16, intstr_arr + 16);
		PRINT_ALL(m);

		m.insert(intstr_arr + 1, intstr_arr + 7);
		PRINT_ALL(m);

		m.insert(intstr_arr, intstr_arr + 1);
		PRINT_ALL(m);

		m.insert(intstr_arr, intstr_arr + 17);
		PRINT_ALL(m);

		m.insert(intstr_arr, intstr_arr + intstr_size);
		PRINT_ALL(m);
	}
}

void map_iterator()
{
	SETUP_ARRAYS();
	{
		intmap m;
		PRINT_ALL(m);
	}
	{
		strmap                 m(strstr_arr, strstr_arr + strstr_size);
		strmap::iterator       it   = m.begin();
		strmap::iterator       it2  = m.begin();
		strmap::const_iterator cit  = m.begin();
		strmap::const_iterator cit2 = m.begin();

		if (it == it2)
		{
			PRINT_MSG("Equal");
		}
		if (it == cit)
		{
			PRINT_MSG("Equal.");
		}
		if (cit == cit2)
		{
			PRINT_MSG("Equal..");
		}
		if (it != it2)
		{
			PRINT_MSG("Not Equal");
		}
		if (it != cit)
		{
			PRINT_MSG("Not Equal.");
		}
		if (cit != cit2)
		{
			PRINT_MSG("Not Equal..");
		}

		PRINT_PAIR_PTR(++it);
		PRINT_PAIR_PTR(++cit);

		if (it == it2)
		{
			PRINT_MSG("Equal...");
		}
		if (it == cit)
		{
			PRINT_MSG("Equal....");
		}
		if (cit == cit2)
		{
			PRINT_MSG("Equal.....");
		}
		if (it != it2)
		{
			PRINT_MSG("Not Equal...");
		}
		if (it != cit)
		{
			PRINT_MSG("Not Equal....");
		}
		if (cit != cit2)
		{
			PRINT_MSG("Not Equal.....");
		}

		++it2;

		if (it == it2)
		{
			PRINT_MSG("Equal........");
		}

		--it;
		--it2;

		if (it == it2)
		{
			PRINT_MSG("Equal.........");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);

		intmap::iterator       it   = m.begin();
		intmap::iterator       it2  = m.begin();
		intmap::const_iterator cit  = m.begin();
		intmap::const_iterator cit2 = m.begin();

		PRINT_ALL(m);

		it->second = "Hello";

		PRINT_PAIR_PTR(m.begin());
		PRINT_PAIR_REF(*it);
		PRINT_PAIR_PTR(++it);
		PRINT_PAIR_PTR(it2++);
		PRINT_PAIR_REF(*it++);
		PRINT_PAIR_PTR(cit++);
		PRINT_PAIR_PTR(cit2++);
		PRINT_PAIR_PTR(++cit);
		PRINT_PAIR_PTR(++cit2);
		PRINT_PAIR_PTR(it2);
		PRINT_PAIR_PTR(cit2);
		PRINT_PAIR_PTR(it++);
		PRINT_PAIR_PTR(it++);
		PRINT_PAIR_PTR(it++);
		PRINT_PAIR_PTR(it2++);
		PRINT_PAIR_PTR(it2++);
		PRINT_PAIR_PTR(++it2);
		PRINT_PAIR_REF(*cit);
		PRINT_PAIR_REF(*cit--);
		PRINT_PAIR_REF(*it--);
		PRINT_PAIR_PTR(it--);
		PRINT_PAIR_PTR(--it);
		PRINT_PAIR_PTR(--cit2);
		PRINT_PAIR_PTR(cit2);
		PRINT_PAIR_REF(*cit2);
		PRINT_PAIR_REF(*it2);
		it = it2;
		PRINT_PAIR_REF(*it);
		PRINT_PAIR_REF(*it2);
		cit = cit2;
		PRINT_PAIR_REF(*cit);
		PRINT_PAIR_REF(*cit2);
	}
}

void map_random()
{
	SETUP_ARRAYS();

	{
	    // strmap m(strstr_arr, strstr_arr + 16);

	    // strmap::iterator it = m.find("Hello");

	    // if (it != m.end()) {
	    //    PRINT_PAIR_REF(*it);
	    //}

	    // try {
	    //    std::string& ref = m.at("World!");

	    //    PRINT_LINE("Val:", ref);
	    //} catch (std::out_of_range& e) {
	    //    PRINT_MSG("Exception");
	    //}
	    // CATCH_UNHANDLED_EX();

	    // PRINT_ALL(m);

	    // m.insert(strstr_arr, strstr_arr + strstr_size);

	    // PRINT_ALL(m);

	    // m.erase(m.begin());

	    // PRINT_ALL(m);

	    // it = m.begin();
	    // std::advance(it, 10);

	    // m.erase(it, m.end());

	    // PRINT_ALL(m);

	    // strmap::size_type s = m.erase("1234");

	    // PRINT_ALL(m);
	    // PRINT_LINE("S:", s);

	    // m.clear();

	    // PRINT_ALL(m);

	    // it = m.insert(m.begin(), make_pair("", "test"));

	    // PRINT_LINE("Count:", m.count(""));

	    // PRINT_PAIR_REF(*it);
	    // PRINT_ALL(m);

	    // m.insert(strstr_arr, strstr_arr + strstr_size);

	    // strmap n(strstr_arr, strstr_arr + 10);

	    // m.swap(n);

	    // PRINT_ALL(m);
	    // PRINT_ALL(n);

	    // PRINT_EQ_RANGE(m.equal_range("abcd"), m.end());
	    // PRINT_BOUND(m.lower_bound("123"), m.end());
	    // PRINT_BOUND(m.upper_bound("jhg456"), m.end());

	    // PRINT_LINE("Find:", m.find("hello") != m.end() ? m.find("hello")->first : "End");

	    // m["hello"] = "world";

	    // PRINT_LINE("Find:", m.find("hello") != m.end() ? m.find("hello")->first : "End");
	}

	{
		map< int, int, std::less< int >, std::allocator< pair< const int, int > > > m;

		for (int i = 0; i < 500000; ++i)
		{
			// m.insert(make_pair(rand(), rand()));
			m.insert(make_pair(i, i));
		}

		PRINT_ALL(m);

		m.erase(m.begin(), m.end());

		// PRINT_ALL(m);
	}
}

void map_riterator()
{
	SETUP_ARRAYS();

	{
		intmap m;

		PRINT_ALL(m);
	}

	{
		strmap m(strstr_arr, strstr_arr + strstr_size);

		strmap::reverse_iterator       it   = m.rbegin();
		strmap::reverse_iterator       it2  = m.rbegin();
		strmap::const_reverse_iterator cit  = m.rbegin();
		strmap::const_reverse_iterator cit2 = m.rbegin();

		if (it == it2)
		{
			PRINT_MSG("Equal");
		}
		if (it == cit)
		{
			PRINT_MSG("Equal.");
		}
		if (cit == cit2)
		{
			PRINT_MSG("Equal..");
		}
		if (it != it2)
		{
			PRINT_MSG("Not Equal");
		}
		if (it != cit)
		{
			PRINT_MSG("Not Equal.");
		}
		if (cit != cit2)
		{
			PRINT_MSG("Not Equal..");
		}

		PRINT_PAIR_PTR(++it);
		PRINT_PAIR_PTR(++cit);

		if (it == it2)
		{
			PRINT_MSG("Equal...");
		}
		if (it == cit)
		{
			PRINT_MSG("Equal....");
		}
		if (cit == cit2)
		{
			PRINT_MSG("Equal.....");
		}
		if (it != it2)
		{
			PRINT_MSG("Not Equal...");
		}
		if (it != cit)
		{
			PRINT_MSG("Not Equal....");
		}
		if (cit != cit2)
		{
			PRINT_MSG("Not Equal.....");
		}

		++it2;

		if (it == it2)
		{
			PRINT_MSG("Equal........");
		}

		--it;
		--it2;

		if (it == it2)
		{
			PRINT_MSG("Equal.........");
		}
	}

	{
		intmap m(intstr_arr, intstr_arr + intstr_size);

		intmap::reverse_iterator       it   = m.rbegin();
		intmap::reverse_iterator       it2  = m.rbegin();
		intmap::const_reverse_iterator cit  = m.rbegin();
		intmap::const_reverse_iterator cit2 = m.rbegin();

		for (intmap::reverse_iterator i = m.rbegin(); i != m.rend(); ++i)
		{
			PRINT_PAIR_REF(*i);
		}

		PRINT_ALL(m);

		it->second = "Hello";

		PRINT_PAIR_PTR(m.rbegin());
		PRINT_PAIR_REF(*it);
		PRINT_PAIR_PTR(++it);
		PRINT_PAIR_PTR(it2++);
		PRINT_PAIR_REF(*it++);
		PRINT_PAIR_PTR(cit++);
		PRINT_PAIR_PTR(cit2++);
		PRINT_PAIR_PTR(++cit);
		PRINT_PAIR_PTR(++cit2);
		PRINT_PAIR_PTR(it2);
		PRINT_PAIR_PTR(cit2);
		PRINT_PAIR_PTR(it++);
		PRINT_PAIR_PTR(it++);
		PRINT_PAIR_PTR(it++);
		PRINT_PAIR_PTR(it2++);
		PRINT_PAIR_PTR(it2++);
		PRINT_PAIR_PTR(++it2);
		PRINT_PAIR_REF(*cit);
		PRINT_PAIR_REF(*cit--);
		PRINT_PAIR_REF(*it--);
		PRINT_PAIR_PTR(it--);
		PRINT_PAIR_PTR(--it);
		PRINT_PAIR_PTR(--cit2);
		PRINT_PAIR_PTR(cit2);
		PRINT_PAIR_REF(*cit2);
		PRINT_PAIR_REF(*it2);
		it = it2;
		PRINT_PAIR_REF(*it);
		PRINT_PAIR_REF(*it2);
		cit = cit2;
		PRINT_PAIR_REF(*cit);
		PRINT_PAIR_REF(*cit2);
	}
}

#define CHECK_TYPEDEF(type)                                                  \
	{                                                                        \
		map< int, unsigned int >::type a = map< int, unsigned int >::type(); \
		(void)a;                                                             \
	}

void map_check_typedefs()
{
	CHECK_TYPEDEF(key_type);
	CHECK_TYPEDEF(mapped_type);
	CHECK_TYPEDEF(value_type);
	CHECK_TYPEDEF(allocator_type);
	CHECK_TYPEDEF(key_compare);
	CHECK_TYPEDEF(size_type);
	CHECK_TYPEDEF(difference_type);
	CHECK_TYPEDEF(pointer);
	CHECK_TYPEDEF(const_pointer);
	CHECK_TYPEDEF(iterator);
	CHECK_TYPEDEF(const_iterator);
	CHECK_TYPEDEF(reverse_iterator);
	CHECK_TYPEDEF(const_reverse_iterator);

	{
		map< int, unsigned int >::value_type      b = map< int, unsigned int >::value_type(-11, 85);
		map< int, unsigned int >::reference       c = b;
		map< int, unsigned int >::const_reference d = b;
		(void)b;
		(void)c;
		(void)d;
	}
}

void test_map()
{
	visual_test();

	map_assignment();
	map_at();
	map_begin();
	map_check_typedefs();
	map_clear();
	map_compare();
	map_comparisons_eq();
	map_comparisons_ge();
	map_comparisons_gt();
	map_comparisons_le();
	map_comparisons_lt();
	map_comparisons_ne();
	map_constructor();
	map_count();
	map_ctor();
	map_ctor_copy();
	map_ctor_range();
	map_empty();
	map_end();
	map_equal_range();
	map_erase();
	map_erase_key();
	map_erase_range();
	map_find();
	map_get_allocator();
	map_index_operator();
	map_insert();
	map_insert_hint();
	map_insert_range();
	map_iterator();
	map_key_comp();
	map_lower_bound();
	map_operator_bracket();
	map_operator_equal();
	map_random();
	map_rbegin();
	map_relational_operators();
	map_rend();
	map_riterator();
	map_size();
	map_swap();
	map_swap_overload();
	map_upper_bound();
	map_value_comp();
}
