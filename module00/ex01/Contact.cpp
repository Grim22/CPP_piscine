#include "book.hpp"
#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void    Contact::print_all(void) const
{
    std::cout << "first name: " << this->_first_name << std::endl;
    std::cout << "last name: " << this->_last_name << std::endl;
    std::cout << "nickname: " << this->_nickname << std::endl;
    std::cout << "login: " << this->_login << std::endl;
    std::cout << "postal address: " << this->_postal_address << std::endl;
    std::cout << "email: " << this->_email_address << std::endl;
    std::cout << "phone number: " << this->_phone_number << std::endl;
    std::cout << "birthday: " << this->_birthday << std::endl;
    std::cout << "favorite meal: " << this->_fav_meal << std::endl;
    std::cout << "underwear color: " << this->_und_color << std::endl;
    std::cout << "darkest secret: " << this->_secret << std::endl;
}

void Contact::print_index_line(int index)
{
    if (this->_first_name.size() > 10)
    {
        this->_first_name.resize(10);
        this->_first_name[9] = '.';
    }
    if (this->_last_name.size() > 10)
    {
        this->_last_name.resize(10);
        this->_last_name[9] = '.';
    }
    if (this->_nickname.size() > 10)
    {
        this->_nickname.resize(10);
        this->_nickname[9] = '.';
    }
    std::cout << std::setw(10) << index
    << " | " << std::setw(10) << this->_first_name
    << " | " << std::setw(10) << this->_last_name
    << " | " << std::setw(10) << this->_nickname
    << std::endl;
}

int    Contact::set_email(void)
{
    std::string email;
    size_t arobase_pos;
    size_t dot_pos;
    int i;

    i = 0;
    while (i < 3)
    {
        std::cout << "Email: ";
        std::getline(std::cin, email);
        arobase_pos = email.find_first_of('@');
        dot_pos = email.find_last_of('.');
        if (arobase_pos == std::string::npos || dot_pos == std::string::npos
        || arobase_pos > dot_pos)
            std::cout << "email not well formated, try again: " << std::endl;
        else
        {
            this->_email_address = email;
            return (SUCCESS);
        }
        i++;
    }
        std::cout << "Too many attempts. Failed to add contact" << std::endl;
        return (FAILURE);
}

int    Contact::init(void)
{
    
    std::cout << "First name: ";
    std::getline(std::cin, this->_first_name);
    std::cout << "Last name: ";
    std::getline(std::cin, this->_last_name);
    std::cout << "Nickname: ";
    std::getline(std::cin, this->_nickname);
    std::cout << "Login: ";
    std::getline(std::cin, this->_login);
    std::cout << "Adress: ";
    std::getline(std::cin, this->_postal_address);
    if (Contact::set_email() == FAILURE)
        return (FAILURE);
    std::cout << "Phone: ";
    std::getline(std::cin, this->_phone_number);
    std::cout << "Bday: ";
    std::getline(std::cin, this->_birthday);
    std::cout << "Favorite meal: ";
    std::getline(std::cin, this->_fav_meal);
    std::cout << "Underwear color: ";
    std::getline(std::cin, this->_und_color);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, this->_secret);
    return (SUCCESS);
}
