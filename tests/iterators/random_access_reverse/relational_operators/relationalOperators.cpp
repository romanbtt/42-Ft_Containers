/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationalOperators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:30:34 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	random_access_reverse_relational_operators(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test1(10, 42);

	NS::vector<int>::reverse_iterator it_test1 = test1.rbegin();
    NS::vector<int>::reverse_iterator it_test2 = test1.rend();

	testFile << "namespace::vector<int> test1(10, 42)\n";
    testFile << "namespace::vector<int>::reverse_iterator it_test1 = test.rbegin()\n";
	testFile << "namespace::vector<int>::reverse_iterator it_test2 = test1.rend()\n\n";
	if (it_test1 == it_test2)
		testFile << "it_test1 and it_test2 are equal.\n";
  	if (it_test1 != it_test2)
	  	testFile << "it_test1 and it_test2 are not equal.\n";
  	if (it_test1 < it_test2)
	  	testFile << "it_test1 is less than it_test2.\n";
  	if (it_test1 > it_test2)
	  	testFile << "it_test1 is greater than it_test2.\n";
  	if (it_test1 <= it_test2)
	  	testFile << "it_test1 is less than or equal to it_test2.\n";
  	if (it_test1 >= it_test2)
	  	testFile << "it_test1 is greater than or equal to it_test2.\n";
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
