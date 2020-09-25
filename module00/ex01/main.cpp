#include <string>
#include <iostream>
#include <istream>
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
    book[i].init();
}

void    print_line(Contact book, int i)
{
    if (book.first_name.size() > 10)
    {
        book.first_name.resize(10);
        book.first_name[9] = '.';
    }
    if (book.last_name.size() > 10)
    {
        book.last_name.resize(10);
        book.last_name[9] = '.';
    }
    if (book.nickname.size() > 10)
    {
        book.nickname.resize(10);
        book.nickname[9] = '.';
    }
    std::cout << std::setw(10) << i
    << " | " << std::setw(10) << book.first_name
    << " | " << std::setw(10) << book.last_name
    << " | " << std::setw(10) << book.nickname
    << std::endl;
}

void    get_and_print_entry(Contact book[8], int num)
{
    int index = -1;
    std::cout << "Enter contact's index: ";
    std::cin >> index;
    while (index == -1 || index > num - 1)
    {
        std::cout << "Wrong index. Enter again: ";
        std::cin >> index;
    }
    std::cin.ignore(1000, '\n');
    book[index].print();
}

void    search(Contact book[8], int num)
{
    int i;

    if (num == 0)
    {
        std::cout << "No entry in book" << std::endl;
        return ;
    }
    i = 0;
    std::cout << std::setw(10) << "index"
    << " | " << std::setw(10) << "first name"
    << " | " << std::setw(10) << "last name"
    << " | " << std::setw(10) << "nickname"
    << std::endl;
    while (i < num)
    {
        print_line(book[i], i);
        i++;
    }
    get_and_print_entry(book, i);    
}

int main()
{
    std::string cmd;
    Contact book[8];
    int i = -1;
    
    std::cin >> i;
    std::cout << i;

    while (0)
    {
        std::cout << "Enter your command (ADD, SEARCH or EXIT): ";
        std::getline(std::cin, cmd);
        if (cmd.compare("EXIT") == 0)
            break ;
        else if (cmd.compare("ADD") == 0)
        {
            add_contact(book, i);
            i++;
        }
        else if (cmd.compare("SEARCH") == 0)
            search(book, i);
        else
            std::cout << "Wrong command:" << cmd << "|" << std::endl;

        
    }
    // std::cout << "Bye" << std::endl;
}
