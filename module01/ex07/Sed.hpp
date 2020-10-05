#ifndef SED_HPP
# define SED_HPP

#include <string>
#include "fstream" // ifstream ofstream

class sed
{
private:
    std::string _string_find;
    std::string _string_replace;
    std::ifstream _file_find;
    std::ofstream _file_replace;
public:
    sed(void);
    ~sed(void);
    bool set_strings(char *find, char *replace);
    bool open_files(char *name);
    std::ifstream& get_file_find(void);
    std::ofstream& get_file_replace(void);
    std::string get_string_find(void);
    std::string get_string_replace(void);
};

#endif