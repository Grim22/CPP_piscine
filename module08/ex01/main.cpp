#include "Span.hpp"
#include "list"
#include "deque"
#include <cstdlib> // std::rand std::srand
#include <ctime> // std::time

int get_random_int(void)
{
    return (rand() % 2000);
}

int main()
{
    std::srand(time(NULL));

    // check for errors
    // #0
    Span sp00(5);
    try
    {
        sp00.shortestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // #1
    Span sp01(5);
    sp01.addNumber(12);
    try
    {
        sp01.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // #2
    Span sp02(1);
    sp02.addNumber(12);
    try
    {
        sp02.addNumber(42);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "----" << std::endl;

    // use addNumber(int) to fill span
    Span sp(5);
    sp.addNumber(12);
    sp.addNumber(-12);
    sp.addNumber(0);
    sp.addNumber(42);
    sp.addNumber(122);
    std::cout << "shortest span is: " << sp.shortestSpan() << std::endl;
    std::cout << "longest span is: " << sp.longestSpan() << std::endl;
    std::cout << "----" << std::endl;

    // use addRange<std::list>(it begin, it end) to fill span
    // create a list li "manually"
    std::list<int> li;
    li.push_back(50);
    li.push_back(18);
    li.push_back(49);
    li.push_back(22);
    Span sp1(4);
    sp1.addRange<std::list<int> >(li.begin(), li.end());
    std::cout << "shortest span is: " << sp1.shortestSpan() << std::endl;
    std::cout << "longest span is: " << sp1.longestSpan() << std::endl;
    std::cout << "----" << std::endl;

    // use addRange<std::deque>(it begin, it end) to fill span
    // create deque with std::generate
    std::deque<int> deq(1000);
    std::generate(deq.begin(), deq.end(), get_random_int);
    Span sp2(1000);
    sp2.addRange<std::deque<int> >(deq.begin(), deq.end());
    std::cout << "shortest span is: " << sp2.shortestSpan() << std::endl;
    std::cout << "longest span is: " << sp2.longestSpan() << std::endl;

}