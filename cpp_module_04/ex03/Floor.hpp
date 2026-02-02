/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:11:48 by msidry            #+#    #+#             */
/*   Updated: 2026/01/31 15:05:06 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
#define FLOOR_HPP

class AMateria;
class Floor
{
    private:
        static Floor _instance;
        static unsigned int _count;
        static AMateria* _materias[1024];
        static bool _debug;
        
    public:
        Floor();
        Floor(const Floor&);
        Floor& operator=(const Floor&);
        static Floor& instance(void);
        static void add(AMateria* m);
        static bool debugging(void);
        ~Floor();
};

#endif //FLOOR_HPP
