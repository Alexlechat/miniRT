# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 19:11:24 by anpicard          #+#    #+#              #
#    Updated: 2025/08/06 11:12:09 by allefran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

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

LST_SRCS    = $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/*/*.c)
LST_INCS    = miniRT.h
LST_OBJS    = $(notdir $(LST_SRCS:.c=.o))

SRCS        = $(LST_SRCS)
INCS        = $(addprefix $(INC_DIR)/, $(LST_INCS))
OBJS        = $(addprefix $(OBJ_DIR)/, $(LST_OBJS))

CC          = cc
NAME        = miniRT

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/include -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(INCS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/include -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/src/*/*.c)

$(LIBFT): $(LIBFT_SRCS)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LINKS) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT) $(MLX)

re: fclean all
