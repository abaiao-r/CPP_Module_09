/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:14:20 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/15 00:28:14 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/* main:
** 1. Create an instance of RPN
** 2. Check if there is only one argument
** 3. Call rpncalc
*/
int	main(int argc, char **argv)
{
	RPN	rpn;

	if (argc != 2)
	{
		std::cerr << BOLDRED << "Error: " << RESET
					<< "Wrong number of arguments" << std::endl;
		return (1);
	}
	rpn.rpncalc(argv[1]);
	return (0);
}
