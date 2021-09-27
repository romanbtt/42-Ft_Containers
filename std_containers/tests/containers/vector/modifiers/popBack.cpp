/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popBack.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:37:43 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/26 16:41:42 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

static void	print_vector(std::ofstream & file, std::vector<int> & test)
{
	file << "\ntest.pop_back()\n";
	test.pop_back();
	file << "Size of vector<int> after pop_back : " << test.size() << '\n';
	file << "Capacity of vector<int> after pop_back : " << test.capacity() << '\n';
	file << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		file << "| " << test[i] << " |";
	file << "\n";
}

void	vector_pop_back(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("std", std::ios::out | std::ios::trunc);
	std::vector<int> test(5, 1);

	testFile << "Content of vector<int> : ";
	for (size_t i = 0; i < test.size(); i++)
	{
		test[i] += i;
		testFile << "| " << test[i] << " |";
	}
    testFile << "\nSize of vector<int> before pop_back : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before pop_back : " << test.capacity() << '\n';
	print_vector(testFile, test);
	print_vector(testFile, test);
	print_vector(testFile, test);
	print_vector(testFile, test);
	print_vector(testFile, test);
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file("std");
        std::cout << file.rdbuf();
        file.close();
    }
}