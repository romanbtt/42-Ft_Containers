/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:51:15 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 17:20:08 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

// Dispatch set

static void    dispatch_set_constructors(char *argv)
{
    switch(argv[3]) {
    case '1':
        set_default_constructor(argv);
        break;
    case '2':
        set_range_constructor(argv);
        break;
    case '3':
        set_copy_constructor(argv);
        break;
    case '4':
        set_operator_equal(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_set_iterators(char *argv)
{
        switch(argv[3]) {
    case '1':
        set_begin(argv);
        break;
    case '2':
        set_end(argv);
        break;
    case '3':
        set_rbegin(argv);
        break;
    case '4':
        set_rend(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_set_capacity(char *argv)
{
    switch(argv[3]) {
    case '1':
        set_empty(argv);
        break;
    case '2':
        set_size(argv);
        break;
    case '3':
        set_max_size(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_set_modifiers(char *argv)
{
    switch(argv[3]) {
    case '1':
        set_insert(argv);
        break;
    case '2':
        set_erase(argv);
        break;
    case '3':
        set_swap(argv);
        break;
    case '4':
        set_clear(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_set_observers(char *argv)
{
    switch(argv[3]) {
    case '1':
        set_key_comp(argv);
        break;
    case '2':
        set_value_comp(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_set_operations(char *argv)
{
    switch(argv[3]) {
    case '1':
        set_find(argv);
        break;
    case '2':
        set_count(argv);
        break;
    case '3':
        set_lower_bound(argv);
        break;
    case '4':
        set_upper_bound(argv);
        break;
    case '5':
        set_equal_range(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_set_allocator(char *argv)
{
    switch(argv[3]) {
    case '1':
        set_get_allocator(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_set_relational_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        set_relational_operators(argv);
        break;
    default:
        return;
    }
}

// Dispatch Map

static void    dispatch_map_constructors(char *argv)
{
    switch(argv[3]) {
    case '1':
        map_default_constructor(argv);
        break;
    case '2':
        map_range_constructor(argv);
        break;
    case '3':
        map_copy_constructor(argv);
        break;
    case '4':
        map_operator_equal(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_map_iterators(char *argv)
{
        switch(argv[3]) {
    case '1':
        map_begin(argv);
        break;
    case '2':
        map_end(argv);
        break;
    case '3':
        map_rbegin(argv);
        break;
    case '4':
        map_rend(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_map_capacity(char *argv)
{
    switch(argv[3]) {
    case '1':
        map_empty(argv);
        break;
    case '2':
        map_size(argv);
        break;
    case '3':
        map_max_size(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_map_element_access(char *argv)
{
    switch(argv[3]) {
    case '1':
       map_operator_bracket(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_map_modifiers(char *argv)
{
    switch(argv[3]) {
    case '1':
        map_insert(argv);
        break;
    case '2':
        map_erase(argv);
        break;
    case '3':
        map_swap(argv);
        break;
    case '4':
        map_clear(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_map_observers(char *argv)
{
    switch(argv[3]) {
    case '1':
        map_key_comp(argv);
        break;
    case '2':
        map_value_comp(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_map_operations(char *argv)
{
    switch(argv[3]) {
    case '1':
        map_find(argv);
        break;
    case '2':
        map_count(argv);
        break;
    case '3':
        map_lower_bound(argv);
        break;
    case '4':
        map_upper_bound(argv);
        break;
    case '5':
        map_equal_range(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_map_allocator(char *argv)
{
    switch(argv[3]) {
    case '1':
        map_get_allocator(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_map_relational_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        map_relational_operators(argv);
        break;
    default:
        return;
    }
}

// Dispatch Vector

static void    dispatch_vector_constructors(char *argv)
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

static void    dispatch_vector_iterators(char *argv)
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

static void    dispatch_vector_capacity(char *argv)
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

static void    dispatch_vector_element_access(char *argv)
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

static void    dispatch_vector_modifiers(char *argv)
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

static void    dispatch_vector_allocator(char *argv)
{
    switch(argv[3]) {
    case '1':
        vector_get_allocator(argv);
        break;
    default:
        return;
    }
}

static void    dispatch_vector_relational_operators(char *argv)
{
    switch(argv[3]) {
    case '1':
        vector_relational_operators(argv);
        break;
    default:
        return;
    }
}

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
    case '7':
        dispatch_vector_relational_operators(argv);
        break;
    default:
        return;
    }
}

void    dispatch_map(char *argv)
{
    switch(argv[2]) {
    case '1':
        dispatch_map_constructors(argv);
        break;
    case '2':
        dispatch_map_iterators(argv);
        break;
    case '3':
        dispatch_map_capacity(argv);
        break;
    case '4':
        dispatch_map_element_access(argv);
        break;
    case '5':
        dispatch_map_modifiers(argv);
        break;
    case '6':
        dispatch_map_observers(argv);
        break;
    case '7':
        dispatch_map_operations(argv);
        break;
    case '8':
        dispatch_map_allocator(argv);
        break;
    case '9':
        dispatch_map_relational_operators(argv);
        break;
    default:
        return;
    }
}

void    dispatch_stack(char *argv)
{
    switch(argv[2]) {
    case '1':
        stack_constructor(argv);
        break;
    case '2':
        stack_empty(argv);
        break;
    case '3':
        stack_size(argv);
        break;
    case '4':
        stack_top(argv);
        break;
    case '5':
        stack_push(argv);
        break;
    case '6':
        stack_pop(argv);
        break;
    case '7':
        stack_relational_operators(argv);
        break;
    }
}

void    dispatch_set(char *argv)
{
    switch(argv[2]) {
    case '1':
        dispatch_set_constructors(argv);
        break;
    case '2':
        dispatch_set_iterators(argv);
        break;
    case '3':
        dispatch_set_capacity(argv);
        break;
    case '4':
        dispatch_set_modifiers(argv);
        break;
    case '5':
        dispatch_set_observers(argv);
        break;
    case '6':
        dispatch_set_operations(argv);
        break;
    case '7':
        dispatch_set_allocator(argv);
        break;
    case '8':
        dispatch_set_relational_operators(argv);
        break;
    default:
        return;
    }
}
