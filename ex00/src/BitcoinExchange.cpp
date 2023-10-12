/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:17:01 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/12 16:49:32 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/* Default Constructor */
BitcoinExchange::BitcoinExchange()
{
    std::cout << CYAN << "BitcoinExchange Default Constructor called" << RESET 
        << std::endl;
}

/* Copy Constructor */  
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    std::cout << CYAN << "BitcoinExchange Copy Constructor called" << RESET 
        << std::endl;
    *this = src;
}

/* Destructor */
BitcoinExchange::~BitcoinExchange()
{
    std::cout << RED << "BitcoinExchange Destructor called" << RESET 
        << std::endl;
}

/* Assignment operator overload (Update) */
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    std::cout << YELLOW << "BitcoinExchange Assignment operator called" << RESET 
        << std::endl;
    if (this != &src)
    {
        this->_bitcoinPrices = src._bitcoinPrices;
    }
    return (*this);
}





/* loadDatabase:
** This is the function that will load the database from the file and store it.
*/
void BitcoinExchange::loadDatabase(const std::string &filename)
{

}