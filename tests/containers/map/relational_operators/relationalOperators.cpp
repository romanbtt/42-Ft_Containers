/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relationalOperators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:29:43 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	map_relational_operators(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int,int> test1;
    NS::map<int,int> test2;

	test1.insert(NS::make_pair(2, 9));
	test1.insert(NS::make_pair(4, 2));
	test1.insert(NS::make_pair(1, 3));
	test2.insert(NS::make_pair(2, 9));
	test2.insert(NS::make_pair(9, 2));
	test2.insert(NS::make_pair(8, 4));

   	testFile << "Content of map<int, int> test1 (Keys)   : ";
   	for (NS::map<int, int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << it->first << " |";

   	testFile << "\nContent of map<int, int> test1 (Values) : ";
   	for (NS::map<int, int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << it->second << " |";

	testFile << "\n\n";

	testFile << "Content of map<int, int> test2 (Keys)   : ";
   	for (NS::map<int, int>::iterator it = test2.begin(); it != test2.end(); it++)
       testFile << "| " << it->first << " |";

   	testFile << "\nContent of map<int, int> test2 (Values) : ";
   	for (NS::map<int, int>::iterator it = test2.begin(); it != test2.end(); it++)
       testFile << "| " << it->second << " |";

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
