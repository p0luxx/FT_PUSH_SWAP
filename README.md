*Este proyecto ha sido creado como parte del currículo de 42 por smilitar, gorkgall.*

---

# ft_push_swap 🔄

Ordenamiento de pilas con operaciones limitadas. Implementación en C con múltiples estrategias adaptativas según el nivel de desorden del input.

---

## Descripción

**ft_push_swap** es un proyecto del currículo de 42 cuyo objetivo es ordenar una lista de números enteros utilizando únicamente dos pilas (`a` y `b`) y un conjunto restringido de operaciones. El reto no es solo ordenar, sino hacerlo en el **mínimo número de movimientos posible**.

El programa recibe una secuencia de enteros como argumentos y produce por la salida estándar la lista de operaciones necesarias para dejar la pila `a` completamente ordenada (de menor a mayor, con el menor en el tope) y la pila `b` vacía.

### Operaciones permitidas

| Operación | Efecto |
|-----------|--------|
| `sa` / `sb` / `ss` | Intercambia los dos primeros elementos del tope de `a`, `b`, o ambos simultáneamente |
| `pa` / `pb` | Mueve el elemento del tope de `b` → `a`, o de `a` → `b` |
| `ra` / `rb` / `rr` | Rota hacia arriba: el tope pasa al fondo en `a`, `b`, o ambos |
| `rra` / `rrb` / `rrr` | Rota hacia abajo: el fondo pasa al tope en `a`, `b`, o ambos |

### Características principales

- Implementación modular en C (norminette 42 compliant)
- Tres algoritmos de ordenamiento con complejidades distintas
- Modo adaptativo que selecciona el algoritmo óptimo según el grado de desorden medido
- Modo benchmark (`--bench`) para analizar métricas de rendimiento por estrategia
- Validación robusta de entradas: overflow, duplicados, argumentos inválidos
- Lista doblemente enlazada como estructura de datos central para acceso O(1) a tope y fondo

---

## Instrucciones

### Requisitos

- Compilador `gcc` con soporte para C99 o superior
- Sistema Unix/Linux (macOS o Linux)
- `make`

### Compilación

```bash
# Compilar el programa
make

# Limpiar archivos objeto
make clean

# Limpiar todo (incluido el ejecutable)
make fclean

# Recompilar desde cero
make re
```

### Ejecución

```bash
# Uso básico (modo adaptativo por defecto)
./push_swap 3 1 2
./push_swap "5 2 8 1 9"

# Especificar algoritmo manualmente
./push_swap --simple 3 1 2
./push_swap --medium "5 2 8 1 9"
./push_swap --complex 42 7 3 19 1

# Modo benchmark (imprime estadísticas por stderr)
./push_swap --bench 3 1 2
./push_swap --simple --bench 3 1 2
```

### Verificación con checker

El repositorio incluye el binario `checker_linux` provisto por 42 para validar que la secuencia de operaciones produce un stack correctamente ordenado:

```bash
ARG="3 2 1 4 5"
./push_swap $ARG | ./checker_linux $ARG
# Output esperado: "OK"
```

### Testing automatizado

```bash
# Script de tests incluido
bash test.sh
bash test_push_swap.sh
```

---

## Algoritmos: Explicación y Justificación

El proyecto implementa tres estrategias distintas de ordenamiento, seleccionables mediante flags. La elección del algoritmo adecuado depende del tamaño del input y de su grado de desorden.

### 1. Insertion Sort Simple (`--simple`) — O(n²)

**Descripción:** Inserta cada elemento de la pila `b` en su posición correcta dentro de la pila `a`, rotando hasta encontrar el hueco adecuado.

**Justificación:** Para inputs pequeños (n ≤ ~10 elementos), el overhead de algoritmos más complejos no compensa. El insertion sort, aunque cuadrático en el caso general, produce secuencias de operaciones compactas cuando los elementos están casi ordenados o cuando n es reducido. Su implementación es directa y verificable, lo que facilita la depuración.

**Cuándo usarlo:** Inputs pequeños o con desorden menor al 20%.

---

### 2. Insertion Chunked (`--medium`) — O(n√n)

**Descripción:** Divide el input en chunks (bloques de tamaño ~√n) y los transfiere a `b` en orden de chunk. Luego los reinserta en `a` con lógica de rotación minimizada eligiendo en cada paso el elemento que requiere menos movimientos.

**Justificación:** El truco fundamental de este algoritmo es que, en lugar de insertar elemento a elemento (O(n²)), agrupa elementos cercanos en su posición final. Al procesar grupos, se amortiza el coste de las rotaciones: mover varios elementos del mismo chunk en un solo recorrido de pila reduce drásticamente el número total de operaciones respecto al insertion sort puro. El tamaño de chunk de √n es el balance empírico óptimo entre el número de chunks (rotaciones en `a`) y el tamaño de cada chunk (rotaciones en `b`).

**Cuándo usarlo:** Inputs de tamaño medio (n entre 50 y 200), desorden moderado.

---

### 3. Radix LSD (`--complex`) — O(n log n)

**Descripción:** Normaliza los valores a índices 0..n-1 y los ordena bit a bit de menos significativo a más significativo (Least Significant Digit). En cada pasada, los elementos con el bit actual a 0 permanecen en `a` y los que tienen el bit a 1 se mueven a `b`; luego se reinsertan.

**Justificación:** Radix LSD es el algoritmo con mejor escalabilidad teórica para este problema. Al operar sobre representaciones binarias de los índices normalizados, el número de pasadas es log₂(n), y cada pasada cuesta O(n) operaciones. Para n = 500, esto supone ~9 pasadas de 500 movimientos cada una (≈ 4500 operaciones), muy por debajo del límite impuesto por el evaluador de 42. La normalización previa (mapeo de valores arbitrarios a índices contiguos) elimina la dependencia del rango de los valores y hace el algoritmo predecible independientemente del input.

**Cuándo usarlo:** Inputs grandes (n ≥ 200), cualquier nivel de desorden. Es el algoritmo más robusto para el caso general.

---

### 4. Modo Adaptativo (`--adaptive`, comportamiento por defecto)

El modo adaptativo mide el **grado de desorden** del input antes de decidir qué estrategia usar. El desorden se calcula como la proporción de inversiones respecto al máximo posible: un array ordenado tiene desorden 0.0, uno completamente invertido tiene desorden 1.0.

```
disorder < 0.2  →  --simple   (pocos intercambios necesarios)
disorder < 0.5  →  --medium   (desorden moderado, chunking eficiente)
disorder ≥ 0.5  →  --complex  (alto desorden, Radix es óptimo)
```

**Justificación:** No existe un único algoritmo óptimo para todos los casos. Un array casi ordenado pagará un coste innecesario con Radix (que no aprovecha el orden parcial existente), mientras que un insertion sort sobre 500 elementos completamente desordenados produciría decenas de miles de operaciones. El modo adaptativo combina lo mejor de cada estrategia tomando una decisión informada en tiempo de ejecución.

---

## Estructura del Proyecto

```
ft_push_swap/
├── push_swap.c              # Punto de entrada y orquestación
├── push_swap.h              # Header: estructuras, prototipos
├── ft_flags.c               # Parseo y validación de flags
├── ft_error.c               # Gestión de errores y liberación de memoria
├── ft_validate_inputs.c     # Validación y parseo de argumentos
├── ft_bench.c               # Métricas de benchmark
│
├── algorithms/              # Implementaciones de los tres algoritmos
│   ├── ft_sort_simple.c
│   ├── ft_sort_medium.c
│   ├── ft_sort_complex.c
│   └── ft_sort_adaptive.c
│
├── moves/                   # Operaciones primitivas sobre pilas
│   ├── ft_swap.c            # sa, sb, ss
│   ├── ft_push.c            # pa, pb
│   ├── ft_rotate.c          # ra, rb, rr
│   └── ft_rrotate.c         # rra, rrb, rrr
│
├── list_utils/              # Lista doblemente enlazada
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
├── utils/                   # Utilidades generales
│   ├── ft_atoi.c            # Conversión string → int con detección de overflow
│   ├── ft_split.c           # División de strings
│   ├── ft_strncmp.c
│   ├── ft_is_num.c
│   └── ft_check_argv.c
│
├── ft_printf/               # Librería ft_printf (dependencia interna)
├── DOCS/                    # Diagrama de estructuras de datos (SVG)
├── Makefile
├── checker_linux            # Checker oficial de 42 (binario Linux)
└── README.md
```

---

## Ejemplos de Uso

```bash
# Verificar que 3 números se ordenan
$ ./push_swap 3 1 2

$ ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG

# Contar operaciones para 100 números aleatorios
$ shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)

$ cat bench.txt 

# Benchmark completo
$ ./push_swap --bench --complex 9 3 7 1 5
[bench] disorder:   70.0%
[bench] strategy:   Complex
[bench] total_ops:  25
[bench] sa:  0  sb:  0  ss:  0  pa:  10  pb:  10
[bench] ra:  5  rb:  0  rr:  0  rra:  0  rrb:  0  rrr:  0
```

---

## Recursos

### Documentación y referencias

- [The Push Swap Project — Medium (Jamie Dawson)](https://medium.com/@jamiedawson/push-swap-a-project-about-sorting-algorithms-d0b7b4f1c11b) — Explicación general del proyecto y estrategias comunes
- [Visualizador de Push Swap](https://github.com/o-reo/push_swap_visualizer) — Herramienta para visualizar las operaciones gráficamente
- [Radix Sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort) — Base teórica del algoritmo Radix LSD
- [Counting Inversions — GeeksForGeeks](https://www.geeksforgeeks.org/counting-inversions/) — Fundamento para la métrica de desorden adaptativo
- [Norminette 42](https://github.com/42School/norminette) — Herramienta de validación del estilo de código de 42

### Uso de Inteligencia Artificial

Durante el desarrollo de este proyecto se utilizó Claude (Anthropic) como herramienta de apoyo en las siguientes áreas:

- **Diseño de la estructura de datos:** Se consultó sobre el uso de lista doblemente enlazada vs. arrays para implementar las pilas, evaluando los trade-offs de cada opción en términos de complejidad de rotación y acceso a tope/fondo.
- **Elección y análisis de algoritmos:** Se utilizó IA para contrastar las complejidades del insertion sort, chunking y Radix LSD, y para razonar sobre los umbrales óptimos del modo adaptativo.
- **Depuración:** Se consultaron casos límite relacionados con overflow en `ft_atoi`, manejo de entradas negativas y detección de duplicados.
- **Generación del README:** Este documento fue redactado con ayuda de Claude a partir del análisis del código fuente del repositorio.

La IA no generó código fuente directamente incluido en el proyecto; su rol fue consultivo y de documentación.

---

## Autores

| Login | Área principal |
|-------|---------------|
| **smilitar** | Parseo de flags, validación de inputs, orquestación |
| **gorkgall** | Estructuras de datos, lista enlazada, control general |

---

*Proyecto desarrollado en 42 Barcelona · Mayo 2026 · Norminette ✅*