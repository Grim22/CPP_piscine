#include <stack>
#include <string>
#include <list>
#include <iostream>
#include "Mutantstack.hpp"

int main()
{
    // std::stack<std::string, std::list<std::string> > st;
    // st.push("basile");
    // st.push("brunet");
    // st.push("venance");
    // st.top() += "des maz";
    // while (!st.empty())
    // {
    //     std::cout << st.top() << std::endl;
    //     st.pop();
    // }

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
    Mutantstack<std::string> mut1;
    mut1.push("basile");
    mut1.push("brunet");
    mut1.push("student at 42");
    Mutantstack<std::string>::iterator it1 = mut1.begin();
    Mutantstack<std::string>::iterator ite1 = mut1.end();
    it1++;
    it1--;
    while (it1 != ite1)
    {
        std::cout << *it1 << std::endl;
        ++it1;
    }
    Mutantstack<std::string> mut1_bis;
    mut1_bis = mut1;
    std::cout << mut1_bis.top() << std::endl;


}