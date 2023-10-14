/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:16:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/14 18:48:15 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/* Default Constructor */
RPN::RPN(void)
{
    std::cout << CYAN << "RPN default constructor called" << RESET << std::endl;
    return;
}

/* Copy Constructor */
RPN::RPN(RPN const &src)
{
    std::cout << CYAN << "RPN copy constructor called" << RESET << std::endl;
    *this = src;
    return;
}

/* Destructor */
RPN::~RPN(void)
{
    std::cout << RED << "RPN destructor called" << RESET << std::endl;
    return;
}

/* Assignment operator overload (Update) */
RPN &RPN::operator=(RPN const &src)
{
    std::cout << CYAN << "RPN assignment operator called" << RESET << std::endl;
    if (this != &src)
    {
        this->_rpn_stack = src._rpn_stack;
    }
    return (*this);
}


// convert argv to int and push to stack
// if argv is not a number, check if it is an operator
// if it is an operator, pop the last two numbers from the stack
// and perform the operation
// if it is not an operator, throw an error
// if the stack has more than one number, throw an error
// if the stack is empty, throw an error
// if the stack has one number, print it and return
// if the stack has no numbers, return
void RPN::rpncalc(std::string str)
{
    std::stringstream ss(str);
    std::string token;
    int num;
    int num1;
    int num2;

    //check if str is only spaces or digits or operators
    if (str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
    {
        std::cerr << BOLDRED << "Error: " << RESET 
            << "Invalid character" << std::endl;
        return;
    }
    while (ss >> token)
    {
        if (std::stringstream(token) >> num)
        {
            // check if num is an is less than 2 digits
            if (token.length() > 1)
            {
                if (token[0] == '-')
                {
                    std::cerr << BOLDRED << "Error: " << RESET 
                        << "Negative number" << std::endl;
                    return;
                }
                if (token[0] == '+')
                {
                    break;
                }
                std::cerr << BOLDRED << "Error: " << RESET 
                    << "Number with more than 1 digit" << std::endl;
                return;
            }
            this->_rpn_stack.push(num);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%")
        {
            if (this->_rpn_stack.size() < 2)
            {
                std::cerr << BOLDRED << "Error: " << RESET 
                    << "Not enough numbers in stack" << std::endl;
                return;
            }
            num1 = this->_rpn_stack.top();
            this->_rpn_stack.pop();
            num2 = this->_rpn_stack.top();
            this->_rpn_stack.pop();
            if (token == "+")
                this->_rpn_stack.push(num2 + num1);
            else if (token == "-")
                this->_rpn_stack.push(num2 - num1);
            else if (token == "*")
                this->_rpn_stack.push(num2 * num1);
            else if (token == "/")
            {
                if(num1 == 0)
                {
                    std::cerr << BOLDRED << "Error: " << RESET 
                        << "Division by zero" << std::endl;
                    return;
                }
                else
                    this->_rpn_stack.push(num2 / num1);
            }
            else if (token == "%")
                this->_rpn_stack.push(num2 % num1);
        }
        else
        {
            std::cerr << BOLDRED << "Error: " << RESET 
                << "Invalid character" << std::endl;
            return;
        }
    }
    if (this->_rpn_stack.size() > 1)
    {
        std::cerr << BOLDRED << "Error: " << RESET 
            << "Too many numbers in stack" << std::endl;
        return;
    }
    else if (this->_rpn_stack.size() == 0)
    {
        std::cerr << BOLDRED << "Error: " << RESET 
            << "No numbers in stack" << std::endl;
        return;
    }
    std::cout << this->_rpn_stack.top() << std::endl;
    return;
}
