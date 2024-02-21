# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 13:17:32 by mrusu             #+#    #+#              #
#    Updated: 2024/02/20 17:34:29 by mrusu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILER
CC = cc

# FLAGS FOR COMPILATION
FLAGS = -Wall -Wextra -Werror

# PROGRAM NAME
PROGRAM = push_swap
PROGRAM_CHECKER = checker

# DIRECTORIES
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = inc

HEADER = $(INC_DIR)/push_swap.h

# LIBFT
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# LIST OF SOURCE FILES
SRCSS_PUSH_SWAP = $(filter-out $(SRC_DIR)/checker.c, $(wildcard $(SRC_DIR)/*.c))
SRCSS_CHECKER = $(filter-out $(SRC_DIR)/main.c, $(wildcard $(SRC_DIR)/*.c))

# OBJECT FILES
OBJS_PUSH_SWAP = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCSS_PUSH_SWAP))
OBJS_CHECKER = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCSS_CHECKER))

# RULES BONUS
BONUS_DIR = checker
BONUS_SRC = $(wildcard $(BONUS_DIR)/*.c)
BONUS_OBJ = $(BONUS_SRC:$(BONUS_DIR)/%.c=$(OBJ_DIR)/$(BONUS_DIR)/%.o)

# COLORS
GREEN = \033[0;32m
NC = \033[0m

# Bonus checker rule
bonus: $(LIBFT) $(PROGRAM) $(PROGRAM_CHECKER)
	@echo "$(GREEN)Build successful$(NC)"

# ALL RULE
# RULES TO MAKE THE PROGRAM
all: $(LIBFT) $(PROGRAM)
	@echo "$(GREEN)Build successful$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -I$(LIBFT_DIR)/$(INC_DIR) -c $< -o $@

$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

$(PROGRAM): $(OBJS_PUSH_SWAP)
	@echo "$(GREEN)Linking $(PROGRAM)$(NC)"
	@$(CC) $(FLAGS) -o $(PROGRAM) $(OBJS_PUSH_SWAP) $(LIBFT)

$(PROGRAM_CHECKER): $(OBJS_CHECKER) $(BONUS_OBJ)
	@echo "$(GREEN)Linking $(PROGRAM_CHECKER)$(NC)"
	@$(CC) $(FLAGS) -o $(PROGRAM_CHECKER) $(OBJS_CHECKER) $(BONUS_OBJ) $(LIBFT)

# Dependency for bonus
$(BONUS_OBJ): $(OBJ_DIR)/$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Object files created: $@$(RESET)"

# RULES TO CLEAN EVERYTHING
clean:
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(BONUS_OBJ)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(PROGRAM) $(PROGRAM_CHECKER)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

# RULES FOR RECOMPILATION
re: fclean all

# PHONY targets
.PHONY: all clean fclean re