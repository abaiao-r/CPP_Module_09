/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:33:25 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/16 18:15:36 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe	pmergeMe;

	if (pmergeMe.validateArgs(ac, av) && pmergeMe.checkPositiveIntegers(ac, av))
	{
		pmergeMe.storeVector(ac, av);
		std::cout << "Before sorting ";
		pmergeMe.printVector();
		pmergeMe.doFordJohnsonVector();
		std::cout << "After sorting ";
		pmergeMe.printVector();
		pmergeMe.printTimeUsedVector();
	}
	return (0);
}

