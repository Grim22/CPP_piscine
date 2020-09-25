#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class   Contact
{
public:
    Contact(void);
    ~Contact(void);
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string login;
    std::string postal_address;
    std::string email_address;
    std::string phone_number;
    std::string birthday;
    std::string fav_meal;
    std::string und_color;
    std::string secret;
    void print_all(void);
    void print_index_line(int index);
    void init(void);
};

#endif