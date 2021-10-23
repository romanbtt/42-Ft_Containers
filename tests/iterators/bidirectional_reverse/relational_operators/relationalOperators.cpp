/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationalOperators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/22 16:30:49 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	bidirectional_reverse_relational_operators(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int, int> test;

	test.insert(NS::make_pair(1, 2));
    test.insert(NS::make_pair(3, 4));
    test.insert(NS::make_pair(5, 6));
    test.insert(NS::make_pair(7, 8));
    test.insert(NS::make_pair(9, 0));

	NS::map<int, int>::reverse_iterator it_test1 = test.rbegin();
    NS::map<int, int>::reverse_iterator it_test2 = test.rend();

	testFile << "namespace::map<int> test1\n";
    testFile << "namespace::map<int>::reverse_iterator it_test1 = test.rbegin()\n";
	testFile << "namespace::map<int>::reverse_iterator it_test2 = test1.rend()\n\n";
	if (it_test1 == it_test2)
		testFile << "it_test1 and it_test2 are equal.\n";
  	if (it_test1 != it_test2)
	  	testFile << "it_test1 and it_test2 are not equal.\n";
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}