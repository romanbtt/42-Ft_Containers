/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_modifiers.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:14:18 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 14:38:46 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	map_insert(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);


	NS::map<int, int> test1;
	NS::pair<NS::map<int, int>::iterator,bool> ret;

	testFile << "Insert single elements\n\n";

	test1.insert (NS::make_pair<int, int>(4, 400));
	for(int i = 1; i <= 5; i++)
	{
		ret = test1.insert (NS::make_pair<int, int>(i, i * 100));
		if (ret.second==false)
		{
    		testFile << "Element " << i << " already existed";
    		testFile << " with a value of " << ret.first->second << '\n';
  		}
		else
		{
		   	testFile << "Element " << i << " was correctly added";
    		testFile << " with a value of " << ret.first->second << '\n';
		}
	}

	NS::map<int, int>::iterator it = test1.begin();
	NS::map<int, int>::iterator ret1;

	testFile << "\nInsert single elements with an hint\n";

  	ret1 = test1.insert (it, NS::make_pair<int, int>(5,500));
	testFile << "\nThe iterator content is : " << ret1->first << " | " << ret1->second;
  	ret1 = test1.insert (it, NS::make_pair<int, int>(7,700));
	testFile << "\nThe iterator content is : " << ret1->first << " | " << ret1->second;
	
	NS::map<int, int> test2;

	testFile << "\n\nInsert range\n\n";

	test2.insert(test1.begin(), test1.find(5));

   testFile << "Content of map<int, int> test1 (Keys)   : ";
   for (NS::map<int, int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   testFile << "\nContent of map<int, int> test1 (Values) : ";
   for (NS::map<int, int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << it->second << " |";

	testFile << "\n\n";

	testFile << "Content of map<int, int> test2 (Keys)   : ";
   	for (NS::map<int, int>::iterator it = test2.begin(); it != test2.end(); it++)
       testFile << "| " << it->first << " |";

	testFile << '\n';

   	testFile << "\nContent of map<int, int> test2 (Values) : ";
   	for (NS::map<int, int>::iterator it = test2.begin(); it != test2.end(); it++)
       testFile << "| " << it->second << " |";

	testFile << "\n\nInsert 50000 elements\n\n";

	srand (time(NULL));
	NS::map<int, int>test3;

	for (int i = 0; i < 50000; i++)
	{
		test3.insert(NS::make_pair(rand() % 2147483647, rand() % 10000 + 5000));
	}

	testFile << "Size of map<int, int>test3 is : " << test3.size();

	testFile << '\n';
	
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

static void	print_map(std::ofstream & file, NS::map<int,int> & test)
{
	file << "Size of map<int, int> test             : " << test.size();
	file << "\nContent of map<int, int> test (Keys)   : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       file << "| " << it->first << " |";

   	file << "\nContent of map<int, int> test (Values) : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       file << "| " << it->second << " |";
}

void	map_erase(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::map<int, int>test;
	NS::map<int, int>::iterator it;

	for(int i = 1; i < 10; i++)
		test.insert (NS::make_pair<int, int>(i, i));
	
	print_map(testFile, test);

	testFile << "\n\nErase single element by iterator\n\n";

	it = test.find(4);
  	test.erase(it); 

	print_map(testFile, test);

	testFile << "\n\nErase single element by key\n\n";

  	test.erase(9); 

	print_map(testFile, test);

	testFile << "\n\nErase single element by range\n\n";

	it = test.find(7);
  	test.erase(test.begin(), it); 

	print_map(testFile, test);

	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	map_swap(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);


	NS::map<int, int> test1;
	NS::map<int, int> test2;

    test1.insert(NS::make_pair(2, 9));
    test1.insert(NS::make_pair(10, 86));
    test1.insert(NS::make_pair(14, 54));
    test1.insert(NS::make_pair(1, 8));
    test1.insert(NS::make_pair(8, 4));
    test1.insert(NS::make_pair(9, 0));
    test1.insert(NS::make_pair(2, 6));

	test2.insert(NS::make_pair(7, 1));
    test2.insert(NS::make_pair(99, 77));
    test2.insert(NS::make_pair(19, 53));
    test2.insert(NS::make_pair(2, 7));

	testFile << "\nSize of map<int, int> test1 before swap : " << test1.size() << '\n';

	testFile << "Content of map<int, int> test1 (Keys) before swap   : ";
   	for (NS::map<int, int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   	testFile << "\nContent of map<int, int> test1 (Values) before swap : ";
   	for (NS::map<int, int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << it->second << " |";

	testFile << "\n\n";

	testFile << "\nSize of map<int, int> test2 before swap : " << test2.size() << '\n';

	testFile << "Content of map<int, int> test2 (Keys) before swap   : ";
   	for (NS::map<int, int>::iterator it = test2.begin(); it != test2.end(); it++)
       testFile << "| " << it->first << " |";

	testFile << '\n';

   	testFile << "\nContent of map<int, int> test2 (Values) before swap : ";
   	for (NS::map<int, int>::iterator it = test2.begin(); it != test2.end(); it++)
       testFile << "| " << it->second << " |";
	
	test1.swap(test2);
	testFile << "\n\n";

	testFile << "\nSize of map<int, int> test1 after swap : " << test1.size() << '\n';

	testFile << "Content of map<int, int> test1 (Keys) after swap   : ";
   	for (NS::map<int, int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   	testFile << "\nContent of map<int, int> test1 (Values) after swap : ";
   	for (NS::map<int, int>::iterator it = test1.begin(); it != test1.end(); it++)
       testFile << "| " << it->second << " |";

	testFile << "\n\n";

	testFile << "\nSize of map<int, int> test2 after swap : " << test2.size() << '\n';

	testFile << "Content of map<int, int> test2 (Keys) after swap   : ";
   	for (NS::map<int, int>::iterator it = test2.begin(); it != test2.end(); it++)
       testFile << "| " << it->first << " |";

	testFile << '\n'; 

   	testFile << "\nContent of map<int, int> test2 (Values) after swap : ";
   	for (NS::map<int, int>::iterator it = test2.begin(); it != test2.end(); it++)
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

void	map_clear(char *argv)
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

	testFile << "\nSize of map<int, int> test before clear : " << test.size() << '\n';

	testFile << "Content of map<int, int> test (Keys) before clear   : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   	testFile << "\nContent of map<int, int> test (Values) before clear : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->second << " |";

	test.clear();
	testFile << "\n\n";

	testFile << "\nSize of map<int, int> test after clear : " << test.size() << '\n';

	testFile << "Content of map<int, int> test (Keys) after clear   : ";
   	for (NS::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << it->first << " |";
	
	testFile << '\n';

   	testFile << "\nContent of map<int, int> test (Values) after clear : ";
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