/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tests.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:25:41 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 20:11:24 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../tests.hpp"

void	stack_constructor(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::vector<int> t_vector(10, 42);
	NS::stack<int, NS::vector<int> > empty;
	NS::stack<int, NS::vector<int> > copy(t_vector);

	testFile << "NS::vector<int> t_vector(10, 42)\n";
	testFile << "NS::stack<int, NS::vector<int> > empty\n";
	testFile << "NS::stack<int, NS::vector<int> > copy(t_vector)\n\n";

	testFile << "Size of t_vector : " << t_vector.size() << "\n";
	testFile << "Size of empty    : " << empty.size() << "\n";
	testFile << "Size of copy     : " << copy.size() << "\n";

    testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    } 
}

void	stack_empty(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::vector<int> t_vector(10, 42);
	NS::stack<int, NS::vector<int> > test1;
	NS::stack<int, NS::vector<int> > test2(t_vector);

	testFile << "NS::vector<int> t_vector(10, 42)\n";
	testFile << "NS::stack<int, NS::vector<int> > test1\n";
	testFile << "NS::stack<int, NS::vector<int> > test2(t_vector)\n\n";

	testFile << std::boolalpha;
	testFile << "test1 is empty ? : " << test1.empty() << "\n";
	testFile << "test2 is empty ? : " << test2.empty() << "\n";

    testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    } 
}

void	stack_size(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::vector<int> t_vector(100, 42);
	NS::stack<int, NS::vector<int> > empty;
	NS::stack<int, NS::vector<int> > copy(t_vector);

	testFile << "NS::vector<int> t_vector(100, 42)\n";
	testFile << "NS::stack<int, NS::vector<int> > empty\n";
	testFile << "NS::stack<int, NS::vector<int> > copy(t_vector)\n\n";

	testFile << "Size of t_vector : " << t_vector.size() << "\n";
	testFile << "Size of empty    : " << empty.size() << "\n";
	testFile << "Size of copy     : " << copy.size() << "\n";

    testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    } 
}

void	stack_top(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::stack<int, NS::vector<int> > test;

	for (int i = 10; i < 15; i++)
		test.push(i);

	testFile << "Top of stack is : " << test.top() << "\n";

    testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    } 
}

void	stack_push(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::stack<int, NS::vector<int> > test;

	testFile << "Content of stack is : | ";

	for (int i = 10; i < 30; i++)
	{
		test.push(i);
		testFile << test.top() << " | ";
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

void	stack_pop(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

	NS::stack<int, NS::vector<int> > test;

	testFile << "Content of stack before pop is : | ";

	for (int i = 0; i < 10; i++)
	{
		test.push(i);
		testFile << test.top() << " | ";
	}

	testFile << "\nPrint then Pop                 : | ";

	while (test.empty() == false)
	{
		testFile << test.top() << " | ";
		test.pop();
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

void	stack_relational_operators(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::stack<int, NS::vector<int> > test1;
    NS::stack<int, NS::vector<int> > test2;

	testFile << "NS::stack<int> test1\n";
    testFile << "Content of vector<int>'s test1 : ";
    for (int i = 0; i < 10; i++)
    {
		test1.push(i);
		testFile << "| " << test1.top() << " |";
	}   
	testFile << "\n\nNS::stack<int> test2\n";
	testFile << "Content of vector<int>'s test1 : ";
    for (int i = 10; i < 20; i++)
    {
		test2.push(i);
		testFile << "| " << test2.top() << " |";
	}   
	testFile << "\n\n";
	if (test1 == test2)
		testFile << "test1 and test2 are equal.\n";
  	if (test1 != test2)
	  	testFile << "test1 and test2 are not equal.\n";
  	if (test1 < test2)
	  	testFile << "test1 is less than test2.\n";
  	if (test1 > test2)
	  	testFile << "test1 is greater than test2.\n";
  	if (test1 <= test2)
	  	testFile << "test1 is less than or equal to test2.\n";
  	if (test1 >= test2)
	  	testFile << "test1 is greater than or equal to test2.\n";
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
