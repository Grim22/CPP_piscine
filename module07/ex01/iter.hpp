#include "iostream"

template <typename T>
void iter(T *address, unsigned int lenght, void (*f)(T &elem))
{
    for (unsigned int i = 0; i < lenght; i++)
    {
        f(address[i]);
    }
}

// template with a const param for function f
template <typename T>
void iter(T *address, unsigned int lenght, void (*f)(T const &elem))
{
    for (unsigned int i = 0; i < lenght; i++)
    {
        f(address[i]);
    }
}

template <typename T>
void increment(T &elem)
{
    elem++;
}

template <>
void increment<char>(char &elem)
{
    elem += 2;
}