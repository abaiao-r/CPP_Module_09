/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:24:34 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/13 19:49:02 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << RED << "Error: Invalid number of arguments" << RESET << std::endl;
        std::cout << "Usage: ./btc [input_file]" << std::endl;
        return (1);
    }
    
    BitcoinExchange btc;
    (void)av;
    btc.extractInfo("data.csv");
/*     btc.printRaw(); */
    btc.printValue(av[1]);

    return (0);
}