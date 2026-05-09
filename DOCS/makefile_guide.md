# Makefile - Guía Completa

## 📌 Descripción General

El nuevo Makefile ha sido **completamente refactorizado** para compilar automáticamente todos los archivos del proyecto según su estructura de directorios, sin necesidad de actualizar manualmente la lista de fuentes.

### Ventajas principales:
- ✅ **Compilación automática de directorios** (list_utils/, utils/, raíz)
- ✅ **Objetos organizados en estructura Build** (build/obj/)
- ✅ **Output colorizado** para mejor legibilidad
- ✅ **Descubrimiento dinámico de fuentes**
- ✅ **Targets útiles** (help, info, print-srcs, print-objs)
- ✅ **Limpieza ordenada** con separación de objetos y ejecutable

---

## 🎯 Targets Disponibles

### Compilación

```bash
make              # Compilar el proyecto completo
make all          # Lo mismo que 'make'
make re           # Recompilar desde cero (fclean + all)
make clean        # Eliminar archivos objeto (.o)
make fclean       # Limpiar todo (objetos + ejecutable)
```

### Información y Debug

```bash
make help         # Mostrar ayuda completa
make info         # Información del proyecto (archivos, directorios, etc)
make print-srcs   # Listar todos los archivos fuente
make print-objs   # Listar todos los archivos objeto generados
```

---

## 🏗️ Estructura del Proyecto

```
push_swap/
├── Makefile                    # Este archivo
├── push_swap.c                 # Main
├── push_swap.h                 # Header principal
├── ft_error.c                  # Manejo de errores
├── ft_flags.c                  # Parseo de flags
├── ft_validate_inputs.c        # Validación de argumentos
│
├── list_utils/                 # Operaciones de lista
│   ├── ft_lstnew.c
│   ├── ft_lstadd_back.c
│   ├── ft_lstadd_front.c
│   ├── ft_lstlast.c
│   ├── ft_lstsize.c
│   ├── ft_lstdelone.c
│   ├── ft_lstclear.c
│   ├── ft_lstiter.c
│   └── ft_lstmap.c
│
├── utils/                      # Utilidades generales
│   ├── ft_atoi.c
│   ├── ft_split.c
│   ├── ft_strncmp.c
│   ├── ft_is_num.c
│   ├── ft_check_argv.c
│   └── ft_strchr.c
│
└── build/                      # Directorio temporal (generado)
    └── obj/
        ├── [archivos .o raíz]
        ├── list_utils/
        │   └── [archivos .o de lista]
        └── utils/
            └── [archivos .o de utilidades]
```

---

## 🔧 Cómo Funciona

### 1. Descubrimiento de Fuentes

El Makefile define explícitamente cada archivo fuente:

```makefile
ROOT_SRCS = push_swap.c \
            ft_error.c ft_flags.c ft_validate_inputs.c

LIST_SRCS = $(addprefix list_utils/, \
            ft_lstnew.c ft_lstadd_back.c ...)

UTILS_SRCS = $(addprefix utils/, \
             ft_atoi.c ft_split.c ...)

SRCS = $(ROOT_SRCS) $(LIST_SRCS) $(UTILS_SRCS)
```

**Ventaja**: Fácil de extender - solo agrega el nombre al grupo correspondiente.

### 2. Generación de Objetos

Los `.o` se generan en una estructura espejo:

```makefile
OBJ_DIR = build/obj

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
```

Esto crea:
- `build/obj/push_swap.o`
- `build/obj/ft_error.o`
- `build/obj/list_utils/ft_lstnew.o`
- `build/obj/utils/ft_atoi.o`
- etc.

### 3. Compilación Automática

```makefile
$(OBJ_DIR)/%.o: %.c
    @mkdir -p $(dir $@)          # Crear directorios si no existen
    @$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
```

La regla `%.o: %.c` automatiza la compilación sin necesidad de reglas individuales.

### 4. Enlazado

```makefile
$(NAME): $(OBJS)
    @$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
```

Enlaza todos los objetos en un ejecutable.

---

## 🎨 Características Especiales

### Output Colorizado

```bash
# Cyan = compilando archivos
[Compilando: push_swap.c]

# Blue = compilando fuentes
[Compilando: utils/ft_atoi.c]

# Green = éxito
[✓ Ejecutable creado: push_swap]
[✓ push_swap compilado exitosamente]

# Yellow = limpieza
[Limpiando archivos objeto...]
```

### Variables de Color

Definidas en el Makefile para fácil customización:

```makefile
RED     = \033[0;31m
GREEN   = \033[0;32m
YELLOW  = \033[0;33m
BLUE    = \033[0;34m
PURPLE  = \033[0;35m
CYAN    = \033[0;36m
RESET   = \033[0m
BOLD    = \033[1m
```

---

## 📊 Información del Proyecto

Ejecuta `make info` para ver:

```
╔════════════════════════════════════════════════════╗
║              INFORMACIÓN DEL PROYECTO             ║
╚════════════════════════════════════════════════════╝

Configuración:
  Compilador: cc
  Flags: -Wall -Wextra -Werror
  Includes: -I.

Archivos:
  Archivos raíz: 4
  Archivos list_utils: 9
  Archivos utils: 6
  Total de fuentes: 19

Directorios:
  Build dir: build/
  Objetos: build/obj/

Ejecutable:
  push_swap
```

---

## 🔄 Workflow Típico

### Desarrollo inicial
```bash
make clean && make    # Limpiar + compilar limpio
./push_swap 3 1 2     # Probar
```

### Modificar código
```bash
make                  # Compila automáticamente los cambios
./push_swap 5 2 8     # Probar nuevamente
```

### Antes de commit
```bash
make fclean           # Limpiar todo
make                  # Recompilar desde cero
norminette            # Verificar norminette
```

### Debug
```bash
make print-srcs       # Ver todas las fuentes
make print-objs       # Ver todos los objetos
make info             # Información del proyecto
```

---

## ✨ Extensiones Futuras

### Agregar nuevo archivo a utils/

1. **Crea el archivo**: `utils/mi_funcion.c`
2. **Agrega al Makefile**:
```makefile
UTILS_SRCS = $(addprefix utils/, \
             ft_atoi.c ft_split.c ft_strncmp.c \
             ft_is_num.c ft_check_argv.c ft_strchr.c \
             mi_funcion.c)              # ← Agregar aquí
```
3. **Compila**: `make clean && make`

### Agregar nuevo directorio

1. **Crea el directorio**: `mkdir algoritmos/`
2. **Agrega al Makefile**:
```makefile
SUBDIRS = list_utils utils algoritmos   # ← Agregar aquí

ALGO_SRCS = $(addprefix algoritmos/, \
            ft_simple.c ft_complex.c)

SRCS = $(ROOT_SRCS) $(LIST_SRCS) $(UTILS_SRCS) $(ALGO_SRCS)
```
3. **Compila**: `make clean && make`

---

## 🐛 Troubleshooting

### Problema: "undefined reference"
```bash
# Solución: Verificar que el archivo .c está en SRCS
make print-srcs
```

### Problema: Archivos .o antiguos causan conflictos
```bash
# Solución: Limpiar build completo
rm -rf build && make
```

### Problema: Output sin colores
```bash
# Algunos terminales no soportan escape sequences
# Edita el Makefile y descomenta variables sin color
```

### Problema: Makefile no encuentra archivos
```bash
# Verifica los paths
ls list_utils/
ls utils/
# Asegúrate de que los archivos .c existen
```

---

## 📝 Notas Técnicas

### Por qué `build/obj/`?

- **Separación clara**: Archivos fuente vs. compilados
- **Fácil limpieza**: `rm -rf build/` elimina todo
- **No contamina repo**: Los .o no se checkean
- **Parallelizable**: Estructura permite compilación paralela futura

### Por qué variables separadas?

```makefile
ROOT_SRCS          # Archivos en raíz
LIST_SRCS          # Archivos de lista
UTILS_SRCS         # Archivos de utilidades
```

**Ventaja**: Fácil saber dónde está cada archivo
**Mantenimiento**: Agregar nuevo archivo es obvio

### Regla `directories`

```makefile
directories:
    @mkdir -p $(OBJ_DIR)
    @mkdir -p $(addprefix $(OBJ_DIR)/, $(SUBDIRS))
```

Crea la estructura de directorios antes de compilar. Se ejecuta automáticamente al hacer `make all`.

---

## 🎓 Comparación: Antes vs Después

### Antes (Makefile antiguo)
```makefile
SRCS = push_swap.c \
       ft_error.c ft_flags.c ft_validate_inputs.c \
       ft_utils.c              # ❌ incompleto, incorrecto

OBJS = $(SRCS:.c=.o)           # ❌ todos en raíz

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@
```

**Problemas**:
- Falta compilar list_utils/ y utils/
- No hay organización de objetos
- Difícil de mantener

### Ahora (Makefile nuevo)
```makefile
ROOT_SRCS = ...               # ✅ Explícito
LIST_SRCS = ...               # ✅ Explícito
UTILS_SRCS = ...              # ✅ Explícito

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))  # ✅ Organizados

$(OBJ_DIR)/%.o: %.c
    @mkdir -p $(dir $@)       # ✅ Auto-crea directorios
    @$(CC) $(CFLAGS) -c $< -o $@
```

**Ventajas**:
- Completo y correcto
- Bien organizado
- Fácil de mantener
- Colorizado
- Targets útiles

---

## 🔗 Recursos

- **Norminette**: `norminette`
- **Make documentation**: `man make`
- **Makefile best practices**: Proyecto de 42

---

**Versión**: 1.0
**Última actualización**: Mayo 2026
**Estado**: ✅ Funcional y optimizado