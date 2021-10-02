/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 12:15:18 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/27 17:05:04 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

static void try_catch(std::ofstream & testFile, NS::vector<int> test, int index)
{
    try
	{
		testFile << "test[" << index << "] : " << test.at(index) << '\n';
	}
	catch(const std::exception& e)
	{
		testFile << "Out of bounds.\n";
	}
}

void	vector_at(char *argv)
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
    testFile << '\n';
    try_catch(testFile, test, 0);
    try_catch(testFile, test, 5);
    try_catch(testFile, test, 9);
    try_catch(testFile, test, 10);
    try_catch(testFile, test, -1);
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}