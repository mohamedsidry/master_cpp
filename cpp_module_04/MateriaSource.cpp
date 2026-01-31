/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 10:49:38 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 15:01:49 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>
#include "Floor.hpp"



/**
 * @brief MateriaSource create materia generator .
*/
MateriaSource::MateriaSource():
IMateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->learned[i] = NULL;
    if (Floor::debugging())
        std::cout << "MateriaSource default constructor was called !" << std::endl;
}

/**
 * @brief MateriaSource copy materia generator .
*/
MateriaSource::MateriaSource(const MateriaSource& other):
IMateriaSource(other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.learned[i] == NULL)
        {
            this->learned[i] = NULL;
            continue;
        }
        this->learned[i] = other.learned[i]->clone();
    }
    if (Floor::debugging())
        std::cout << "MateriaSource copy constructor was called !" << std::endl;
}

/**
 * @brief operator= asign copy materia generator .
*/
MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            IMateriaSource::operator=(other);
            if (this->learned[i])
                delete this->learned[i];
            if (other.learned[i] == NULL)
            {
                this->learned[i] = NULL;
                continue;
            }
            this->learned[i] = other.learned[i]->clone();
        }  
    }
    if (Floor::debugging())
        std::cout << "MateriaSource copy assign constructor was called !" << std::endl;
    return *this;
}

/**
 * @brief MateriaSource destructor .
*/

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->learned[i])
            delete this->learned[i];
    }
    if (Floor::debugging())
        std::cout << "MateriaSource destructor was called !" << std::endl;
}

/**
 * @brief learnMateria store copy of learned materias in array of 4 slots if no place left do nothing.
 * @param [in] m Materia to be remember .
*/
void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->learned[i] == NULL)
        {
            this->learned[i] = m;
            return;
        }
    }
    Floor::instance().add(m);
}
/**
 * @brief createMateria Create a materia of type given as input if it ws learned before .
 * @param [in] type The type of materia .
 * @return new materia of type given or NULL if never learned .
*/
AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->learned[i] && this->learned[i]->getType() == type)
            return this->learned[i]->clone();
    }
    return NULL;
}
