/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushBack.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:21:36 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/26 17:18:38 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

static void	print_vector(std::ofstream & file, std::vector<int> & test, int val)
{
	file << "\ntest.push_back(" << val << ")\n";
	test.push_back(val);
	file << "Size of vector<int> after push_back : " << test.size() << '\n';
	file << "Capacity of vector<int> after push_back : " << test.capacity() << '\n';
	file << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		file << "| " << test[i] << " |";
	file << "\n";
}

void	vector_push_back(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("std", std::ios::out | std::ios::trunc);
	std::vector<int> test;

	testFile << "namespace::vector<int> test\n";
    testFile << "Size of vector<int> before push_back : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before push_back : " << test.capacity() << '\n';
	print_vector(testFile, test, 1);
	print_vector(testFile, test, 2);
	print_vector(testFile, test, 4);
	print_vector(testFile, test, 8);
	print_vector(testFile, test, 16);
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file("std");
        std::cout << file.rdbuf();
        file.close();
    }
}