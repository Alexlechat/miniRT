# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 19:11:24 by anpicard          #+#    #+#              #
#    Updated: 2025/10/18 14:48:25 by allefran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT

# Directories
SRC_DIR		= src
OBJ_DIR		= .objects
INC_DIR		= include
LIBFT_DIR	= libft
MLX_DIR		= mlx_linux

# Libraries
LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx.a

# Source files
SRCS		= $(SRC_DIR)/core/main.c \
				$(SRC_DIR)/core/utils.c \
				$(SRC_DIR)/display/calculate/camera.c \
				$(SRC_DIR)/display/calculate/light.c \
				$(SRC_DIR)/display/create_ray.c \
				$(SRC_DIR)/display/init_display.c \
				$(SRC_DIR)/display/intersection/cylinder.c \
				$(SRC_DIR)/display/intersection/cylinder_caps.c \
				$(SRC_DIR)/display/intersection/cylinder_utils.c \
				$(SRC_DIR)/display/intersection/intersection.c \
				$(SRC_DIR)/display/intersection/plane.c \
				$(SRC_DIR)/display/intersection/sphere.c \
				$(SRC_DIR)/display/normal.c \
				$(SRC_DIR)/display/quadratic.c \
				$(SRC_DIR)/display/reflection.c \
				$(SRC_DIR)/display/render.c \
				$(SRC_DIR)/display/window.c \
				$(SRC_DIR)/maths/maths_utils.c \
				$(SRC_DIR)/maths/vector_operation.c \
				$(SRC_DIR)/maths/vector_utils.c \
				$(SRC_DIR)/parsing/elements/ambient.c \
				$(SRC_DIR)/parsing/elements/camera.c \
				$(SRC_DIR)/parsing/elements/light.c \
				$(SRC_DIR)/parsing/file.c \
				$(SRC_DIR)/parsing/objects/add_cy.c \
				$(SRC_DIR)/parsing/objects/add_pl.c \
				$(SRC_DIR)/parsing/objects/add_sp.c \
				$(SRC_DIR)/parsing/objects/bonus_objects.c \
				$(SRC_DIR)/parsing/parsing.c \
				$(SRC_DIR)/parsing/parsing_dispatch.c \
				$(SRC_DIR)/parsing/parsing_helpers.c \
				$(SRC_DIR)/parsing/utils/coordinate_utils.c \
				$(SRC_DIR)/parsing/utils/elements_utils.c \
				$(SRC_DIR)/parsing/utils/number_utils.c \
				$(SRC_DIR)/parsing/utils/trim_utils.c \
				$(SRC_DIR)/parsing/validation/validation_helpers.c \
				$(SRC_DIR)/parsing/validation/validation_utils.c

# Object files
OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Headers
HEADERS		= $(INC_DIR)/display.h \
				$(INC_DIR)/elements.h \
				$(INC_DIR)/objects.h \
				$(INC_DIR)/parsing.h \
				$(INC_DIR)/utils.h \
				$(INC_DIR)/vectors.h

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -I$(LIBFT_DIR)/includes -I$(MLX_DIR)
LDFLAGS		= -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
RM			= rm -f

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS) Makefile $(MLX)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)✓$(RESET) Compiled $<"

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX): FORCE
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "$(RED)✗ Object files removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)✗ $(NAME) removed$(RESET)"

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE
