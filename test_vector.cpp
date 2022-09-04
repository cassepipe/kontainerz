#include "test_vector.hpp"
#include "test.h"

void test_vector()
{
	test_vector_assign();
	test_vector_at();
	test_vector_back();
	test_vector_begin();
	//test_vector_capacity();
	//test_vector_clear();
	//test_vector_constructors();
	//test_vector_empty();
	//test_vector_end();
	//test_vector_erase();
	//test_vector_front();
	//test_vector_get_allocator();
	//test_vector_insert();
	//test_vector_max_size();
	//test_vector_operator_bracket();
	//test_vector_operator_equal();
	//test_vector_pop_back();
	//test_vector_push_back();
	//test_vector_rbegin();
	//test_vector_relational_operators();
	//test_vector_rend();
	//test_vector_reserve();
	//test_vector_resize();
	//test_vector_size();
	//test_vector_swap();
	//test_vector_swap_overload();
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

		// Prevents linkage
		{
			//vector<int> my_range_vec;
			//my_range_vec.assign(my_vec.begin(), my_vec.end());
			//std::cout << "vector< int > my_range_vec;" << std::endl;
			//std::cout << "my_range_vec.assign( my_vec.begin(), my_vec.end() );" << std::endl;
			//std::cout << "my_range_vec" << std::endl;
			//std::cout << "size : " << my_range_vec.size() << std::endl;
			//for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
			//{

			//    std::cout << *it;
			//    if (it + 1 != my_range_vec.end())
			//        std::cout << " ";
			//}
		}

		std::cout << std::endl;
		
		// Prevents linkage
	//    {
	//        vector<int> my_range_vec;
	//        my_range_vec.assign(my_vec.begin(), my_vec.begin() + 5);
	//        std::cout << "vector< int > my_range_vec;" << std::endl;
	//        std::cout << "my_range_vec.assign( my_vec.begin(), my_vec.begin() + 5 );" << std::endl;
	//        std::cout << "my_range_vec" << std::endl;
	//        std::cout << "size : " << my_range_vec.size() << std::endl;
	//        for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
	//        {

	//            std::cout << *it;
	//            if (it + 1 != my_range_vec.end())
	//                std::cout << " ";
	//        }
	//    }

		std::cout << std::endl;

		// Prevent linkage
	//    {
	//        vector<int> my_range_vec;
	//        my_range_vec.assign(my_vec.begin(), my_vec.begin());
	//        std::cout << "vector< int > my_range_vec;" << std::endl;
	//        std::cout << "my_range_vec.assign( my_vec.begin(), my_vec.begin() );" << std::endl;
	//        std::cout << "my_range_vec" << std::endl;
	//        std::cout << "size : " << my_range_vec.size() << std::endl;
	//        for (vector<int>::iterator it = my_range_vec.begin(); it != my_range_vec.end(); it++)
	//        {

	//            std::cout << *it;
	//            if (it + 1 != my_range_vec.end())
	//                std::cout << " ";
	//        }
	//    }
	}
}

void test_vector_at()
{

	{
		vector< int > my_vec(10);
		std::cout << my_vec.at(0) << std::endl;
	}

	{
		vector< int > my_vec(10);
		try {
			std::cout << my_vec.at(10) << std::endl;
		} catch ( const std::exception & e ) {
			std::cout << "Range exception caught after access attempt at index" << 10 << " while the vector only has" << my_vec.size() << "\n";
			//std::cout << e.what() << std::endl;
		}
	}
	{
		vector< int > my_vec;
		try {
			std::cout << my_vec.at(0) << std::endl;
		} catch ( const std::exception & e ) {
			std::cout << "Range exception caught after access attempt in empty vector !";
			//std::cout << e.what() << std::endl;
		}
	}
	{
		vector< int > my_vec(10);
		const vector< int > my_const_vec(10);
		const int constI = my_const_vec.at(0);
		int i = my_vec.at(0);
		std::cout << constI << " " << i << std::endl;
	}
}

void test_vector_back()
{
	{
		vector< int > my_vec(1, 42);
		std::cout << my_vec.back() << std::endl;
	}
	{
		vector< int > my_vec;
		for ( int i = 0; i < 42; i++ )
			my_vec.push_back( i + 1 );
		std::cout << my_vec.back() << std::endl;
	}
	{
		vector< int > my_vec( 10, 42 );
		const vector< int > my_const_vec( 10, 42 );
		const int constI = my_const_vec.back();
		int i = my_vec.back();
		std::cout << constI << " " << i << std::endl;
	}
}

void test_vector_begin()
{
	{
		vector< int > my_vec( 10, 42 );
		std::cout << *(my_vec.begin()) << std::endl;
	}
	{
		vector< int > my_vec;
		std::cout << (my_vec.begin() == my_vec.end()) << std::endl;
	}
	{
		vector< int > my_vec(10, 42);
		const vector< int > my_const_vec(10, 42);
		vector< int >::iterator it = my_vec.begin();
		vector< int >::const_iterator constIt = my_const_vec.begin();
		//std::cout << *constIt << " " << *it << std::endl;
	}
}

//void test_vector_capacity()
//{
//}

//void test_vector_clear()
//{
//}

//void test_vector_constructors()
//{
//}

//void test_vector_empty()
//{
//}

//void test_vector_end()
//{
//}

//void test_vector_erase()
//{
//}

//void test_vector_front()
//{
//}

//void test_vector_get_allocator()
//{
//}

//void test_vector_insert()
//{
//}

//void test_vector_max_size()
//{
//}

//void test_vector_operator_bracket()
//{
//}

//void test_vector_operator_equal()
//{
//}

//void test_vector_pop_back()
//{
//}

//void test_vector_push_back()
//{
//}

//void test_vector_rbegin()
//{
//}

//void test_vector_relational_operators()
//{
//}

//void test_vector_rend()
//{
//}

//void test_vector_reserve()
//{
//}

//void test_vector_resize()
//{
//}

//void test_vector_size()
//{
//}

//void test_vector_swap()
//{
//}

//void test_vector_swap_overload()
//{
//}
