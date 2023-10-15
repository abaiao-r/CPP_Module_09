/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:33:52 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/15 14:31:39 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <algorithm>
# include <iomanip>
# include <list>
# include <vector>
# include <deque>
# include <set>
# include <ctime>
# include <cstdlib>
# include <cmath>
# include <climits>
# include <cctype>
# include <cstring>



# include "colours.hpp"

class PmergeMe
{
    private:
        std::vector<int> pmergeVector;
        std::list<int> pmergeList;

    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const &src);
        ~PmergeMe(void);

        PmergeMe &operator=(PmergeMe const &src);

        bool validateArgs(int ac, char **av);
        // check if the arguments are positive integers
        bool checkPositiveIntegers(int ac, char **av);
        // convert av to int and store it in the vector
        void storeVector(int ac, char **av);
        // convert av to int and store it in the list
        void storeList(int ac, char **av);
        
        // do ford johnson algorithm to sort the vector
        void doFordJohnsonVector(void);
        // print vector
        void printVector(void);
        // time used by the algorithm to sort the vector
        void printTimeUsedVector(void);

        // do ford johnson algorithm to sort the list
        void doFordJohnsonList(void);
        // print list
        void printList(void);
        // time used by the algorithm to sort the list
        void printTimeUsedList(void);


};

#endif
