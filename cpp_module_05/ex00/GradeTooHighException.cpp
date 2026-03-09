/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:54:41 by msidry            #+#    #+#             */
/*   Updated: 2026/03/09 15:05:43 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "GradeTooHighException.hpp"



const char* GradeTooHighException::what(void) const throw()
{
    return ("Grade Too High .");
}

