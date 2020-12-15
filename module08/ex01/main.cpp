#include "Span.hpp"
#include "list"

// revoir les fonction shortest span: le span peut être calculé entre tous les membres

// faire une fonction qui rempli les containers d'ints (à l'aide de generate)

int main()
{
    Span sp(3);
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(12);
    vec.push_back(15);
    sp.addRange<std::vector<int> >(vec.begin(), vec.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span sp1(3);
    std::list<int> li;
    li.push_back(18);
    li.push_back(49);
    li.push_back(22);
    sp1.addRange<std::list<int> >(li.begin(), li.end());
    std::cout << sp1.shortestSpan() << std::endl;
    std::cout << sp1.longestSpan() << std::endl;
}