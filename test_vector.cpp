/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassepipe <norminet@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:52:31 by cassepipe         #+#    #+#             */
/*   Updated: 2022/09/10 13:52:31 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void test_vector_assign()
{
	{
		vector< int > my_vec;
		cout << "vector< int > my_vec;" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		my_vec.assign(10, 42);
		cout << "my_vec.assign( 10, 42 );" << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
	}

	cout << endl;

	{
		vector< int > my_vec(10, 0);
		cout << "vector< int > my_vec(10, 0);" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		my_vec.assign(10, 42);
		cout << "my_vec.assign( 10, 42 );" << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
	}

	cout << endl;

	{
		vector< int > my_vec(10, 42);
		cout << "vector< int > my_vec(10, 42);" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{
			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		my_vec.assign(0, 3);
		cout << "my_vec.assign( 0, 3 );" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
	}

	{
		vector< int > my_vec;
		for (vector< int >::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		cout << "my_vec" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{
			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}

		cout << endl;

		{
			vector< int > my_range_vec;
			my_range_vec.assign(my_vec.begin(), my_vec.end());
			cout << "vector< int > my_range_vec;" << endl;
			cout << "my_range_vec.assign( my_vec.begin(), my_vec.end() );" << endl;
			cout << "my_range_vec" << endl;
			cout << "size : " << my_range_vec.size() << endl;
			for (vector< int >::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				cout << *it;
				if (it + 1 != my_range_vec.end())
					cout << " ";
			}
		}

		cout << endl;

		{
			vector< int > my_range_vec;
			my_range_vec.assign(my_vec.begin(), my_vec.begin() + 5);
			cout << "vector< int > my_range_vec;" << endl;
			cout << "my_range_vec.assign( my_vec.begin(), my_vec.begin() + 5 );" << endl;
			cout << "my_range_vec" << endl;
			cout << "size : " << my_range_vec.size() << endl;
			for (vector< int >::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				cout << *it;
				if (it + 1 != my_range_vec.end())
					cout << " ";
			}
		}

		cout << endl;

		{
			vector< int > my_range_vec;
			my_range_vec.assign(my_vec.begin(), my_vec.begin());
			cout << "vector< int > my_range_vec;" << endl;
			cout << "my_range_vec.assign( my_vec.begin(), my_vec.begin() );" << endl;
			cout << "my_range_vec" << endl;
			cout << "size : " << my_range_vec.size() << endl;
			for (vector< int >::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				cout << *it;
				if (it + 1 != my_range_vec.end())
					cout << " ";
			}
		}
	}
}

void test_vector_at()
{

	{
		vector< int > my_vec(10);
		cout << my_vec.at(0) << endl;
	}

	{
		vector< int > my_vec(10);
		try
		{
			cout << my_vec.at(10) << endl;
		}
		catch (const std::exception& e)
		{
			cout << "Range exception caught after access attempt at index" << 10 << " while the vector only has"
			     << my_vec.size() << "\n";
			// cout << e.what() << endl;
		}
	}
	{
		vector< int > my_vec;
		try
		{
			cout << my_vec.at(0) << endl;
		}
		catch (const std::exception& e)
		{
			cout << "Range exception caught after access attempt in empty vector !";
			// cout << e.what() << endl;
		}
	}
	{
		vector< int >       my_vec(10);
		const vector< int > my_const_vec(10);
		const int           constI = my_const_vec.at(0);
		int                 i      = my_vec.at(0);
		cout << constI << " " << i << endl;
	}
}

void test_vector_back()
{
	{
		vector< int > my_vec(1, 42);
		cout << my_vec.back() << endl;
	}
	{
		vector< int > my_vec;
		for (int i = 0; i < 42; i++)
			my_vec.push_back(i + 1);
		cout << my_vec.back() << endl;
	}
	{
		vector< int >       my_vec(10, 42);
		const vector< int > my_const_vec(10, 42);
		const int           constI = my_const_vec.back();
		int                 i      = my_vec.back();
		cout << constI << " " << i << endl;
	}
}

void test_vector_begin()
{
	{
		vector< int > my_vec(10, 42);
		cout << *(my_vec.begin()) << endl;
	}
	{
		vector< int > my_vec;
		cout << (my_vec.begin() == my_vec.end()) << endl;
	}
	{
		vector< int >                 my_vec(10, 42);
		const vector< int >           my_const_vec(10, 42);
		vector< int >::iterator       it      = my_vec.begin();
		vector< int >::const_iterator constIt = my_const_vec.begin();
		cout << *constIt << " " << *it << endl;
	}
}

void test_vector_capacity()
{
	{
		vector< int > my_vec;
		cout << my_vec.capacity() << endl;
	}
	{
		vector< int > my_vec;
		my_vec.push_back(42);
		cout << my_vec.capacity() << endl;
	}
	{
		vector< int > my_vec;
		my_vec.push_back(42);
		my_vec.push_back(42);
		cout << my_vec.capacity() << endl;
	}
	{
		vector< int > my_vec;
		my_vec.push_back(42);
		my_vec.push_back(42);
		my_vec.push_back(42);
		cout << my_vec.capacity() << endl;
	}
	{
		vector< int > my_vec;
		my_vec.push_back(42);
		my_vec.push_back(42);
		my_vec.push_back(42);
		my_vec.push_back(42);
		my_vec.push_back(42);
		cout << my_vec.capacity() << endl;
	}
	{
		vector< int > my_vec;
		for (int i = 0; i < 42; i++)
			my_vec.push_back(i + 1);
		cout << "my_vec: " << my_vec.capacity() << endl;
		vector< int > my_copy_vec(my_vec);
		cout << "my_copy_vec: " << my_copy_vec.capacity() << endl;
	}
	{
		vector< int > my_vec;
		my_vec.assign(7, 42);
		cout << "my_vec: " << my_vec.capacity() << endl;
	}
	{
		vector< int > my_vec;
		for (int i = 0; i < 42; i++)
			my_vec.push_back(i + 1);
		cout << "my_vec: " << my_vec.capacity() << endl;
		cout << endl;
		vector< int > my_range_vec;
		my_range_vec.assign(my_vec.begin() + 4, my_vec.end() - 8);
		cout << "my_range_vec: " << my_range_vec.capacity() << endl;
	}
}

void test_vector_clear()
{
	{
		vector< int > my_vec(10, 42);
		cout << "size : " << my_vec.size() << " capacity : " << my_vec.capacity() << endl;
		my_vec.clear();
		cout << "After clear(), size : " << my_vec.size() << " capacity : " << my_vec.capacity() << endl;
	}
	{
		vector< int > my_vec;
		cout << "size : " << my_vec.size() << " capacity : " << my_vec.capacity() << endl;
		my_vec.clear();
		cout << "After clear(), size : " << my_vec.size() << " capacity : " << my_vec.capacity() << endl;
	}
	{
		vector< vector< int > > my_vec(10, vector< int >(15, 42));
		int                     i = 1;
		for (vector< vector< int > >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{
			cout << "inner vector #" << i << ", size : " << it->size() << " capacity : " << it->capacity() << endl;
			i++;
		}
		cout << " outer vector, size : " << my_vec.size() << " capacity : " << my_vec.capacity() << endl;
		cout << "Now let's clear all inner vectors" << endl;
		i = 1;
		for (vector< vector< int > >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{
			it->clear();
			cout << "After clear inner vector #" << i << ", size : " << it->size() << " capacity : " << it->capacity()
			     << endl;
			i++;
		}
		cout << "Now let's clear outer vector" << endl;
		my_vec.clear();
		cout << "After clear(), size : " << my_vec.size() << " capacity : " << my_vec.capacity() << endl;
	}
	{
		vector< int > my_vec(10, 42);
		cout << "size : " << my_vec.size() << " capacity : " << my_vec.capacity() << endl;
		my_vec.clear();
		cout << "After clear(), size : " << my_vec.size() << " capacity : " << my_vec.capacity() << endl;
		my_vec.clear();
		cout << "After second clear(), size : " << my_vec.size() << " capacity : " << my_vec.capacity() << endl;
	}
	{

		vector< int > my_vec;
		for (vector< int >::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		cout << "my_vec" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		my_vec.clear();
		my_vec.push_back(101010);
		my_vec.push_back(33);
		cout << "my_vec" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
	}
	{
		vector< int > my_vec;
		for (vector< int >::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		cout << "my_vec" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		my_vec.clear();
		my_vec.push_back(101010);
		my_vec.push_back(33);
		cout << "my_vec" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
	}
}

void test_vector_constructors()
{

	{
		vector< int > empty;
		cout << "size : " << empty.size() << endl;
		cout << "empty : " << empty.empty() << endl;
	}
	{
		vector< std::string > empty;
		cout << "size : " << empty.size() << endl;
		cout << "empty : " << empty.empty() << endl;
	}
	{
		vector< vector< int > > empty;
		cout << "size : " << empty.size() << endl;
		cout << "empty : " << empty.empty() << endl;
	}
	{
		vector< int > my_vec(10);
		cout << "vector< int > my_vec(10);" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;
	{
		vector< int > my_vec(10, 42);
		cout << "vector< int > my_vec(10, 42);" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
	}
	cout << endl;
	{
		vector< int > my_vec(0);
		cout << "vector< int > my_vec(0);" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
	}

	{

		vector< int > my_vec;
		for (vector< int >::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		cout << "my_vec" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		{
			vector< int > my_range_vec(my_vec.begin(), my_vec.end());
			cout << "vector< int > my_range_vec( my_vec.begin(), my_vec.end());" << endl;
			cout << "my_range_vec" << endl;
			cout << "size : " << my_range_vec.size() << endl;
			for (vector< int >::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				cout << *it;
				if (it + 1 != my_range_vec.end())
					cout << " ";
			}
		}
		cout << endl;
		{
			vector< int > my_range_vec(my_vec.begin(), my_vec.begin() + 5);
			cout << "vector< int > my_range_vec( my_vec.begin(), my_vec.begin() + 5);" << endl;
			cout << "my_range_vec" << endl;
			cout << "size : " << my_range_vec.size() << endl;
			for (vector< int >::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				cout << *it;
				if (it + 1 != my_range_vec.end())
					cout << " ";
			}
		}
		cout << endl;
		{
			vector< int > my_range_vec(my_vec.begin(), my_vec.begin());
			cout << "vector< int > my_range_vec( my_vec.begin(), my_vec.begin());" << endl;
			cout << "my_range_vec" << endl;
			cout << "size : " << my_range_vec.size() << endl;
			for (vector< int >::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				cout << *it;
				if (it + 1 != my_range_vec.end())
					cout << " ";
			}
		}
	}

	{
		vector< int > my_vec;
		for (vector< int >::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		cout << "my_vec" << endl;
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		{
			vector< int > my_range_vec(my_vec);
			my_vec.clear();
			cout << "vector< int > my_range_vec( my_vec );" << endl;
			cout << "my_range_vec" << endl;
			cout << "size : " << my_range_vec.size() << endl;
			for (vector< int >::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				cout << *it;
				if (it + 1 != my_range_vec.end())
					cout << " ";
			}
			cout << endl;
			cout << endl;
			cout << "my_vec.clear();" << endl;
			cout << "my_vec" << endl;
			cout << "size : " << my_vec.size() << endl;
			cout << endl;
			cout << "my_range_vec" << endl;
			cout << "size : " << my_range_vec.size() << endl;
			for (vector< int >::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				cout << *it;
				if (it + 1 != my_range_vec.end())
					cout << " ";
			}
		}
		cout << endl;
		{
			vector< int > my_range_vec(my_vec);
			cout << "vector< int > my_range_vec( my_vec );" << endl;
			cout << "my_range_vec" << endl;
			cout << "size : " << my_range_vec.size() << endl;
			for (vector< int >::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				cout << *it;
				if (it + 1 != my_range_vec.end())
					cout << " ";
			}
		}
	}
}

void test_vector_empty()
{
	{
		vector< int > my_vec;
		cout << my_vec.empty() << endl;
	}
	{
		vector< int > my_vec(1, 42);
		cout << my_vec.empty() << endl;
	}
	{
		vector< int > my_vec(1, 42);
		my_vec.clear();
		cout << my_vec.empty() << endl;
	}
	{
		vector< int > my_vec(1, 42);
		my_vec.clear();
		my_vec.push_back(101010);
		cout << my_vec.empty() << endl;
	}
}

void test_vector_end()
{
	{
		vector< int > my_vec;
		for (int i = 0; i < 42; i++)
			my_vec.push_back(i + 1);
		cout << *(my_vec.end() - 1) << endl;
	}

	{
		vector< int >                 my_vec(10, 42);
		const vector< int >           myConstVec(10, 42);
		vector< int >::iterator       it      = my_vec.end() - 1;
		vector< int >::const_iterator constIt = myConstVec.end() - 1;

		cout << *constIt << " " << *it << endl;
	}
}

void test_vector_erase()
{
	{
		vector< int > my_vec;
		for (vector< int >::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		my_vec.erase(my_vec.begin());
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		my_vec.erase(my_vec.begin() + 10);
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		cout << endl;
		my_vec.erase(my_vec.end() - 1);
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
	}
	{
		vector< int > my_vec;
		for (vector< int >::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		cout << endl;
		my_vec.erase(my_vec.begin(), my_vec.begin() + 5);
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		cout << endl;
		my_vec.erase(my_vec.begin(), my_vec.begin());
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		cout << endl;
		my_vec.erase(my_vec.begin() + 10, my_vec.end() - 10);
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		cout << endl;
		my_vec.erase(my_vec.begin(), my_vec.end());
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
	}
}

void test_vector_front()
{
	{
		vector< int > my_vec;
		for (vector< int >::size_type i = 0; i < 42; ++i)
		{
			my_vec.push_back(i + 1);
			my_vec.front() += i;
		}
		cout << "size : " << my_vec.size() << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
	}
	{
		vector< vector< int > > my_vec(5, vector< int >());
		int                     i = 1;
		for (vector< vector< int > >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{
			for (int j = 1; j < 21; j++)
			{
				it->push_back(j * i);
			}
			i++;
		}
		for (vector< vector< int > >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			for (vector< vector< int > >::iterator it2 = it; it2 != my_vec.end(); it2++)
			{

				for (vector< int >::iterator it3 = it2->begin(); it3 != it2->end(); it3++)
				{
					it->front() += *it3;
				}
			}
		}

		i = 1;
		for (vector< vector< int > >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << "vector #" << i << " : ";
			for (vector< int >::iterator it2 = it->begin(); it2 != it->end(); it2++)
			{

				cout << *it2;
				if (it2 + 1 != it->end())
					cout << " ";
			}
			cout << endl;
			i++;
		}
	}
}

void test_vector_get_allocator()
{
	vector< int > myvector;
	int*          p;
	unsigned int  i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().construct(&p[i], i);

	cout << "The allocated array contains:";
	for (i = 0; i < 5; i++)
		cout << ' ' << p[i];
	cout << '\n';

	// destroy and deallocate:
	for (i = 0; i < 5; i++)
		myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p, 5);
}

void test_vector_insert()
{
	{
		vector< int > my_vec;
		my_vec.insert(my_vec.begin(), 42);
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); ++it)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;

		my_vec.insert(my_vec.begin(), 33);
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); ++it)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;

		my_vec.insert(my_vec.begin() + 1, 101010);
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); ++it)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;

		my_vec.insert(my_vec.end(), 9);
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); ++it)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		my_vec.clear();
		cout << endl;

		my_vec.insert(my_vec.end(), 101);
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); ++it)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
	}
}

void test_vector_max_size()
{
	{
		vector< int > my_vec;
		cout << "max_size : " << my_vec.max_size() << endl;
	}
	{
		vector< char > my_vec;
		cout << "max_size : " << my_vec.max_size() << endl;
	}
	{
		vector< std::string > my_vec;
		cout << "max_size : " << my_vec.max_size() << endl;
	}
	{
		// This one will differ, I can explain
		// vector< vector< vector <int >  > >	my_vec;
		// cout << "max_size : " << my_vec.max_size() << endl;
	}
}

void test_vector_operator_bracket()
{
	{
		vector< int >            myvector(10); // 10 zero-initialized elements
		vector< int >::size_type sz = myvector.size();
		// assign some values:
		for (unsigned i = 0; i < sz; i++)
			myvector[i] = i;
		// reverse vector using operator[]:
		for (unsigned i = 0; i < sz / 2; i++)
		{
			int temp;
			temp                 = myvector[sz - 1 - i];
			myvector[sz - 1 - i] = myvector[i];
			myvector[i]          = temp;
		}
		cout << "myvector contains:";
		for (unsigned i = 0; i < sz; i++)
			cout << ' ' << myvector[i];
		cout << '\n';
	}
	{
		vector< int > my_vec(10);
		cout << my_vec[9] << endl;
	}
}

void test_vector_operator_equal()
{
	vector< int > foo(3, 0);
	vector< int > bar(5, 0);

	bar = foo;
	foo = vector< int >(42, 42);

	cout << "Size of foo: " << int(foo.size()) << '\n';
	for (vector< int >::iterator it = foo.begin(); it != foo.end(); ++it)
	{

		cout << *it;
		if (it + 1 != foo.end())
			cout << " ";
	}
	cout << endl;
	cout << "Size of bar: " << int(bar.size()) << '\n';
	for (vector< int >::iterator it = bar.begin(); it != bar.end(); ++it)
	{

		cout << *it;
		if (it + 1 != bar.end())
			cout << " ";
	}
	cout << endl;
}

void test_vector_pop_back()
{
	{
		vector< int > myvector;
		int           sum(0);
		myvector.push_back(100);
		myvector.push_back(200);
		myvector.push_back(300);
		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}
		cout << "The elements of myvector add up to " << sum << '\n';
	}
	{
		vector< int > my_vec;
		for (int i = 0; i < 42; i++)
			my_vec.push_back(i + 1);
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;

		my_vec.pop_back();

		cout << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		my_vec.insert(my_vec.end(), my_vec.end() - 10, my_vec.end());
		cout << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;

		my_vec.pop_back();
		cout << endl;
		for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			cout << *it;
			if (it + 1 != my_vec.end())
				cout << " ";
		}
		cout << endl;
		cout << endl;
		while (my_vec.empty() == false)
		{

			my_vec.pop_back();
			for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
			{

				cout << *it;
				if (it + 1 != my_vec.end())
					cout << " ";
			}
			cout << endl;
		}
	}
}

void test_vector_push_back()
{
	vector< int > my_vec;

	for (int i = 1; i <= 42; ++i)
		my_vec.push_back(i % 10);
	for (vector< int >::iterator it = my_vec.begin(); it != my_vec.end(); ++it)
	{

		cout << *it;
		if (it + 1 != my_vec.end())
			cout << " ";
	}
	cout << endl;
}

void test_vector_rbegin()
{
	{
		vector< int >                   myvector(5); // 5 default-constructed ints
		int                             i   = 0;
		vector< int >::reverse_iterator rit = myvector.rbegin();
		for (; rit != myvector.rend(); ++rit)
			*rit = ++i;
		cout << "myvector contains:";
		for (vector< int >::iterator it = myvector.begin(); it != myvector.end(); ++it)
			cout << ' ' << *it;
		cout << endl;
	}
}

void test_vector_relational_operators()
{
	vector< int > foo(3, 100);
	vector< int > bar(5, 200);

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

void test_vector_rend()
{
	{
		vector< int > my_vec;
		for (int i = 0; i < 42; i++)
			my_vec.push_back(i + 1);
		cout << endl;
		cout << *(my_vec.rend() - 1) << endl;
	}
	{
		vector< int >                         my_vec(10, 42);
		const vector< int >                   myconstvec(10, 42);
		vector< int >::reverse_iterator       it      = --my_vec.rend();
		vector< int >::const_reverse_iterator constit = --myconstvec.rend();
		cout << *constit << " " << *it << endl;
	}
}

void test_vector_reserve()
{
	{
		vector< int >::size_type sz;

		vector< int > foo;
		sz = foo.capacity();
		cout << "making foo grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			foo.push_back(i);
			if (sz != foo.capacity())
			{
				sz = foo.capacity();
				cout << "capacity changed: " << sz << '\n';
			}
		}

		vector< int > bar;
		sz = bar.capacity();
		bar.reserve(100); // this is the only difference with foo above
		cout << "making bar grow:\n";
		for (int i = 0; i < 100; ++i)
		{
			bar.push_back(i);
			if (sz != bar.capacity())
			{
				sz = bar.capacity();
				cout << "capacity changed: " << sz << '\n';
			}
		}
	}
	{

		vector< int > my_vec;

		try
		{
			my_vec.reserve(my_vec.max_size() + 1);
		}
		catch (const std::exception& e)
		{
			cout << e.what() << std::endl;
		}
	}

	{
		// vector< int > my_vec;
		// try {
		//    my_vec.reserve( my_vec.max_size() - 1 );
		//} catch ( const std::exception & e ) {
		//    cout << e.what() << std::endl;
		//}
	}
}

void test_vector_resize()
{
	vector< int > my_vec;
	for (int i = 1; i < 10; i++)
		my_vec.push_back(i);
	my_vec.resize(5);
	my_vec.resize(8, 100);
	my_vec.resize(13);
	cout << "my vector contains:";
	for (vector< int >::size_type i = 0; i < my_vec.size(); ++i)
		cout << ' ' << my_vec[i];
	cout << std::endl;
	my_vec.resize(0);
	cout << "my vector contains:";
	for (vector< int >::size_type i = 0; i < my_vec.size(); ++i)
		cout << ' ' << my_vec[i];
	cout << std::endl;
	my_vec.resize(0);
	for (vector< int >::size_type i = 0; i < my_vec.size(); ++i)
		cout << ' ' << my_vec[i];
	cout << std::endl;
}

void test_vector_size()
{
	vector< int > my_vec;
	std::cout << "0. size : " << my_vec.size() << std::endl;

	for (int i = 0; i < 10; i++)
		my_vec.push_back(i);
	std::cout << "1. size : " << my_vec.size() << std::endl;

	my_vec.insert(my_vec.end(), 10, 100);
	std::cout << "2. size : " << my_vec.size() << std::endl;

	my_vec.pop_back();
	std::cout << "3. size : " << my_vec.size() << std::endl;
}

void test_vector_swap()
{
	vector< int > foo(3, 100);
	vector< int > bar(5, 200);
	foo.swap(bar);
	std::cout << "foo contains:";
	for (unsigned int i = 0; i < foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << std::endl;
	std::cout << "bar contains:";
	for (unsigned int i = 0; i < bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << std::endl;
}

void test_vector_swap_overload()
{
	vector< int > foo(3, 100);
	vector< int > bar(5, 200);

	std::swap(foo, bar);

	std::cout << "foo contains:";
	for (unsigned int i = 0; i < foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << std::endl;

	std::cout << "bar contains:";
	for (unsigned int i = 0; i < bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << std::endl;
}

void test_vector()
{
	test_vector_assign();
	test_vector_at();
	test_vector_back();
	test_vector_begin();
	test_vector_capacity();
	test_vector_clear();
	test_vector_constructors();
	test_vector_empty();
	test_vector_end();
	test_vector_erase();
	test_vector_front();
	test_vector_get_allocator();
	test_vector_insert();
	test_vector_max_size();
	test_vector_operator_bracket();
	test_vector_operator_equal();
	test_vector_pop_back();
	test_vector_push_back();
	test_vector_rbegin();
	test_vector_relational_operators();
	test_vector_rend();
	test_vector_reserve();
	test_vector_resize();
	test_vector_size();
	test_vector_swap();
	test_vector_swap_overload();
}
