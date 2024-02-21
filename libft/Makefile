# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/07 19:00:18 by mrusu             #+#    #+#              #
#    Updated: 2024/02/21 14:43:32 by mrusu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILER
CC = cc

# FLAGS FOR COMPILATION
FLAGS = -Wall -Wextra -Werror -g

# LIBRARY NAME
NAME = libft.a

# DIRECTORIES
SRC_DIR = srcs
INC_DIR = inc
OBJ_DIR = obj

# HEADER FILE
HEADER = $(INC_DIR)/libft.h

# LIST OF SOURCE FILES
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# COLORS
GREEN = \033[0;32m
NC = \033[0m

# ALL RULE
# RULES TO MAKE A LIBRARY
all: $(NAME)
	@echo "$(GREEN)libft build successful$(NC)"

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# RULES FOR CREATING OBJECT FILES
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I$(INC_DIR) -c $< -o $@

# RULES TO CLEAN EVERYTHING
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)libft cleaned$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(GREEN)libft fcleaned$(NC)"

# RULES FOR RECOMPILATION
re: fclean all

.PHONY: all clean fclean re