/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:41:03 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 19:12:40 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"
#include "AMateria.hpp"

Floor Floor::_instance;
unsigned int Floor::_count = 0;
AMateria* Floor::_materias[1024] = { 0 };
bool Floor::_debug = false;

Floor::Floor(){
    if (Floor::debugging())
        std::cout << "Floor constructor was called !" << std::endl;
}
Floor& Floor::instance() { return _instance; }
Floor::~Floor()
{
    for (unsigned int i = 0; i < _count; i++)
    {
        delete _materias[i];
        _materias[i] = 0;
    }
    _count = 0;
    if (Floor::debugging())
        std::cout << "Floor destructor was called !" << std::endl;
}

void Floor::add(AMateria* m)
{
    if (_count < 1024)
        _materias[_count++] = m;
    else
        delete m;
}

bool Floor::debugging(void) {return _debug;}
