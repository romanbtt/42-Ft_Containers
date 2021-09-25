/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:57:06 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/25 14:29:55 by romanbtt         ###   ########.fr       */
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

#endif