#include "Contact.hpp"
#include "book.hpp"

int    add_contact(Contact book[MAX_CONTACTS], int i)
{
    if (i > MAX_CONTACTS - 1)
    {
        std::cout << "Phonebook is full: 8 contacts maximum" << std::endl;
        return (FAILURE);
    }
    if (book[i].init() == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

void    get_and_print_entry(Contact book[8], int num)
{
    std::string index;
    int i;

    std::cout << "Enter contact's index: ";
    std::getline(std::cin, index);
    while (index.length() > 1 || isdigit(index[0]) == 0 || (i = atoi(index.c_str())) >= num)
    {
        std::cout << "Wrong index. Enter again: ";
        std::getline(std::cin, index);
    }
    i = index[0] - '0';
    book[i].print_all();
}

void    search(Contact book[8], int num)
{
    int i;
    Contact tmp;

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
        tmp = book[i];
        tmp.print_index_line(i);
        i++;
    }
    get_and_print_entry(book, i);    
}

int     main()
{
    std::string cmd;
    Contact book[MAX_CONTACTS];
    int i(0);
    
    while (1)
    {
        std::cout << "Enter your command (ADD, SEARCH or EXIT): ";
        std::getline(std::cin, cmd);
        if (cmd.compare("EXIT") == 0)
            break ;
        else if (cmd.compare("ADD") == 0)
        {
            if (add_contact(book, i) == SUCCESS)
                i++;
        }
        else if (cmd.compare("SEARCH") == 0)
            search(book, i);
        else
            std::cout << "Wrong command:" << "[" << cmd << "]" << std::endl;
    }
    std::cout << "Bye" << std::endl;
}
