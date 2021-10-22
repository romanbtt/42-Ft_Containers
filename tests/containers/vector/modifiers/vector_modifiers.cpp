/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_modifiers.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:59:51 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 14:49:26 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_assign(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::vector<int> range(5, 1);
	NS::vector<int> test;

	testFile << "Content of vector<int> range : ";
	for (size_t i = 0; i < range.size(); i++)
	{
		range[i] += i;
		testFile << "| " << range[i] << " |";
	}
	testFile << "\n\nnamespace::vector<int> test\n";
    testFile << "Size of vector<int> before assign : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before assign : " << test.capacity() << '\n';
	testFile << "\ntest.assign(range.begin(), range.end())\n";
	test.assign(range.begin(), range.end());
	testFile << "Size of vector<int> after assign : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after assign : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << "\n\ntest.assign(10, 42)\n";
	test.assign(10, 42);
	testFile << "Size of vector<int> after assign : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after assign : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	vector_clear(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
	NS::vector<int> test(10, 1);

	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
	{
		test[i] *= i;
		testFile << "| " << test[i] << " |";
	}
	testFile << "\nSize of vector<int> test before clear : " << test.size() << '\n';
	testFile << "Capacity of vector<int> test before clear : " << test.capacity() << '\n';
	testFile << "\ntest.clear(test2)\n";
	test.clear();
	testFile << "Size of vector<int> test after clear : " << test.size() << '\n';
	testFile << "Capacity of vector<int> test after clear : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	vector_erase(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
	NS::vector<int> test(10, 1);
	NS::vector<int>::iterator ret;

	for (size_t i = 0; i < test.size(); i++)
		test[i] += i;
	testFile << "namespace::vector<int> test\n";
    testFile << "Size of vector<int> before erase : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before erase : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << "\n\ntest.erase(test.begin() + 5)\n";
	ret = test.erase(test.begin() + 5);
	testFile << "Size of vector<int> after erase : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after erase : " << test.capacity() << '\n';
	testFile << "Return value : " << *ret << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	
	testFile << "\n\ntest.erase(test.begin() + 2, test.end() - 2)\n";
	ret = test.erase(test.begin() + 2, test.end() - 2);
	testFile << "Size of vector<int> after erase : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after erase : " << test.capacity() << '\n';
	testFile << "Return value : " << *ret << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	vector_insert(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
	NS::vector<int> range(10, 1);
	NS::vector<int> test;

	testFile << "Content of vector<int> range : ";
	for (size_t i = 0; i < range.size(); i++)
	{
		range[i] += i;
		testFile << "| " << range[i] << " |";
	}
	testFile << "\n\nnamespace::vector<int> test\n";
    testFile << "Size of vector<int> before insert : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before insert : " << test.capacity() << '\n';
	testFile << "\ntest.insert(test.begin(), range.begin(), range.end())\n";
	test.insert(test.begin(), range.begin(), range.end());
	testFile << "Size of vector<int> after insert : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after insert : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << "\n\ntest.insert(test.begin() + 5, 5, 42)\n";
	test.insert(test.begin() + 5, 5, 42);
	testFile << "Size of vector<int> after insert : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after insert : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << "\n\ntest.insert(test.begin() + 10, 1000)\n";
	test.insert(test.begin() + 10, 1000);
	testFile << "Size of vector<int> after insert : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after insert : " << test.capacity() << '\n';
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		testFile << "| " << test[i] << " |";
	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

static void	print_vector_pop(std::ofstream & file, NS::vector<int> & test)
{
	file << "\ntest.pop_back()\n";
	test.pop_back();
	file << "Size of vector<int> after pop_back : " << test.size() << '\n';
	file << "Capacity of vector<int> after pop_back : " << test.capacity() << '\n';
	file << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		file << "| " << test[i] << " |";
	file << "\n";
}

void	vector_pop_back(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
	NS::vector<int> test(5, 1);

	testFile << "Content of vector<int> : ";
	for (size_t i = 0; i < test.size(); i++)
	{
		test[i] += i;
		testFile << "| " << test[i] << " |";
	}
    testFile << "\nSize of vector<int> before pop_back : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before pop_back : " << test.capacity() << '\n';
	print_vector_pop(testFile, test);
	testFile << *test.end() << "\n";
	print_vector_pop(testFile, test);
	testFile << *test.end() << "\n";
	print_vector_pop(testFile, test);
	testFile << *test.end() << "\n";
	print_vector_pop(testFile, test);
	testFile << *test.end() << "\n";
	print_vector_pop(testFile, test);
	testFile << *test.end() << "\n";
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

static void	print_vector_push(std::ofstream & file, NS::vector<int> & test, int val)
{
	file << "\ntest.push_back(" << val << ")\n";
	test.push_back(val);
	file << "Size of vector<int> after push_back : " << test.size() << '\n';
	file << "Capacity of vector<int> after push_back : " << test.capacity() << '\n';
	file << "Content of vector<int> test : ";
	for (size_t i = 0; i < test.size(); i++)
		file << "| " << test[i] << " |";
	file << "\n";
}

void	vector_push_back(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
	NS::vector<int> test;

	testFile << "namespace::vector<int> test\n";
    testFile << "Size of vector<int> before push_back : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before push_back : " << test.capacity() << '\n';
	print_vector_push(testFile, test, 1);
	print_vector_push(testFile, test, 2);
	print_vector_push(testFile, test, 4);
	print_vector_push(testFile, test, 8);
	print_vector_push(testFile, test, 16);
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	vector_swap(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
	NS::vector<int> test1(10, 1);
	NS::vector<int> test2(5, 3);

	testFile << "Content of vector<int> test1 : ";
	for (size_t i = 0; i < test1.size(); i++)
	{
		test1[i] *= i;
		testFile << "| " << test1[i] << " |";
	}
	testFile << "\nSize of vector<int> test1 before swap : " << test1.size() << '\n';
	testFile << "Capacity of vector<int> test1 before swap : " << test1.capacity() << '\n';
	testFile << "\nContent of vector<int> test2 : ";
	for (size_t i = 0; i < test2.size(); i++)
	{
		test2[i] *= i;
		testFile << "| " << test2[i] << " |";
	}
	testFile << "\nSize of vector<int> test2 before swap : " << test2.size() << '\n';
	testFile << "Capacity of vector<int> test2 before swap : " << test2.capacity() << '\n';
	testFile << "\ntest1.swap(test2)\n";
	test1.swap(test2);
	testFile << "Size of vector<int> test1 after swap : " << test1.size() << '\n';
	testFile << "Capacity of vector<int> test1 after swap : " << test1.capacity() << '\n';
	testFile << "Content of vector<int> test1 : ";
	for (size_t i = 0; i < test1.size(); i++)
		testFile << "| " << test1[i] << " |";
	testFile << "\n\nSize of vector<int> test2 after swap : " << test2.size() << '\n';
	testFile << "Capacity of vector<int> test2 after swap : " << test2.capacity() << '\n';
	testFile << "Content of vector<int> test1 : ";
	for (size_t i = 0; i < test2.size(); i++)
		testFile << "| " << test2[i] << " |";
	testFile << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}