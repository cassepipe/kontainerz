#include "test.hpp"

void test_vector()
{
	// test_vector_assign();
	// test_vector_at();
	// test_vector_back();
	// test_vector_begin();
	// test_vector_capacity();
	// test_vector_clear();
	// test_vector_constructors();
	//test_vector_empty();
	//test_vector_end();
	//test_vector_erase();
	//test_vector_front();
	//test_vector_get_allocator();
	test_vector_insert();
	// test_vector_max_size();
	// test_vector_operator_bracket();
	// test_vector_operator_equal();
	// test_vector_pop_back();
	// test_vector_push_back();
	// test_vector_rbegin();
	// test_vector_relational_operators();
	// test_vector_rend();
	// test_vector_reserve();
	// test_vector_resize();
	// test_vector_size();
	// test_vector_swap();
	// test_vector_swap_overload();
}

void test_vector_assign()
{
	{
		vector<int> my_vec;
		std::cout << "vector< int > my_vec;" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		my_vec.assign(10, 42);
		std::cout << "my_vec.assign( 10, 42 );" << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		vector<int> my_vec(10, 0);
		std::cout << "vector< int > my_vec(10, 0);" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		my_vec.assign(10, 42);
		std::cout << "my_vec.assign( 10, 42 );" << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		vector<int> my_vec(10, 42);
		std::cout << "vector< int > my_vec(10, 42);" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{
			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		my_vec.assign(0, 3);
		std::cout << "my_vec.assign( 0, 3 );" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	{
		vector<int> my_vec;
		for (vector<int>::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		std::cout << "my_vec" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{
			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}

		std::cout << std::endl;

		{
			vector<int> my_range_vec;
			my_range_vec.assign(my_vec.begin(), my_vec.end());
			std::cout << "vector< int > my_range_vec;" << std::endl;
			std::cout << "my_range_vec.assign( my_vec.begin(), my_vec.end() );" << std::endl;
			std::cout << "my_range_vec" << std::endl;
			std::cout << "size : " << my_range_vec.size() << std::endl;
			for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				std::cout << *it;
				if (it + 1 != my_range_vec.end())
					std::cout << " ";
			}
		}

		std::cout << std::endl;

		{
			vector<int> my_range_vec;
			my_range_vec.assign(my_vec.begin(), my_vec.begin() + 5);
			std::cout << "vector< int > my_range_vec;" << std::endl;
			std::cout << "my_range_vec.assign( my_vec.begin(), my_vec.begin() + 5 );" << std::endl;
			std::cout << "my_range_vec" << std::endl;
			std::cout << "size : " << my_range_vec.size() << std::endl;
			for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				std::cout << *it;
				if (it + 1 != my_range_vec.end())
					std::cout << " ";
			}
		}

		std::cout << std::endl;

		{
			vector<int> my_range_vec;
			my_range_vec.assign(my_vec.begin(), my_vec.begin());
			std::cout << "vector< int > my_range_vec;" << std::endl;
			std::cout << "my_range_vec.assign( my_vec.begin(), my_vec.begin() );" << std::endl;
			std::cout << "my_range_vec" << std::endl;
			std::cout << "size : " << my_range_vec.size() << std::endl;
			for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				std::cout << *it;
				if (it + 1 != my_range_vec.end())
					std::cout << " ";
			}
		}
	}
}

void test_vector_at()
{

	{
		vector<int> my_vec(10);
		std::cout << my_vec.at(0) << std::endl;
	}

	{
		vector<int> my_vec(10);
		try
		{
			std::cout << my_vec.at(10) << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Range exception caught after access attempt at index" << 10 << " while the vector only has"
				<< my_vec.size() << "\n";
			// std::cout << e.what() << std::endl;
		}
	}
	{
		vector<int> my_vec;
		try
		{
			std::cout << my_vec.at(0) << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Range exception caught after access attempt in empty vector !";
			// std::cout << e.what() << std::endl;
		}
	}
	{
		vector<int>       my_vec(10);
		const vector<int> my_const_vec(10);
		const int         constI = my_const_vec.at(0);
		int               i      = my_vec.at(0);
		std::cout << constI << " " << i << std::endl;
	}
}

void test_vector_back()
{
	{
		vector<int> my_vec(1, 42);
		std::cout << my_vec.back() << std::endl;
	}
	{
		vector<int> my_vec;
		for (int i = 0; i < 42; i++)
			my_vec.push_back(i + 1);
		std::cout << my_vec.back() << std::endl;
	}
	{
		vector<int>       my_vec(10, 42);
		const vector<int> my_const_vec(10, 42);
		const int         constI = my_const_vec.back();
		int               i      = my_vec.back();
		std::cout << constI << " " << i << std::endl;
	}
}

void test_vector_begin()
{
	{
		vector<int> my_vec(10, 42);
		std::cout << *(my_vec.begin()) << std::endl;
	}
	{
		vector<int> my_vec;
		std::cout << (my_vec.begin() == my_vec.end()) << std::endl;
	}
	{
		vector<int>                 my_vec(10, 42);
		const vector<int>           my_const_vec(10, 42);
		vector<int>::iterator       it      = my_vec.begin();
		vector<int>::const_iterator constIt = my_const_vec.begin();
		std::cout << *constIt << " " << *it << std::endl;
	}
}

void test_vector_capacity()
{
	{
		vector<int> my_vec;
		std::cout << my_vec.capacity() << std::endl;
	}
	{
		vector<int> my_vec;
		my_vec.push_back(42);
		std::cout << my_vec.capacity() << std::endl;
	}
	{
		vector<int> my_vec;
		my_vec.push_back(42);
		my_vec.push_back(42);
		std::cout << my_vec.capacity() << std::endl;
	}
	{
		vector<int> my_vec;
		my_vec.push_back(42);
		my_vec.push_back(42);
		my_vec.push_back(42);
		std::cout << my_vec.capacity() << std::endl;
	}
	{
		vector<int> my_vec;
		my_vec.push_back(42);
		my_vec.push_back(42);
		my_vec.push_back(42);
		my_vec.push_back(42);
		my_vec.push_back(42);
		std::cout << my_vec.capacity() << std::endl;
	}
	{
		vector<int> my_vec;
		for (int i = 0; i < 42; i++)
			my_vec.push_back(i + 1);
		std::cout << "my_vec: " << my_vec.capacity() << std::endl;
		vector<int> my_copy_vec(my_vec);
		std::cout << "my_copy_vec: " << my_copy_vec.capacity() << std::endl;
	}
	{
		vector<int> my_vec;
		my_vec.assign(7, 42);
		std::cout << "my_vec: " << my_vec.capacity() << std::endl;
	}
	{
		vector<int> my_vec;
		for (int i = 0; i < 42; i++)
			my_vec.push_back(i + 1);
		std::cout << "my_vec: " << my_vec.capacity() << std::endl;
		std::cout << std::endl;
		vector<int> my_range_vec;
		my_range_vec.assign(my_vec.begin() + 4, my_vec.end() - 8);
		std::cout << "my_range_vec: " << my_range_vec.capacity() << std::endl;
	}
}

void test_vector_clear()
{
	{
		vector<int> my_vec(10, 42);
		std::cout << "size : " << my_vec.size() << " capacity : " << my_vec.capacity() << std::endl;
		my_vec.clear();
		std::cout << "After clear(), size : " << my_vec.size() << " capacity : " << my_vec.capacity() << std::endl;
	}
	{
		vector<int> my_vec;
		std::cout << "size : " << my_vec.size() << " capacity : " << my_vec.capacity() << std::endl;
		my_vec.clear();
		std::cout << "After clear(), size : " << my_vec.size() << " capacity : " << my_vec.capacity() << std::endl;
	}
	{
		vector< vector<int> > my_vec(10, vector<int>(15, 42));
		int                 i = 1;
		for (vector< vector<int> >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{
			std::cout << "inner vector #" << i << ", size : " << it->size() << " capacity : " << it->capacity()
				<< std::endl;
			i++;
		}
		std::cout << " outer vector, size : " << my_vec.size() << " capacity : " << my_vec.capacity() << std::endl;
		std::cout << "Now let's clear all inner vectors" << std::endl;
		i = 1;
		for (vector< vector<int> >::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{
			it->clear();
			std::cout << "After clear inner vector #" << i << ", size : " << it->size()
				<< " capacity : " << it->capacity() << std::endl;
			i++;
		}
		std::cout << "Now let's clear outer vector" << std::endl;
		my_vec.clear();
		std::cout << "After clear(), size : " << my_vec.size() << " capacity : " << my_vec.capacity() << std::endl;
	}
	{
		vector<int> my_vec(10, 42);
		std::cout << "size : " << my_vec.size() << " capacity : " << my_vec.capacity() << std::endl;
		my_vec.clear();
		std::cout << "After clear(), size : " << my_vec.size() << " capacity : " << my_vec.capacity() << std::endl;
		my_vec.clear();
		std::cout << "After second clear(), size : " << my_vec.size() << " capacity : " << my_vec.capacity()
			<< std::endl;
	}
	{

		vector<int> my_vec;
		for (vector<int>::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		std::cout << "my_vec" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		my_vec.clear();
		my_vec.push_back(101010);
		my_vec.push_back(33);
		std::cout << "my_vec" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	{
		vector<int> my_vec;
		for (vector<int>::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		std::cout << "my_vec" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		my_vec.clear();
		my_vec.push_back(101010);
		my_vec.push_back(33);
		std::cout << "my_vec" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void test_vector_constructors()
{

	{
		vector<int> empty;
		std::cout << "size : " << empty.size() << std::endl;
		std::cout << "empty : " << empty.empty() << std::endl;
	}
	{
		vector<std::string> empty;
		std::cout << "size : " << empty.size() << std::endl;
		std::cout << "empty : " << empty.empty() << std::endl;
	}
	{
		vector< vector<int> > empty;
		std::cout << "size : " << empty.size() << std::endl;
		std::cout << "empty : " << empty.empty() << std::endl;
	}
	{
		vector<int> my_vec(10);
		std::cout << "vector< int > my_vec(10);" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		vector<int> my_vec(10, 42);
		std::cout << "vector< int > my_vec(10, 42);" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	{
		vector<int> my_vec(0);
		std::cout << "vector< int > my_vec(0);" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	{

		vector<int> my_vec;
		for (vector<int>::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		std::cout << "my_vec" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		{
			vector<int> my_range_vec(my_vec.begin(), my_vec.end());
			std::cout << "vector< int > my_range_vec( my_vec.begin(), my_vec.end());" << std::endl;
			std::cout << "my_range_vec" << std::endl;
			std::cout << "size : " << my_range_vec.size() << std::endl;
			for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				std::cout << *it;
				if (it + 1 != my_range_vec.end())
					std::cout << " ";
			}
		}
		std::cout << std::endl;
		{
			vector<int> my_range_vec(my_vec.begin(), my_vec.begin() + 5);
			std::cout << "vector< int > my_range_vec( my_vec.begin(), my_vec.begin() + 5);" << std::endl;
			std::cout << "my_range_vec" << std::endl;
			std::cout << "size : " << my_range_vec.size() << std::endl;
			for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				std::cout << *it;
				if (it + 1 != my_range_vec.end())
					std::cout << " ";
			}
		}
		std::cout << std::endl;
		{
			vector<int> my_range_vec(my_vec.begin(), my_vec.begin());
			std::cout << "vector< int > my_range_vec( my_vec.begin(), my_vec.begin());" << std::endl;
			std::cout << "my_range_vec" << std::endl;
			std::cout << "size : " << my_range_vec.size() << std::endl;
			for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				std::cout << *it;
				if (it + 1 != my_range_vec.end())
					std::cout << " ";
			}
		}
	}

	{
		vector<int> my_vec;
		for (vector<int>::size_type i = 0; i < 42; ++i)
			my_vec.push_back(i + 1);
		std::cout << "my_vec" << std::endl;
		std::cout << "size : " << my_vec.size() << std::endl;
		for (vector<int>::iterator it = my_vec.begin(); it != my_vec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		{
			vector<int> my_range_vec(my_vec);
			my_vec.clear();
			std::cout << "vector< int > my_range_vec( my_vec );" << std::endl;
			std::cout << "my_range_vec" << std::endl;
			std::cout << "size : " << my_range_vec.size() << std::endl;
			for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				std::cout << *it;
				if (it + 1 != my_range_vec.end())
					std::cout << " ";
			}
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "my_vec.clear();" << std::endl;
			std::cout << "my_vec" << std::endl;
			std::cout << "size : " << my_vec.size() << std::endl;
			std::cout << std::endl;
			std::cout << "my_range_vec" << std::endl;
			std::cout << "size : " << my_range_vec.size() << std::endl;
			for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				std::cout << *it;
				if (it + 1 != my_range_vec.end())
					std::cout << " ";
			}
		}
		std::cout << std::endl;
		{
			vector<int> my_range_vec(my_vec);
			std::cout << "vector< int > my_range_vec( my_vec );" << std::endl;
			std::cout << "my_range_vec" << std::endl;
			std::cout << "size : " << my_range_vec.size() << std::endl;
			for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			{

				std::cout << *it;
				if (it + 1 != my_range_vec.end())
					std::cout << " ";
			}
		}
	}
}

void test_vector_empty()
{
	{
		vector<int> my_vec;
		std::cout << my_vec.empty() << std::endl;
	}
	{
		vector<int> my_vec(1, 42);
		std::cout << my_vec.empty() << std::endl;
	}
	{
		vector<int> my_vec(1, 42);
		my_vec.clear();
		std::cout << my_vec.empty() << std::endl;
	}
	{
		vector<int> my_vec(1, 42);
		my_vec.clear();
		my_vec.push_back(101010);
		std::cout << my_vec.empty() << std::endl;
	}
}

void test_vector_end()
{
	{
		vector<int> my_vec;
		for (int i = 0; i < 42; i++)
			my_vec.push_back(i + 1);
		std::cout << *(my_vec.end() - 1) << std::endl;
	}

	{
		vector<int>                 my_vec(10, 42);
		const vector<int>           myConstVec(10, 42);
		vector<int>::iterator       it      = my_vec.end() - 1;
		vector<int>::const_iterator constIt = myConstVec.end() - 1;

		std::cout << *constIt << " " << *it << std::endl;
	}
}

void test_vector_erase()
{
	{
		vector< int > my_vec;
		for ( vector< int >::size_type i = 0; i < 42 ; ++i )
			my_vec.push_back(i + 1);
		for ( vector< int >::iterator it = my_vec.begin() ; it != my_vec.end() ; it++ ) {

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		my_vec.erase(my_vec.begin());
		for ( vector< int >::iterator it = my_vec.begin() ; it != my_vec.end() ; it++ ) {

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		my_vec.erase(my_vec.begin() + 10);
		for ( vector< int >::iterator it = my_vec.begin() ; it != my_vec.end() ; it++ ) {

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		my_vec.erase(my_vec.end() - 1);
		for ( vector< int >::iterator it = my_vec.begin() ; it != my_vec.end() ; it++ ) {

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	{
		vector< int > my_vec;
		for ( vector< int >::size_type i = 0; i < 42 ; ++i )
			my_vec.push_back(i + 1);
		std::cout << "size : " << my_vec.size() << std::endl;
		for ( vector< int >::iterator it = my_vec.begin() ; it != my_vec.end() ; it++ ) {

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		my_vec.erase(my_vec.begin(), my_vec.begin() + 5);
		std::cout << "size : " << my_vec.size() << std::endl;
		for ( vector< int >::iterator it = my_vec.begin() ; it != my_vec.end() ; it++ ) {

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		my_vec.erase(my_vec.begin(), my_vec.begin());
		std::cout << "size : " << my_vec.size() << std::endl;
		for ( vector< int >::iterator it = my_vec.begin() ; it != my_vec.end() ; it++ ) {

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		my_vec.erase(my_vec.begin() + 10, my_vec.end() - 10);
		std::cout << "size : " << my_vec.size() << std::endl;
		for ( vector< int >::iterator it = my_vec.begin() ; it != my_vec.end() ; it++ ) {

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;
		my_vec.erase(my_vec.begin(), my_vec.end());
		std::cout << "size : " << my_vec.size() << std::endl;
		for ( vector< int >::iterator it = my_vec.begin() ; it != my_vec.end() ; it++ ) {

			std::cout << *it;
			if (it + 1 != my_vec.end())
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

void test_vector_front()
{
	{
		vector< int > myVec;
		for ( vector< int >::size_type i = 0; i < 42 ; ++i ) {
			myVec.push_back(i + 1);
			myVec.front() += i;
		}
		std::cout << "size : " << myVec.size() << std::endl;
		for ( vector< int >::iterator it = myVec.begin() ; it != myVec.end() ; it++ ) {

			std::cout << *it;
			if (it + 1 != myVec.end())
				std::cout << " ";
		}
	}
	{
		vector< vector< int > > myVec( 5, vector< int > () );
		int i = 1;
		for ( vector< vector< int > >::iterator it = myVec.begin() ; it != myVec.end() ; it++) {
			for ( int j = 1 ; j < 21 ; j++ ) {
				it->push_back( j * i );
			}
			i++;
		}
		for ( vector< vector< int > >::iterator it = myVec.begin() ; it != myVec.end() ; it++) {

			for ( vector< vector< int > >::iterator it2 = it ; it2 != myVec.end() ; it2++ ) {

				for ( vector< int >::iterator it3 = it2->begin() ; it3 != it2->end() ; it3++ ) {
					it->front() += *it3;
				}
			}
		}

		i = 1;
		for ( vector< vector< int > >::iterator it = myVec.begin() ; it != myVec.end() ; it++) {

			std::cout << "vector #"	<< i << " : ";
			for ( vector< int >::iterator it2 = it->begin() ; it2 != it->end() ; it2++ ) {

				std::cout << *it2;
				if ( it2 + 1 != it->end() )
					std::cout << " ";
			}
			std::cout << std::endl;
			i++;
		}
	}
}

void test_vector_get_allocator()
{
	vector<int>	myvector;
	int *	p;
	unsigned int	i;

	// allocate an array with space for 5 elements using vector's allocator:
	p = myvector.get_allocator().allocate(5);

	// construct values in-place on the array:
	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';

	// destroy and deallocate:
	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void test_vector_insert()
{
	{
		vector< int > myVec;
		myVec.insert( myVec.begin(), 42);
		//for ( vector< int >::iterator it = myVec.begin() ; it != myVec.end() ; ++it ) {

		//    std::cout << *it;
		//    if ( it + 1 != myVec.end() )
		//        std::cout << " ";
		//}
		//std::cout << std::endl;
		//std::cout << std::endl;

		//myVec.insert( myVec.begin(), 33);
		//for ( vector< int >::iterator it = myVec.begin() ; it != myVec.end() ; ++it ) {

		//    std::cout << *it;
		//    if ( it + 1 != myVec.end() )
		//        std::cout << " ";
		//}
		//std::cout << std::endl;
		//std::cout << std::endl;

		//myVec.insert( myVec.begin() + 1, 101010);
		//for ( vector< int >::iterator it = myVec.begin() ; it != myVec.end() ; ++it ) {

		//    std::cout << *it;
		//    if ( it + 1 != myVec.end() )
		//        std::cout << " ";
		//}
		//std::cout << std::endl;
		//std::cout << std::endl;

		//myVec.insert( myVec.end(), 9);
		//for ( vector< int >::iterator it = myVec.begin() ; it != myVec.end() ; ++it ) {

		//    std::cout << *it;
		//    if ( it + 1 != myVec.end() )
		//        std::cout << " ";
		//}
		//std::cout << std::endl;
		//myVec.clear();
		//std::cout << std::endl;

		//myVec.insert( myVec.end(), 101);
		//for ( vector< int >::iterator it = myVec.begin() ; it != myVec.end() ; ++it ) {

		//    std::cout << *it;
		//    if ( it + 1 != myVec.end() )
		//        std::cout << " ";
		//}
		//std::cout << std::endl;
	}
}

void test_vector_max_size()
{
}

void test_vector_operator_bracket()
{
}

void test_vector_operator_equal()
{
}

void test_vector_pop_back()
{
}

void test_vector_push_back()
{
}

void test_vector_rbegin()
{
}

void test_vector_relational_operators()
{
}

void test_vector_rend()
{
}

void test_vector_reserve()
{
}

void test_vector_resize()
{
}

void test_vector_size()
{
}

void test_vector_swap()
{
}

void test_vector_swap_overload()
{
}
