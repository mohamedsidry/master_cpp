/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooLowException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:02:46 by msidry            #+#    #+#             */
/*   Updated: 2026/03/09 15:05:40 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRADETOOLOWEXCEPTION_HPP
#define GRADETOOLOWEXCEPTION_HPP

#include <exception>

class GradeTooLowException : public std::exception
{
    public:
        const char *what(void) const throw();
};


#endif // GRADETOOLOWEXCEPTION_HPP

