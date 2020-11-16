#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include <iostream>
#include <string>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria *learnt_materias[4]; 
        // "Of course, you’ll have to be able to support ANY AMateria in a Character’s inventory." -> pointer to AMateria is used
        int materia_learnt_num;

    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource &copy);
        virtual ~MateriaSource(void);
        MateriaSource&  operator=(const MateriaSource &copy);

        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};

std::ostream & operator<<(std::ostream &o, const MateriaSource &rhs);

#endif