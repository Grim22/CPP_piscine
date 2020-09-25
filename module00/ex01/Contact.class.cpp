#include "book.hpp"
#include "Contact.class.hpp"

Contact::Contact(void)
{
    // std::cout << "Constructor" << std::endl;
    // this->num = 0;
}

Contact::~Contact(void)
{
    // std::cout << "Destructor" << std::endl;
}

void    Contact::print_all(void)
{
    std::cout << "first name: " << this->first_name << std::endl;
    std::cout << "last name: " << this->last_name << std::endl;
    std::cout << "nickname: " << this->nickname << std::endl;
    std::cout << "login: " << this->login << std::endl;
    std::cout << "postal address: " << this->postal_address << std::endl;
    std::cout << "email: " << this->email_address << std::endl;
    std::cout << "phone number: " << this->phone_number << std::endl;
    std::cout << "birthday: " << this->birthday << std::endl;
    std::cout << "favorite meal: " << this->fav_meal << std::endl;
    std::cout << "underwear color: " << this->und_color << std::endl;
    std::cout << "darkest secret: " << this->secret << std::endl;
}

void Contact::print_index_line(int index)
{
    if (this->first_name.size() > 10)
    {
        this->first_name.resize(10);
        this->first_name[9] = '.';
    }
    if (this->last_name.size() > 10)
    {
        this->last_name.resize(10);
        this->last_name[9] = '.';
    }
    if (this->nickname.size() > 10)
    {
        this->nickname.resize(10);
        this->nickname[9] = '.';
    }
    std::cout << std::setw(10) << index
    << " | " << std::setw(10) << this->first_name
    << " | " << std::setw(10) << this->last_name
    << " | " << std::setw(10) << this->nickname
    << std::endl;
}

void    Contact::init(void)
{
    std::cout << "First name: ";
    std::getline(std::cin, this->first_name);
    std::cout << "Last name: ";
    std::getline(std::cin, this->last_name);
    std::cout << "Nickname: ";
    std::getline(std::cin, this->nickname);
    std::cout << "Login: ";
    std::getline(std::cin, this->login);
    std::cout << "Adress: ";
    std::getline(std::cin, this->postal_address);
    std::cout << "Email: ";
    std::getline(std::cin, this->email_address);
    std::cout << "Phone: ";
    std::getline(std::cin, this->phone_number);
    std::cout << "Bday: ";
    std::getline(std::cin, this->birthday);
    std::cout << "Favorite meal: ";
    std::getline(std::cin, this->fav_meal);
    std::cout << "Underwear color: ";
    std::getline(std::cin, this->und_color);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, this->secret);
}
