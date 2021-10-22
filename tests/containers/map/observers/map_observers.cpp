/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_observers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:47:50 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 14:39:49 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	map_key_comp(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

 	NS::map<int,int> test;
  	NS::map<int,int>::key_compare comp = test.key_comp();

  	test[1] = 100;
  	test[2] = 200;
  	test[3] = 300;

  	int highest = test.rbegin()->first;
	NS::map<int,int>::iterator it = test.begin();
  
  	if (comp((*it).first, highest))
		testFile << it->first << " is less than " << highest;
	else
		testFile << highest << " is not less than " << it->first;
	testFile << '\n';
	if (comp(highest, (*it).first))
		testFile << it->first << " is less than " << highest;
	else
		testFile << highest << " is not less than " << it->first;

	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	map_value_comp(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

 	NS::map<int,int> test;

  	test[1] = 100;
  	test[2] = 200;
  	test[3] = 300;

  	NS::pair<int, int> highest = *test.rbegin();
	NS::map<int,int>::iterator it = test.begin();
  
  	if (test.value_comp()(*it, highest))
		testFile << it->first << " is less than " << highest.first;
	else
		testFile << highest.first << " is not less than " << it->first;
	testFile << '\n';
	if (test.value_comp()(highest, *it))
		testFile << it->first << " is less than " << highest.first;
	else
		testFile << highest.first << " is not less than " << it->first;

	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}