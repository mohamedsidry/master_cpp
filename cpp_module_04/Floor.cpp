/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:41:03 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 15:06:02 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"
#include "AMateria.hpp"

Floor Floor::_instance;
unsigned int Floor::_count = 0;
AMateria* Floor::_materias[1024] = { 0 };
bool Floor::_debug = false;

Floor::Floor(){}
Floor& Floor::instance() { return _instance; }
Floor::~Floor()
{
    for (unsigned int i = 0; i < _count; i++)
    {
        delete _materias[i];
        _materias[i] = 0;
    }
    _count = 0;
}

void Floor::add(AMateria* m)
{
    if (_count < 1024)
        _materias[_count++] = m;
    else
        delete m;
}

bool Floor::debugging(void) {return _debug;}
