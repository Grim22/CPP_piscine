#include "fstream"
#include "sstream"
#include "iostream"
#include "string"
#include "locale"


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

int main(int ac, char **av)
{
    std::string line;
    std::string find_str;
    std::string replace_str;
    size_t pos;
    std::ifstream file;
    std::ofstream file_replace;
    int i(0);

    if (ac != 4)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    find_str = av[2];
    replace_str = av[3];
    file.open(av[1]);
    file_replace.open(to_upper(av[1]) + ".replace");
    while (getline(file, line))
    {
        while ((pos = line.find(find_str)) != std::string::npos)
            line.replace(pos, find_str.length(), replace_str);
        file_replace << line;
        if (file.eof() == false)
            file_replace << std::endl;
    }
    file.close();
}