# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 15:08:37 by abaiao-r          #+#    #+#              #
#    Updated: 2023/10/13 19:45:54 by abaiao-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -g #-fstandalone-debug #-fsanitize=address

# Directories
SRCDIR = src
OBJDIR = objs

# Source Files

SRCS =  $(SRCDIR)/main.cpp \
		$(SRCDIR)/BitcoinExchange.cpp

		
OBJS = 	$(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Targets
NAME = btc

all: 	$(NAME)


clean:
		rm -rf $(OBJDIR)

fclean:	clean
		rm -f $(NAME)

run:	fclean all
		./$(NAME)

re:		fclean all

test: 	all
		./$(NAME) input_file.txt
		@echo "\n-------------------\n"
		./$(NAME) csv_input/bad_header.txt
		@echo "\n-------------------\n"
		./$(NAME) csv_input/bad.txt
		@echo "\n-------------------\n"
		./$(NAME) csv_input/empty.txt
		@echo "\n-------------------\n"
		./$(NAME) csv_input/empty_line.txt
		@echo "\n-------------------\n"
		./$(NAME) csv_input/good.txt
		@echo "\n-------------------\n"
		./$(NAME) csv_input/no_records.txt


valgrind: fclean all
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

valgrind_test: fclean all
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) input_file.txt
		@echo "\n-------------------\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) csv_input/bad_header.txt
		@echo "\n-------------------\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) csv_input/bad.txt
		@echo "\n-------------------\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) csv_input/empty.txt
		@echo "\n-------------------\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) csv_input/empty_line.txt
		@echo "\n-------------------\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) csv_input/good.csv
		@echo "\n-------------------\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) csv_input/no_records.txt
		@echo "\n-------------------\n"
		valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) csv_input/ds.txt

$(NAME): 	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o  $(NAME) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean fclean re run test
