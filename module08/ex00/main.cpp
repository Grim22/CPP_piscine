
#include "list"
#include "vector"
#include "deque"
#include "iostream"

#include "easyfind.hpp"

int main()
{
    int test = 22;

    std::list<int> li;
    li.push_front(3);
    li.push_front(8);
    li.push_front(42);
    li.push_front(22);
    std::list<int>::const_iterator it_ret = easyfind<std::list<int> >(li, test);
    if (it_ret == li.end())
        std::cout << "not found\n";
    else
        std::cout << "found " << *it_ret << std::endl; 
    
    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(9);
    vec.push_back(42);
    std::vector<int>::const_iterator it_ret1 = easyfind<std::vector<int> >(vec, test);
    if (it_ret1 == vec.end())
        std::cout << "not found\n";
    else
        std::cout << "found " << *it_ret1 << std::endl;

    std::deque<int> deq;
    deq.push_back(10);
    deq.push_back(12);
    deq.push_back(14);
    deq.push_back(42);
    std::deque<int>::const_iterator it_ret2 = easyfind<std::deque<int> >(deq, test);
    if (it_ret2 == deq.end())
        std::cout << "not found" << std::endl;
    else
        std::cout << "found " << *it_ret2 << std::endl;

    
}