# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 09:27:14 by nnabaeei          #+#    #+#              #
#    Updated: 2025/05/12 11:12:19 by nnabaeei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := bts
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++17 -g
CXXFLAGS += -fsanitize=address -Wshadow -Wno-shadow

# Directories
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj

# Explicit source and header files
SRC_FILES := $(SRC_DIR)/main.cpp $(SRC_DIR)/BitcoinExchange.cpp
HEADER_FILES := $(INCLUDE_DIR)/BitcoinExchange.hpp


# Object files (same names as source, different extension, in obj/)
# patsubst converts each .cpp to corresponding .o inside obj/.
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADER_FILES)
	@mkdir -p $(@D)
	@$(CXX)  -c -o $@ $< $(CXXFLAGS) -I$(INCLUDE_DIR)

$(NAME): $(OBJ_FILES)
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME) $(LDFLAGS)
	@echo $(ORG)----- $(RESET)$(GREEN)$(NAME)$(RESET)$(ORG) as exe file is created!-----$(RESET)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re

BLUE	= "\033[38;5;4m"
GREEN	= "\033[38;5;2m"
ORG		= "\033[38;5;214m"
RED		= "\033[38;5;196m"
RESET	= "\033[0m"

