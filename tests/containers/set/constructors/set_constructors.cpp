/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_constructors.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:21:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 12:56:02 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void    set_default_constructor(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::set<int> test;

    testFile << "Size of set<int> test    : " << test.size() << '\n';

    testFile << "\nContent of set<int> test : ";
    for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
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

void	set_copy_constructor(char *argv)
{
   bool runAll = argv[4] == '1' ? true : false;
   std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

   NS::set<int> original;

   original.insert(2);
   original.insert(10);
   original.insert(10);
   original.insert(14);
   original.insert(1);
   original.insert(8);
   original.insert(9);
   original.insert(2);
   original.insert(8);

   NS::set<int> copy(original);

   testFile << "\nContent of set<int> original : ";
   for (NS::set<int>::iterator it = original.begin(); it != original.end(); it++)
       testFile << "| " << *it << " |";

    testFile << "\nContent of set<int> copy     : ";
   for (NS::set<int>::iterator it = copy.begin(); it != copy.end(); it++)
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

void	set_range_constructor(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

   NS::set<int> range;

   range.insert(2);
   range.insert(10);
   range.insert(10);
   range.insert(14);
   range.insert(1);
   range.insert(8);
   range.insert(9);
   range.insert(2);
   range.insert(8);

   NS::set<int> test(range.begin(), range.end());

   testFile << "\nContent of set<int> range : ";
   for (NS::set<int>::iterator it = range.begin(); it != range.end(); it++)
       testFile << "| " << *it << " |";

    testFile << "\nContent of set<int> test  : ";
   for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
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

void	set_operator_equal(char *argv)
{
   bool runAll = argv[4] == '1' ? true : false;
   std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

   NS::set<int> original;

   original.insert(2);
   original.insert(10);
   original.insert(10);
   original.insert(14);
   original.insert(1);
   original.insert(8);
   original.insert(9);
   original.insert(2);
   original.insert(8);

   NS::set<int> copy = original;

   testFile << "\nContent of set<int> original : ";
   for (NS::set<int>::iterator it = original.begin(); it != original.end(); it++)
       testFile << "| " << *it << " |";

    testFile << "\nContent of set<int> copy     : ";
   for (NS::set<int>::iterator it = copy.begin(); it != copy.end(); it++)
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
