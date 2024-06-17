# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnavidd <nnavidd@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 09:27:14 by nnabaeei          #+#    #+#              #
#    Updated: 2024/06/18 00:45:09 by nnavidd          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := serialization
CXX      := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g
CXXFLAGS += -fsanitize=address -Wshadow -Wno-shadow

# Directories
SRC_DIR := src
INCLUDE_DIR := include
OBJ_DIR := obj

# Find all .cpp files in the SRC directory
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)

# Find all .hpp files in the INCLUDE directory
HEADERS := $(wildcard $(INCLUDE_DIR)/*.hpp)

# Generate object file names
OBJ_FILES := $(addprefix $(OBJ_DIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
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

.PHONY: all, clean, fclean, re

BLUE	= "\033[38;5;4m"
GREEN	= "\033[38;5;2m"
ORG		= "\033[38;5;214m"
RED		= "\033[38;5;196m"
RESET	= "\033[0m"

# define BLUE		"\033[38;5;4m"
# define MAGENTA	"\033[38;5;5m"
# define CYAN		"\033[38;5;44m"
# define GREEN		"\033[38;5;2m"
# define ORG		"\033[38;5;214m"
# define RED		"\033[38;5;196m"
# define RESET		"\033[0m"