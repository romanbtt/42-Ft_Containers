/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_allocators.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:28:13 by romanbtt          #+#    #+#             */
/*   Updated: 2021/10/29 16:28:56 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../tests.hpp"

void	vector_get_allocator(char *argv)
{
    bool runAll = argv[4] == '1' ? true : false;
    std::ofstream testFile(DIFF, std::ios::out | std::ios::trunc);
	NS::vector<int> test;
	int * adress;

	testFile << "namespace::vector<int> test\n";
	testFile << "adress = test.get_allocator().allocate(10)\n";
	adress = test.get_allocator().allocate(10);
	for (size_t i = 0; i < 10; i++)
		test.get_allocator().construct(&adress[i], i);
	testFile << "Content of vector<int> test : ";
	for (size_t i = 0; i < 10; i++)
		testFile << "| " << adress[i] << " |";
	testFile << '\n';
	for (size_t i = 0; i < 10; i++)
		test.get_allocator().destroy(&adress[i]);
	test.get_allocator().deallocate(adress, 10);
    testFile.close();
    if (runAll == false)
    {
        std::ifstream file(DIFF);
        std::cout << file.rdbuf();
        file.close();
    }
}
