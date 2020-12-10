#include "iter.hpp"
#include "iostream"
#include "Fixed.hpp"

void increment_int(int &a)
{
    a++;
}

int main()
{
    int tab[4] = {2, 4, 1, 8};
    std::cout << tab[0] << tab[1] << tab[2] << tab[3] << std::endl;
    iter<int>(tab, 4, &increment<int>);
    std::cout << tab[0] << tab[1] << tab[2] << tab[3] << std::endl;

    char tab2[4] = {'a', 'r', 's', 'g'};
    std::cout << tab2[0] << tab2[1] << tab2[2] << tab2[3] << std::endl;
    iter<char>(tab2, 4, &increment<char>); // will use char-specialized template of increment
    std::cout << tab2[0] << tab2[1] << tab2[2] << tab2[3] << std::endl;

    Fixed tab3[4] = {Fixed(1), Fixed(2), Fixed(3.33f), Fixed(2.25f)};
    std::cout << tab3[0] << " " << tab3[1] << " " << tab3[2] << " " << tab3[3] << std::endl;
    iter<Fixed>(tab3, 4, &increment<Fixed>);
    std::cout << tab3[0] << " " << tab3[1] << " " << tab3[2] << " " << tab3[3] << std::endl;
}