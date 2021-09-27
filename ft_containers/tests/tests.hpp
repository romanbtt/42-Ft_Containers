/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:57:06 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/26 18:38:48 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
#define TESTS_H

#include <fstream>
#include <iostream>
#include "../containers/vector.hpp"

void    vector_default_constructor(char *argvs);
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

#endif