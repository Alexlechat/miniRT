# ----------------------------------------------Variables------------------------------------------

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror
AR := ar
ARFLAGS := rcs

# Directories
SRC_DIR := src/
OBJ_DIR := obj/
INC_DIR := includes/

# Source files
STR_FILES := str/ft_strlen.c str/ft_strlcpy.c str/ft_strlcat.c str/ft_strchr.c \
	str/ft_strrchr.c str/ft_strncmp.c str/ft_strnstr.c str/ft_strdup.c \
	str/ft_substr.c str/ft_strjoin.c str/ft_strtrim.c str/ft_split.c \
	str/ft_strmapi.c str/ft_striteri.c

MEM_FILES := mem/ft_memset.c mem/ft_bzero.c mem/ft_memcpy.c mem/ft_memmove.c \
	mem/ft_memchr.c mem/ft_memcmp.c mem/ft_calloc.c

CHAR_FILES := char/ft_isalpha.c char/ft_isdigit.c char/ft_isalnum.c \
	char/ft_isascii.c char/ft_isprint.c char/ft_toupper.c char/ft_tolower.c

LST_FILES := lst/ft_lstnew.c lst/ft_lstadd_front.c lst/ft_lstadd_back.c \
	lst/ft_lstsize.c lst/ft_lstlast.c lst/ft_lstdelone.c lst/ft_lstclear.c \
	lst/ft_lstiter.c lst/ft_lstmap.c

IO_FILES := io/ft_putchar_fd.c io/ft_putstr_fd.c io/ft_putendl_fd.c \
	io/ft_putnbr_fd.c io/ft_itoa.c io/ft_atoi.c

PRINTF_FILES := printf/ft_printf.c printf/ft_printf_utils.c printf/ft_printf_hex.c \
	printf/ft_printf_uns.c

GNL_FILES := gnl/get_next_line.c gnl/get_next_line_utils.c

# Object files
SRCS := $(STR_FILES) $(MEM_FILES) $(CHAR_FILES) $(LST_FILES) $(IO_FILES) $(PRINTF_FILES) $(GNL_FILES)
OBJS := $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS := $(OBJS:.o=.d)

# Headers
HEADERS := $(INC_DIR)libft.h $(INC_DIR)ft_printf.h $(INC_DIR)get_next_line.h

# Output
NAME := libft.a

# Progress bar variables
TOTAL_FILES := $(words $(SRCS))
CURR_FILE := 0

# Colors and formatting
DEF_COLOR := \033[0;39m
YELLOW := \033[0;93m
GREEN := \033[0;92m
BLUE := \033[0;94m
CYAN := \033[0;96m
BOLD := \033[1m

# Silent mode (make V=1 for verbose output)
ifndef V
	MAKEFLAGS += --silent
	VERBOSE := @
else
	VERBOSE :=
endif

# -----------------------------------TARGET---------------------------------------------------

all: $(NAME)

# Create object directory with subdirectories
$(OBJ_DIR)%/:
	$(VERBOSE)mkdir -p $@

# Compile objects with dependency files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS) Makefile | $(dir $(OBJS))
	$(eval CURR_FILE := $(shell echo $$(($(CURR_FILE) + 1))))
	$(VERBOSE)printf "$(YELLOW)Compiling [%3d%%] %-33s$(DEF_COLOR)\r" $$(($(CURR_FILE) * 100 / $(TOTAL_FILES))) $(notdir $<)
	$(VERBOSE)$(CC) $(CFLAGS) -MMD -MP -I$(INC_DIR) -c $< -o $@

# Link library
$(NAME): $(OBJS)
	$(VERBOSE)$(AR) $(ARFLAGS) $@ $?
	$(VERBOSE)printf "\n$(GREEN)$(BOLD)Library '$(NAME)' compiled successfully$(DEF_COLOR)\n"

# Clean targets
clean:
	$(VERBOSE)rm -rf $(OBJ_DIR)
	$(VERBOSE)printf "$(CYAN)Object files and dependencies cleaned$(DEF_COLOR)\n"

fclean: clean
	$(VERBOSE)rm -f $(NAME)
	$(VERBOSE)printf "$(BLUE)Library '$(NAME)' removed$(DEF_COLOR)\n"

re:
	$(VERBOSE)$(MAKE) fclean
	$(VERBOSE)$(MAKE) all
	$(VERBOSE)printf "$(GREEN)$(BOLD)Project rebuilt successfully$(DEF_COLOR)\n"

# Include dependency files
-include $(DEPS)

# Declare phony targets
.PHONY: all clean fclean re

# Set parallel jobs
MAKEFLAGS += -j