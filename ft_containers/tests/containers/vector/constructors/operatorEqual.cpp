/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatorEqual.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/25 16:35:34 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_operator_equal(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("ft", std::ios::out | std::ios::trunc);

    ft::vector<int> original(10, 42);
    ft::vector<int> copy = original;

    testFile << "Capacity of vector<int>'s original : " << original.capacity() << '\n';
    testFile << "Size of vector<int>'s original : " << original.size() << '\n';
    testFile << "Content of vector<int>'s orginal : ";
    for (ft::vector<int>::iterator it = original.begin(); it != original.end(); it++)
       testFile << "| " << *it << " |";
    testFile << "\n\n";
    testFile << "Capacity of vector<int>'s copy : " << copy.capacity() << '\n';
    testFile << "Size of vector<int>'s copy : " << copy.size() << '\n';
    testFile << "Content of vector<int>'s copy : ";
    for (ft::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
        testFile << "| " << *it << " |";
    testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file("ft");
        std::cout << file.rdbuf();
        file.close();
    }

}