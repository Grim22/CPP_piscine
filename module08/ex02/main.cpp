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

    Mutantstack mut;
    mut.push(2);
    mut.push(4);
    mut.push(8);
    // while (!mut.empty())
    // {
    //     std::cout << mut.top() << std::endl;
    //     mut.pop();
    // }
    std::deque<int>::iterator it;
    for (it = mut.begin(); it != mut.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    

}