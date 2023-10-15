/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:33:25 by andrefranci       #+#    #+#             */
/*   Updated: 2023/10/15 13:58:00 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".../includes/PmergeMe.hpp"

int	main(int ac, char **av)
{
	PmergeMe	pmergeMe;

	if (pmergeMe.validateArgs(ac, av))
	{
		pmergeMe.doFordJohnson();
		pmergeMe.printUnsortedVector();
		pmergeMe.printSortedVector();
		pmergeMe.printTimeUsedVector();
		pmergeMe.printUnsortedList();
		pmergeMe.printSortedList();
		pmergeMe.printTimeUsedList();
	}
	return (0);
}