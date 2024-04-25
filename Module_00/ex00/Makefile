CC 			= g++  #-fsanitize=thread #-fno-omit-frame-pointer
FLAGS		= -Wall -Wextra -Werror -std=c++98 -g

NAME_PRJ	= ***CPP_ex00***
NAME		= megaphone
# NAME_BONUS 	= 

# LIBFT		= objs/libft/libft.a
# HEADER 		= -I./header/

SRC_DIR		= .
SRC_FILES	=  megaphone.cpp
SRC 		= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ1_DIR	= ./objs/mandatory
OBJ1_FILES 	=  megaphone.o
MAND_OBJS 	= $(addprefix $(OBJ1_DIR)/, $(OBJ1_FILES))

# BONUS_DIR	= ./bonus/
# BONUS_FILES	=  
# BONUS		= $(addprefix $(BONUS_DIR), $(BONUS_FILES))

# OBJ2_DIR	= ./objs/bonus
# OBJ2_FILES 	=  
# BONUS_OBJS 	= $(addprefix $(OBJ2_DIR)/, $(OBJ2_FILES))


all: $(NAME)

# bonus : $(NAME_BONUS)

$(NAME): $(MAND_OBJS) 

	@echo "\033[38;5;214m         $(NAME_PRJ)"
#	@echo "\033[38;5;214m ⠀⢀⣠⣄⡀⠀⠀⠀⣠⣶⣾⣿⣿⣶⣦⣴⣾⣿⣿⣷⣦⣄⠀⠀⠀⢀⣠⣄⡀"
#	@echo "\033[38;5;214m ⣰⣿⠟⠛⢻⡆⣠⣾⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣷⡄⢰⠟⠛⢻⣿⣦" 
#	@echo "\033[38;5;214m ⢻⣿⣦⣀⣤⣾⣿⣿⣿⣿⣿⣿⠟⠋⠀⠀⠙⠿⣿⣿⣿⣿⣿⣿⣦⣤⣀⣼⣿⡿" 
#	@echo "\033[38;5;214m  ⠙⠿⢿⣿⣿⡿⠿⠟⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⠿⢿⣿⣿⡿⠿⠋⠀"
#	@echo "                                                 "
#	@echo "    												"
#	@echo "                                                 "
#	@echo "\033[38;5;214m-----Linking all objective files-----"
	@$(CC) $(FLAGS) -o $(NAME) $(MAND_OBJS)
	@echo "                                                 "

$(NAME_BONUS): $(BONUS_OBJS)
	@echo "\033[38;5;214m-----BONES PART-----"
	@$(CC) $(FLAGS) -g -o $(NAME_BONUS) $(BONUS_OBJS)
	
$(OBJ1_DIR)/%.o : $(SRC_DIR)/%.cpp | $(OBJ1_DIR)
	@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(OBJ2_DIR)/%.o : $(BONUS_DIR)/%.c | $(OBJ2_DIR)
	@$(CC) $(FLAGS) $(HEADER) -c $< -o $@

$(OBJ1_DIR):
	@echo "\033[38;5;214m-----Compiling the source files-----"
	@mkdir -p $(OBJ1_DIR)

$(OBJ2_DIR):
	@mkdir -p $(OBJ2_DIR)


clean:
	@rm -f $(OBJ1_FILES)
	@rm -f $(OBJ2_FILES)
	@rm -rf $(OBJ1_DIR)
	@rm -rf $(OBJ2_DIR)
	@rm -rf ./objs
	@echo "\033[38;5;214m-----Object files successfully cleaned-----"
	@echo "                                                 "


fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@if [ -e ./.vscode ]; then rm -rf ./.vscode; fi
	@if [ -e ./imgui.ini ]; then rm ./imgui.ini; fi
	@echo "\033[38;5;214m-----$(NAME) executable file successfully cleaned-----"
	@echo "                                                 "


re: fclean all
	@echo "\033[38;5;214m-----All objects and executable file successfully cleaned and rebuilt-----"
	@echo "                                                 "

.PHONY: all clean fclean re