/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testerVectorDefaultConstructor.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:21:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/25 12:22:35 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void    vector_default_constructor(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("ft", std::ios::out | std::ios::trunc);

    ft::vector<int> test1;
    ft::vector<bool> test2;

    testFile << "Capacity of vector<int> : " << test1.capacity() << '\n';
    testFile << "Size of vector<int> : " << test1.size() << '\n';
    testFile << "Content of vector<int> : ";
    for (ft::vector<int>::iterator it = test1.begin(); it != test1.end(); it++)
        std::cout << "| " << *it << " |";
    testFile << "\n\n";
    testFile << "Capacity of vector<bool> : " << test2.capacity() << '\n';
    testFile << "Size of vector<bool> : " << test2.size() << '\n';
    testFile << "Content of vector<bool> : ";
    for (ft::vector<bool>::iterator it = test2.begin(); it != test2.end(); it++)
        std::cout << "| " << *it << " |";
    testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file("ft");
        std::cout << file.rdbuf();
        file.close();
    } 
}