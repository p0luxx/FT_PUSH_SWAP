# ============================================================================
#                         CONFIGURACIÓN GENERAL
# ============================================================================

NAME         = push_swap
NAME_BONUS   = checker
CC           = cc
CFLAGS       = -Wall -Wextra -Werror
INCLUDES     = -I. -Ift_printf/ft_printf -Ift_printf/libft

# ============================================================================
#                      DIRECTORIOS Y ESTRUCTURA
# ============================================================================

BUILD_DIR    = build
OBJ_DIR      = $(BUILD_DIR)/obj

# ============================================================================
#                           FUENTES Y OBJETOS
# ============================================================================

ROOT_SRCS   = push_swap.c \
              ft_error.c \
              ft_flags.c \
              ft_validate_inputs.c \
              ft_bench.c

LIST_SRCS   = $(addprefix list_utils/, \
              ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c \
              ft_lstlast.c ft_lstsize.c ft_lstdelone.c \
              ft_lstclear.c ft_lstiter.c ft_init_stack.c \
              ft_add_node.c ft_is_sorted.c)

UTILS_SRCS  = $(addprefix utils/, \
              ft_atoi.c ft_split.c ft_strncmp.c \
              ft_is_num.c ft_check_argv.c ft_strchr.c ft_substr.c \
              ft_has_duplicates.c ft_strdup.c ft_strlcpy.c \
              ft_memcpy.c ft_memset.c) 

MOVES_SRCS  = $(addprefix moves/, \
              ft_push.c ft_rotate.c ft_swap.c ft_rrotate.c \
              record_operation.c)

ALGO_SRCS   = $(addprefix algorithms/, \
              ft_sort_simple.c ft_sort_medium.c ft_sort_medium2.c  \
              ft_sort_complex.c ft_sort_adaptative.c ft_sort_medium3.c \
              ft_sort_complex2.c)

PRINTF_MAIN = ft_printf/ft_printf.c

PRINTF_SRCS = $(addprefix ft_printf/ft_printf/, \
              ft_print_char.c ft_print_str.c \
              ft_print_int.c ft_print_hex.c ft_print_ptr.c \
              ft_print_un_int.c)

LIBFT_SRCS  = $(addprefix ft_printf/libft/, \
              ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
              ft_putunbr_fd.c ft_putendl_fd.c ft_strlen.c \
              ft_len_nb.c ft_len_unb.c)

ALL_SRCS    = $(ROOT_SRCS) $(LIST_SRCS) $(UTILS_SRCS) $(MOVES_SRCS) \
              $(ALGO_SRCS) $(PRINTF_SRCS) $(LIBFT_SRCS) $(PRINTF_MAIN)

ALL_OBJS    = $(addprefix $(OBJ_DIR)/, $(ALL_SRCS:.c=.o))

BONUS_SRCS  = checker.c checker_utils.c $(LIST_SRCS) $(UTILS_SRCS) $(MOVES_SRCS) \
              $(PRINTF_SRCS) $(LIBFT_SRCS) $(PRINTF_MAIN) \
              ft_error.c

BONUS_OBJS  = $(addprefix $(OBJ_DIR)/bonus/, $(BONUS_SRCS:.c=.o))

# ============================================================================
#                              REGLAS
# ============================================================================

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(ALL_OBJS)
	@$(CC) $(CFLAGS) $(ALL_OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(NAME_BONUS)

# Compilación de objetos normales
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilación de objetos del bonus
$(OBJ_DIR)/bonus/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)

re: fclean all
