/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_constructors.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:21:23 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:29:05 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void    map_default_constructor(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int, int> test;

    testFile << "Size of map<int, int> test             : " << test.size() << '\n';
    testFile << "Content of map<int, int> test (Keys)   : ";
    for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << it->first << " |";

    testFile << "\nContent of map<int, int> test (Values) : ";
    for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << it->second << " |";
    testFile << '\n';
    
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    } 
}

void	map_copy_constructor(char *argv)
{
   bool runAll = argv[4] == '1' ? true : false;
   std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

   NS::map<int, int> original;

   original.insert(NS::make_pair(2, 9));
   original.insert(NS::make_pair(10, 86));
   original.insert(NS::make_pair(14, 54));
   original.insert(NS::make_pair(1, 8));
   original.insert(NS::make_pair(8, 4));
   original.insert(NS::make_pair(9, 0));
   original.insert(NS::make_pair(2, 6));

   NS::map<int, int> copy(original);

   testFile << "Size of map<int, int> original             : " << original.size() << '\n';
   testFile << "Content of map<int, int> original (Keys)   : ";
   for (NS::map<int, int>::iterator it = original.begin(); it != original.end(); it++)
       testFile << "| " << it->first << " |";

   testFile << "\nContent of map<int, int> original (Values) : ";
   for (NS::map<int, int>::iterator it = original.begin(); it != original.end(); it++)
       testFile << "| " << it->second << " |";

   testFile << "\n\nSize of map<int, int> copy                 : " << copy.size() << '\n';
   testFile << "Content of map<int, int> copy (Keys)       : ";
   for (NS::map<int, int>::iterator it = copy.begin(); it != copy.end(); it++)
       testFile << "| " << it->first << " |";

    testFile << "\nContent of map<int, int> copy (Values)     : ";
   for (NS::map<int, int>::iterator it = copy.begin(); it != copy.end(); it++)
       testFile << "| " << it->second << " |";
   testFile << '\n';
   
   testFile.close();
   if (runAll == false)
   {
       std::ifstream file(DIFF);
       std::cout << file.rdbuf();
       file.close();
   } 
}

void	map_range_constructor(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

   NS::map<int, int> range;

   range.insert(NS::make_pair(2, 9));
   range.insert(NS::make_pair(10, 86));
   range.insert(NS::make_pair(14, 54));
   range.insert(NS::make_pair(1, 8));
   range.insert(NS::make_pair(8, 4));
   range.insert(NS::make_pair(9, 0));
   range.insert(NS::make_pair(2, 6));

   NS::map<int, int> test(range.begin(), range.end());

   testFile << "Size of map<int, int> range             : " << range.size() << '\n';
   testFile << "Content of map<int, int> range (Keys)   : ";
   for (NS::map<int, int>::iterator it = range.begin(); it != range.end(); it++)
       testFile << "| " << it->first << " |";

   testFile << "\nContent of map<int, int> range (Values) : ";
   for (NS::map<int, int>::iterator it = range.begin(); it != range.end(); it++)
       testFile << "| " << it->second << " |";

   testFile << "\n\nSize of map<int, int> test              : " << test.size() << '\n';
   testFile << "Content of map<int, int> test (Keys)    : ";
   for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->first << " |";

    testFile << "\nContent of map<int, int> test (Values)  : ";
   for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->second << " |";
   testFile << '\n';
   
   testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	map_operator_equal(char *argv)
{
   bool runAll = argv[4] == '1' ? true : false;
   std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

   NS::map<int, int> original;

   original.insert(NS::make_pair(2, 9));
   original.insert(NS::make_pair(10, 86));
   original.insert(NS::make_pair(14, 54));
   original.insert(NS::make_pair(1, 8));
   original.insert(NS::make_pair(8, 4));
   original.insert(NS::make_pair(9, 0));
   original.insert(NS::make_pair(2, 6));

   NS::map<int, int> copy = original;

   testFile << "Size of map<int, int> original             : " << original.size() << '\n';
   testFile << "Content of map<int, int> original (Keys)   : ";
   for (NS::map<int, int>::iterator it = original.begin(); it != original.end(); it++)
       testFile << "| " << it->first << " |";

   testFile << "\nContent of map<int, int> original (Values) : ";
   for (NS::map<int, int>::iterator it = original.begin(); it != original.end(); it++)
       testFile << "| " << it->second << " |";

   testFile << "\n\nSize of map<int, int> copy                 : " << copy.size() << '\n';
   testFile << "Content of map<int, int> copy (Keys)       : ";
   for (NS::map<int, int>::iterator it = copy.begin(); it != copy.end(); it++)
       testFile << "| " << it->first << " |";

    testFile << "\nContent of map<int, int> copy (Values)     : ";
   for (NS::map<int, int>::iterator it = copy.begin(); it != copy.end(); it++)
       testFile << "| " << it->second << " |";
   testFile << '\n';
   
   testFile.close();
   if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    } 
}
