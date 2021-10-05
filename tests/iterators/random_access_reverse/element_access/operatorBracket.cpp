/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatorBracket.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 21:08:29 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/29 13:31:56 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	random_access_reverse_operator_bracket(char *argv)
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

    NS::vector<int>::reverse_iterator it_test = test.rbegin();
    testFile << "namespace::vector<int>::reverse_iterator it_test = test.rbegin()\n\n";
    testFile << "it_test[0] : " << it_test[0] << '\n';
	testFile << "it_test[5] : " << it_test[5] << '\n';
	testFile << "it_test[9] : " << it_test[9] << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}