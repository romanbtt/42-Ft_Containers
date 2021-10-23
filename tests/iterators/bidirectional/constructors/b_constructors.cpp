/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_constructors.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/22 14:57:54 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	bidirectional_copy_constructors(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int, int> test;
    test.insert(NS::make_pair(1, 2));
    test.insert(NS::make_pair(3, 4));
    test.insert(NS::make_pair(5, 6));
    test.insert(NS::make_pair(7, 8));
    test.insert(NS::make_pair(9, 0));

    NS::map<int, int>::iterator original = test.begin();
    NS::map<int, int>::iterator copy(original);

    testFile << "NS::map<int, int> test\n";
    testFile << "NS::map<int, int>::iterator original = test.begin()\n";
    testFile << "NS::map<int, int>::iterator copy(original)\n\n";

    testFile << "original key point to : " << original->first << '\n';
    testFile << "copy point key to : " << copy->first << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void    bidirectional_default_constructors(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int, int> test;

    test.insert(NS::make_pair(1, 2));
    test.insert(NS::make_pair(3, 4));
    test.insert(NS::make_pair(5, 6));
    test.insert(NS::make_pair(7, 8));
    test.insert(NS::make_pair(9, 0));

    NS::map<int, int>::iterator it_test = test.begin();
    testFile << " NS::map<int, int> test\n";
    testFile << " NS::map<int, int>::iterator it_test = test.begin()\n\n";
    testFile << "it_test key point to : " << it_test->first << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    } 
}

void	bidirectional_operator_equal(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int, int> test;

    test.insert(NS::make_pair(1, 2));
    test.insert(NS::make_pair(3, 4));
    test.insert(NS::make_pair(5, 6));
    test.insert(NS::make_pair(7, 8));
    test.insert(NS::make_pair(9, 0));

    NS::map<int, int>::iterator original = test.begin();
    NS::map<int, int>::iterator copy = original;

    testFile << "NS::map<int, int> test\n";
    testFile << "NS::map<int, int>::iterator original = test.begin()\n";
    testFile << "NS::map<int, int>::iterator copy = original\n\n";

    testFile << "original key point to : " << original->first << '\n';
    testFile << "copy key point to : " << copy->first << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}