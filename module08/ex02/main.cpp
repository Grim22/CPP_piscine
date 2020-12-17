#include <stack>
#include <string>
#include <list>
#include <iostream>
#include "Mutantstack.hpp"

int main()
{
    //# T is int

    MutantStack<int> mut;
    mut.push(2);
    mut.push(4);
    mut.push(8);
    MutantStack<int>::iterator it = mut.begin();
    MutantStack<int>::iterator ite = mut.end();
    ++it;
    --it;
    *it = 12;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> st(mut);
    std::cout << "---" << std::endl;

    // T is string
    MutantStack<std::string> mut1;
    mut1.push("basile");
    mut1.push("brunet");
    mut1.push("student at 42");
    MutantStack<std::string>::iterator it1 = mut1.begin();
    MutantStack<std::string>::iterator ite1 = mut1.end();
    it1++;
    it1--;
    *it1 = "Basileb"; // can modify element through iterator
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    std::cout << "---" << std::endl;

    // try const_iterator
    const MutantStack<std::string> mut1_bis(mut1);
    MutantStack<std::string>::const_iterator it2 = mut1_bis.begin(); // calls const begin() overlead
    MutantStack<std::string>::const_iterator ite2 = mut1_bis.end();
    // *it2 = "Basileb"; // can't modify element trhough iterator
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }

}

// int main()
// {
// MutantStack<int> mstack;
// mstack.push(5);
// mstack.push(17);
// std::cout << mstack.top() << std::endl;
// mstack.pop();
// std::cout << mstack.size() << std::endl;
// mstack.push(3);
// mstack.push(5);
// mstack.push(737);
// //[...]
// mstack.push(0);
// MutantStack<int>::iterator it = mstack.begin();
// MutantStack<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::stack<int> s(mstack);
// return 0;
// }