#include "Human.hpp"

int main()
{
    Human basile;
    Human *ptr_basile;
    ptr_basile = &basile;

    basile.action("melee", "marc");
    basile.action("shouting", "marc");
    ptr_basile->action("ranged", "tom");
}