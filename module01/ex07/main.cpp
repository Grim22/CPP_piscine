#include <iostream>
#include <string>
#include "Sed.hpp"


// start_pos represente l'index du debut de recherche
// sans start_pos, on boucle a l'infini dans les cas suivants:
// ./replace file string string
// ./replace file string stringyopo

int main(int ac, char **av)
{
    std::string line;
    sed file;
    size_t pos;
    size_t start_pos(0);

    if (ac != 4)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    if (file.set_strings(av[2], av[3]) == false || file.open_files(av[1]) == false)
        return 1;
    while (getline(file.get_file_find(), line))
    {
        while ((pos = line.find(file.get_string_find(), start_pos)) != std::string::npos)
        {
            line.replace(pos, file.get_string_find().length(), file.get_string_replace());
            start_pos += file.get_string_replace().length() + pos;
        }
        file.get_file_replace() << line;
        if (file.get_file_find().eof() == false)
            file.get_file_replace() << std::endl;
    }
    return 0;
}