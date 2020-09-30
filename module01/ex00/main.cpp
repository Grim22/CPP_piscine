#include "Pony.hpp"
#include <iostream>

int main()
{
    Pony jolly("black", "jolly", "argentina", "carrots", 3);
    Pony *jumper;

    jumper = new Pony("white", "jumper", "USA", "pastas", 2);
    if (jolly.get_age() > jumper->get_age())
        std::cout << "jolly is older than jumper" << std::endl;
    else if (jolly.get_age() < jumper->get_age())
        std::cout << "jolly is younger than jumper" << std::endl;
    else
        std::cout << "jolly and jumper are the same age" << std::endl;
    delete jumper;
}