# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpicard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 19:11:24 by anpicard          #+#    #+#              #
#    Updated: 2025/08/07 13:52:49 by anpicard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

SRC_DIR     = src
OBJ_DIR     = .objects
INC_DIR     = include
LIBFT_DIR   = libft
MLX_DIR     = mlx_linux

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx_Linux.a

CFLAGS      = -Wall -Wextra -Werror -g3
MLX_FLAGS   = -I/usr/include -I$(MLX_DIR)
MLX_LINKS   = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

LST_SRCS	= $(shell find $(SRC_DIR) -name "*.c")
LST_OBJS    = $(LST_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRCS        = $(LST_SRCS)
OBJS        = $(LST_OBJS)

INCS        = -I$(INC_DIR) -I$(LIBFT_DIR)/includes

CC          = cc
NAME        = miniRT

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LINKS) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT) $(MLX)

re: fclean all

bonus: all
