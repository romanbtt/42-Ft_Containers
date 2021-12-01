/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_capacity.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:34:05 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:29:14 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	map_empty(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int, int> test;

	testFile << std::boolalpha;
	testFile << "map<int, int> test\n";
    testFile << "map<int, int> test is empty ? : " << test.empty() << "\n\n";
    
    test.insert(NS::make_pair(1, 2));
	testFile << "test.insert(namespace::make_pair(1, 2);\n";

	testFile << "map<int, int> test is empty ? : " << test.empty() << '\n';

    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	map_max_size(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int, int> test;

	testFile << "map<int, int> test1\n";
    testFile << "Max size of map<int, int> test : " << test.max_size() << "\n";
    
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void	map_size(char *argv)
{
	bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::map<int, int> test1;
    NS::map<int, int> test2;

    test2.insert(NS::make_pair(2, 9));
    test2.insert(NS::make_pair(10, 86));
    test2.insert(NS::make_pair(14, 54));
    test2.insert(NS::make_pair(1, 8));
    test2.insert(NS::make_pair(8, 4));
    test2.insert(NS::make_pair(9, 0));
    test2.insert(NS::make_pair(2, 6));

    testFile << "map<int, int> test1\n";
    testFile << "Size of map<int, int> test1 : " << test1.size() << "\n\n";
    
    testFile << "namespace::map<int, int> test2\n";
	testFile << "Size of map<int> test2      : " << test2.size() << '\n';
    
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
