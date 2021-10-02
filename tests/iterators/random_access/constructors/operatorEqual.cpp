/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operatorEqual.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/28 17:06:26 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	random_access_operator_equal(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test(10, 42);
    NS::vector<int>::iterator original = test.begin() + 5;
    NS::vector<int>::iterator copy = original;

    testFile << "NS::vector<int> test(10, 42)\n";
    testFile << "NS::vector<int>::iterator original = test.begin() + 5\n";
    testFile << "NS::vector<int>::iterator copy = original\n\n";

    testFile << "original point to : " << *original << '\n';
    testFile << "copy point to : " << *copy << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}