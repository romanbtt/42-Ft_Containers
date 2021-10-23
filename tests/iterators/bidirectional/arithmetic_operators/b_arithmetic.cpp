/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_arithmetic.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/22 15:51:28 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	bidirectional_decrement(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::map<int, int> test;

    test.insert(NS::make_pair(1, 2));
    test.insert(NS::make_pair(3, 4));
    test.insert(NS::make_pair(5, 6));
    test.insert(NS::make_pair(7, 8));
    test.insert(NS::make_pair(9, 0));

   testFile << "Content of map<int, int> test (Keys)   : ";
   for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   testFile << "\nContent of map<int, int> test (Values) : ";
   for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->second << " |";
    testFile << "\n\n";

    NS::map<int, int>::iterator it_test = test.end();
    testFile << "NS::map<int, int>::iterator it_test = test.end()\n\n";
    testFile << "(--it_test)->second  : " << (--it_test)->second << '\n';
	testFile << "(it_test--)->second  : " << (it_test--)->second << '\n';
	testFile << "(*it_test--).second  : " << (*it_test--).second << '\n';
    testFile << "it_test->second      : " << it_test->second << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	bidirectional_increment(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int, int> test;
    test.insert(NS::make_pair(1, 2));
    test.insert(NS::make_pair(3, 4));
    test.insert(NS::make_pair(5, 6));
    test.insert(NS::make_pair(7, 8));
    test.insert(NS::make_pair(9, 0));

   testFile << "Content of map<int, int> test (Keys)   : ";
   for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   testFile << "\nContent of map<int, int> test (Values) : ";
   for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->second << " |";
    testFile << "\n\n";

    NS::map<int, int>::iterator it_test = test.begin();
    testFile << "namespace::map<int, int>::iterator it_test = test.begin()\n\n";
    testFile << "(++it_test)->second  : " << (++it_test)->second << '\n';
	testFile << "(it_test++)->second  : " << (it_test++)->second << '\n';
	testFile << "(*it_test++).second  : " << (*it_test++).second << '\n';
    testFile << "it_test->second      : " << it_test->second << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
