/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rar_constructors.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:57:48 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:30:20 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	random_access_reverse_copy_constructors(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test(10, 42);
    NS::vector<int>::reverse_iterator original = test.rbegin() + 5;
    NS::vector<int>::reverse_iterator copy(original);

    testFile << "NS::vector<int> test(10, 42)\n";
    testFile << "NS::vector<int>::reverse_iterator original = test.rbegin() + 5\n";
    testFile << "NS::vector<int>::reverse_iterator copy(original)\n\n";

    testFile << "original point to : " << *original << '\n';
    testFile << "copy point to : " << *copy << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}

void    random_access_reverse_default_constructors(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test(10, 42);
    NS::vector<int>::reverse_iterator it_test = test.rbegin();
    testFile << " namespace::vector<int> test(10, 42)\n";
    testFile << " namespace::vector<int>::reverse_iterator it_test = test.rbegin()\n\n";
    testFile << "it_test1 point to : " << *it_test << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    } 
}

void	random_access_reverse_operator_equal(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);

    NS::vector<int> test(10, 42);
    NS::vector<int>::reverse_iterator original = test.rbegin() + 5;
    NS::vector<int>::reverse_iterator copy = original;

    testFile << "NS::vector<int> test(10, 42)\n";
    testFile << "NS::vector<int>::reverse_iterator original = test.rbegin() + 5\n";
    testFile << "NS::vector<int>::reverse_iterator copy = original\n\n";

    testFile << "original point to : " << *original << '\n';
    testFile << "copy point to : " << *copy << '\n';
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
