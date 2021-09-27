/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:04:00 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/25 20:02:25 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_reserve(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("std", std::ios::out | std::ios::trunc);

    std::vector<int> test(10, 42);
	testFile << "namespace::vector<int> test(10, 42)\n";

    testFile << "Size of vector<int> before reserve : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before reserve : " << test.capacity() << '\n';
	testFile << "\ntest.reserve(84)\n";
	test.reserve(84);
	testFile << "Size of vector<int> after reserve : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after reserve : " << test.capacity() << '\n';
	testFile << "\ntest.reserve(42)\n";
	test.reserve(42);
	testFile << "Size of vector<int> after reserve : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after reserve : " << test.capacity() << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file("std");
        std::cout << file.rdbuf();
        file.close();
    }
}