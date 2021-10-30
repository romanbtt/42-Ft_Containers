/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationalOperators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 15:51:46 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	set_relational_operators(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::set<int> test1;
    NS::set<int> test2;

	test1.insert(2);
	test1.insert(4);
	test1.insert(1);
	test2.insert(2);
	test2.insert(9);
	test2.insert(8);

   	testFile << "\nContent of set<int> test1 : ";
   	for (NS::set<int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << *it << " |";

	testFile << "\n\n";

   	testFile << "\nContent of set<int> test2 : ";
   	for (NS::set<int>::iterator it = test2.begin(); it != test2.end(); it++)
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
