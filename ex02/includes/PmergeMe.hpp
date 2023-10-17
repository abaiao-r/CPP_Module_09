/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:33:52 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/17 16:27:23 by abaiao-r         ###   ########.fr       */
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
# include <cerrno>
# include <cfloat>
# include <csignal>
# include <cstddef>
# include <cstdio>
# include <ctime>





# include "colours.hpp"

class PmergeMe
{
    private:
        std::vector<int> pmergeVector;
        std::vector<int> pmergeVectorRemainder;
        std::list<int> pmergeList;
        std::list<int> pmergeListRemainder;
      
        // start time
        std::clock_t startTimeVector;
        // end time
        std::clock_t currentTimeVector;

        // start time
        std::clock_t startTimeList;
        // end time
        std::clock_t currentTimeList;
        

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
        std::vector<int> insertRemainingVector(std::vector<int> S);
        std::vector<int> sortedLargerElementsVector(std::vector<int> &pairs);
        std::vector<int> groupPairsVector();
        void doFordJohnsonVector(void);
        // print vector
        void printVector(void);
  
        // time used by the algorithm to sort the vector
        void startTimerVector(void);
        void currentTimerVector(void);
        void printTimeUsedVector(void);

        // do ford johnson algorithm to sort the list
        std::list<int> insertRemainingList(std::list<int> S);
        std::list<int> sortedLargerElementsList(std::list<int> pairs);
        std::list<int> groupPairsList();
        void doFordJohnsonList(void);
       
        // print list
        void printList(void);


        // time used by the algorithm to sort the list
        void printTimeUsedList(void);
        void startTimerList(void);
        void currentTimerList(void);


};

#endif
