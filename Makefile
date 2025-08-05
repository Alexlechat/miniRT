.PHONY: all clean fclean re

MLX			= $(MLX_DIR)/libmlx_Linux.a
MLX_DIR		= mlx_linux
MLX_FLAGS	= -I/usr/include -Imlx_linux
MLX_LINKS	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz


SRC_DIR		= sources
OBJ_DIR		= .objects
INC_DIR		= include
LIBFT_DIR	= libft
LIBFT		=	$(LIBFT_DIR)/libft.a

LST_SRCS	= main.c	

LST_INCS	=	miniRT.h
LST_OBJS	=	$(LST_SRCS:.c=.o)

SRCS		=	$(addprefix $(SRC_DIR)/, $(LST_SRCS))
INCS		=	$(addprefix $(INC_DIR)/, $(LST_INCS))
OBJS		=	$(addprefix $(OBJ_DIR)/, $(LST_OBJS))

CC 			=	cc
NAME		=	miniRT
FLAGS 		=	-Wall -Wextra -Werror -lm

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/scene $(OBJ_DIR)/mlx
	$(CC) $(FLAGS) $(MLX_FLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/include -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT): force
	$(MAKE) -C $(LIBFT_DIR)

force:
$(NAME):	$(LIBFT) $(MLX) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MLX_LINKS) $(LIBFT) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(MLX_DIR)/obj
	make clean -C $(LIBFT_DIR)


fclean: clean
	make clean -C $(MLX_DIR)
	rm -f $(NAME) $(LIBFT)

re: fclean all
