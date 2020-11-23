#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

int main()
{
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISquad* vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    for (int i = 0; i < vlc->getCount(); ++i)
    {
    ISpaceMarine* cur = vlc->getUnit(i);
    cur->battleCry();
    cur->rangedAttack();
    cur->meleeAttack();
    }
    delete vlc; // frees vlc and then calls destructor on Squad object
    // no need to call delete on ISpaceMarine* bob and jim, as they are destroyed along with the squad (cf squad destructor)
    // be careful: bob and jim now point to deleted objects ! we should set them to NULL to avoid missusage
    jim = NULL;
    bob = NULL;
    
    std::cout << "----" << std::endl;

    ISpaceMarine* patricia = new TacticalMarine;
    ISpaceMarine* angela = new AssaultTerminator;
    Squad pat;
    pat.push(patricia);
    pat.push(angela);
    pat.push(NULL); // cant add NULL
    pat.push(patricia); // cant add duplicate
    Squad other;
    other = pat; // assignation
    Squad last(other); // copy
    
    std::cout << "----" << std::endl;

    // 2 inital pointers patricia and angela are deleted along when squad pat is deleted
    // new pointers were created when assignation (other) or copy (last) were done. they are also deleted (2 * 2 pointers)

    return 0;
}