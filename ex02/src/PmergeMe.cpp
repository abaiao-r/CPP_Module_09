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
            if (!std::isdigit(av[i][j]))
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
**
1. Group the elements of X into floor(n/2) pairs of elements, arbitrarily,
   leaving one element unpaired if there is an odd number of elements.

2. Perform floor(n/2) comparisons, one per pair, to determine the larger
   of the two elements in each pair.

3. Recursively sort the floor(n/2) larger elements from each pair, creating
   a sorted sequence S of floor(n/2) of the input elements, in ascending order.

4. Insert at the start of S the element that was paired with the first and
   smallest element of S.

5. Insert the remaining ceil(n/2) - 1 elements of X \ S into S, one at a time,
   with a specially chosen insertion ordering. Use binary search in subsequences
   of S (as described below) to determine the position at which each element
   should be inserted.
*/
void PmergeMe::doFordJohnsonVector()
{
    int i;
    int pairSize;


    // 1. Group the elements of X into floor(n/2) pairs of elements
    i = 0;
    while(this->pmergeVector.size() > 0)
    {
        std::vector<int> pair;
        if (this->pmergeVector.size() == 1)
        {
            pair.push_back(this->pmergeVector[0]);
            this->pmergeVector.erase(this->pmergeVector.begin());
            this->pmergeVector.push_back(pair[0]);
            break ;
        }
        pair.push_back(this->pmergeVector[0]);
        this->pmergeVector.erase(this->pmergeVector.begin());
        pair.push_back(this->pmergeVector[0]);
        this->pmergeVector.erase(this->pmergeVector.begin());
        i++;
    }
    pairSize = i;
    i = 0;

    // 2. Perform floor(n/2) comparisons, one per pair, to determine the larger
    while ( i < pairSize)
    {
        if (pair[i][0] > pair[i][1])
        {
            int tmp = pair[i][0];
            pair[i][0] = pair[i][1];
            pair[i][1] = tmp;
        }
        i++;
    }

    // 3. Recursively sort the floor(n/2) larger elements from each pair, creating
    //    a sorted sequence S of floor(n/2) of the input elements, in ascending order.








    
    
}

/* printVector:
** print the vector*/
void PmergeMe::printVector(void)
{
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = this->pmergeVector.begin(); it != this->pmergeVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

/* printTimeUsedVector:
** calculate the time used by the algorithm to sort the vector
** print the time used*/
void PmergeMe::printTimeUsedVector(void)
{
    std::cout << "Time used by the algorithm to sort the vector: ";
    std::cout << std::endl;
}

