/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/28 19:45:05 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	random_access_plus(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::vector<int> test(10, 1);

    testFile << "Content of vector<int> : ";
	for (size_t i = 0; i < test.size(); i++)
	{
        test[i] *= i;
        testFile << "| " << test[i] << " |";
    }
    testFile << "\n\n";

    NS::vector<int>::iterator it_test1 = test.begin();
    testFile << "namespace::vector<int>::iterator it_test1 = test.begin()\n";
	    NS::vector<int>::iterator it_test2 = test.begin() + 5;
    testFile << "namespace::vector<int>::iterator it_test2 = test.begin() + 5\n\n";
	it_test1 = it_test1 + 2;
    testFile << "it_test1 = it_test1 + 2 : " << *it_test1 << '\n';
	it_test1 = 3 + it_test2;
	testFile << "it_test1 = 3 + it_test2 : " << *it_test1 << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}