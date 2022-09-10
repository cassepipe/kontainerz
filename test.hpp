#ifndef TEST_H
#define TEST_H

#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"

#include <map>
#include <stack>
#include <vector>

#ifndef NAMESPACE
#define NAMESPACE ft
#endif

using NAMESPACE::make_pair;
using NAMESPACE::map;
using NAMESPACE::pair;
using NAMESPACE::stack;
using NAMESPACE::vector;

using std::cout;
using std::endl;
using std::string;

void test_vector();
void test_stack();
void test_map();

#endif /* TEST_H */
