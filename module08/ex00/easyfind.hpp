#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

#include <algorithm>

// synthax 0: two template param
// template <typename Iter, typename T>
// Iter easyfind(const T &cont, const int &a)
// {
//     Iter it;
//     for (it = cont.begin() ; it != cont.end(); ++it)
//     {
//         if (*it == a)
//             break;
//     }
//     std::cout << *it << std::endl;
//     return it;
// }

// synthax 1: only one template param
// template <typename T>
// typename T::const_iterator easyfind(const T &cont, const int &a)
// {
//     typename T::const_iterator it;
//     for (it = cont.begin() ; it != cont.end(); ++it) // as cont is const, begin() and end() return const_iterators (so return type is const_iterator too)
//     {
//         if (*it == a)
//             break;
//     }
//     return it;
// }

// synthax 2: only one template param and use find() from STL
template <typename T>
typename T::const_iterator easyfind(const T &cont, const int &a) // "typename" is mandatory before a "dependent name" (name that depends on a template parameter): it tells the compilator that T::const_iterator is a type name (else it could be a non type, like a variable. Even if this situation a non type doesnt make sense)
{
    return std::find(cont.begin(), cont.end(), a);
}

#endif