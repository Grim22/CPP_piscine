#include "Sed.hpp"
#include <iostream> // cout
#include <locale> // toupper

sed::sed(void){}
sed::~sed(void){
    this->_file_find.close();
    this->_file_replace.close();
}

bool sed::set_strings(char *find, char *replace)
{
    this->_string_find.assign(find);
    this->_string_replace.assign(replace);
    if (this->_string_find.length() == 0 || this->_string_replace.length() == 0)
    {
        std::cout << "Error: empty string" << std::endl;
        return false;
    }
    return true;
}

std::string to_upper(char *str)
{
    int i(0);
    while (str[i])
    {
        str[i] = std::toupper(str[i]);
        i++;
    }
    std::string str_upper(str);
    return(str_upper);
}

bool sed::open_files(char *name)
{
    this->_file_find.open(name);
    if (this->_file_find.fail())
    {
        std::cout << "Error: cant open file" << std::endl;
        return false;
    }
    this->_file_replace.open(to_upper(name) + ".replace", std::ofstream::trunc);
    if (this->_file_replace.fail())
    {
        std::cout << "Error: cant open output file" << std::endl;
        return false;
    }
    return true;
}

std::ifstream& sed::get_file_find(void)
{
    return this->_file_find;
}

std::ofstream& sed::get_file_replace(void)
{
    return this->_file_replace;
}

std::string sed::get_string_find(void)
{
    return this->_string_find;
}

std::string sed::get_string_replace(void)
{
    return this->_string_replace;
}