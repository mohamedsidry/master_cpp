/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:54:25 by msidry            #+#    #+#             */
/*   Updated: 2026/02/02 18:24:35 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <string>

/**
 * @brief Brain default constructor .
*/
Brain::Brain()
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = "An idea";
    std::cout << "Brain constructor was called !" << std::endl;
}

/**
 * @brief Brain copy constructor .
 * @param other Obj to copy from it .
*/
Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    std::cout << "Brain copy constructor was called !" << std::endl;
}

Brain::Brain(const std::string& idea)
{
    for (int i = 0; i < 100; i++)
        this->ideas[i] = idea;
    std::cout << "Brain constructor was called !" << std::endl;
}

/**
 * @brief Brain copy assign constructor .
 * @param other Obj to copy from it .
 * @return Copy of given obj .
*/
Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0 ; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy assign constructor was called !" << std::endl;
    return (*this);
}

/**
 * @brief ~Brain destructor .
*/
Brain::~Brain()
{
    std::cout << "Brain destructor was called !" << std::endl;
}

/**
 * @brief getIdeaByIndex get idea in index idx .
 * @param [in] idx index of idea .
 * @return idea or empty string if out of range .
*/
std::string Brain::getIdeaByIndex(unsigned int idx) const
{
    if (idx < 100)
        return this->ideas[idx];
    return "";
}

/**
 * @brief setIdeaByIndex set idea in index idx .
 * @param [in] idx new idea .
*/
void Brain::setIdeaByIndex(const std::string& idea, unsigned int idx)
{
    if (idx > 100)
        return ;
    this->ideas[idx] = idea;
}
