/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:57:06 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/23 21:17:05 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <fstream>
# include <iostream>

# include <vector>
# include "../ft_containers/containers/vector.hpp"

# include <map>
# include "../ft_containers/containers/map.hpp"

# include <stack>
# include "../ft_containers/containers/stack.hpp"

# if ISFT
#  undef NS
#  undef DIFF1
#  define NS ft
#  define DIFF "ft"
#  undef ISFT
# endif

# if ISSTD
#  undef NS
#  undef DIFF
#  define NS std
#  define DIFF "std"
#  undef ISSTD
# endif


/*
** Tests Vector
*/

void    dispatch_vector(char *argv);

void    vector_default_constructor(char *argv);
void    vector_fill_constructor(char *argv);
void	vector_range_constructor(char *argv);
void	vector_copy_constructor(char *argv);
void	vector_operator_equal(char *argv);

void	vector_begin(char *argv);
void	vector_end(char *argv);
void	vector_rbegin(char *argv);
void	vector_rend(char *argv);

void	vector_size(char *argv);
void	vector_max_size(char *argv);
void	vector_resize(char *argv);
void	vector_capacity(char *argv);
void	vector_empty(char *argv);
void	vector_reserve(char *argv);

void	vector_operator_bracket(char *argv);
void	vector_at(char *argv);
void	vector_front(char *argv);
void	vector_back(char *argv);

void	vector_assign(char *argv);
void	vector_push_back(char *argv);
void	vector_pop_back(char *argv);
void	vector_insert(char *argv);
void	vector_erase(char *argv);
void	vector_swap(char *argv);
void	vector_clear(char *argv);

void	vector_get_allocator(char *argv);

void	vector_relational_operators(char *argv);

/*
** Tests Map
*/

void    dispatch_map(char *argv);

void    map_default_constructor(char *argv);
void	map_range_constructor(char *argv);
void	map_copy_constructor(char *argv);
void	map_operator_equal(char *argv);

void	map_begin(char *argv);
void	map_end(char *argv);
void	map_rbegin(char *argv);
void	map_rend(char *argv);

void	map_empty(char *argv);
void	map_size(char *argv);
void	map_max_size(char *argv);

void	map_operator_bracket(char *argv);

void	map_insert(char *argv);
void	map_erase(char *argv);
void	map_swap(char *argv);
void	map_clear(char *argv);

void	map_key_comp(char *argv);
void	map_value_comp(char *argv);

void	map_find(char *argv);
void	map_count(char *argv);
void	map_lower_bound(char *argv);
void	map_upper_bound(char *argv);
void	map_equal_range(char *argv);

void	map_get_allocator(char *argv);

void	map_relational_operators(char *argv);

/*
** Tests Stack
*/

void    dispatch_stack(char *argv);

void	stack_constructor(char *argv);
void	stack_empty(char *argv);
void	stack_size(char *argv);
void	stack_top(char *argv);
void	stack_push(char *argv);
void	stack_pop(char *argv);
void	stack_relational_operators(char *argv);

/*
** Tests Iterator Random access
*/

void    dispatch_random_access(char *argv);

void    random_access_default_constructors(char *argv);
void    random_access_copy_constructors(char *argv);
void    random_access_operator_equal(char *argv);

void    random_access_operator_bracket(char *argv);
void    random_access_operator_star(char *argv);

void    random_access_increment(char *argv);
void    random_access_decrement(char *argv);
void    random_access_plus(char *argv);
void    random_access_minus(char *argv);
void    random_access_compound(char *argv);

void    random_access_relational_operators(char *argv);

/*
** Tests Iterator Random access reverse
*/

void    dispatch_random_access_reverse(char *argv);

void    random_access_reverse_default_constructors(char *argv);
void    random_access_reverse_copy_constructors(char *argv);
void    random_access_reverse_operator_equal(char *argv);

void    random_access_reverse_operator_bracket(char *argv);
void    random_access_reverse_operator_star(char *argv);

void    random_access_reverse_increment(char *argv);
void    random_access_reverse_decrement(char *argv);
void    random_access_reverse_plus(char *argv);
void    random_access_reverse_minus(char *argv);
void    random_access_reverse_compound(char *argv);

void    random_access_reverse_relational_operators(char *argv);

/*
** Tests Iterator Bidirectional
*/

void    dispatch_bidirectional(char *argv);

void    bidirectional_default_constructors(char *argv);
void	bidirectional_copy_constructors(char *argv);
void	bidirectional_operator_equal(char *argv);

void	bidirectional_relational_operators(char *argv);

void	bidirectional_decrement(char *argv);
void	bidirectional_increment(char *argv);

void	bidirectional_operator_star(char *argv);

/*
** Tests Iterator Bidirectional reverse
*/

void    dispatch_bidirectional_reverse(char *argv);

void    bidirectional_reverse_default_constructors(char *argv);
void	bidirectional_reverse_copy_constructors(char *argv);
void	bidirectional_reverse_operator_equal(char *argv);

void	bidirectional_reverse_relational_operators(char *argv);

void	bidirectional_reverse_decrement(char *argv);
void	bidirectional_reverse_increment(char *argv);

void	bidirectional_reverse_operator_star(char *argv);

/*
** Tests Subject
*/

void 	test_subject(char *argv);

#endif
