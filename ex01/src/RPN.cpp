/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefrancisco <andrefrancisco@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:16:46 by abaiao-r          #+#    #+#             */
/*   Updated: 2023/10/15 02:34:02 by andrefranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

/* Default Constructor */
RPN::RPN(void)
{
	std::cout << CYAN << "RPN default constructor called" << RESET << std::endl;
	return ;
}

/* Copy Constructor */
RPN::RPN(RPN const &src)
{
	std::cout << CYAN << "RPN copy constructor called" << RESET << std::endl;
	*this = src;
	return ;
}

/* Destructor */
RPN::~RPN(void)
{
	std::cout << RED << "RPN destructor called" << RESET << std::endl;
	return ;
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

/* printResult:
** 1. If the stack has more than one number, throw an error
** 2. If the stack is empty, throw an error
** 3. If the stack has one number, print it and return
*/
void RPN::printResult(void)
{
	if (this->_rpn_stack.size() > 1)
	{
		std::cerr << BOLDRED << "Error: " << RESET
					<< "Too many numbers in stack" << std::endl;
		return ;
	}
	else if (this->_rpn_stack.size() == 0)
	{
		std::cerr << BOLDRED << "Error: " << RESET
					<< "No numbers in stack" << std::endl;
		return ;
	}
	std::cout << this->_rpn_stack.top() << std::endl;
	return ;
}

/* performOperation:
** 1. If the stack has at least 2 numbers, pop the last two numbers from the 
** stack and perform the operation
*/
void RPN::performOperation(std::string token)
{
	int	num1;
	int	num2;

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
		if (num1 == 0)
		{
			std::cerr << BOLDRED << "Error: " << RESET
						<< "Division by zero" << std::endl;
			return ;
		}
		else
			this->_rpn_stack.push(num2 / num1);
	}
}

/* handleLargeToken:
** 1. Check if token is a number larger than 1 digit
** 2. If it is larger than 1 digit, throw an error
*/
bool RPN::handleLargeToken(std::string token)
{
	if (token.length() > 1)
	{
		if (token[0] == '-')
		{
			std::cerr << BOLDRED << "Error: " << RESET
						<< "Negative number" << std::endl;
			return (false);
		}
		if (token[0] == '+' && token.length() <= 2)
			return (true);
		std::cerr << BOLDRED << "Error: " << RESET
					<< "Number with more than 1 digit" << std::endl;
		return (false);
	}
	return (true);
}

/* checkStr:
** 1. Check if str is only spaces or digits or operators
** 2. If it is not, throw an error
*/
bool RPN::checkStr(std::string str)
{
	if (str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
	{
		std::cerr << BOLDRED << "Error: " << RESET
					<< "Invalid character "
					<< "'" << str[str.find_first_not_of("0123456789+-*/ ")] << "'"
					<< std::endl;
		return (false);
	}
	return (true);
}

/* rpncalc:
** 1. Check if str is valid
** 2. If it is not, throw an error
** 3. If it is valid, read the string stream and put the values in token
** 4. If token is a number, push it to the stack
** 5. If token is an operator, perform the operation
** 6. If token is not a number or an operator, throw an error
*/
void RPN::rpncalc(std::string str)
{
	int	num;

	std::stringstream ss(str);
	std::string token;
	if (!checkStr(str))
		return ;
	while (ss >> token)
	{
		if (std::stringstream(token) >> num)
		{
			if (!handleLargeToken(token))
				return ;
			this->_rpn_stack.push(num);
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (this->_rpn_stack.size() < 2)
			{
				std::cerr << BOLDRED << "Error: " << RESET
							<< "Not enough numbers in stack" << std::endl;
				return ;
			}
			performOperation(token);
		}
		else
		{
			std::cerr << BOLDRED << "Error: " << RESET
						<< "Invalid character "
						<< "'" << token << "'" << std::endl;
			return ;
		}
	}
	printResult();
	return ;
}
