/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_allocators.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:28:13 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 15:47:28 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	set_get_allocator(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
  	
 	NS::set<int> test;
  	int* p;
  	unsigned int i;

  	p = test.get_allocator().allocate(5);


  	for (i = 0; i < 5; i++)
		p[i] = (i + 1) * 10;

  	testFile << "The allocated array contains :";
  	for (i=0; i<5; i++)
  		testFile << ' ' << p[i];
  	testFile << '\n';

  	test.get_allocator().deallocate(p,5);

    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
