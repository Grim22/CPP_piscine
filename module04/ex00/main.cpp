#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"
#include "Slave.hpp"

int main()
{
Sorcerer robert("Robert", "the Magnificent");
Victim jim("Jimmy");
Peon joe("Joe");
Slave grim("Grimou");
std::cout << robert << jim << joe;
robert.polymorph(jim);
robert.polymorph(joe); // NEEDS VIRTUAL TO WORK CORRECTLY
robert.polymorph(grim); // NEEDS VIRTUAL TO WORK CORRECTLY
return 0;

// Sorcerer robert("Robert", "the Magnificent");
// Victim *ptr_base1 = new Victim("moet");
// Victim *ptr_base2 = new Peon("chandon");
// std::cout << "----" << std::endl;
// ptr_base1->getPolymorphed();
// ptr_base2->getPolymorphed(); // NEEDS VIRTUAL TO WORK CORRECTLY
// std::cout << "----" << std::endl;
// delete ptr_base2; // NEEDS VIRTUAL (destructor) TO WORK CORRECTLY
// return 0;

}