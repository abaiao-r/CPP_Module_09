/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:03:16 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/12 15:50:53 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "colours.hpp"

class BitcoinExchange
{
    private:
        std::map<std::string, float> _bitcoinPrices;
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &src);
        ~BitcoinExchange();

        BitcoinExchange &operator=(const BitcoinExchange &src);

        void loadDatabase(const std::string &filename); // this is the function that will load the database from the file
        void evaluatePrices(const std::string &inputFilename); // this is the function that will read the input file and evaluate the prices
}

#endif
