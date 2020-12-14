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

// synthax 2: only one template param
template <typename T>
typename T::const_iterator easyfind(const T &cont, const int &a)
{
    typename T::const_iterator it;
    for (it = cont.begin() ; it != cont.end(); ++it) // as cont is const, begin() and end() return const_iterators (so return type is const_iterator too)
    {
        if (*it == a)
            break;
    }
    return it;
}