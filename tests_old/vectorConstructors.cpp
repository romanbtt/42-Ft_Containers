/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorConstructors.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:16:51 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/21 15:52:19 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.hpp"

static void printVectorConstructorsMenu( void )
{
    std::cout << FMAG("--- Vector Constructor menu ---") << std::endl;
    std::cout << FCYN("1") << FWHT(" - Default constructor") << std::endl;
    std::cout << FCYN("2") << FWHT(" - Fill constructor") << std::endl;
    std::cout << FCYN("3") << FWHT(" - Range constructor") << std::endl;
    std::cout << FCYN("4") << FWHT(" - Copy constructor") << std::endl;
    std::cout << FCYN("5") << FWHT(" - Operator =") << std::endl;
    std::cout << FGRN("A") << FWHT(" - All") << std::endl;
    std::cout << FYEL("B") << FWHT(" - Back") << std::endl;
    std::cout << FRED("E") << FWHT(" - Exit") << std::endl;
    std::cout << FBLU("Select a test : ");
}

bool    testVectorConstructors( void )
{
    std::string input;

    printVectorConstructorsMenu();
    while (std::getline(std::cin, input))
    {
        system("clear");
        if (!input.compare("1"))
            testVectorDefaultConstructor(true, "std", false);
        else if (!input.compare("2"))
            testVectorFillConstructor(true, "std", false);
        else if (!input.compare("3"))
            testVectorRangeConstructor(true, "std", false);
        else if (!input.compare("4"))
            testVectorCopyConstructor(true, "std", false);
        else if (!input.compare("5"))
            testVectorOperatorEqual(true, "std", false);
        else if (!input.compare("A") || !input.compare("a"))
            testVectorConstructorAll();
        else if (!input.compare("B") || !input.compare("b"))
            return (false);
        else if (!input.compare("E") || !input.compare("e"))
            return (true);
        else
            std::cout << FRED("Command not found!") << std::endl << std::endl;
        printVectorConstructorsMenu();
    }
    return (true);
}

void    testVectorConstructorAll( void )
{
    testVectorDefaultConstructor(true, "std", true);
    testVectorFillConstructor(true, "std", true);
    testVectorRangeConstructor(true, "std", true);
    testVectorCopyConstructor(true, "std", true);
    testVectorOperatorEqual(true, "std", true);
}

void    testVectorDefaultConstructor( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
    #define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Default Constructor ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
    NAMESPACE::vector<int> test;

    if (!all)
    {
        std::cout << "Default constructor namespace : " << ns << std::endl;
        std::cout << "Capacity of " << ns << " vector : " << test.capacity() << std::endl;
        std::cout << "Size of " << ns << " vector : " << test.size() << std::endl;
        std::cout << "Content of " << ns << " vector :" << std::endl;
        for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
            std::cout << "| " << *it << " |"; 
        std::cout << std::endl;
    }
    testFile << test.capacity() << "\n";
    testFile << test.size() << "\n";
    for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << *it << " |";
    testFile.close();
    if (isStd == true)
        testVectorDefaultConstructor(false, "ft", all);
    else
        compareFilesOutput();
    
}

void	testVectorFillConstructor( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
	#define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Fill Constructor ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
	NAMESPACE::vector<int> test(10, 42);

    if (!all)
    {
        std::cout << "Fill constructor namespace : " << ns << std::endl;
        std::cout << "Capacity of " << ns << " vector : " << test.capacity() << std::endl;
        std::cout << "Size of " << ns << " vector : " << test.size() << std::endl;
        std::cout << "Content of " << ns << " vector :" << std::endl;
        for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
            std::cout << "| " << *it << " |"; 
        std::cout << std::endl << std::endl;
    }
    testFile << test.capacity() << "\n";
    testFile << test.size() << "\n";
    for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << *it << " |";
    testFile.close();
    if (isStd == true)
        testVectorFillConstructor(false, "ft", all);
    else
        compareFilesOutput();
}

void	testVectorRangeConstructor( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
	#define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Range Constructor ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
	NAMESPACE::vector<int> range(10, 84);
	NAMESPACE::vector<int> test(range.begin(), range.end() - 5);

    if (!all)
    {
        std::cout << "Range constructor namespace : " << ns << std::endl;
        std::cout << "Capacity of " << ns << " vector : " << test.capacity() << std::endl;
        std::cout << "Size of " << ns << " vector : " << test.size() << std::endl;
        std::cout << "Content of " << ns << " vector :" << std::endl;
        for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
            std::cout << "| " << *it << " |"; 
        std::cout << std::endl << std::endl;
    }
    testFile << test.capacity() << "\n";
    testFile << test.size() << "\n";
    for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << *it << " |";
    testFile.close();
    if (isStd == true)
        testVectorRangeConstructor(false, "ft", all);
    else
        compareFilesOutput();
}

void	testVectorCopyConstructor( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
	#define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Copy Constructor ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
	NAMESPACE::vector<int> original(10, 1);
	for (size_t i = 0; i < original.size(); i++)
		original[i] += i;
	NAMESPACE::vector<int> test(original);

    if (!all)
    {
        std::cout << "Copy constructor namespace : " << ns << std::endl;
        std::cout << "Capacity of " << ns << " vector : " << test.capacity() << std::endl;
        std::cout << "Size of " << ns << " vector : " << test.size() << std::endl;
        std::cout << "Content of " << ns << " vector :" << std::endl;
        for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
            std::cout << "| " << *it << " |"; 
        std::cout << std::endl << std::endl;
    }
    testFile << test.capacity() << "\n";
    testFile << test.size() << "\n";
    for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << *it << " |";
    testFile.close();
    if (isStd == true)
        testVectorCopyConstructor(false, "ft", all);
    else
        compareFilesOutput();
}

void	testVectorOperatorEqual( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
	#define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Operator Equal ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
	NAMESPACE::vector<int> original(7, 1);
	for (size_t i = 0; i < original.size(); i++)
		original[i] += i * 2;
	NAMESPACE::vector<int> test = original;

    if (!all)
    {
        std::cout << "Operator = namespace : " << ns << std::endl;
        std::cout << "Capacity of " << ns << " vector : " << test.capacity() << std::endl;
        std::cout << "Size of " << ns << " vector : " << test.size() << std::endl;
        std::cout << "Content of " << ns << " vector :" << std::endl;
        for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
            std::cout << "| " << *it << " |"; 
        std::cout << std::endl << std::endl;
    }
    testFile << test.capacity() << "\n";
    testFile << test.size() << "\n";
    for (NAMESPACE::vector<int>::iterator it = test.begin(); it != test.end(); it++)
        testFile << "| " << *it << " |";
    testFile.close();
    if (isStd == true)
        testVectorOperatorEqual(false, "ft", all);
    else
        compareFilesOutput();
}