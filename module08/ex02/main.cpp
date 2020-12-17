#include <stack>
#include <string>
#include <list>
#include <iostream>
#include "Mutantstack.hpp"

int main()
{
    //# T is int

    Mutantstack<int> mut;
    mut.push(2);
    mut.push(4);
    mut.push(8);
    Mutantstack<int>::iterator it = mut.begin();
    Mutantstack<int>::iterator ite = mut.end();
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
    Mutantstack<std::string> mut1;
    mut1.push("basile");
    mut1.push("brunet");
    mut1.push("student at 42");
    Mutantstack<std::string>::iterator it1 = mut1.begin();
    Mutantstack<std::string>::iterator ite1 = mut1.end();
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
    const Mutantstack<std::string> mut1_bis(mut1);
    Mutantstack<std::string>::const_iterator it2 = mut1_bis.begin(); // calls const begin() overlead
    Mutantstack<std::string>::const_iterator ite2 = mut1_bis.end();
    // *it2 = "Basileb"; // can't modify element trhough iterator
    while (it2 != ite2)
    {
        std::cout << *it2 << std::endl;
        ++it2;
    }

}