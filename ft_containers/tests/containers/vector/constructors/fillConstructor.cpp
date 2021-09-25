/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillConstructor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:23:13 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/25 14:56:12 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void    vector_fill_constructor(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile("ft", std::ios::out | std::ios::trunc);

    ft::vector<int> test1(10, 42);;
    ft::vector<float> test2(10, 4.2);;

std::string s = "Hello, world";
for (ft::reverse_iterator<std::string::iterator> it = s.rbegin(); it != s.rend(); it++)
  std::cout << *it;
std::cout << std::endl;

    testFile << "Capacity of vector<int> : " << test1.capacity() << '\n';
    testFile << "Size of vector<int> : " << test1.size() << '\n';
    testFile << "Content of vector<int> : ";
    for (ft::vector<int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << *it << " |";
    testFile << "\n\n";
    testFile << "Capacity of vector<float> : " << test2.capacity() << '\n';
    testFile << "Size of vector<float> : " << test2.size() << '\n';
    testFile << "Content of vector<float> : ";
    for (ft::vector<float>::iterator it = test2.begin(); it != test2.end(); it++)
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
