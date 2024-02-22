# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 13:17:32 by mrusu             #+#    #+#              #
#    Updated: 2024/02/22 16:01:07 by mrusu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILER
CC = cc

# FLAGS FOR COMPILATION
FLAGS = -Wall -Wextra -Werror

# PROGRAM NAMES
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

# LIST OF SOURCE FILES FOR PUSH_SWAP
SRCSS_PUSH_SWAP = $(SRC_DIR)/cmd_push.c $(SRC_DIR)/cmd_rotate.c $(SRC_DIR)/cmd_rev_rotate.c \
    $(SRC_DIR)/cmd_swap.c $(SRC_DIR)/sort_stacks0.c $(SRC_DIR)/sort_stacks1.c \
    $(SRC_DIR)/stack_create.c $(SRC_DIR)/stack_update.c $(SRC_DIR)/stack_utils0.c \
    $(SRC_DIR)/stack_utils1.c $(SRC_DIR)/special_split.c $(SRC_DIR)/main.c \
    $(SRC_DIR)/errors_handle.c

# LIST OF SOURCE FILES FOR CHECKER
SRCSS_CHECKER = $(SRC_DIR)/cmd_push.c $(SRC_DIR)/cmd_rotate.c $(SRC_DIR)/cmd_rev_rotate.c \
    $(SRC_DIR)/cmd_swap.c $(SRC_DIR)/errors_handle.c $(SRC_DIR)/sort_stacks0.c \
    $(SRC_DIR)/sort_stacks1.c $(SRC_DIR)/stack_create.c $(SRC_DIR)/stack_update.c \
    $(SRC_DIR)/stack_utils0.c $(SRC_DIR)/stack_utils1.c $(SRC_DIR)/special_split.c \
    $(SRC_DIR)/checker.c

# OBJECT FILES DIRECTORIES
OBJ_DIR_PUSH_SWAP = $(OBJ_DIR)/push_swap
OBJ_DIR_CHECKER = $(OBJ_DIR)/checker

# OBJECT FILES
OBJS_PUSH_SWAP = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR_PUSH_SWAP)/%.o, $(SRCSS_PUSH_SWAP))
OBJS_CHECKER = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR_CHECKER)/%.o, $(SRCSS_CHECKER))

# COLORS
GREEN = \033[0;32m
NC = \033[0m

# ALL RULE
# RULES TO MAKE THE PROGRAM
all: $(LIBFT) $(PROGRAM)
	@echo "$(GREEN)Build successful$(NC)"

$(PROGRAM): $(LIBFT) $(OBJS_PUSH_SWAP)
	@echo "$(GREEN)Linking $(PROGRAM)$(NC)"
	@$(CC) $(FLAGS) -o $(PROGRAM) $(OBJS_PUSH_SWAP) $(LIBFT)

# Bonus checker rule
bonus: $(LIBFT) $(PROGRAM_CHECKER)
	@echo "$(GREEN)Build successful$(NC)"

$(PROGRAM_CHECKER): $(LIBFT) $(OBJS_CHECKER)
	@echo "$(GREEN)Linking $(PROGRAM_CHECKER)$(NC)"
	@$(CC) $(FLAGS) -o $(PROGRAM_CHECKER) $(OBJS_CHECKER) $(LIBFT)

# RULES TO COMPILE OBJECT FILES
$(OBJ_DIR_PUSH_SWAP)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR_PUSH_SWAP)
	@$(CC) $(FLAGS) -I$(LIBFT_DIR)/$(INC_DIR) -c $< -o $@

$(OBJ_DIR_CHECKER)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR_CHECKER)
	@$(CC) $(FLAGS) -I$(LIBFT_DIR)/$(INC_DIR) -c $< -o $@

# Dependency for libft
$(LIBFT):
	@$(MAKE) -s -C $(LIBFT_DIR)

# RULES TO CLEAN EVERYTHING
clean:
	rm -f $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(PROGRAM) $(PROGRAM_CHECKER)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

# RULES FOR RECOMPILATION
re: fclean all