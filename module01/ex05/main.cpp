#include "Brain.hpp"
#include "Human.hpp"
#include <iostream>


int main() {
    Human bob;

    std::cout << "back to main" << std::endl;
    std::cout << bob.identify() << std::endl;
    std::cout << bob.getBrain().identify() << std::endl;
    std::cout << "back to main" << std::endl;
}