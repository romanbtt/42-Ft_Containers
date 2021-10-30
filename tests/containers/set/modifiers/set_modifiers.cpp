/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_modifiers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:14:18 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 17:15:45 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	set_insert(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::set<int> test1;
	NS::pair<NS::set<int>::iterator,bool> ret;

	testFile << "Insert single elements\n\n";

	test1.insert (400);
	for(int i = 1; i <= 5; i++)
	{
		ret = test1.insert (i * 100);
		if (ret.second==false)
    		testFile << "Element " << *ret.first << " already existed.\n";
		else
		   	testFile << "Element " << *ret.first << " was correctly added.\n";
	}

	NS::set<int>::iterator it = test1.begin();
	NS::set<int>::iterator ret1;

	testFile << "\nInsert single elements with an hint\n";

  	ret1 = test1.insert (it, 500);
	testFile << "\nThe iterator content is : " << *ret1;
  	ret1 = test1.insert (it, 700);
	testFile << "\nThe iterator content is : " << *ret1;
	
	NS::set<int> test2;

	testFile << "\n\nInsert range\n\n";

	test2.insert(test1.begin(), test1.find(5));

   	testFile << "\nContent of set<int> test1 : ";
   	for (NS::set<int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << *it << " |";

   	testFile << "\nContent of set<int> test2 : ";
   	for (NS::set<int>::iterator it = test2.begin(); it != test2.end(); it++)
       testFile << "| " << *it << " |";

	testFile << "\n\nInsert 10000 elements\n\n";

	srand (time(NULL));
	NS::set<int>test3;

	for (int i = 0; i < 10000; i++)
	{
		test3.insert(rand() % 2147483647);
	}

	testFile << "Size of set<int> test3 is : " << test3.size();

	testFile << '\n';
	
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

static void	print_set(std::ofstream & file, NS::set<int> & test)
{
	file << "Size of set<int> test      : " << test.size();

   	file << "\nContent of set<int> test : ";
   	for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
       file << "| " << *it << " |";
}

void	set_erase(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::set<int>test;
	NS::set<int>::iterator it;

	for(int i = 1; i < 10; i++)
		test.insert(i);
	
	print_set(testFile, test);

	testFile << "\n\nErase single element by iterator\n\n";

	it = test.find(4);
  	test.erase(it); 

	print_set(testFile, test);

	testFile << "\n\nErase single element by key\n\n";

  	test.erase(9); 

	print_set(testFile, test);

	testFile << "\n\nErase single element by range\n\n";

	it = test.find(7);
  	test.erase(test.begin(), it); 

	print_set(testFile, test);

	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	set_swap(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);


	NS::set<int> test1;
	NS::set<int> test2;

    test1.insert(2);
    test1.insert(10);
    test1.insert(14);
    test1.insert(1);
    test1.insert(8);
    test1.insert(9);
    test1.insert(2);

	test2.insert(7);
    test2.insert(99);
    test2.insert(19);
    test2.insert(2);

	testFile << "\nSize of set<int> test1 before swap    : " << test1.size() << '\n';
	
   	testFile << "\nContent of set<int> test1 before swap : ";
   	for (NS::set<int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << *it << " |";

	testFile << "\n\nSize of set<int> test2 before swap    : " << test2.size() << '\n';

   	testFile << "\nContent of set<int> test2 before swap : ";
   	for (NS::set<int>::iterator it = test2.begin(); it != test2.end(); it++)
       testFile << "| " << *it << " |";
	
	test1.swap(test2);
	testFile << "\n\n";

	testFile << "\nSize of set<int> test1 after swap     : " << test1.size() << '\n';

   	testFile << "\nContent of set<int> test1 after swap  : ";
   	for (NS::set<int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << *it << " |";

	testFile << "\n\nSize of set<int> test2 after swap     : " << test2.size() << '\n';

   	testFile << "\nContent of set<int> test2 after swap  : ";
   	for (NS::set<int>::iterator it = test2.begin(); it != test2.end(); it++)
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

void	set_clear(char *argv)
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

	testFile << "\nSize of set<int> test before clear    : " << test.size() << '\n';

   	testFile << "\nContent of set<int> test before clear : ";
   	for (NS::set<int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << *it << " |";

	test.clear();

	testFile << "\n\nSize of set<int> test after clear     : " << test.size() << '\n';

   	testFile << "\nContent of set<int> test after clear  : ";
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
