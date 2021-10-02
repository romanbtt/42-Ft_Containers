/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:57:06 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/29 13:29:12 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <fstream>
# include <iostream>
# include <vector>
# include "../ft_containers/containers/vector.hpp"

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


void    dispatch_map(char *argv);

void    dispatch_stack(char *argv);




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

#endif