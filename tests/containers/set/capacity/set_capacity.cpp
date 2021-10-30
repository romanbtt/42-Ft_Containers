/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_capacity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:34:05 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:29:50 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	set_empty(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::set<int> test;

	testFile << std::boolalpha;
	testFile << "set<int> test\n";
    testFile << "set<int> test is empty ? : " << test.empty() << "\n\n";
    
    test.insert(2);
	testFile << "test.insert(2);\n";

	testFile << "set<int> test is empty ? : " << test.empty() << '\n';

    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	set_max_size(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::set<int> test;

	testFile << "set<int> test\n";
    testFile << "Max size of set<int> test : " << test.max_size() << "\n";
    
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	set_size(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::set<int> test1;
    NS::set<int> test2;

    test2.insert(2);
    test2.insert(10);
    test2.insert(14);
    test2.insert(1);
	test2.insert(9);
    test2.insert(8);
    test2.insert(9);
    test2.insert(2);
	test2.insert(14);

    testFile << "set<int> test1\n";
    testFile << "Size of set<int> test1 : " << test1.size() << "\n\n";
    
    testFile << "namespace::set<int> test2\n";
	testFile << "Size of set<int> test2 : " << test2.size() << '\n';
    
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
