/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterators.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:21:31 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/22 15:22:35 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.hpp"

static void	printVectorIteratorsMenu( void )
{
    std::cout << FMAG("--- Vector Iterator menu ---") << std::endl;
    std::cout << FCYN("1") << FWHT(" - Begin") << std::endl;
    std::cout << FCYN("2") << FWHT(" - End") << std::endl;
    std::cout << FCYN("3") << FWHT(" - Rbegin") << std::endl;
    std::cout << FCYN("4") << FWHT(" - Rend") << std::endl;
    std::cout << FGRN("A") << FWHT(" - All") << std::endl;
    std::cout << FYEL("B") << FWHT(" - Back") << std::endl;
    std::cout << FRED("E") << FWHT(" - Exit") << std::endl;
    std::cout << FBLU("Select a test : ");
}

bool    testVectorIterators( void )
{
    std::string input;

	printVectorIteratorsMenu();
    while (std::getline(std::cin, input))
    {
        system("clear");
        if (!input.compare("1"))
            testVectorIteratorBegin(true, "std", false);
        else if (!input.compare("2"))
            testVectorIteratorEnd(true, "std", false);
        else if (!input.compare("3"))
           testVectorIteratorRbegin(true, "std", false);
        else if (!input.compare("4"))
            testVectorIteratorRend(true, "std", false);
        else if (!input.compare("A") || !input.compare("a"))
            testVectorIteratorAll();
        else if (!input.compare("B") || !input.compare("b"))
            return (false);
        else if (!input.compare("E") || !input.compare("e"))
            return (true);
        else
            std::cout << FRED("Command not found!") << std::endl << std::endl;
		printVectorIteratorsMenu();
    }
    return (true);
}

void    testVectorIteratorAll( void )
{
    testVectorIteratorBegin(true, "std", true);
    testVectorIteratorEnd(true, "std", true);
    testVectorIteratorRbegin(true, "std", true);
    testVectorIteratorRend(true, "std", true);
}

void    testVectorIteratorBegin( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
    #define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Iterator Begin ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
    NAMESPACE::vector<int> vec(10, 1);
	for (size_t i = 0; i < vec.size(); i++)
		vec[i] += i;

    if (!all)
    {
		std::cout << "Iterator Begin namespace : " << ns << std::endl << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << "| " << *it << " |";
		std::cout << std::endl << std::endl;
        std::cout << "Iterator Begin namespace : " << ns << std::endl;
        std::cout << "Begin of " << ns << " iterator : " << *(vec.begin()) << std::endl;
		std::cout << "Begin + 4 of " << ns << " iterator : " << *(vec.begin() + 4) << std::endl;
        std::cout << std::endl;
    }
    testFile << *(vec.begin()) << "\n";
    testFile << *(vec.begin() + 4) << "\n";
    testFile.close();
    if (isStd == true)
        testVectorIteratorBegin(false, "ft", all);
    else
        compareFilesOutput();
}

void    testVectorIteratorEnd( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
    #define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Iterator End ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
    NAMESPACE::vector<int> vec(10, 1);
	for (size_t i = 0; i < vec.size(); i++)
		vec[i] += i;

    if (!all)
    {
		std::cout << "Iterator End namespace : " << ns << std::endl << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << "| " << *it << " |";
		std::cout << std::endl << std::endl;
        std::cout << "End - 1 of " << ns << " iterator : " << *(vec.end() - 1) << std::endl;
		std::cout << "End - 4 of " << ns << " iterator : " << *(vec.end() - 4) << std::endl;
        std::cout << std::endl;
    }
    testFile << *(vec.end() - 1) << "\n";
    testFile << *(vec.end() - 4) << "\n";
    testFile.close();
    if (isStd == true)
        testVectorIteratorEnd(false, "ft", all);
    else
        compareFilesOutput();
}

void    testVectorIteratorRbegin( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
    #define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Iterator Rbegin ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
    NAMESPACE::vector<int> vec(10, 1);
	for (size_t i = 0; i < vec.size(); i++)
		vec[i] += i;

    if (!all)
    {
        std::cout << "Iterator Rbegin namespace : " << ns << std::endl << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << "| " << *it << " |";
		std::cout << std::endl << std::endl;
        std::cout << "Rbegin of " << ns << " iterator : " << *(vec.rbegin()) << std::endl;
		std::cout << "Rbegin + 4 of " << ns << " iterator : " << *(vec.rbegin() + 4) << std::endl;
        std::cout << std::endl;
    }
    testFile << *(vec.rbegin()) << "\n";
    testFile << *(vec.rbegin() + 4) << "\n";
    testFile.close();
    if (isStd == true)
        testVectorIteratorRbegin(false, "ft", all);
    else
        compareFilesOutput();
}

void    testVectorIteratorRend( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
    #define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Iterator Rend ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
    NAMESPACE::vector<int> vec(10, 1);
	for (size_t i = 0; i < vec.size(); i++)
		vec[i] += i;

    if (!all)
    {
        std::cout << "Iterator Rend namespace : " << ns << std::endl << std::endl;
		for (NAMESPACE::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
            std::cout << "| " << *it << " |";
		std::cout << std::endl << std::endl;
        std::cout << "Rend - 1 of " << ns << " iterator : " << *(vec.rend() - 1) << std::endl;
		std::cout << "Rend - 4 of " << ns << " iterator : " << *(vec.rend() - 4) << std::endl;
        std::cout << std::endl;
    }
    testFile << *(vec.rend() - 1) << "\n";
    testFile << *(vec.rend() - 4) << "\n";
    testFile.close();
    if (isStd == true)
        testVectorIteratorRend(false, "ft", all);
    else
        compareFilesOutput();
}