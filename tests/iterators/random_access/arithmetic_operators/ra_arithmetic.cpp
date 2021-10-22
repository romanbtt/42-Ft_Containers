/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_arithmetic.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/20 14:53:12 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	random_access_compound(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::vector<int> test(10, 1);

    testFile << "Content of vector<int> : ";
	for (size_t i = 0; i < test.size(); i++)
	{
        test[i] *= i;
        testFile << "| " << test[i] << " |";
    }
    testFile << "\n\n";

    NS::vector<int>::iterator it_test = test.begin();
    testFile << "namespace::vector<int>::iterator it_test = test.begin()\n\n";
    testFile << "*(it_test += 3) : " << *(it_test += 3) << '\n';
	testFile << "*(it_test += 6) : " << *(it_test += 6) << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	random_access_decrement(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::vector<int> test(10, 1);

    testFile << "Content of vector<int> : ";
	for (size_t i = 0; i < test.size(); i++)
	{
        test[i] *= i;
        testFile << "| " << test[i] << " |";
    }
    testFile << "\n\n";

    NS::vector<int>::iterator it_test = test.end();
    testFile << "namespace::vector<int>::iterator it_test = test.end()\n\n";
    testFile << "*(--it_test) : " << *(--it_test) << '\n';
	testFile << "*(it_test--) : " << *(it_test--) << '\n';
	testFile << "*it_test-- : " << *it_test-- << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	random_access_increment(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::vector<int> test(10, 1);

    testFile << "Content of vector<int> : ";
	for (size_t i = 0; i < test.size(); i++)
	{
        test[i] *= i;
        testFile << "| " << test[i] << " |";
    }
    testFile << "\n\n";

    NS::vector<int>::iterator it_test = test.begin();
    testFile << "namespace::vector<int>::iterator it_test = test.begin()\n\n";
    testFile << "*(++it_test) : " << *(++it_test) << '\n';
	testFile << "*(it_test++) : " << *(it_test++) << '\n';
	testFile << "*it_test++ : " << *it_test++ << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	random_access_minus(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::vector<int> test(10, 1);

    testFile << "Content of vector<int> : ";
	for (size_t i = 0; i < test.size(); i++)
	{
        test[i] *= i;
        testFile << "| " << test[i] << " |";
    }
    testFile << "\n\n";

    NS::vector<int>::iterator it_test1 = test.end();
    testFile << "namespace::vector<int>::iterator it_test1 = test.end()\n";
	    NS::vector<int>::iterator it_test2 = test.end() - 5;
    testFile << "namespace::vector<int>::iterator it_test2 = test.end() - 5\n\n";
	it_test1 = it_test1 - 2;
    testFile << "it_test1 = it_test1 - 2 : " << *it_test1  << '\n';
	*it_test1 = it_test1 - it_test2;
	testFile << "*it_test1 = it_test1 - it_test2 : " << *it_test1 << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	random_access_plus(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
    NS::vector<int> test(10, 1);

    testFile << "Content of vector<int> : ";
	for (size_t i = 0; i < test.size(); i++)
	{
        test[i] *= i;
        testFile << "| " << test[i] << " |";
    }
    testFile << "\n\n";

    NS::vector<int>::iterator it_test1 = test.begin();
    testFile << "namespace::vector<int>::iterator it_test1 = test.begin()\n";
	    NS::vector<int>::iterator it_test2 = test.begin() + 5;
    testFile << "namespace::vector<int>::iterator it_test2 = test.begin() + 5\n\n";
	it_test1 = it_test1 + 2;
    testFile << "it_test1 = it_test1 + 2 : " << *it_test1 << '\n';
	it_test1 = 3 + it_test2;
	testFile << "it_test1 = 3 + it_test2 : " << *it_test1 << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
