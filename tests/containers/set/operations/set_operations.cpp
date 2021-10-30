/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_operations.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:47:50 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:29:58 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	set_count(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::set<int> test;
	int count;

   	test.insert(2);
   	test.insert(10);
   	test.insert(14);
   	test.insert(1);
   	test.insert(8);
   	test.insert(9);
   	test.insert(2);

   	testFile << "\nContent of set<int> test (Values) : ";
   	for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << *it << " |";

	testFile << "\n\n";

	for (int i = 0; i < 20; i++)
	{
		count = test.count(i);
		if (count > 0)
		testFile << i << " is an element of set<int> test\n";
		else
		testFile << i << " is not an element of set<int> test\n";
	}

	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	set_equal_range(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::set<int> test;

   	test.insert(2);
   	test.insert(10);
   	test.insert(14);
   	test.insert(1);
   	test.insert(8);
   	test.insert(9);
   	test.insert(2);

   	testFile << "\nContent of set<int> test : ";
   	for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << *it << " |";

	testFile << "\n\n";
	NS::pair<NS::set<int>::iterator, NS::set<int>::iterator> ret;


	for (int i = 0; i < 20; i++)
	{
		ret = test.equal_range(i);
		if (ret.first == test.end() || ret.second == test.end())
		{
			testFile << "Upper bound or lower bound points to end\n";
			continue ;
		}	
  		testFile << "Lower bound points to: ";
  		testFile << *ret.first << '\n';

  		testFile << "Upper bound points to: ";
  		testFile << *ret.second << "\n\n";
	}

	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	set_find(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::set<int> test;
	NS::set<int>::iterator it;

   	test.insert(2);
   	test.insert(10);
   	test.insert(14);
   	test.insert(1);
   	test.insert(8);
   	test.insert(9);
   	test.insert(2);

   	testFile << "\nContent of set<int> test : ";
   	for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << *it << " |";

	testFile << "\n\n";

	for (int i = 0; i < 20; i++)
	{
		it = test.find(i);
		if (it != test.end())
		testFile << *it << " was found\n";
	else
		testFile << "The value " << i << " was not found\n";
	}

	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	set_lower_bound(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::set<int> test;
	NS::set<int>::iterator it;

   	test.insert(2);
   	test.insert(10);
   	test.insert(14);
   	test.insert(1);
   	test.insert(8);
   	test.insert(9);
   	test.insert(2);

   	testFile << "\nContent of set<int> test : ";
   	for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << *it << " |";

	testFile << "\n\n";

	for (int i = 0; i < 20; i++)
	{
		it = test.lower_bound(i);
		if (it != test.end())
			testFile << "Lower bound of " << i << " is :" << *it << "\n";
		else
			testFile << "Iterator points to end\n";
	}

	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	set_upper_bound(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::set<int> test;
	NS::set<int>::iterator it;

   	test.insert(2);
   	test.insert(10);
   	test.insert(14);
   	test.insert(1);
   	test.insert(8);
   	test.insert(9);
   	test.insert(2);

   	testFile << "\nContent of set<int> test : ";
   	for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << *it << " |";

	testFile << "\n\n";

	for (int i = 0; i < 20; i++)
	{
		it = test.upper_bound(i);
		if (it != test.end())
			testFile << "Upper bound of " << i << " is :" << *it << "\n";
		else
			testFile << "Iterator points to end\n";
	}

	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
