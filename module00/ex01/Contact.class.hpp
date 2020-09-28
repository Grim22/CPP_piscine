#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>

class   Contact
{
public:
    Contact(void);
    ~Contact(void);
    void print_all(void);
    void print_index_line(int index);
    void init(void);

private:
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _login;
    std::string _postal_address;
    std::string _email_address;
    std::string _phone_number;
    std::string _birthday;
    std::string _fav_meal;
    std::string _und_color;
    std::string _secret;
    
};

#endif