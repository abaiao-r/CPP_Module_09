/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:58:38 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/17 20:10:18 by abaiao-r         ###   ########.fr       */
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

std::vector<int> PmergeMe::groupPairsVector()
{
    std::vector<int> pairs;
    size_t n = this->pmergeVector.size();
    size_t i = 0;


    while (i < n) 
    {
        if (n % 2 == 1 && i == n - 1)
        {
            pairs.push_back(this->pmergeVector[i]);
            break;
        }
        if (i + 1 < n && this->pmergeVector[i] > this->pmergeVector[i + 1]) 
        {
            pairs.push_back(this->pmergeVector[i]);
            this->pmergeVectorRemainder.push_back(this->pmergeVector[i + 1]);
        } else 
        {
            pairs.push_back(this->pmergeVector[i + 1]);
            this->pmergeVectorRemainder.push_back(this->pmergeVector[i]);
        }
        i += 2;
    }

    return (pairs);
}

std::vector<int> PmergeMe::sortedLargerElementsVector(std::vector<int> &pairs)
{
    if (pairs.size() <= 1)
    {
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

std::vector<int> PmergeMe::insertRemainingVector(std::vector<int> S)
{

    for (std::vector<int>::iterator it = this->pmergeVectorRemainder.begin(); it != this->pmergeVectorRemainder.end(); ++it)
    {
        std::vector<int>::iterator low = std::lower_bound(S.begin(), S.end(), *it);
        S.insert(low, *it);
    }

    return S;
}

void PmergeMe::doFordJohnsonVector() 
{
    std::vector<int> pairs = groupPairsVector();
    std::vector<int> sorted = sortedLargerElementsVector(pairs);
    std::vector<int> S = sorted;

    // remove everything from pmergeVector
    this->pmergeVector.clear();
    // insert everything from S into pmergeVector usinge insertRemainingVector
    this->pmergeVector = insertRemainingVector(S);

    // stop timer
    currentTimerVector();
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

/* startTimerVector:
** start the timer*/
void PmergeMe::startTimerVector(void)
{
    this->startTimeVector = std::clock();
}

/* currentTimerVector:
** calculate the time used by the algorithm to sort the vector*/
void PmergeMe::currentTimerVector(void)
{
    std::clock_t endTime = std::clock();
    double elapsedTime = static_cast<double>(endTime - this->startTimeVector) / CLOCKS_PER_SEC * 1000000;
    this->currentTimeVector = elapsedTime;
}

/* printTimeUsedVector:
** calculate the time used by the algorithm to sort the vector
** print the time used*/
void PmergeMe::printTimeUsedVector(void)
{
    std::cout << "Time to process a range of " << this->pmergeVector.size() 
        << " elements with std::vector: ";
    std::cout << this->currentTimeVector << " us" << std::endl;
    std::cout << std::endl;
}

/* doFordJohnsonList:
** Ford-Johnson algorithm for std::list*/
void PmergeMe::doFordJohnsonList(void)
{

    std::list<int> pairs = groupPairsList();
    std::list<int> sorted = sortedLargerElementsList(pairs);
    std::list<int> S = sorted;
    // delete everything from pmergeList all nodes
    this->pmergeList.clear();
    // insert everything from S into pmergeList using insertRemainingList
    this->pmergeList = insertRemainingList(S);

    // stop timer
    currentTimerList();
}

/* groupPairsList:
** group pairs of elements in the list*/
std::list<int> PmergeMe::groupPairsList()
{
    std::list<int> pairs;
    size_t n = this->pmergeList.size();
    size_t i = 0;

    while (i < n) 
    {
        if (n % 2 == 1 && i == n - 1)
        {
            pairs.push_back(this->pmergeList.back());
            break;
        }

        std::list<int>::iterator it = this->pmergeList.begin();
        std::advance(it, i);
        int current = *it;

        std::advance(it, 1);
        int next = *it;

        if (it != this->pmergeList.end() && current > next) 
        {
            pairs.push_back(current);
            this->pmergeListRemainder.push_back(next);
        } else 
        {
            pairs.push_back(next);
            this->pmergeListRemainder.push_back(current);
        }
        i += 2;
    }

    return (pairs);
}

/* sortedLargerElementsList:
** sort the larger elements in the list*/
std::list<int> PmergeMe::sortedLargerElementsList(std::list<int> pairs)
{
    if (pairs.size() <= 1)
    {
        return pairs;
    }

    size_t mid = pairs.size() / 2;

    std::list<int> left;
    std::list<int>::iterator it = pairs.begin();
    std::advance(it, mid);
    std::copy(pairs.begin(), it, std::back_inserter(left));

    std::list<int> right;
    std::copy(it, pairs.end(), std::back_inserter(right));

    left = sortedLargerElementsList(left);
    right = sortedLargerElementsList(right);

    std::list<int> sorted;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::inserter(sorted, sorted.begin()));

    return sorted;
}

/* insertRemainingList:
** insert the remaining elements in the list*/
std::list<int> PmergeMe::insertRemainingList(std::list<int> S)
{
    for (std::list<int>::iterator it = this->pmergeListRemainder.begin(); it != this->pmergeListRemainder.end(); ++it)
    {
        std::list<int>::iterator low = std::lower_bound(S.begin(), S.end(), *it);
        S.insert(low, *it);
    }

    return S;
}

/* printList:
** print the list*/
void PmergeMe::printList(void)
{
    std::cout << "List: ";
    for (std::list<int>::iterator it = this->pmergeList.begin(); it != this->pmergeList.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

/* startTimerList:
** start the timer*/
void PmergeMe::startTimerList(void)
{
    this->startTimeList = std::clock();
}

/* currentTimerList:
** calculate the time used by the algorithm to sort the list in microseconds
** formula: (endTime - startTime) / CLOCKS_PER_SEC * 1000000*/
void PmergeMe::currentTimerList(void)
{
    std::clock_t endTime = std::clock();
    double elapsedTime = static_cast<double>(endTime - this->startTimeList) / CLOCKS_PER_SEC * 1000000;
    this->currentTimeList = elapsedTime;
}

/* printTimeUsedList:
** calculate the time used by the algorithm to sort the list
** print the time used*/
void PmergeMe::printTimeUsedList(void)
{
    std::cout << "Time to process a range of " << this->pmergeList.size() 
        << " elements with std::list: ";
    std::cout << this->currentTimeList << " us" << std::endl;
    std::cout << std::endl;
}