/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorCapacity.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romanbtt <marvin@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:07:20 by romanbtt          #+#    #+#             */
/*   Updated: 2021/09/23 18:05:08 by romanbtt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.hpp"

static void	printVectorCapacityMenu( void )
{
	std::cout << FMAG("--- Vector Capacity menu ---") << std::endl;
    std::cout << FCYN("1") << FWHT(" - Size") << std::endl;
    std::cout << FCYN("2") << FWHT(" - Max_size") << std::endl;
    std::cout << FCYN("3") << FWHT(" - Resize") << std::endl;
    std::cout << FCYN("4") << FWHT(" - Capacity") << std::endl;
    std::cout << FCYN("5") << FWHT(" - Empty") << std::endl;
	std::cout << FCYN("6") << FWHT(" - Reserve") << std::endl;
    std::cout << FGRN("A") << FWHT(" - All") << std::endl;
    std::cout << FYEL("B") << FWHT(" - Back") << std::endl;
    std::cout << FRED("E") << FWHT(" - Exit") << std::endl;
    std::cout << FBLU("Select a test : ");
}

bool    testVectorCapacity( void )
{
    std::string input;
	
	printVectorCapacityMenu();
    while (std::getline(std::cin, input))
    {
        system("clear");
        if (!input.compare("1"))
            testVectorSize(true, "std", false);
        else if (!input.compare("2"))
            testVectorMaxSize(true, "std", false);
        else if (!input.compare("3"))
            testVectorResize(true, "std", false);
        else if (!input.compare("4"))
            testVectorCapacity(true, "std", false);
        else if (!input.compare("5"))
            testVectorEmpty(true, "std", false);
		//else if (!input.compare("5"))
        //    testVectorReserve(true, "std", false);
        //else if (!input.compare("A") || !input.compare("a"))
        //    testVectorConstructorAll();
        else if (!input.compare("B") || !input.compare("b"))
            return (false);
        else if (!input.compare("E") || !input.compare("e"))
            return (true);
        else
            std::cout << FRED("Command not found!") << std::endl << std::endl;
		printVectorCapacityMenu();
    }
    return (true);
}

void    testVectorSize( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
    #define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Vector Size ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
    NAMESPACE::vector<int> test1;
	NAMESPACE::vector<int> test2(10, 10);

    if (!all)
    {
        std::cout << "Namespace : " << ns << std::endl;
        std::cout << "Size of " << ns << " vector test 1 : " << test1.size() << std::endl;
		std::cout << "Size of " << ns << " vector test 2 : " << test2.size() << std::endl;
        std::cout << std::endl;
    }
    testFile << test1.size() << "\n";
	testFile << test2.size() << "\n";
    testFile.close();
    if (isStd == true)
        testVectorSize(false, "ft", all);
    else
        compareFilesOutput();
}

void    testVectorMaxSize( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
    #define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Vector Max Size ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
    NAMESPACE::vector<int> test;

    if (!all)
    {
        std::cout << "Namespace : " << ns << std::endl;
        std::cout << "Size of " << ns << " vector : " << test.max_size() << std::endl;
        std::cout << std::endl;
    }
    testFile << test.max_size() << "\n";
    testFile.close();
    if (isStd == true)
        testVectorMaxSize(false, "ft", all);
    else
        compareFilesOutput();
}

void    testVectorResize( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
    #define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Vector Resize ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
    NAMESPACE::vector<int> test;
    NAMESPACE::vector<int> testAll;
    

    if (!all)
    {
        std::cout << "Namespace : " << ns << std::endl;
        std::cout << "Before Resize() : " << std::endl;
        std::cout << "Size of " << ns << " vector : " << test.size() << std::endl;
        std::cout << "Capacity of " << ns << " vector : " << test.capacity() << std::endl;
        test.resize(158);
        std::cout << "After Resize() : " << std::endl;
        std::cout << "Size of " << ns << " vector : " << test.size() << std::endl;
        std::cout << "Capacity of " << ns << " vector : " << test.capacity() << std::endl;
        std::cout << std::endl;
    }
    testFile << testAll.size() << "\n";
    testFile << testAll.capacity() << "\n";
    testAll.resize(158);
    testFile << testAll.size() << "\n";
    testFile << testAll.capacity() << "\n";
    testFile.close();
    if (isStd == true)
        testVectorResize(false, "ft", all);
    else
        compareFilesOutput();
}

void    testVectorCapacity( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
    #define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Vector Capacity ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
    NAMESPACE::vector<int> test1;
    NAMESPACE::vector<int> test2(12568, 56);

    if (!all)
    {
        std::cout << "Namespace : " << ns << std::endl;
        std::cout << "Capacity of " << ns << " vector test 1 : " << test1.capacity() << std::endl;
        std::cout << "Capacity of " << ns << " vector test 2 : " << test2.capacity() << std::endl;
        std::cout << std::endl;
    }
    testFile << test1.capacity() << "\n";
    testFile << test2.capacity() << "\n";
    testFile.close();
    if (isStd == true)
        testVectorCapacity(false, "ft", all);
    else
        compareFilesOutput();
}

void    testVectorEmpty( bool isStd, std::string ns, bool all )
{
	#undef NAMESPACE
    #define NAMESPACE ft
    if (isStd)
    {
        #undef NAMESPACE
        #define NAMESPACE std
        std::cout << FBLU("--- Test Vector Empty ---\n") << std::endl;
    }

    std::ofstream testFile(ns.c_str(), std::ios::out | std::ios::trunc);
    NAMESPACE::vector<int> test1;
    NAMESPACE::vector<int> test2(12568, 56);

    if (!all)
    {
        std::cout << "Namespace : " << ns << std::endl;
        std::cout << "Capacity of " << ns << " vector test 1 : " << test1.empty() << std::endl;
        std::cout << "Capacity of " << ns << " vector test 2 : " << test2.empty() << std::endl;
        std::cout << std::endl;
    }
    testFile << test1.empty() << "\n";
    testFile << test2.empty() << "\n";
    testFile.close();
    if (isStd == true)
        testVectorEmpty(false, "ft", all);
    else
        compareFilesOutput();
}