
#include <typeinfo>
#include <vector>
#include <iostream>
#include "./containers/vector.hpp"

template<typename T>
void test_insert()
{
    T capstd(10);
    std::cout << capstd.capacity() << std::endl;
    
    typename T::const_iterator std_it = capstd.begin();
    typename T::const_iterator std_end = capstd.end();
    capstd.insert(capstd.begin() + 3, 1);
    std::cout << typeid(std_end).name() << '\n';

    capstd.insert(capstd.begin() + 3, 1);
    while (std_it != std_end)
    {
        std::cout << *std_it << " | ";
        std_it++;
    }
    std::cout << std::endl;
    for (typename T::const_iterator it = capstd.begin(); it != capstd.end(); it += 1)
        std::cout << *it << " | ";
    std::cout << std::endl;
	std::cout << capstd.capacity() << std::endl;
}

int main(void)
{
    test_insert< std::vector<int> >();
    test_insert< ft::vector<int> >();
}