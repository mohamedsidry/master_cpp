/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 08:50:17 by msidry            #+#    #+#             */
/*   Updated: 2025/10/19 09:04:28 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

static std::string toUpper(std::string str)
{
    int idx;
    int len;

    idx = 0;
    len = str.length();
    while (idx < len)
    {
        if (str[idx] >= 'a' && str[idx] <= 'z')
            str[idx] = str[idx] - ('a' - 'A');
        idx++;
    }
    return (str);
}

int main(int argc, char *argv[])
{
    int idx;
    std::string tmp;

    idx = 1;
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    while (argv[idx])
    {
        std::cout << toUpper(argv[idx]);
        idx++;
    }
    std::cout << std::endl;
    return (0);
}
