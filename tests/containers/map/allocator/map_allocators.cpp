/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getAllocator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:28:13 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/19 19:03:50 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	map_get_allocator(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
  	
	int psize;
  	NS::map<int,int> test;
  	NS::pair<const int,int>* pair;

  	pair = test.get_allocator().allocate(5);

  	psize = sizeof(NS::map<int,int>::value_type) * 5;

  	testFile << "The allocated array has a size of " << psize << " bytes.\n";

  	test.get_allocator().deallocate(pair,5);
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}