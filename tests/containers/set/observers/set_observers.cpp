/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_observers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:47:50 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 15:10:14 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	set_key_comp(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

 	NS::set<int> test;
  	NS::set<int>::key_compare comp = test.key_comp();

  	test.insert(100);
  	test.insert(200);
  	test.insert(300);

  	int highest = *test.rbegin();
	NS::set<int>::iterator it = test.begin();
  
  	if (comp(*it, highest))
		testFile << *it << " is less than " << highest;
	else
		testFile << highest << " is not less than " << *it;
	testFile << '\n';
	if (comp(highest, *it))
		testFile << *it << " is less than " << highest;
	else
		testFile << highest << " is not less than " << *it;

	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	set_value_comp(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

 	NS::set<int> test;

  	test.insert(100);
  	test.insert(200);
  	test.insert(300);

  	int highest = *test.rbegin();
	NS::set<int>::iterator it = test.begin();
  
  	if (test.value_comp()(*it, highest))
		testFile << *it << " is less than " << highest;
	else
		testFile << highest << " is not less than " << *it;
	testFile << '\n';
	if (test.value_comp()(highest, *it))
		testFile << *it << " is less than " << highest;
	else
		testFile << highest << " is not less than " << *it;

	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
