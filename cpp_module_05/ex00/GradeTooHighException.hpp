/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeTooHighException.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:54:41 by msidry            #+#    #+#             */
/*   Updated: 2026/03/09 15:05:37 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GRADETOOHIGHEXCEPTION_HPP
# define GRADETOOHIGHEXCEPTION_HPP

#include <exception>


class GradeTooHighException: public std::exception
{
    public:
        const char *what(void) const throw();
};

#endif // GRADETOOHIGHEXCEPTION_HPP

