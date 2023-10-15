/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:03:16 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/15 00:25:00 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include "colours.hpp"
# include <algorithm>
# include <cmath>
# include <cstdlib>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <limits>
# include <map>
# include <sstream>
# include <string>
# include <vector>

class BitcoinExchange
{
  private:
	std::map<std::string, float> _bitcoinPrices;

  public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &src);
	~BitcoinExchange(void);

	BitcoinExchange &operator=(const BitcoinExchange &src);

	// print the raw _bitcoinPrices
	void printRaw(void);
	// extract info from data.csv and store in _bitcoinPrices
	void extractInfo(std::string inputFile);
	//validate info (string) from _bitcoinPrices
	bool validateDate(std::string date);
	//validate info (float) from _bitcoinPrices
	float validateValue(std::string value);
	//receives input file and checks line per line if date is valid and if price is valid. If are valid then lookup at _bitcoinPrices for the date, calculates the value with exchange rate and prints it.
	void printValue(std::string inputFile);
	// look up for closest date that occurred in _bitcoinPrices and returns the value
	float lookup(std::string date);
	// check if year is leap
	bool isLeap(int year);
};

#endif
