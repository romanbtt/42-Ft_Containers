/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterators.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:56:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 14:37:30 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	map_begin(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::map<int, int> test;

    test.insert(NS::make_pair(2, 9));
    test.insert(NS::make_pair(10, 86));
    test.insert(NS::make_pair(14, 54));
    test.insert(NS::make_pair(1, 8));
    test.insert(NS::make_pair(8, 4));
    test.insert(NS::make_pair(9, 0));
    test.insert(NS::make_pair(2, 6));

    testFile << "Content of map<int, int> test1 (Keys)   : ";
    for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << it->first << " |";

    testFile << "\nContent of map<int, int> test1 (Values) : ";
    for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << it->second << " |";

    testFile << "\nIterator Begin (Key)   : " << test.begin()->first << '\n';
    testFile << "Iterator Begin (Value) : " << test.begin()->second << '\n';
    
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	map_end(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::map<int, int> test;

    test.insert(NS::make_pair(2, 9));
    test.insert(NS::make_pair(10, 86));
    test.insert(NS::make_pair(14, 54));
    test.insert(NS::make_pair(1, 8));
    test.insert(NS::make_pair(8, 4));
    test.insert(NS::make_pair(9, 0));
    test.insert(NS::make_pair(2, 6));
    
    testFile << "Content of map<int, int> test1 (Keys)   : ";
    for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << it->first << " |";

    testFile << "\nContent of map<int, int> test1 (Values) : ";
    for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << it->second << " |";

    for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
    {
        if (test.end() == it)
        {
            testFile << "\n\nTest failed. Iterator end take part of map<int, int> test.\n";
            break ;
        }    
    }
    testFile << "\n\nTest succeed. Iterator end doesn't take part of map<int, int> test.\n";
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	map_rbegin(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int, int> test;

    test.insert(NS::make_pair(2, 9));
    test.insert(NS::make_pair(10, 86));
    test.insert(NS::make_pair(14, 54));
    test.insert(NS::make_pair(1, 8));
    test.insert(NS::make_pair(8, 4));
    test.insert(NS::make_pair(9, 0));
    test.insert(NS::make_pair(2, 6));

    testFile << "Content of map<int, int> test1 (Keys)   : ";
    for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << it->first << " |";

    testFile << "\nContent of map<int, int> test1 (Values) : ";
    for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << it->second << " |";

    testFile << "\nIterator Rbegin (Key)   : " << test.rbegin()->first << '\n';
    testFile << "Iterator Rbegin (Value) : " << test.rbegin()->second << '\n';
    
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	map_rend(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::map<int, int> test;

    test.insert(NS::make_pair(2, 9));
    test.insert(NS::make_pair(10, 86));
    test.insert(NS::make_pair(14, 54));
    test.insert(NS::make_pair(1, 8));
    test.insert(NS::make_pair(8, 4));
    test.insert(NS::make_pair(9, 0));
    test.insert(NS::make_pair(2, 6));

    testFile << "Content of map<int, int> test1 (Keys)   : ";
    for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << it->first << " |";

    testFile << "\nContent of map<int, int> test1 (Values) : ";
    for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << it->second << " |";

    for (NS::map<int, int>::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
    {
        if (test.rend() == it)
        {
            testFile << "\n\nTest failed. Iterator rend take part of map<int, int> test.\n";
            break ;
        }   
    }
    testFile << "\n\nTest succeed. Iterator rend doesn't take part of map<int, int> test.\n";
    
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}