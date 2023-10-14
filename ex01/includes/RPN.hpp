/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:15:50 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/14 15:59:34 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <map>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <limits>
#include "colours.hpp"

class RPN
{
private:
    std::stack<int> _rpn_stack;

public:
    RPN(void);
    RPN(RPN const &src);
    ~RPN(void);

    RPN &operator=(RPN const &src);

    // convert argv to int and push to stack
    // if argv is not a number, check if it is an operator
    // if it is an operator, pop the last two numbers from the stack
    // and perform the operation
    // if it is not an operator, throw an error
    // if the stack has more than one number, throw an error
    // if the stack is empty, throw an error
    // if the stack has one number, print it and return
    // if the stack has no numbers, return
    
    void rpncalc(std::string str);

};

#endif
