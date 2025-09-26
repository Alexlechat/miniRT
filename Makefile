# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 19:11:24 by anpicard          #+#    #+#              #
#    Updated: 2025/09/26 11:45:07 by allefran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

# ==== CONFIGURATION ====
NAME        := miniRT
CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g3

SRC_DIR     := src
OBJ_DIR     := .objects
INC_DIR     := include

LIBFT_DIR   := libft
LIBFT       := $(LIBFT_DIR)/libft.a
LIBFT_SRCS  := $(shell find $(LIBFT_DIR) -name "*.c")

MLX_DIR     := mlx_linux
MLX         := $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   := -I/usr/include -I$(MLX_DIR)
MLX_LINKS   := -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

INCS        := -I$(INC_DIR) -I$(LIBFT_DIR)/includes
SRCS        := $(shell find $(SRC_DIR) -name "*.c")
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LST_INCS	:=	$(shell find $(inc_dir) -name "*.h")

# ==== RULES ====

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS) $(LST_INCS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LINKS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(INCS) -c $< -o $@

$(LIBFT): $(LIBFT_SRCS)
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT) $(MLX)

re: fclean all

bonus: all
