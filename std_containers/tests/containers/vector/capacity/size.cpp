/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:04:00 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/25 20:40:43 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_size(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("std", std::ios::out | std::ios::trunc);

    std::vector<int> test1;
    std::vector<int> test2(10, 42);

    testFile << "namespace::vector<int> test1\n";
    testFile << "Size of vector<int> test1 : " << test1.size() << "\n\n";
    testFile << "namespace::vector<int> test2(10, 42)\n";
	testFile << "Size of vector<int> test2 : " << test2.size() << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file("std");
        std::cout << file.rdbuf();
        file.close();
    }
}