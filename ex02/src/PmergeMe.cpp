/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:58:38 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/15 14:42:04 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

/* Default constructor */
PmergeMe::PmergeMe(void)
{
    std::cout << CYAN << "PmergeMe default constructor called" << RESET 
        << std::endl;
}

/* Copy constructor */
PmergeMe::PmergeMe(PmergeMe const &src)
{
    std::cout << CYAN << "PmergeMe copy constructor called" << RESET 
        << std::endl;
    *this = src;
}

/* Destructor */
PmergeMe::~PmergeMe(void)
{
    std::cout << RED << "PmergeMe destructor called" << RESET << std::endl;
}

/* Assignment operator overload (Update) */
PmergeMe &PmergeMe::operator=(PmergeMe const &src)
{
    std::cout << YELLOW << "PmergeMe assignment operator called" << RESET 
        << std::endl;
    if (this != &src)
    {
        this->pmergeVector = src.pmergeVector;
        this->pmergeList = src.pmergeList;
    }
    return (*this);
}

/* validateArgs:
** 1. Check if the number of arguments is correct
** 2. Check if the arguments are positive digits*/
bool PmergeMe::validateArgs(int ac, char **av)
{
    int i;
    int j;
    if (ac < 2)
    {
        std::cout << BOLDRED << "Error: " << RESET << "Wrong number of arguments"
            << std::endl;
        return (false);
    }
    for (i = 1; i < ac; i++)
    {
        if (av[i][0] == '-')
        {
            std::cout << BOLDRED << "Error: " << RESET << "Negative numbers are"
                << " not allowed" << std::endl;
            return (false);
        }
        for (j = 0; av[i][j]; j++)
        {
            if (!std::digit(av[i][j]))
            {
                std::cout << BOLDRED << "Error: '" << RESET << av[i][j] 
                    << BOLDRED << "' is not a digit" << RESET << std::endl;
                return (false);
            }
        }
    }
    return (true);
}

/* checkPositiveIntegers:
** 1. Check if the length of av is > 10
** 2. convert av to long int
** 3. check if the number is within the range of int*/
bool PmergeMe::checkPositiveIntegers(int ac, char **av)
{
    int i;
    long int tmp;
    
    for (i = 1; i < ac; i++)
    {
        if (std::strlen(av[i]) > 10)
        {
            std::cout << BOLDRED << "Error: " << RESET << "Number '" << av[i] 
                << BOLDRED << "' is too long" << RESET << std::endl;
            return (false);
        }
        tmp = std::atol(av[i]);
        if (tmp > INT_MAX || tmp < 0)
        {
            std::cout << BOLDRED << "Error: " << RESET << "Number '" << tmp 
                << BOLDRED << "' is out of range. Only positive integers " 
                << "are accepted" << RESET << std::endl;
            return (false);
        }
    }
    return (true);
}

/* storeVector:
** 1. check if the arguments are positive integers
** 2. store the number in the vector as int*/
void PmergeMe::storeVector(int ac, char **av)
{
    int i;

    if (checkPositiveIntegers(ac, av) == false)
        return ;
    for (i = 1; i < ac; i++)
        this->pmergeVector.push_back(std::atoi(av[i]));
}

/* storeList:
** 1. check if the arguments are positive integers
** 2. store the number in the list as int*/
void PmergeMe::storeList(int ac, char **av)
{
    int i;

    if (checkPositiveIntegers(ac, av) == false)
        return ;
    for (i = 1; i < ac; i++)
        this->pmergeList.push_back(std::atoi(av[i]));
}

/* doFordJohnsonVector:




