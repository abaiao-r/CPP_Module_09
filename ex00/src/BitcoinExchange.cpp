/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:17:01 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/15 13:27:10 by andrefranci      ###   ########.fr       */
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

/* Open and validate the input file */
bool openInputFile(const std::string& inputFile, std::ifstream& file) 
{
    file.open(inputFile.c_str());
    if (!file.is_open()) 
    {
        std::cout << RED << "Error: Failed to open the input file!" << RESET 
            << std::endl;
        return false;
    }
    return true;
}

/* Check if the file is empty */
bool isFileEmpty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}

/* Process each line in the input file and store data in _bitcoinPrices */
void processFileLines(std::ifstream& file, std::map<std::string, float>& _bitcoinPrices) 
{
    std::string line;
    std::string key;
    float value;

    // Skip the header line
    std::getline(file, line);
    while (std::getline(file, line))
    {
        if (line.find(',') == std::string::npos)
        {
            key = line;
            value = NAN;
        } 
        else
        {
            key = line.substr(0, line.find(','));
            value = strtod(line.substr(line.find(',') + 1).c_str(), NULL);
        }
        _bitcoinPrices.insert(std::pair<std::string, float>(key, value));
    }
}

/* Extract info from input file and store in _bitcoinPrices */
void BitcoinExchange::extractInfo(std::string inputFile)
{
    std::ifstream file;
    
    if (!openInputFile(inputFile, file))
        exit(1);
    if (isFileEmpty(file))
    {
        std::cout << RED << "Error: Input file is empty!" << RESET << std::endl;
        file.close();
        exit(1);
    }
    processFileLines(file, _bitcoinPrices);
    file.close();
}

/*void print the raw _bitcoinPrices */
void BitcoinExchange::printRaw(void)
{
    unsigned int i;
    
    // because the first line is the header, we start at 2
    i = 2;
    std::cout << "Raw _bitcoinPrices:" << std::endl;
    for (std::map<std::string, float>::iterator it = _bitcoinPrices.begin(); it != _bitcoinPrices.end(); ++it)
    {
        std::cout << i <<". " << it->first << " => " << it->second << std::endl;
        i++;
    }
}

/*void printValues the _bitcoinPrices */
void BitcoinExchange::printValue(std::string inputFile)
{
    std::ifstream file(inputFile.c_str());
    std::string line;
    std::string key;
    std::string value;
    float valueFloat;
    float exchangeValue;
    float conversionValue;

    if (!file.is_open())
    {
        std::cerr << RED << "Error: Failed to open the input file!" << RESET << std::endl;
        return ;
    }
    // check if has header, if has header, skip it if not, continue
    if (std::getline(file, line))
    {
       if (line != "date | value")
       {
            std::cerr << RED << "Error: bad header => " << line << RESET 
                << std::endl;
            std::cerr << RED << "Header should be: <date> | <value>" << RESET 
                << std::endl;
            file.close();
           return ;
       }
    }
    // check if file is empty
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << RED << "Error: Input file is empty!" << RESET << std::endl;
        file.close();
        return ;
    }
    while(std::getline(file, line))
    {
        // if line empty continue
        if (line.empty())
            continue;
        // set key and value
        if (line.find('|') == std::string::npos) // if no | in line
        {
            std::cerr << RED << "Error: bad input => " << line << RESET 
                << std::endl;
        }
        else // if | in line
        {
            key = line.substr(0, line.find('|'));
            value = line.substr(line.find('|') + 1);
        }
        // check if key and value are valid
        if (key.empty())
        {
            std::cerr << RED << "Error: bad input => " << line << RESET 
                << std::endl;
            continue;
        }
        if (validateDate(key) == false)
            continue;
        valueFloat = validateValue(value);
        if (valueFloat == -1)
            continue;
        // look for key in _bitcoinPrices, if found print key and value and print the value * the value in _bitcoinPrices
        exchangeValue = lookup(key);
        if (exchangeValue == -1)
            continue;
        //std::cout << valueFloat << " * " << exchangeValue << " = " << std::endl;
        conversionValue = valueFloat * exchangeValue;


        // print key and value 2011-01-03 => 3 = 0.9
        std::cout << key << " => " << value << " = " << conversionValue << std::endl;
    }
}

/*Validate if the key and value are valid*/
bool BitcoinExchange::validateDate(std::string date)
{
    struct tm time;
    int month;
    int day;
    int year;
    int i;

    // check if date has yyyy-mm-dd format. skip white spaces and check if has 10 chars
    //skip white spaces
    while (date[0] == ' ')
        date.erase(0, 1);
    if (date[4] != '-' && date[7] != '-')
    {
        std::cerr << RED << "Error: bad date => " << date << RESET 
            << std::endl;
        return (false);
    }
    for (i = 0; date[i] != '\0'; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (std::isdigit(date[i]) == false)
            break;
    }
    if (i != 10)
    {
        std::cerr << RED << "Error: bad date format should be yyyy-mm-dd => "
            << date << RESET << std::endl;
        return (false);
    }
    if (!strptime(date.c_str(), "%Y-%m-%d", &time))
    {
        std::cerr << RED << "Error: bad date => " << date << RESET 
            << std::endl;
        return (false);
    }
    // check if day is valid for month code it
    month = time.tm_mon + 1;
    day = time.tm_mday;
    year = time.tm_year + 1900;
    if (isLeap(year) == true && month == 2 && day > 29)
    {
        std::cerr << RED << "Error: bad date => " << date << RESET 
            << std::endl;
        return (false);
    }
    if (isLeap(year) == false && month == 2 && day > 28)
    {
        std::cerr << RED << "Error: bad date => " << date << RESET 
            << std::endl;
        return (false);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            std::cerr << RED << "Error: bad date => " << date << RESET 
                << std::endl;
            return (false);
        }
    }
    return (true);
}

/* Validate value and convert to double, and then check if value is in the float range */
float BitcoinExchange::validateValue(std::string value)
{
    double d;
    unsigned int len;
    unsigned int i;
    int dotCount;

    dotCount = 0;
    // skip initial spaces
    while (value[0] == ' ')
        value.erase(0, 1);
    // no negative values
    if (value[0] == '-')
    {
        std::cerr << RED << "Error: negative number => " << value << RESET 
            << std::endl;
        return (-1);
    }
    len = value.length();
    if (len > 328) // 328 is the max length of a float
    {
        std::cerr << RED << "Error: value out of range => " << value << RESET 
            << std::endl;
        return (-1);
    }
    // check if value is a number
    for (i = 0 ; value[i] != '\0'; i++)
    {
        if (std::isdigit(value[i]) == false)
        {
            if (value[i] == '.')
            {
                dotCount++;
                if (dotCount > 1)
                {
                    std::cerr << RED << "Error: bad input 2=> " << value 
                        << RESET << std::endl;
                    return (-1);
                }
                if (value[i] == '.' && value[i + 1] == '\0')
                {
                    std::cerr << RED << "Error: bad input => dot. nothing " 
                        << value << RESET << std::endl;
                    return (-1);
                }
                continue;   
            }
            std::cerr << RED << "Error: bad input => not a digit " << value[i] 
                << RESET << std::endl;
            return (-1);
        }
    }
    d = std::strtod(value.c_str(), NULL);
    if (d < -std::numeric_limits<float>::max() 
        || d > std::numeric_limits<float>::max()) 
    {
        std::cerr << RED << "Error: value out of range => " << value << RESET 
            << std::endl;
        return (-1);
    }
    if (d < 0 || d > 1000)
    {
        std::cerr << RED << "Error: value out of range => " << value << RESET 
            << std::endl;
        return (-1);
    }
    return (static_cast<float>(d));
}

/* lookup key in _bitcoinPrices and return the value */
float BitcoinExchange::lookup(std::string key)
{
    std::map<std::string, float>::iterator it;

    //lower_bound returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
    it = _bitcoinPrices.lower_bound(key);

    // if key is not found
    if (it == _bitcoinPrices.begin() && it->first != key)
    {
        std::cerr << RED << "Error: key not found => " << key << RESET 
            << std::endl;
        return (-1);
    }
    else if (it->first != key)
    {
        it--;
    }
    return (it->second);
}

/* isLeap: check if year is a leap year
** 1. The year can be evenly divided by 4;
** 2. If the year can be evenly divided by 100, it is NOT a leap year, unless;
** 3. The year is also evenly divisible by 400. Then it is a leap year.
** we divide not only by 4 due rounding errors. Ex: 1900 is not a leap year
** but 1900 % 4 == 0
*/
bool BitcoinExchange::isLeap(int year)
{
    if (year % 4 != 0)
        return (false);
    else if (year % 100 != 0)
        return (true);
    else if (year % 400 != 0) 
        return (false);
    else
        return (true);
}
