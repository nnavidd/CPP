# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnabaeei <nnabaeei@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/27 09:28:38 by nnabaeei          #+#    #+#              #
#    Updated: 2024/04/27 09:28:40 by nnabaeei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := PhoneBook
CXX      := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g
CXXFLAGS += -fsanitize=address

CPP_FILES := main.cpp Contact.cpp PhoneBook.cpp
HEADERS   := Contact.hpp PhoneBook.hpp

OBJ_DIR := obj

OBJ_FILES := $(addprefix $(OBJ_DIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

all: $(NAME)


$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	@$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(NAME) $(LDFLAGS)
	@echo "\033[38;5;214m-----executable file has been created!-----"
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re