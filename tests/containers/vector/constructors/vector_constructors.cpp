/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructors.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:28:27 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_copy_constructor(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> original(10, 42);
    NS::vector<int> copy(original);

    testFile << "Capacity of vector<int>'s original : " << original.capacity() << '\n';
    testFile << "Size of vector<int>'s original     : " << original.size() << '\n';
    testFile << "Content of vector<int>'s orginal   : ";
    for (NS::vector<int>::iterator it = original.begin(); it != original.end(); it++)
       testFile << "| " << *it << " |";
    testFile << "\n\n";
    testFile << "Capacity of vector<int>'s copy     : " << copy.capacity() << '\n';
    testFile << "Size of vector<int>'s copy         : " << copy.size() << '\n';
    testFile << "Content of vector<int>'s copy      : ";
    for (NS::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
        testFile << "| " << *it << " |";
    testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void    vector_default_constructor(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test1;
    NS::vector<float> test2;

    testFile << "Capacity of vector<int>   : " << test1.capacity() << '\n';
    testFile << "Size of vector<int>       : " << test1.size() << '\n';
    testFile << "Content of vector<int>    : ";
    for (NS::vector<int>::iterator it = test1.begin(); it != test1.end(); it++)
        testFile << "| " << *it << " |";
    testFile << "\n\n";
    testFile << "Capacity of vector<float> : " << test2.capacity() << '\n';
    testFile << "Size of vector<float>     : " << test2.size() << '\n';
    testFile << "Content of vector<float>  : ";
    for (NS::vector<float>::iterator it = test2.begin(); it != test2.end(); it++)
        testFile << "| " << *it << " |";
    testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    } 
}

void    vector_fill_constructor(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test1(10, 42);
    NS::vector<float> test2(10, 4.2);

    testFile << "Capacity of vector<int>   : " << test1.capacity() << '\n';
    testFile << "Size of vector<int>       : " << test1.size() << '\n';
    testFile << "Content of vector<int>    : ";
    for (NS::vector<int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << *it << " |";
    testFile << "\n\n";
    testFile << "Capacity of vector<float> : " << test2.capacity() << '\n';
    testFile << "Size of vector<float>     : " << test2.size() << '\n';
    testFile << "Content of vector<float>  : ";
    for (NS::vector<float>::iterator it = test2.begin(); it != test2.end(); it++)
        testFile << "| " << *it << " |";
    testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    } 
}

void	vector_operator_equal(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> original(10, 42);
    NS::vector<int> copy = original;

    testFile << "Capacity of vector<int>'s original : " << original.capacity() << '\n';
    testFile << "Size of vector<int>'s original     : " << original.size() << '\n';
    testFile << "Content of vector<int>'s orginal   : ";
    for (NS::vector<int>::iterator it = original.begin(); it != original.end(); it++)
       testFile << "| " << *it << " |";
    testFile << "\n\n";
    testFile << "Capacity of vector<int>'s copy     : " << copy.capacity() << '\n';
    testFile << "Size of vector<int>'s copy         : " << copy.size() << '\n';
    testFile << "Content of vector<int>'s copy      : ";
    for (NS::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
        testFile << "| " << *it << " |";
    testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	vector_range_constructor(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> range1(10, 42);
    NS::vector<float> range2(10, 4.2);
	NS::vector<int> test1(range1.begin(), range1.end());
	NS::vector<float> test2(range2.rbegin(), range2.rend());

    testFile << "Capacity of vector<int>   : " << test1.capacity() << '\n';
    testFile << "Size of vector<int>       : " << test1.size() << '\n';
    testFile << "Content of vector<int>    : ";
    for (NS::vector<int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << *it << " |";
    testFile << "\n\n";
    testFile << "Capacity of vector<float> : " << test2.capacity() << '\n';
    testFile << "Size of vector<float>     : " << test2.size() << '\n';
    testFile << "Content of vector<float>  : ";
    for (NS::vector<float>::iterator it = test2.begin(); it != test2.end(); it++)
        testFile << "| " << *it << " |";
    testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
