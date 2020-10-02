#include "fstream"
#include "sstream"
#include "iostream"

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
    std::ifstream file(av[1]);
    std::ofstream file_replace("replace");
    std::string str;

    while (getline(file, str))
    {
        file_replace << str << std::endl;
    }
    

    // std::getline(file, str1);
    // file >> str;
    // std::cout << str << std::endl;
    // std::cout << file.eof() << std::endl;
    // file >> str;
    // std::cout << str << std::endl;
    // std::cout << file.eof() << std::endl;
    // file >> str;
    // std::cout << str << std::endl;
    // std::cout << file.eof() << std::endl;
    // file >> str;
    // std::cout << str << std::endl;
    // std::cout << file.eof() << std::endl;

}