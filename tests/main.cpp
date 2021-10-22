/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:21:46 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/22 11:49:02 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <typeinfo>

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
    switch(argv[1]) {
    case '1':
        dispatch_random_access(argv);
        break;
    case '2':
        dispatch_random_access_reverse(argv);
        break;
    //case '3':
    //    dispatch_bidirectional(argv);
    //    break;
    //case '4':
    //    dispatch_bidirectional_reverse(argv);
    //    break;
    default:
        return;
    }
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
    test_subject(argc, argv);
    if (argc < 2 || argc > 3)
        return (1);
    else
        dispatch_tests(argv[1]);
    return (0);
}

