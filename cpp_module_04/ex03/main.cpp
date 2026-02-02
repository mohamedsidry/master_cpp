/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:23:32 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 13:58:25 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// void ll()
// {
//     system("leaks a.out");
// }
int main(void)
{
    MateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    Character bob("uncle Bob");
    Character alb(bob);
    bob.equip(src->createMateria("ice"));
    bob.equip(src->createMateria("cure"));
    bob.equip(src->createMateria("ice"));
    bob.equip(src->createMateria("cure"));
    bob.equip(src->createMateria("ice"));
    bob.equip(src->createMateria("cure"));
    bob.use(0, alb);
    bob.use(1, alb); 
    delete src;
    //atexit(ll);
    return (0);
}

