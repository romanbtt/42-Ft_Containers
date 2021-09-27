/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:04:00 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/25 20:18:02 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_empty(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("ft", std::ios::out | std::ios::trunc);

    ft::vector<int> test1;
    ft::vector<int> test2(10, 42);

	testFile << std::boolalpha;
	testFile << "namespace::vector<int> test1\n";
    testFile << "vector<int> test1 is empty ? : " << test1.empty() << "\n\n";
	testFile << "namespace::vector<int> test2(10, 42)\n";
	testFile << "vector<int> test2 is empty ? : " << test2.empty() << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file("ft");
        std::cout << file.rdbuf();
        file.close();
    }
}