#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void):
learnt_materias(), materia_learnt_num(0) // learnt_materias() : "In order to set an array of pointers to nulls in constructor initializer list, you can use the () initializer"
{
    std::cout << "Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy):
materia_learnt_num(copy.materia_learnt_num)
{
    for (int i = 0; i < copy.materia_learnt_num; i++)
        this->learnt_materias[i] = copy.learnt_materias[i]->clone();
    std::cout << "Copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
    for (int i = 0; i < this->materia_learnt_num; i++)
    {
        delete this->learnt_materias[i];
        this->learnt_materias[i] = NULL;
    }
    
    std::cout << "Destructor called" << std::endl;
}

MateriaSource&   MateriaSource::operator=(const MateriaSource &rhs)
{
    std::cout << "Assignement operator called" << std::endl;
    for (int i = 0; i < this->materia_learnt_num; i++)
    {
        delete this->learnt_materias[i];
        this->learnt_materias[i] = NULL;
    }

    for (int i = 0; i < rhs.materia_learnt_num; i++)
        this->learnt_materias[i] = rhs.learnt_materias[i]->clone();
    this->materia_learnt_num = rhs.materia_learnt_num;
    
    return(*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (materia == NULL || this->materia_learnt_num == 4)
    {
        std::cout << "materiaSource is full" << std::endl;
        return;
    }
    this->learnt_materias[this->materia_learnt_num] = materia;
    this->materia_learnt_num++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < this->materia_learnt_num; i++)
    {
        if (type == this->learnt_materias[i]->getType())
            return this->learnt_materias[i]->clone();
    }
    return 0;
}

