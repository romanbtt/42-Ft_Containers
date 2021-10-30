/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterators.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:56:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 13:08:58 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	set_begin(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::set<int> test;

    test.insert(2);
    test.insert(10);
    test.insert(14);
    test.insert(1);
	test.insert(9);
    test.insert(8);
    test.insert(9);
    test.insert(2);
	test.insert(14);

    testFile << "\nContent of set<int> test : ";
    for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << *it << " |";

    testFile << "\nIterator Begin : " << *test.begin() << '\n';
    
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	set_end(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::set<int> test;

    test.insert(2);
    test.insert(10);
    test.insert(14);
    test.insert(1);
	test.insert(9);
    test.insert(8);
    test.insert(9);
    test.insert(2);
	test.insert(14);
    

    testFile << "\nContent of set<int> test : ";
    for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << *it << " |";

    for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
    {
        if (test.end() == it)
        {
            testFile << "\n\nTest failed. Iterator end take part of set<int> test.\n";
            break ;
        }    
    }
    testFile << "\n\nTest succeed. Iterator end doesn't take part of set<int> test.\n";
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	set_rbegin(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::set<int> test;

    test.insert(2);
    test.insert(10);
    test.insert(14);
    test.insert(1);
	test.insert(9);
    test.insert(8);
    test.insert(9);
    test.insert(2);
	test.insert(14);

    testFile << "\nContent of set<int> test : ";
    for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << *it << " |";

    testFile << "\nIterator Rbegin : " << *test.rbegin() << '\n';
    
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	set_rend(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::set<int> test;

    test.insert(2);
    test.insert(10);
    test.insert(14);
    test.insert(1);
	test.insert(9);
    test.insert(8);
    test.insert(9);
    test.insert(2);
	test.insert(14);

    testFile << "\nContent of set<int> test : ";
    for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << *it << " |";

    for (NS::set<int>::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
    {
        if (test.rend() == it)
        {
            testFile << "\n\nTest failed. Iterator rend take part of set<int> test.\n";
            break ;
        }   
    }
    testFile << "\n\nTest succeed. Iterator rend doesn't take part of set<int> test.\n";
    
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
