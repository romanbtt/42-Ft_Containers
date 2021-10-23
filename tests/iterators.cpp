/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:21:46 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/22 16:29:17 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

static void    dispatch_random_access_constructors(char *argv)
{
    switch(argv[3]) {
    case '1':
        random_access_default_constructors(argv);
        break;
    case '2':
        random_access_copy_constructors(argv);
        break;
    case '3':
        random_access_operator_equal(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_random_access_access_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        random_access_operator_bracket(argv);
        break;
    case '2':
        random_access_operator_star(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_random_access_arithmetic_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        random_access_increment(argv);
        break;
    case '2':
        random_access_decrement(argv);
        break;
	case '3':
        random_access_plus(argv);
        break;
    case '4':
        random_access_minus(argv);
        break;
	case '5':
        random_access_compound(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_random_access_relational_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        random_access_relational_operators(argv);
        break;
    default:
        return;
    }
}

void    dispatch_random_access(char *argv)
{
    switch(argv[2]) {
    case '1':
        dispatch_random_access_constructors(argv);
        break;
    case '2':
        dispatch_random_access_access_operators(argv);
        break;
    case '3':
        dispatch_random_access_arithmetic_operators(argv);
        break;
    case '4':
        dispatch_random_access_relational_operators(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_random_access_reverse_constructors(char *argv)
{
    switch(argv[3]) {
    case '1':
        random_access_reverse_default_constructors(argv);
        break;
    case '2':
        random_access_reverse_copy_constructors(argv);
        break;
    case '3':
        random_access_reverse_operator_equal(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_random_access_reverse_access_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        random_access_reverse_operator_bracket(argv);
        break;
    case '2':
        random_access_reverse_operator_star(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_random_access_reverse_arithmetic_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        random_access_reverse_increment(argv);
        break;
    case '2':
        random_access_reverse_decrement(argv);
        break;
	case '3':
        random_access_reverse_plus(argv);
        break;
    case '4':
        random_access_reverse_minus(argv);
        break;
	case '5':
        random_access_reverse_compound(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_random_access_reverse_relational_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        random_access_reverse_relational_operators(argv);
        break;
    default:
        return;
    }
}

void    dispatch_random_access_reverse(char *argv)
{
        switch(argv[2]) {
    case '1':
        dispatch_random_access_reverse_constructors(argv);
        break;
    case '2':
        dispatch_random_access_reverse_access_operators(argv);
        break;
    case '3':
        dispatch_random_access_reverse_arithmetic_operators(argv);
        break;
    case '4':
        dispatch_random_access_reverse_relational_operators(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_bidirectional_constructors(char *argv)
{
    switch(argv[3]) {
    case '1':
        bidirectional_default_constructors(argv);
        break;
    case '2':
        bidirectional_copy_constructors(argv);
        break;
    case '3':
        bidirectional_operator_equal(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_bidirectional_access_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        bidirectional_operator_star(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_bidirectional_arithmetic_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        bidirectional_increment(argv);
        break;
    case '2':
        bidirectional_decrement(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_bidirectional_relational_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        bidirectional_relational_operators(argv);
        break;
    default:
        return;
    }
}

void    dispatch_bidirectional(char *argv)
{
        switch(argv[2]) {
    case '1':
        dispatch_bidirectional_constructors(argv);
        break;
    case '2':
        dispatch_bidirectional_access_operators(argv);
        break;
    case '3':
        dispatch_bidirectional_arithmetic_operators(argv);
        break;
    case '4':
        dispatch_bidirectional_relational_operators(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_bidirectional_reverse_constructors(char *argv)
{
    switch(argv[3]) {
    case '1':
        bidirectional_reverse_default_constructors(argv);
        break;
    case '2':
        bidirectional_reverse_copy_constructors(argv);
        break;
    case '3':
        bidirectional_reverse_operator_equal(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_bidirectional_reverse_access_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        bidirectional_reverse_operator_star(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_bidirectional_reverse_arithmetic_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        bidirectional_reverse_increment(argv);
        break;
    case '2':
        bidirectional_reverse_decrement(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_bidirectional_reverse_relational_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        bidirectional_reverse_relational_operators(argv);
        break;
    default:
        return;
    }
}

void    dispatch_bidirectional_reverse(char *argv)
{
        switch(argv[2]) {
    case '1':
        dispatch_bidirectional_reverse_constructors(argv);
        break;
    case '2':
        dispatch_bidirectional_reverse_access_operators(argv);
        break;
    case '3':
        dispatch_bidirectional_reverse_arithmetic_operators(argv);
        break;
    case '4':
        dispatch_bidirectional_reverse_relational_operators(argv);
        break;
    default:
        return;
    }
}