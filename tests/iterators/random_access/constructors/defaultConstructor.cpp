/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaultConstructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:21:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/28 17:01:55 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void    random_access_default_constructors(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test(10, 42);
    NS::vector<int>::iterator it_test = test.begin();
    testFile << " namespace::vector<int> test(10, 42)\n";
    testFile << " namespace::vector<int>::iterator it_test = test.begin()\n\n";
    testFile << "it_test1 point to : " << *it_test << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    } 
}