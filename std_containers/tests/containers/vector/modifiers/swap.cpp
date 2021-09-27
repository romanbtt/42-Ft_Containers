/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:11:24 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/26 18:18:28 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_swap(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("std", std::ios::out | std::ios::trunc);
	std::vector<int> test1(10, 1);
	std::vector<int> test2(5, 3);

	testFile << "Content of vector<int> test1 : ";
	for (size_t i = 0; i < test1.size(); i++)
	{
		test1[i] *= i;
		testFile << "| " << test1[i] << " |";
	}
	testFile << "\nSize of vector<int> test1 before swap : " << test1.size() << '\n';
	testFile << "Capacity of vector<int> test1 before swap : " << test1.capacity() << '\n';
	testFile << "\nContent of vector<int> test2 : ";
	for (size_t i = 0; i < test2.size(); i++)
	{
		test2[i] *= i;
		testFile << "| " << test2[i] << " |";
	}
	testFile << "\nSize of vector<int> test2 before swap : " << test2.size() << '\n';
	testFile << "Capacity of vector<int> test2 before swap : " << test2.capacity() << '\n';
	testFile << "\ntest1.swap(test2)\n";
	test1.swap(test2);
	testFile << "Size of vector<int> test1 after swap : " << test1.size() << '\n';
	testFile << "Capacity of vector<int> test1 after swap : " << test1.capacity() << '\n';
	testFile << "Content of vector<int> test1 : ";
	for (size_t i = 0; i < test1.size(); i++)
		testFile << "| " << test1[i] << " |";
	testFile << "\n\nSize of vector<int> test2 after swap : " << test2.size() << '\n';
	testFile << "Capacity of vector<int> test2 after swap : " << test2.capacity() << '\n';
	testFile << "Content of vector<int> test1 : ";
	for (size_t i = 0; i < test2.size(); i++)
		testFile << "| " << test2[i] << " |";
	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file("std");
        std::cout << file.rdbuf();
        file.close();
    }
}