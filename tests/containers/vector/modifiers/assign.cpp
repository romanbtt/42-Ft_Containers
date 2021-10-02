/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:59:51 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/27 17:05:33 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_assign(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::vector<int> range(5, 1);
	NS::vector<int> test;

	testFile << "Content of vector<int> range : ";
	for (size_t i = 0; i < range.size(); i++)
	{
		range[i] += i;
		testFile << "| " << range[i] << " |";
	}
	testFile << "\n\nnamespace::vector<int> test\n";
    testFile << "Size of vector<int> before assign : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before assign : " << test.capacity() << '\n';
	testFile << "\ntest.assign(range.begin(), range.end())\n";
	test.assign(range.begin(), range.end());
	testFile << "Size of vector<int> after assign : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after assign : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << "\n\ntest.assign(10, 42)\n";
	test.assign(10, 42);
	testFile << "Size of vector<int> after assign : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after assign : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}