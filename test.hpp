/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassepipe <norminet@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:52:19 by cassepipe         #+#    #+#             */
/*   Updated: 2022/09/10 13:52:19 by cassepipe        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
#define TEST_H

#include <stdexcept>
#include <limits>

#include "map.hpp"
#include "stack.hpp"
#include "vector.hpp"

#include <map>
#include <stack>
#include <vector>

#include <memory>

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
using std::swap;

void test_vector();
void test_stack();
void test_map();

#include "prelude.hpp"

#endif /* TEST_H */
