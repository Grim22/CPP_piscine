#include <string>
#include <iostream>

int main()
{
    std::string prenom;
    int pi;
    std::cout << "whats pi?\n";
    std::cin >> pi;
    std::cout << "whats ur name?\n";
    std::getline(std::cin, prenom);
    std::cout << "Ur name is: " << prenom << " pi is: " << pi << std::endl;

}