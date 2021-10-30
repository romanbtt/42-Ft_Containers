/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:47:50 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:29:34 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	map_count(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::map<int,int> test;
	int count;

   	test.insert(NS::make_pair(2, 9));
   	test.insert(NS::make_pair(10, 86));
   	test.insert(NS::make_pair(14, 54));
   	test.insert(NS::make_pair(1, 8));
   	test.insert(NS::make_pair(8, 4));
   	test.insert(NS::make_pair(9, 0));
   	test.insert(NS::make_pair(2, 6));

	testFile << "Content of map<int, int> test (Keys)   : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   	testFile << "\nContent of map<int, int> test (Values) : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->second << " |";

	testFile << "\n\n";

	for (int i = 0; i < 20; i++)
	{
		count = test.count(i);
		if (count > 0)
		testFile << i << " is an element of map<int, int> test\n";
		else
		testFile << i << " is not an element of map<int, int> test\n";
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

void	map_equal_range(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::map<int,int> test;

   	test.insert(NS::make_pair(2, 9));
   	test.insert(NS::make_pair(10, 86));
   	test.insert(NS::make_pair(14, 54));
   	test.insert(NS::make_pair(1, 8));
   	test.insert(NS::make_pair(8, 4));
   	test.insert(NS::make_pair(9, 0));
   	test.insert(NS::make_pair(2, 6));

	testFile << "Content of map<int, int> test (Keys)   : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   	testFile << "\nContent of map<int, int> test (Values) : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->second << " |";

	testFile << "\n\n";
	NS::pair<NS::map<int,int>::iterator, NS::map<int,int>::iterator> ret;


	for (int i = 0; i < 20; i++)
	{
		ret = test.equal_range(i);
		if (ret.first == test.end() || ret.second == test.end())
		{
			testFile << "Upper bound or lower bound points to end\n";
			continue ;
		}	
  		testFile << "Lower bound points to: ";
  		testFile << ret.first->first << " => " << ret.first->second << '\n';

  		testFile << "Upper bound points to: ";
  		testFile << ret.second->first << " => " << ret.second->second << "\n\n";
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

void	map_find(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::map<int,int> test;
	NS::map<int,int>::iterator it;

   	test.insert(NS::make_pair(2, 9));
   	test.insert(NS::make_pair(10, 86));
   	test.insert(NS::make_pair(14, 54));
   	test.insert(NS::make_pair(1, 8));
   	test.insert(NS::make_pair(8, 4));
   	test.insert(NS::make_pair(9, 0));
   	test.insert(NS::make_pair(2, 6));

	testFile << "Content of map<int, int> test (Keys)   : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   	testFile << "\nContent of map<int, int> test (Values) : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->second << " |";

	testFile << "\n\n";

	for (int i = 0; i < 20; i++)
	{
		it = test.find(i);
		if (it != test.end())
		testFile << it->first << " was found with a value of " << it->second << "\n";
	else
		testFile << "The key " << i << " was not found\n";
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

void	map_lower_bound(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::map<int,int> test;
	NS::map<int,int>::iterator it;

   	test.insert(NS::make_pair(2, 9));
   	test.insert(NS::make_pair(10, 86));
   	test.insert(NS::make_pair(14, 54));
   	test.insert(NS::make_pair(1, 8));
   	test.insert(NS::make_pair(8, 4));
   	test.insert(NS::make_pair(9, 0));
   	test.insert(NS::make_pair(2, 6));

	testFile << "Content of map<int, int> test (Keys)   : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   	testFile << "\nContent of map<int, int> test (Values) : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->second << " |";

	testFile << "\n\n";

	for (int i = 0; i < 20; i++)
	{
		it = test.lower_bound(i);
		if (it != test.end())
			testFile << "Lower bound of " << i << " is :" << it->first << "\n";
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

void	map_upper_bound(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::map<int,int> test;
	NS::map<int,int>::iterator it;

   	test.insert(NS::make_pair(2, 9));
   	test.insert(NS::make_pair(10, 86));
   	test.insert(NS::make_pair(14, 54));
   	test.insert(NS::make_pair(1, 8));
   	test.insert(NS::make_pair(8, 4));
   	test.insert(NS::make_pair(9, 0));
   	test.insert(NS::make_pair(2, 6));

	testFile << "Content of map<int, int> test (Keys)   : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   	testFile << "\nContent of map<int, int> test (Values) : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->second << " |";

	testFile << "\n\n";

	for (int i = 0; i < 20; i++)
	{
		it = test.upper_bound(i);
		if (it != test.end())
			testFile << "Upper bound of " << i << " is :" << it->first << "\n";
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
