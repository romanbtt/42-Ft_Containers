/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:56:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/27 17:05:16 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_begin(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::vector<int> test1(10, 1);

	testFile << "Content of vector<int> : ";
	for (size_t i = 0; i < test1.size(); i++)
	{
		test1[i] += i;
		testFile << "| " << test1[i] << " |";
	}
	testFile << '\n';
    testFile << "Iterator Begin = " << *(test1.begin()) << '\n';
	testFile << "Iterator Begin + 5 = " << *(test1.begin() + 5) << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}