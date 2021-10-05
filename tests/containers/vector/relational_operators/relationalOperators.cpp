/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationalOperators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/28 16:23:48 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_relational_operators(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test1(10, 42);
    NS::vector<int> test2(5, 84);

	testFile << "namespace::vector<int> test1(10, 42)\n";
    testFile << "Content of vector<int>'s test1 : ";
    for (NS::vector<int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << *it << " |";
	testFile << "\n\nnamespace::vector<int> test2(5, 84)\n";
	for (NS::vector<int>::iterator it = test2.begin(); it != test2.end(); it++)
       testFile << "| " << *it << " |";
	testFile << "\n\n";
	if (test1 == test2)
		testFile << "test1 and test2 are equal.\n";
  	if (test1 != test2)
	  	testFile << "test1 and test2 are not equal.\n";
  	if (test1 < test2)
	  	testFile << "test1 is less than test2.\n";
  	if (test1 > test2)
	  	testFile << "test1 is greater than test2.\n";
  	if (test1 <= test2)
	  	testFile << "test1 is less than or equal to test2.\n";
  	if (test1 >= test2)
	  	testFile << "test1 is greater than or equal to test2.\n";
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}