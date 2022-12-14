#ifndef VECTOR_PRELUDE_HPP
#define VECTOR_PRELUDE_HPP

#include "vector.hpp"
#include <vector>

#include "prelude.hpp"

#define PRINT_VEC(vec)                       \
	{                                        \
		std::cout << "\nVector content:\n";  \
		print_range(vec.begin(), vec.end()); \
		std::cout << std::endl;              \
	}

#define PRINT_ALL(vec)   \
	{                    \
		PRINT_SIZE(vec); \
		PRINT_VEC(vec);  \
	}

#define CHECK_CAPACITY(vec)                             \
	{                                                   \
		if (!(vec.capacity() >= vec.size()))            \
		{                                               \
			PRINT_MSG("Capacity is smaller than size"); \
		}                                               \
		else                                            \
		{                                               \
			PRINT_MSG("Capacity Ok");                   \
		}                                               \
	}

#define CHECK_AND_PRINT_ALL(vec) \
	{                            \
		CHECK_CAPACITY(vec);     \
		PRINT_ALL(vec);          \
	}

template < class T, class Alloc >
void cmp(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############" << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs < rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs > rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

template < typename T >
void init_array(T* arr, std::size_t size)
{
	iota(arr, arr + size, (T)rand());
}

#define SETUP_ARRAY(type, name, size) \
	type name[size];                  \
	init_array(name, size);

#define SETUP_ARRAYS()                                                                                   \
	SETUP_ARRAY(long, s_long, 32);                                                                       \
	SETUP_ARRAY(long, b_long, 64);                                                                       \
	SETUP_ARRAY(int, s_int, 32);                                                                         \
	SETUP_ARRAY(int, b_int, 64);                                                                         \
	SETUP_ARRAY(double, s_double, 32);                                                                   \
	SETUP_ARRAY(double, b_double, 64);                                                                   \
	char s_char[32];                                                                                     \
	iota(s_char, s_char + 32, '@');                                                                      \
	char b_char[64];                                                                                     \
	iota(b_char, b_char + 64, '$');                                                                      \
	std::size_t s_size = 32;                                                                             \
	std::size_t b_size = 64;                                                                             \
	(void)s_size;                                                                                        \
	(void)b_size;                                                                                        \
	std::string s_string[32] = {                                                                         \
	    "QExoqp0nICr0sXsHqty2", "naax9QcpJhvaL7DezsNQ", "25ZTtB6wbptfbxM8AvHB", "tShYNtc0MkdjqLrOatgz",  \
	    "7Z3kf1Qec0NnsLSEpbOt", "WhkSNrKJC966fvjZ2Or1", "8vlxlFRRgW7yYj4GO7dt", "5sq1aoT8zP0HaHj3nFOK",  \
	    "61Dv31GYZhkgjKCErpng", "l0IIcWWHhOcPzoxEamQM", "bE1RYclskwXlhCm46YFs", "kXeoi5qz94JYPqSDTs79",  \
	    "TFsQP1dz8VVos9KzUpY0", "b3wYQR7An193gjgYuRj3", "xSmyNsnSJ47jLqrvbpyr", "guAIP2Wq43Gf8VhHsyu5",  \
	    "yT6c2loPebHovnq9BQog", "3qvU1xcVm2g1DKFDlqh4", "L0q8RR9P41VD4sVjdnWl", "YdjESsIZM4b1oGQPjpBe",  \
	    "l1ZVQbWKw7brHUSimJgq", "xdn0cf4vqRzpfXWtl10G", "lYnZvpqaV0s8DowMZwzV", "8P1cyKrwJNLoJyvLjYqO",  \
	    "4MhOXNbAX23CEijO5cRT", "tHe3miAwCOVQbuoLaEP2", "l6uNLsc8fiLl3eWoG6j6", "477xt6l0lph9ALQdr4HX",  \
	    "D9UJNe4s8YF02LhrwOdl", "dLCisBNOdE8yugntu6cj", "YvY4aQFHgAuagn4dFLO1", "eGR6Dtv7LW75qlV5Fkik"}; \
	std::string b_string[64] = {                                                                         \
	    "uvg6KqtcgduR31n3ajsv", "wbiAcjgojb9JOagZwyMn", "ATZKCzaPOqgkhPjwuGlf", "MOhaJs56yjOw8f6nLPRA",  \
	    "0gyB2Tr42v6awMw2nK7J", "e6GsiLFUuoDpVFEhJKZ1", "z0jXAhiV9keBsaLOY0Xf", "P68p2ZAosHJdmoZh1C7N",  \
	    "Pu3EuZVeY0TCO3ojdK0t", "z7jCHMooHCS73M8GygKB", "uT4KoK83JrZxZjkul7ty", "g8gfrZoY5XwfzRusvHvv",  \
	    "7PGmkM0OSRnYREt9mFIP", "q1od7mBIpPEsCtpF9kdw", "XQo0LWId5TdZnLnpUNOb", "U0m1R0kFFhAFyS6hmHHw",  \
	    "K0lPKfxJxIOnE8QB90xn", "cZ5xyQifMJhrKxqBK9A7", "cFBiwjfYw7Js6qEGy5Kt", "1tW0KWfXxeFO69tByqcE",  \
	    "3Fvq9NxBrhPXHe0IlIVx", "MSRDjdFRvHAhFGhiMtDe", "zGm2joMh71jQkYzg5L4V", "Mq4RRaeLvSAO0z2ibp8Q",  \
	    "WnLFYnQKP8TNJkqVVbUg", "E98UphbbVSzrW5Mzurmg", "F8HRxeEcaTZDkFPkioij", "jmUVl4Q8X5BwVNzXN219",  \
	    "n7Xp4w4FwzGKit7AI4SO", "4MxXYr6rKOcXLt9UkVd2", "4RVTDsADtRyboaai9d29", "XaSqsrrtdhAfFoJIc5KK",  \
	    "9Z9jdVCrTT09bg348ceb", "I6uqLG9dO5mfNdSMwOYm", "UwMTzJPlbnhgwbHpDi6w", "DebjMP9afncYE6GhhO00",  \
	    "YGPuscYDiGfAjY1UWST0", "K6gbvgGjVZgEFUDlkdSk", "8xCBPI0w6TpC0RA62c2W", "fYMxkNwmKg3moP8KvD9v",  \
	    "QpPdhwhEYjIugg3OPcPH", "qQBXjSn43I3EMP54SyxZ", "7qvdKwoW1CQEZTWPvuSC", "rCT212rdYO0zTGHXesKg",  \
	    "dBHvlHsBwcR9MkkenYYG", "NQiSlergqR8fVbOeivLj", "xYVqsV147UIe7jVBVwXo", "tcxayO4DdEJ885TbqUMy",  \
	    "9TGSMTD8U8ksRpHqq0cL", "TIJ16jCv9BSUiWvhbF9T", "BM9GL2ig1hePkA6lM6Ck", "TfJTYB9JQMU6CGcYg20Q",  \
	    "Fg6e5YT2FQbpTZNTDqdo", "LI5q6ml40MeE9H1dPb93", "OaxJUSm3nYN9Y8Ela7sS", "BgBeODAwXz7xJo50Rwqd",  \
	    "xdkgKj1dEoJ6zuVhkvvo", "olIewtUEvXJgs1lB9bCn", "dTsPDS0x2uXtcgOIJHb8", "DYvJ2phLppGNZKboTBrd",  \
	    "DjNFMtt9PxkzqvWBHI6j", "1Z3YkeTFlPniKnzFhzgu", "76XqQg6hqMf5IXxKPOEs", "gzaapTWW7i9EZjjzLeK6"}; \
	(void)s_string;                                                                                      \
	(void)b_string;

typedef NAMESPACE::vector< std::string, std::allocator< std::string > > strvector;
typedef NAMESPACE::vector< int, std::allocator< int > >                 intvector;
typedef NAMESPACE::vector< long, std::allocator< long > >               longvector;
typedef NAMESPACE::vector< double, std::allocator< double > >           doublevector;
typedef NAMESPACE::vector< char, std::allocator< char > >               charvector;

template < typename T >
T times2(const T& x)
{
	return x * 2;
}

template < typename T >
void print(const T& x)
{
	std::cout << x << '\n';
}

template < typename T >
void printSize(vector< T > const& vct, bool print_content = true)
{
	const typename vector< T >::size_type size         = vct.size();
	const typename vector< T >::size_type capacity     = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename vector< T >::const_iterator it  = vct.begin();
		typename vector< T >::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

#endif /* VECTOR_PRELUDE_HPP */
