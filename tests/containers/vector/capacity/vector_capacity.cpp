/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_capacity.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 19:04:00 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:28:37 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_capacity(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test1;
    NS::vector<int> test2(10, 42);
	
	testFile << "namespace::vector<int> test1\n";
	testFile << "Capacity of vector<int> test1 : " << test1.capacity() << "\n\n";
	testFile << "namespace::vector<int> test2(10, 42)\n";
	testFile << "Capacity of vector<int> test2 : " << test2.capacity() << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	vector_empty(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test1;
    NS::vector<int> test2(10, 42);

	testFile << std::boolalpha;
	testFile << "namespace::vector<int> test1\n";
    testFile << "vector<int> test1 is empty ? : " << test1.empty() << "\n\n";
	testFile << "namespace::vector<int> test2(10, 42)\n";
	testFile << "vector<int> test2 is empty ? : " << test2.empty() << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	vector_max_size(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test1;
    NS::vector<int> test2(10, 42);

	testFile << "namespace::vector<int> test1\n";
    testFile << "Max size of vector<int> test1 : " << test1.max_size() << "\n\n";
	testFile << "namespace::vector<int> test2(10, 42)\n";
	testFile << "Max size of vector<int> test2 : " << test2.max_size() << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	vector_reserve(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test(10, 42);
	testFile << "namespace::vector<int> test(10, 42)\n";

    testFile << "Size of vector<int> before reserve : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before reserve : " << test.capacity() << '\n';
	testFile << "\ntest.reserve(84)\n";
	test.reserve(84);
	testFile << "Size of vector<int> after reserve : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after reserve : " << test.capacity() << '\n';
	testFile << "\ntest.reserve(42)\n";
	test.reserve(42);
	testFile << "Size of vector<int> after reserve : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after reserve : " << test.capacity() << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	vector_resize(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test(5, 42);

	testFile << "namespace::vector<int> test(5, 42)\n";
    testFile << "Size of vector<int> before resize : " << test.size() << '\n';
	testFile << "Capacity of vector<int> before resize : " << test.capacity() << '\n';
	testFile << "Content of vector<int> before resize : ";
    for (NS::vector<int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << *it << " |";
	testFile << "\n\ntest.resize(10, 84)\n";
	test.resize(10, 84);
	testFile << "Size of vector<int> after resize : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after resize : " << test.capacity() << '\n';
	testFile << "Content of vector<int> after resize : ";
	for (NS::vector<int>::iterator it = test.begin(); it != test.end(); it++)
       testFile << "| " << *it << " |";
	test.resize(2);
	testFile << "\n\ntest.resize(2)\n";
	testFile << "Size of vector<int> after resize : " << test.size() << '\n';
	testFile << "Capacity of vector<int> after resize : " << test.capacity() << '\n';
	testFile << "Content of vector<int> after resize : ";
    for (NS::vector<int>::iterator it = test.begin(); it != test.end(); it++)
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

void	vector_size(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test1;
    NS::vector<int> test2(10, 42);

    testFile << "namespace::vector<int> test1\n";
    testFile << "Size of vector<int> test1 : " << test1.size() << "\n\n";
    testFile << "namespace::vector<int> test2(10, 42)\n";
	testFile << "Size of vector<int> test2 : " << test2.size() << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
