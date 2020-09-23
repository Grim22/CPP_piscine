#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

// int main()
// {
//     std::string prenom;
//     std::cout << "whats ur name?\n";
//     std::getline(std::cin, prenom);
//     prenom = prenom + "Nrinet";
//     std:: cout << prenom << std::endl;
// }

// int main()
// {
//     std::ofstream file("myfile2");
//     if (file)
//     {
//         std::cout << "ok" << std::endl;
//     }
//     file << "hello";
// }

// int main()
// {
//     std:: cout << 100 << std::endl;
//     // std::cout.width(10);
//     // std:: cout << std::setw(10);
//     std:: cout << std::setw(10) << 100 << std::endl
//     << 200 << std::setw(30) << std::setfill('*') << 300 << std::endl;

// }

#include "Contact.class.hpp"

void    add_contact(Contact book[8], int i)
{
    if (i > 7)
    {
        std::cout << "Phonebook is full: 8 contacts maximum";
        return ;

    }
    std::cout << "First name:: ";
    std::cin >> book[i].first_name;
    std::cout << "Last name:: ";
    std::cin >> book[i].last_name;
    std::cout << "Nickname:: ";
    std::cin >> book[i].nickname;
}

void    print_line(Contact book, int i)
{
    std::cout << std::setw(10) << i
    << " | " << std::setw(10) << book.first_name
    << " | " << std::setw(10) << book.last_name
    << " | " << std::setw(10) << book.nickname
    << std::endl;
}

void    search(Contact book[8])
{
    int i;

    i = 0;
    std::cout << std::setw(10) << "index"
    << " | " << std::setw(10) << "surname"
    << " | " << std::setw(10) << "name"
    << " | " << std::setw(10) << "nickname"
    << std::endl;
    while (i < 8)
    {
        print_line(book[i], i);
        i++;
    }
    
}

int main()
{
    std::string cmd;
    Contact book[8];
    int i;

    while (1)
    {
        std::cout << "Enter your command (ADD, SEARCH or EXIT): ";
        std::cin >> cmd;
        if (cmd.compare("EXIT") == 0)
            break ;
        else if (cmd.compare("ADD") == 0)
        {
            add_contact(book, i);
            i++;
        }
        else if (cmd.compare("SEARCH") == 0)
            search(book);
        else
            std::cout << "Wrong command" << std::endl;

        
    }
    std::cout << "Bye" << std::endl;
}
