#include <iostream>

char    *ft_toupper(char *str)
{
	int i;

    i = 0;
    while(str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
    return (str);
}

int     main(int argc, char **argv)
{
    int i;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    i = 1;
    while (argv[i])
    {
        std::cout << ft_toupper(argv[i]);
        i++;
    }
    std::cout << std::endl;
    
}