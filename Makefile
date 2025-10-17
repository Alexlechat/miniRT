# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allefran <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/05 19:11:24 by anpicard          #+#    #+#              #
#    Updated: 2025/10/17 11:27:41 by allefran         ###   ########.fr        #
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

MLX_DIR     := mlx_linux
MLX         := $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   := -I/usr/include -I$(MLX_DIR)
MLX_LINKS   := -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

INCS        := -I$(INC_DIR) -I$(LIBFT_DIR)/includes

# Source files
SRCS        := src/core/utils.c \
                src/core/main.c \
                src/display/calculate/camera.c \
                src/display/calculate/light.c \
                src/display/intersection/cylinder_caps.c \
                src/display/intersection/cylinder_utils.c \
                src/display/intersection/cylinder.c \
                src/display/intersection/intersection.c \
                src/display/intersection/plane.c \
                src/display/intersection/sphere.c \
                src/display/init_display.c \
                src/display/window.c \
                src/display/display_utils.c \
                src/display/normal.c \
                src/display/create_ray.c \
                src/display/quadratic.c \
                src/display/reflection.c \
                src/display/render.c \
                src/maths/ray.c \
                src/maths/intersection.c \
                src/maths/maths_utils.c \
                src/maths/vector_utils.c \
                src/maths/vector_operation.c \
                src/parsing/elements/ambient.c \
                src/parsing/elements/camera.c \
                src/parsing/elements/light.c \
                src/parsing/file.c \
                src/parsing/objects/bonus_objects.c \
                src/parsing/objects/objects.c \
                src/parsing/objects/add_sp.c \
                src/parsing/objects/add_cy.c \
                src/parsing/objects/add_pl.c \
                src/parsing/parsing.c \
                src/parsing/parsing_dispatch.c \
                src/parsing/parsing_helpers.c \
                src/parsing/utils/coordinate_utils.c \
                src/parsing/utils/elements_utils.c \
                src/parsing/utils/number_utils.c \
                src/parsing/utils/trim_utils.c \
                src/parsing/validation/validation_helpers.c \
                src/parsing/validation/validation_utils.c

OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ==== RULES ====

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LINKS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(INCS) -c $< -o $@

$(LIBFT):
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
