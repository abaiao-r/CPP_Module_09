/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:14:20 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/14 16:00:36 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << BOLDRED << "Error: " << RESET 
            << "Wrong number of arguments" << std::endl;
        return (1);
    }

    RPN rpn;

    rpn.rpncalc(argv[1]);

    return (0);
}
