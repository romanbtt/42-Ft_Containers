/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:54:37 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/26 18:25:26 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_erase(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("std", std::ios::out | std::ios::trunc);
	std::vector<int> test(10, 1);
	std::vector<int>::iterator ret;

	for (size_t i = 0; i < test.size(); i++)
		test[i] += i;
	testFile << "namespace::vector<int> test\n";
    testFile << "Size of vector<int> before erase : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before erase : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << "\n\ntest.erase(test.begin() + 5)\n";
	ret = test.erase(test.begin() + 5);
	testFile << "Size of vector<int> after erase : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after erase : " << test.capacity() << '\n';
	testFile << "Return value : " << *ret << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << "\n\ntest.erase(test.begin() + 2, test.end() - 2)\n";
	ret = test.erase(test.begin() + 2, test.end() - 2);
	testFile << "Size of vector<int> after erase : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after erase : " << test.capacity() << '\n';
	testFile << "Return value : " << *ret << '\n';
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