/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:15:50 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/15 02:07:20 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include "colours.hpp"
# include <algorithm>
# include <cmath>
# include <cstdlib>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <limits>
# include <map>
# include <sstream>
# include <stack>
# include <string>
# include <vector>

class RPN
{
  private:
	std::stack<int> _rpn_stack;

  public:
	RPN(void);
	RPN(RPN const &src);
	~RPN(void);

	RPN &operator=(RPN const &src);

    // auxiliary functions
    bool checkStr(std::string str);
    bool handleLargeToken(std::string token);
    void performOperation(std::string token);
    void printResult(void);
    // principal function
	void rpncalc(std::string str);
};

#endif
