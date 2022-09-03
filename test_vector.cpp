#include "test_vector.hpp"
#include "test.h"

void test_vector()
{
	test_vector_assign();
	//test_vector_at();
	//test_vector_back();
	//test_vector_begin();
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
		//vector<int> myVec;
		//std::cout << "vector< int > myVec;" << std::endl;
		//std::cout << "size : " << myVec.size() << std::endl;
		//for (vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
		//{

		//    std::cout << *it;
		//    if (it + 1 != myVec.end())
		//        std::cout << " ";
		//}
		//std::cout << std::endl;
		//myVec.assign(10, 42);
		//std::cout << "myVec.assign( 10, 42 );" << std::endl;
		//for (vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
		//{

		//    std::cout << *it;
		//    if (it + 1 != myVec.end())
		//        std::cout << " ";
		//}
		//std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		//vector<int> myVec(10, 0);
		//std::cout << "vector< int > myVec(10, 0);" << std::endl;
		//std::cout << "size : " << myVec.size() << std::endl;
		//for (vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
		//{

		//    std::cout << *it;
		//    if (it + 1 != myVec.end())
		//        std::cout << " ";
		//}
		//std::cout << std::endl;
		//myVec.assign(10, 42);
		//std::cout << "myVec.assign( 10, 42 );" << std::endl;
		//for (vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
		//{

		//    std::cout << *it;
		//    if (it + 1 != myVec.end())
		//        std::cout << " ";
		//}
		//std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		//vector<int> myVec(10, 42);
		//std::cout << "vector< int > myVec(10, 42);" << std::endl;
		//std::cout << "size : " << myVec.size() << std::endl;
		//for (vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
		//{
		//    std::cout << *it;
		//    if (it + 1 != myVec.end())
		//        std::cout << " ";
		//}
		//std::cout << std::endl;
		//myVec.assign(0, 3);
		//std::cout << "myVec.assign( 0, 3 );" << std::endl;
		//std::cout << "size : " << myVec.size() << std::endl;
		//for (vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
		//{

		//    std::cout << *it;
		//    if (it + 1 != myVec.end())
		//        std::cout << " ";
		//}
		//std::cout << std::endl;
	}

	{
		vector<int> myVec;
		for (vector<int>::size_type i = 0; i < 42; ++i)
			myVec.push_back(i + 1);
		std::cout << "myVec" << std::endl;
		std::cout << "size : " << myVec.size() << std::endl;
		for (vector<int>::iterator it = myVec.begin(); it != myVec.end(); it++)
		{

			std::cout << *it;
			if (it + 1 != myVec.end())
				std::cout << " ";
		}

		std::cout << std::endl;

		//{
		//    vector<int> myRangeVec;
		//    myRangeVec.assign(myVec.begin(), myVec.end());
		//    std::cout << "vector< int > myRangeVec;" << std::endl;
		//    std::cout << "myRangeVec.assign( myVec.begin(), myVec.end() );" << std::endl;
		//    std::cout << "myRangeVec" << std::endl;
		//    std::cout << "size : " << myRangeVec.size() << std::endl;
		//    for (vector<int>::iterator it = myRangeVec.begin(); it != myRangeVec.end(); it++)
		//    {

		//        std::cout << *it;
		//        if (it + 1 != myRangeVec.end())
		//            std::cout << " ";
		//    }
		//}

		std::cout << std::endl;

		//{
		//    vector<int> myRangeVec;
		//    myRangeVec.assign(myVec.begin(), myVec.begin() + 5);
		//    std::cout << "vector< int > myRangeVec;" << std::endl;
		//    std::cout << "myRangeVec.assign( myVec.begin(), myVec.begin() + 5 );" << std::endl;
		//    std::cout << "myRangeVec" << std::endl;
		//    std::cout << "size : " << myRangeVec.size() << std::endl;
		//    for (vector<int>::iterator it = myRangeVec.begin(); it != myRangeVec.end(); it++)
		//    {

		//        std::cout << *it;
		//        if (it + 1 != myRangeVec.end())
		//            std::cout << " ";
		//    }
		//}

		std::cout << std::endl;

		//{
		//    vector<int> myRangeVec;
		//    myRangeVec.assign(myVec.begin(), myVec.begin());
		//    std::cout << "vector< int > myRangeVec;" << std::endl;
		//    std::cout << "myRangeVec.assign( myVec.begin(), myVec.begin() );" << std::endl;
		//    std::cout << "myRangeVec" << std::endl;
		//    std::cout << "size : " << myRangeVec.size() << std::endl;
		//    for (vector<int>::iterator it = myRangeVec.begin(); it != myRangeVec.end(); it++)
		//    {

		//        std::cout << *it;
		//        if (it + 1 != myRangeVec.end())
		//            std::cout << " ";
		//    }
		//}
	}
}

//void test_vector_at()
//{
//}

//void test_vector_back()
//{
//}

//void test_vector_begin()
//{
//}

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
