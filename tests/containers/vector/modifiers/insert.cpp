/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:14:18 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/27 17:05:51 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_insert(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
	NS::vector<int> range(10, 1);
	NS::vector<int> test;

	testFile << "Content of vector<int> range : ";
	for (size_t i = 0; i < range.size(); i++)
	{
		range[i] += i;
		testFile << "| " << range[i] << " |";
	}
	testFile << "\n\nnamespace::vector<int> test\n";
    testFile << "Size of vector<int> before insert : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before insert : " << test.capacity() << '\n';
	testFile << "\ntest.insert(test.begin(), range.begin(), range.end())\n";
	test.insert(test.begin(), range.begin(), range.end());
	testFile << "Size of vector<int> after insert : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after insert : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << "\n\ntest.insert(test.begin() + 5, 5, 42)\n";
	test.insert(test.begin() + 5, 5, 42);
	testFile << "Size of vector<int> after insert : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after insert : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << "\n\ntest.insert(test.begin() + 10, 1000)\n";
	test.insert(test.begin() + 10, 1000);
	testFile << "Size of vector<int> after insert : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after insert : " << test.capacity() << '\n';
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