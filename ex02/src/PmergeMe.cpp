/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:58:38 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/16 21:38:56 by abaiao-r         ###   ########.fr       */
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
        if (tmp > INT_MAX || tmp <= 0)
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

std::vector<int> groupPairsVector(std::vector<int> &pmergeVector) {
    std::vector<int> pairs;
    size_t n = pmergeVector.size();
    size_t i = 0;

    while (i < n) {
        if (i + 1 < n && pmergeVector[i] > pmergeVector[i + 1]) {
            pairs.push_back(pmergeVector[i]);
        } else {
            pairs.push_back(pmergeVector[i + 1]);
        }
        i += 2;
    }

    if (n % 2 == 1) {
        pairs.push_back(pmergeVector[n - 1]);
    }

    return pairs;
}

std::vector<int> sortedLargerElementsVector(std::vector<int> &pairs) {
    if (pairs.size() <= 1) {
        return pairs;
    }

    size_t mid = pairs.size() / 2;
    std::vector<int> left(pairs.begin(), pairs.begin() + mid);
    std::vector<int> right(pairs.begin() + mid, pairs.end());

    left = sortedLargerElementsVector(left);
    right = sortedLargerElementsVector(right);

    std::vector<int> sorted;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(sorted));
    return sorted;
}

std::vector<int> insertPairedElementVector(std::vector<int> &sorted, int pairedElement) {
    std::vector<int> result;
    result.push_back(pairedElement);
    result.insert(result.end(), sorted.begin(), sorted.end());
    return result;
}

std::vector<int> insertRemainingVector(std::vector<int> &pmergeVector, std::vector<int> &S) {
    std::vector<int> remaining;

    for (size_t i = 0; i < pmergeVector.size(); ++i)
    {
        if (std::find(S.begin(), S.end(), pmergeVector[i]) == S.end()) {
            remaining.push_back(pmergeVector[i]);
        }
    }

    for (size_t i = 0; i < remaining.size(); ++i)
    {
        std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), remaining[i]);
        S.insert(it, remaining[i]);
    }

    return S;
}

void PmergeMe::doFordJohnsonVector() 
{
    std::vector<int> pairs = groupPairsVector(this->pmergeVector);

    std::cout << "Print Pairs: ";
    for (std::vector<int>::iterator it = pairs.begin(); it != pairs.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::vector<int> sorted = sortedLargerElementsVector(pairs);

    std::cout << "Print Sorted: ";
    for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    int pairedElement = *std::min_element(this->pmergeVector.begin(), this->pmergeVector.end());
    
    std::cout << "Print PairedElement: ";
    std::cout << "Print PairedElement: " << pairedElement;
    std::cout << std::endl;
    std::cout << "All Elements: ";
    for (unsigned int i = 0; i < this->pmergeVector.size(); i++)
        std::cout << this->pmergeVector[i] << " ";
    std::cout << std::endl;

    std::vector<int> S = insertPairedElementVector(sorted, pairedElement);

    std::cout << "S: ";
    for (std::vector<int>::iterator it = S.begin(); it != S.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "pmergeVector: ";
    for (std::vector<int>::iterator it = this->pmergeVector.begin(); it != this->pmergeVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    this->pmergeVector = insertRemainingVector(this->pmergeVector, S);

    std::cout << "pmergeVector: ";
    for (std::vector<int>::iterator it = this->pmergeVector.begin(); it != this->pmergeVector.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
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

