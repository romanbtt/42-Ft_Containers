/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:21:46 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/26 18:38:53 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./tests/tests.hpp"

// Dispatch Vector

void    dispatch_vector_constructors(char *argv)
{
    switch(argv[3]) {
    case '1':
        vector_default_constructor(argv);
        break;
    case '2':
        vector_fill_constructor(argv);
        break;
    case '3':
        vector_range_constructor(argv);
        break;
    case '4':
        vector_copy_constructor(argv);
        break;
    case '5':
        vector_operator_equal(argv);
        break;
    default:
        return;
    }
}

void    dispatch_vector_iterators(char *argv)
{
        switch(argv[3]) {
    case '1':
        vector_begin(argv);
        break;
    case '2':
        vector_end(argv);
        break;
    case '3':
        vector_rbegin(argv);
        break;
    case '4':
        vector_rend(argv);
        break;
    default:
        return;
    }
}

void    dispatch_vector_capacity(char *argv)
{
    switch(argv[3]) {
    case '1':
        vector_size(argv);
        break;
    case '2':
        vector_max_size(argv);
        break;
    case '3':
        vector_resize(argv);
        break;
    case '4':
        vector_capacity(argv);
        break;
    case '5':
        vector_empty(argv);
        break;
    case '6':
        vector_reserve(argv);
        break;
    default:
        return;
    }
}

void    dispatch_vector_element_access(char *argv)
{
    switch(argv[3]) {
    case '1':
        vector_operator_bracket(argv);
        break;
    case '2':
        vector_at(argv);
        break;
    case '3':
        vector_front(argv);
        break;
    case '4':
        vector_back(argv);
        break;
    default:
        return;
    }
}

void    dispatch_vector_modifiers(char *argv)
{
    switch(argv[3]) {
    case '1':
        vector_assign(argv);
        break;
    case '2':
        vector_push_back(argv);
        break;
    case '3':
        vector_pop_back(argv);
        break;
    case '4':
        vector_insert(argv);
        break;
    case '5':
        vector_erase(argv);
        break;
    case '6':
        vector_swap(argv);
        break;
    case '7':
        vector_clear(argv);
        break;
    default:
        return;
    }
}

void    dispatch_vector_allocator(char *argv)
{
    switch(argv[3]) {
    case '1':
        vector_get_allocator(argv);
        break;
    default:
        return;
    }
}

// End Dispatch Vector

// Dispatch Containers

void    dispatch_vector(char *argv)
{
    switch(argv[2]) {
    case '1':
        dispatch_vector_constructors(argv);
        break;
    case '2':
        dispatch_vector_iterators(argv);
        break;
    case '3':
        dispatch_vector_capacity(argv);
        break;
    case '4':
        dispatch_vector_element_access(argv);
        break;
    case '5':
        dispatch_vector_modifiers(argv);
        break;
    case '6':
        dispatch_vector_allocator(argv);
        break;
    default:
        return;
    }
}

void    dispatch_map(char *argv)
{
    switch(argv[1]) {
    default:
        return;
    }
}

void    dispatch_stack(char *argv)
{
    switch(argv[1]) {
    default:
        return;
    }
}

// End Dispatch Containers

// Dispatch Tests

void    dispatch_containers(char *argv)
{
    switch(argv[1]) {
    case '1':
        dispatch_vector(argv);
        break;
    case '2':
        dispatch_map(argv);
        break;
    case '3':
        dispatch_stack(argv);
        break;
    default:
        return;
    }
}

void    dispatch_iterators(char *argv)
{
    switch(argv[0])
    default:
        return;
}

void    dispatch_others(char *argv)
{
    switch(argv[0])
    default:
        return;
}

// End Dispatch Tests

void    dispatch_tests(char *argv)
{
    switch(argv[0]) {
    case '1':
        dispatch_containers(argv);
        break;
    case '2':
        dispatch_iterators(argv);
         break;
    case '3':
        dispatch_others(argv);
        break;
    default:
        return;
    }
}

int main( int argc, char *argv[] )
{
    if (argc < 2 || argc > 3)
        return (1);
    else
        dispatch_tests(argv[1]);
    return (0);
}

