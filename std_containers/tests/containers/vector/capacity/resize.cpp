/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:04:00 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/25 20:16:42 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_resize(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("std", std::ios::out | std::ios::trunc);

    std::vector<int> test(5, 42);

	testFile << "namespace::vector<int> test(5, 42)\n";
    testFile << "Size of vector<int> before resize : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before resize : " << test.capacity() << '\n';
	testFile << "Content of vector<int> before resize : ";
    for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << *it << " |";
	testFile << "\n\ntest.resize(10, 84)\n";
	test.resize(10, 84);
	testFile << "Size of vector<int> after resize : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after resize : " << test.capacity() << '\n';
	testFile << "Content of vector<int> after resize : ";
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << *it << " |";
	test.resize(2);
	testFile << "\n\ntest.resize(2)\n";
	testFile << "Size of vector<int> after resize : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after resize : " << test.capacity() << '\n';
	testFile << "Content of vector<int> after resize : ";
    for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << *it << " |";
	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file("std");
        std::cout << file.rdbuf();
        file.close();
    }
}