# ============================================================================
#                         CONFIGURACIÓN GENERAL
# ============================================================================

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I. -Ift_printf/ft_printf -Ift_printf/libft

# ============================================================================
#                      DIRECTORIOS Y ESTRUCTURA
# ============================================================================

SRC_DIR     = .
BUILD_DIR   = build
OBJ_DIR     = $(BUILD_DIR)/obj

# Directorios para organización interna
SUBDIRS     = list_utils utils algorithms moves ft_printf/ft_printf ft_printf/libft

# ============================================================================
#                   DESCUBRIMIENTO AUTOMÁTICO DE FUENTES
# ============================================================================

# Archivos fuente raíz (Se eliminó ft_sort_simple.c de aquí)
ROOT_SRCS   = push_swap.c \
              ft_error.c \
              ft_flags.c \
              ft_validate_inputs.c \
              ft_bench.c

# Archivos fuente en subdirectorios
LIST_SRCS   = $(addprefix list_utils/, \
              ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c \
              ft_lstlast.c ft_lstsize.c ft_lstdelone.c \
              ft_lstclear.c ft_lstiter.c ft_init_stack.c \
              ft_add_node.c)

UTILS_SRCS  = $(addprefix utils/, \
              ft_atoi.c ft_split.c ft_strncmp.c \
              ft_is_num.c ft_check_argv.c ft_strchr.c ft_substr.c \
              ft_has_duplicates.c ft_strdup.c ft_strlcpy.c \
			  ft_memcpy.c) 

MOVES_SRCS  = $(addprefix moves/, \
              ft_push.c ft_rotate.c ft_swap.c ft_rrotate.c \
              record_operation.c)

ALGO_SRCS   = $(addprefix algorithms/, \
              ft_sort_simple.c)

PRINTF_MAIN = ft_printf/ft_printf.c

PRINTF_SRCS = $(addprefix ft_printf/ft_printf/, \
              ft_print_char.c ft_print_str.c \
              ft_print_int.c ft_print_hex.c ft_print_ptr.c \
              ft_print_un_int.c)

LIBFT_SRCS  = $(addprefix ft_printf/libft/, \
              ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c \
              ft_putunbr_fd.c ft_putendl_fd.c ft_strlen.c \
              ft_len_nb.c ft_len_unb.c)

# Unión de todas las fuentes
ALL_SRCS    = $(ROOT_SRCS) $(LIST_SRCS) $(UTILS_SRCS) $(MOVES_SRCS) \
              $(ALGO_SRCS) $(PRINTF_SRCS) $(LIBFT_SRCS) $(PRINTF_MAIN)

# Generación de rutas de objetos: build/obj/path/to/file.o
ALL_OBJS    = $(addprefix $(OBJ_DIR)/, $(ALL_SRCS:.c=.o))

# ============================================================================
#                            COLORES PARA OUTPUT
# ============================================================================

GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
CYAN        = \033[0;36m
RESET       = \033[0m
BOLD        = \033[1m

# ============================================================================
#                              REGLAS PRINCIPALES
# ============================================================================

.PHONY: all clean fclean re directories

all: directories $(NAME)

$(NAME): $(ALL_OBJS)
	@echo "$(CYAN)Enlazando objetos para crear $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(ALL_OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)✓ $(NAME) creado exitosamente$(RESET)"

# ============================================================================
#                        COMPILACIÓN DE OBJETOS
# ============================================================================

# Regla universal: crea el directorio necesario y compila el .c en .o
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compilando: $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ============================================================================
#                         CREACIÓN DE DIRECTORIOS
# ============================================================================

directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(SUBDIRS))

# ============================================================================
#                        LIMPIEZA Y MANTENIMIENTO
# ============================================================================

clean:
	@echo "$(YELLOW)Limpiando objetos...$(RESET)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "$(YELLOW)Limpiando ejecutable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Todo limpio$(RESET)"

re: fclean all
	@echo "$(CYAN)Compilación completa$(RESET)"

# ============================================================================
#                           UTILIDADES Y DEBUG
# ============================================================================

help:
	@echo "$(BOLD)$(CYAN)╔════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(CYAN)║              PUSH_SWAP - MAKEFILE HELP            ║$(RESET)"
	@echo "$(BOLD)$(CYAN)╚════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@echo "$(BOLD)Targets disponibles:$(RESET)"
	@echo "  $(GREEN)make$(RESET)           - Compilar el proyecto completo"
	@echo "  $(GREEN)make all$(RESET)       - Lo mismo que 'make'"
	@echo "  $(GREEN)make re$(RESET)        - Recompilar desde cero"
	@echo "  $(GREEN)make clean$(RESET)     - Eliminar archivos .o"
	@echo "  $(GREEN)make fclean$(RESET)    - Limpiar todo (objetos + ejecutable)"
	@echo "  $(GREEN)make help$(RESET)      - Mostrar esta ayuda"
	@echo "  $(GREEN)make info$(RESET)      - Mostrar información del proyecto"
	@echo ""
	@echo "$(BOLD)Ejemplos de uso:$(RESET)"
	@echo "  $(CYAN)./push_swap 3 1 2$(RESET)"
	@echo "  $(CYAN)./push_swap --simple 5 2 8 1 9$(RESET)"
	@echo "  $(CYAN)./push_swap --complex \"1 2 3\"$(RESET)"
	@echo ""

info:
	@echo "$(BOLD)$(PURPLE)╔════════════════════════════════════════════════════╗$(RESET)"
	@echo "$(BOLD)$(PURPLE)║              INFORMACIÓN DEL PROYECTO             ║$(RESET)"
	@echo "$(BOLD)$(PURPLE)╚════════════════════════════════════════════════════╝$(RESET)"
	@echo ""
	@echo "$(BOLD)Configuración:$(RESET)"
	@echo "  Compilador: $(CC)"
	@echo "  Flags: $(CFLAGS)"
	@echo "  Includes: $(INCLUDES)"
	@echo ""
	@echo "$(BOLD)Archivos:$(RESET)"
	@echo "  Archivos raíz: $(words $(ROOT_SRCS))"
	@echo "  Archivos list_utils: $(words $(LIST_SRCS))"
	@echo "  Archivos utils: $(words $(UTILS_SRCS))"
	@echo "  Total de fuentes: $(words $(SRCS))"
	@echo ""
	@echo "$(BOLD)Directorios:$(RESET)"
	@echo "  Build dir: $(BUILD_DIR)/"
	@echo "  Objetos: $(OBJ_DIR)/"
	@echo ""
	@echo "$(BOLD)Ejecutable:$(RESET)"
	@echo "  $(NAME)"
	@echo ""

# ============================================================================
#                     FUENTES (DESARROLLO - IGNORAR)
# ============================================================================

print-srcs:
	@echo "$(BOLD)Archivos fuente:$(RESET)"
	@echo "$(CYAN)Raíz:$(RESET)"
	@for f in $(ROOT_SRCS); do echo "  $$f"; done
	@echo "$(CYAN)List Utils:$(RESET)"
	@for f in $(LIST_SRCS); do echo "  $$f"; done
	@echo "$(CYAN)Utils:$(RESET)"
	@for f in $(UTILS_SRCS); do echo "  $$f"; done

print-objs:
	@echo "$(BOLD)Archivos objeto:$(RESET)"
	@for f in $(OBJS); do echo "  $$f"; done

.PHONY: all clean fclean re help directories info print-srcs print-objs
