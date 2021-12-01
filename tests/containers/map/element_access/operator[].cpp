/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator[].cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:08:29 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:29:20 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	map_operator_bracket(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int, int> test;

    test.insert(NS::make_pair(2, 9));
    test.insert(NS::make_pair(10, 86));
    test.insert(NS::make_pair(14, 54));
    test.insert(NS::make_pair(1, 8));
    test.insert(NS::make_pair(8, 4));
    test.insert(NS::make_pair(9, 0));
    test.insert(NS::make_pair(2, 6));

   testFile << "Content of map<int, int> test (Keys)   : ";
   for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->first << " |";

   testFile << "\nContent of map<int, int> test (Values) : ";
   for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->second << " |";

    testFile << "\n\n";
	testFile << "test[10] : " << test[10] << '\n';
	testFile << "test[2]  : " << test[2] << '\n';
	testFile << "test[9]  : " << test[9] << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
