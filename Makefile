# ============================================================================
#                          CONFIGURACIÓN GENERAL
# ============================================================================

NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I.

# ============================================================================
#                       DIRECTORIOS Y ESTRUCTURA
# ============================================================================

SRC_DIR		= .
BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/obj

SUBDIRS		= list_utils utils

# ============================================================================
#                    DESCUBRIMIENTO AUTOMÁTICO DE FUENTES
# ============================================================================

# Archivos fuente raíz (en el directorio actual)
ROOT_SRCS	= push_swap.c \
			  ft_error.c \
			  ft_flags.c \
			  ft_validate_inputs.c

# Archivos fuente en subdirectorios
LIST_SRCS	= $(addprefix list_utils/, \
			  ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c \
			  ft_lstlast.c ft_lstsize.c ft_lstdelone.c \
			  ft_lstclear.c ft_lstiter.c ft_init_stack.c \
			  ft_add_node.c)

UTILS_SRCS	= $(addprefix utils/, \
			  ft_atoi.c ft_split.c ft_strncmp.c \
			  ft_is_num.c ft_check_argv.c ft_strchr.c ft_substr.c \
			  ft_has_duplicates.c ft_strdup.c ft_strlen.c)  

# Todas las fuentes combinadas
SRCS		= $(ROOT_SRCS) $(LIST_SRCS) $(UTILS_SRCS)

# Objetos en el directorio de build
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# ============================================================================
#                            COLORES PARA OUTPUT
# ============================================================================

RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
PURPLE		= \033[0;35m
CYAN		= \033[0;36m
WHITE		= \033[0;37m
RESET		= \033[0m
BOLD		= \033[1m

# ============================================================================
#                             REGLAS PRINCIPALES
# ============================================================================

.PHONY: all clean fclean re help directories

all: directories $(NAME)
	@echo "$(GREEN)$(BOLD)✓ $(NAME) compilado exitosamente$(RESET)"

$(NAME): $(OBJS)
	@echo "$(CYAN)Enlazando objetos...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(BOLD)✓ Ejecutable creado: $(NAME)$(RESET)"

# ============================================================================
#                        COMPILACIÓN DE OBJETOS
# ============================================================================

$(OBJ_DIR)/%.o: %.c
	@echo "$(BLUE)Compilando: $<$(RESET)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ============================================================================
#                         CREACIÓN DE DIRECTORIOS
# ============================================================================

directories:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(addprefix $(OBJ_DIR)/, $(SUBDIRS))

# ============================================================================
#                          LIMPIEZA Y MANTENIMIENTO
# ============================================================================

clean:
	@echo "$(YELLOW)Limpiando archivos objeto...$(RESET)"
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)✓ Archivos objeto eliminados$(RESET)"

fclean: clean
	@echo "$(YELLOW)Limpiando ejecutable...$(RESET)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Ejecutable eliminado$(RESET)"

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
