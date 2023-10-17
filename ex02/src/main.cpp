/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:33:25 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/17 18:10:48 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe	pmergeMe;

	// before sorting
	std::cout << YELLOW << "Before sorting: ";
	for(int i = 0; i < ac; i++)
	{
		std::cout << av[i] << " ";
	}
	std::cout << RESET << "\n" << std::endl;
	if (pmergeMe.validateArgs(ac, av) && pmergeMe.checkPositiveIntegers(ac, av))
	{
		
		pmergeMe.startTimerVector();
		pmergeMe.storeVector(ac, av);
		pmergeMe.doFordJohnsonVector();

		pmergeMe.startTimerList();
		pmergeMe.storeList(ac, av);
		pmergeMe.doFordJohnsonList();

		std::cout << GREEN << "After sorting: ";
		pmergeMe.printVector();
		std::cout << RESET;
		pmergeMe.printTimeUsedVector();
		pmergeMe.printTimeUsedList();
	}

/* 	if (pmergeMe.validateArgs(ac, av) && pmergeMe.checkPositiveIntegers(ac, av))
	{
		pmergeMe.startTimerVector();
		pmergeMe.storeVector(ac, av);
		std::cout << "Before sorting ";
		pmergeMe.printVector();
		pmergeMe.doFordJohnsonVector();
		std::cout << "After sorting ";
		pmergeMe.printVector();
		pmergeMe.printTimeUsedVector();
	}
	if (pmergeMe.validateArgs(ac, av) && pmergeMe.checkPositiveIntegers(ac, av))
	{
		pmergeMe.startTimerList();
		pmergeMe.storeList(ac, av);
		std::cout << "Before sorting ";
		pmergeMe.printList();
		pmergeMe.doFordJohnsonList();
		std::cout << "After sorting ";
		pmergeMe.printList();
		pmergeMe.printTimeUsedList();
	} */
	return (0);
}

