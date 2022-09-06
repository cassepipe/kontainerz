#ifndef TEST_H
#define TEST_H

#include "map.hpp"
#include "vector.hpp"

#include <map>
#include <stack>
#include <vector>

#ifndef NAMESPACE
#define NAMESPACE ft
#endif

using NAMESPACE::make_pair;
using NAMESPACE::pair;
using NAMESPACE::vector;
//using NAMESPACE::stack;
using NAMESPACE::map;

using std::cout;
using std::string;

void test_vector();
void test_stack();
void test_map();

#endif /* TEST_H */
