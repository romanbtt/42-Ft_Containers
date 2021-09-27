/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:22:34 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/26 18:25:30 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_clear(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("std", std::ios::out | std::ios::trunc);
	std::vector<int> test(10, 1);

	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
	{
		test[i] *= i;
		testFile << "| " << test[i] << " |";
	}
	testFile << "\nSize of vector<int> test before clear : " << test.size() << '\n';
	testFile << "Capacity of vector<int> test before clear : " << test.capacity() << '\n';
	testFile << "\ntest.clear(test2)\n";
	test.clear();
	testFile << "Size of vector<int> test after clear : " << test.size() << '\n';
	testFile << "Capacity of vector<int> test after clear : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file("std");
        std::cout << file.rdbuf();
        file.close();
    }
}