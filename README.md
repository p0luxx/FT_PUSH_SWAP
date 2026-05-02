# Push Swap 🔄

Algoritmo de ordenamiento de stacks usando movimientos limitados. Implementación modular con soporte para múltiples estrategias de optimización.

## 📋 Descripción

Push Swap es un proyecto que requiere ordenar dos stacks (`a` y `b`) usando únicamente un conjunto limitado de operaciones:
- `sa`, `sb`, `ss` - swap (intercambiar top)
- `pa`, `pb` - push (mover top de un stack a otro)
- `ra`, `rb`, `rr` - rotate (rotar hacia arriba)
- `rra`, `rrb`, `rrr` - reverse rotate (rotar hacia abajo)

El objetivo es minimizar el número de movimientos necesarios para ordenar el stack `a`.

---

## 📁 Estructura del Proyecto

### Organización de directorios

```
push_swap/
├── push_swap.c              # Main (orquestación)
├── push_swap.h              # Header principal con estructuras
├── ft_flags.c               # Parseo y validación de flags/algoritmos
├── ft_error.c               # Gestión de errores
├── ft_validate_inputs.c     # Validación y parseo de argumentos
│
├── list_utils/              # Operaciones de lista doblemente enlazada
│   ├── ft_lstnew.c          # Crear nuevo nodo
│   ├── ft_lstadd_back.c     # Agregar al final
│   ├── ft_lstadd_front.c    # Agregar al inicio
│   ├── ft_lstlast.c         # Obtener último nodo
│   ├── ft_lstsize.c         # Tamaño de lista
│   ├── ft_lstdelone.c       # Eliminar un nodo
│   ├── ft_lstclear.c        # Limpiar lista completa
│   ├── ft_lstiter.c         # Iterar sobre lista
│   └── ft_lstmap.c          # Mapear función sobre lista
│
├── utils/                   # Utilidades generales
│   ├── ft_atoi.c            # String → int
│   ├── ft_split.c           # Split de strings
│   ├── ft_strncmp.c         # Comparación de strings
│   ├── ft_is_num.c          # Validar si es número
│   └── ft_check_argv.c      # Validaciones auxiliares
│
├── DOCS/                    # Documentación
│   └── push_swap_data_structures.svg  # Diagrama de estructuras
│
├── Makefile                 # Compilación
└── README.md                # Este archivo
```

---

## 🏗️ Estructuras de Datos

### `t_node` - Nodo del stack

```c
typedef struct s_node
{
    int     value;    /* Valor original del input */
    int     norm;     /* Índice normalizado (0..n-1) */
    int     target;   /* Posición destino tras ordenamiento */
    int     cost_a;   /* Rotaciones necesarias en stack a */
    int     cost_b;   /* Rotaciones necesarias en stack b */
    s_node  *next;    /* Puntero al siguiente */
    s_node  *prev;    /* Puntero al anterior */
}   t_node;
```

### `t_stack` - Stack (lista doblemente enlazada)

```c
typedef struct s_stack
{
    t_node  *top;     /* Cima del stack */
    t_node  *bottom;  /* Base del stack */
    int     size;     /* Número de elementos */
    char    name;     /* Identificador: 'a' o 'b' */
}   t_stack;
```

### `t_flags` - Selector de algoritmo

```c
typedef struct s_flags
{
    int simple;       /* Flag: usar Insertion Sort */
    int medium;       /* Flag: usar Insertion Chunked */
    int complex;      /* Flag: usar Radix LSD */
    int adaptive;     /* Flag: elegir automáticamente */
    int bench;        /* Flag: benchmark mode */
}   t_flags;
```

---

## 🔧 Algoritmos Disponibles

| Nombre | Flag | Complejidad | Descripción |
|--------|------|-------------|-------------|
| **Simple** | `--simple` | O(n²) | Insertion sort clásico. Fácil de implementar. |
| **Medium** | `--medium` | O(n√n) | Insertion chunked. Balancea rotaciones. |
| **Complex** | `--complex` | O(n log n) | Radix LSD. Óptimo para grandes datasets. |
| **Adaptive** | `--adaptive` (default) | variable | Selecciona automáticamente según desorden. |
| **Benchmark** | `--bench` | - | Modo profiling: mide performance de cada algoritmo. |

### Lógica Adaptativa

El modo `--adaptive` selecciona automáticamente:
- **disorder < 0.1** → `--simple`
- **disorder < 0.4** → `--medium`
- **disorder ≥ 0.4** → `--complex`

---

## 🚀 Uso

### Compilación

```bash
make              # Compilar
make clean        # Limpiar .o
make fclean       # Limpiar todo
make re           # Recompilar
```

### Ejecución

#### Forma básica (adaptive mode)
```bash
./push_swap 3 1 2
./push_swap "5 2 8 1 9"
```

#### Con algoritmo específico
```bash
./push_swap --simple 3 1 2
./push_swap --complex "5 2 8 1 9"
./push_swap --bench 3 1 2
```

#### Con dos flags (selector + benchmark)
```bash
./push_swap --simple --bench 3 1 2
```

---

## ✅ Estado del Proyecto

### Parte 1: Validación de Inputs y Creación del Stack A ✅ COMPLETADA

La primera parte del proyecto se ha completado exitosamente:

#### Implementado:
- ✅ **Parseo de flags** (`ft_flags.c`)
  - Detección de flags válidos
  - Selección de algoritmo
  - Validación de combinaciones de flags
  - Soporte para `--simple`, `--medium`, `--complex`, `--adaptive`, `--bench`

- ✅ **Validación de argumentos** (`ft_validate_inputs.c`)
  - Parseo de argumentos individuales y espaciados
  - Conversión a números con detección de overflow (`ft_atoi.c`)
  - Validación de números válidos (`ft_is_num.c`)
  - Creación del stack `a` con nodos (`ft_lstnew.c`, `ft_lstadd_back.c`)
  - Detección de duplicados (`ft_has_duplicates()`)

- ✅ **Gestión de errores** (`ft_error.c`)
  - Errores de validación con salida estándar

- ✅ **Utilidades**
  - Split de strings (`ft_split.c`)
  - Comparación de strings (`ft_strncmp.c`)
  - Lista doblemente enlazada completa (`list_utils/`)

#### Norminette: ✅ PASS
Todo el código ha pasado las pruebas de norminette (excepto áreas marcadas como aún en desarrollo).

#### Archivo Makefile actualizado
Se ha corregido para compilar correctamente todos los módulos.

---

## 🗺️ Árbol de Funciones

### Árbol de llamadas actual

```
main()
├─ ft_init_flags()              ✅ HECHO | 📏 PASS
└─ ft_parse_argv()              ✅ HECHO | 📏 PASS
   ├─ ft_is_flag()              ✅ HECHO | 📏 PASS
   ├─ ft_select_algorithm()     ✅ HECHO | 📏 PASS
   ├─ ft_validate_single_algorithm() ✅ HECHO | 📏 PASS
   ├─ ft_handle_arg()           ✅ HECHO | 📏 PASS
   │  ├─ ft_add_single()        ✅ HECHO | 📏 PASS
   │  ├─ ft_add_split()         ✅ HECHO | 📏 PASS
   │  ├─ ft_atoi()              ✅ HECHO | 📏 PASS
   │  ├─ ft_split()             ✅ HECHO | 📏 PASS
   │  └─ ft_lstnew()            ✅ HECHO | 📏 PASS
   └─ ft_has_duplicates()       ✅ HECHO | 📏 PASS
```

---

## 📊 Estado por Archivo

| Archivo | Estado | Norminette | Notas |
|---------|--------|-----------|-------|
| `push_swap.c` | ✅ COMPLETO | 📏 PASS | Main orquestador |
| `push_swap.h` | ✅ COMPLETO | 📏 PASS | Header con structs |
| `ft_flags.c` | ✅ COMPLETO | 📏 PASS | Flags y algoritmos |
| `ft_error.c` | ✅ COMPLETO | 📏 PASS | Gestión de errores |
| `ft_validate_inputs.c` | ✅ COMPLETO | 📏 PASS | Parseo de argumentos |
| `list_utils/*.c` | ✅ COMPLETO | 📏 PASS | 9 funciones de lista |
| `utils/*.c` | ✅ COMPLETO | 📏 PASS | 5 utilidades generales |

---

## 📝 Próximas Fases

### Fase 2: Normalización e Índices
- Mapeo de valores a índices 0..n-1
- Cálculo de normalización en la estructura del nodo

### Fase 3: Algoritmos de Ordenamiento
- [ ] Implementar **Insertion Sort Simple** (O(n²))
- [ ] Implementar **Insertion Chunked** (O(n√n))
- [ ] Implementar **Radix LSD** (O(n log n))

### Fase 4: Optimización
- [ ] Cálculo de costos y targets
- [ ] Selección inteligente de movimientos

### Fase 5: Testing
- [ ] Suite de tests para validación de inputs
- [ ] Casos límite (números grandes, negativos, ceros)
- [ ] Benchmark comparativo de algoritmos

---

## 🛠️ Características Implementadas

### ✅ Validación Robusta
- Detección de argumentos inválidos
- Manejo de overflow en conversión a int
- Validación de duplicados
- Soporte para múltiples formatos de entrada

### ✅ Sistema de Flags Flexible
- Hasta 2 flags simultáneamente
- Validación de combinaciones válidas
- Modo adaptativo por defecto
- Bench mode para profiling

### ✅ Estructura de Datos Eficiente
- Lista doblemente enlazada para O(1) acceso front/back
- Nodos con información de costo y target
- Stack con identificador para debugging

### ✅ Código Limpio
- Modularización clara
- Funciones pequeñas y enfocadas
- Cumplimiento de norminette
- Documentación inline

---

## 📚 Documentación

- **DOCS/push_swap_data_structures.svg**: Diagrama visual de las estructuras de datos y relaciones

---

## 👥 Autores

- **@smilitar** - Parseo, flags, validación
- **@gorkgall** - Estructuras, lista enlazada, control general

---

## 📄 Normas

Este proyecto sigue la **norminette 42** (estándar de código de 42 Barcelona).

```bash
# Verificar cumplimiento
norminette
```

---

## 🔍 Testing

Tests aún por implementar (Fase 5). Placeholder para casos límite:
- Números negativos
- Números grandes (INT_MIN, INT_MAX)
- Stack ya ordenado
- Stack ordenado al revés
- Duplicados
- Argumentos inválidos

---

## 📖 Notas Técnicas

### Por qué lista doblemente enlazada?
- **Rotaciones**: Necesitamos acceso eficiente a top y bottom
- **Reverse rotate**: Necesitamos recorrer hacia atrás
- **Visualización**: Facilita debugging

### Por qué "norm" (índice normalizado)?
- Permite usar Radix Sort basado en bits
- Facilita cálculos de distancia
- Reutilizable en múltiples algoritmos

### Overflow handling
`ft_atoi()` detecta overflow comparando contra INT_MIN/INT_MAX antes de aplicar operaciones.

---

**Última actualización:** Mayo 2026
**Estado actual:** Fase 1 ✅ Completa