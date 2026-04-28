paso 1: plantarnos el proyecto(gorkgall, smilitar)
paso 2: crear pseudocodigo para el main(smilitar)
paso 3: crear las validaciones de la matriz(gorkgall)
paso 4: plantearnos que algoritmos usar y como(gorkgall, smilitar)
paso 5: integrar las validaciones en el main, crear los errores, reorganizar ficheros existentes, pasar pruebas de las validaciones, pasar norminette(smilitar)


## push_swap — árbol de funciones

### leyenda
`✅ hecho` `⚠️ parcial` `❌ pendiente` `📏 norm ✓` `⛔ norm ✗` `❓ norm —` `👤 smilitar` `👤 gorka`

---
### árbol de llamadas

| función | archivo | estado | norminette | autor |
|---|---|---|---|---|
| `main()` | `push_swap.c` | ⚠️ parcial | ❓ | 👤 smilitar  👤 gorka  |
| &nbsp;&nbsp;├─ `ft_init_flags()` | `ft_flags.c` | ✅ hecho | 📏 ✓ | 👤 smilitar |
| &nbsp;&nbsp;└─ `ft_parse_argv()` | `ft_validate_inputs.c` | ⚠️ parcial | 📏 ✓ | 👤 smilitar |
| &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├─ `ft_is_flag()` | `ft_flags.c` | ✅ hecho | 📏 ✓ | 👤 smilitar |
| &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├─ `ft_select_algorithm()` | `ft_flags.c` | ✅ hecho | 📏 ✓ | 👤 smilitar |
| &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├─ `ft_validate_single_algorithm()` | `ft_flags.c` | ✅ hecho | ❓ | 👤 smilitar |
| &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├─ `ft_handle_arg()` | `ft_validate_inputs.c` | ❌ pendiente | ❓ | 👤 gorka |
| &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;│&nbsp;&nbsp;└─ ... | ... | ... | ... |
| &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└─ `ft_has_duplicates()` | `ft_validate_inputs.c` | ❌ pendiente | ❓ | 👤 smilitar |

---

### estado por archivo

| archivo | estado | norminette |
|---|---|---|
| `push_swap.c` | ⚠️ parcial | 📏 norm ✓ | ❓ norm —
| `ft_flags.c` | ✅ hecho | 📏 norm ✓ |
| `ft_validate_inputs.c` | ❌ pendiente | 
| `ft_utils.c` | ⚠️ parcial | 📏 norm ✓ |
| `ft_error.c` | ✅ hecho | 📏 norm ✓ |
| `push_swap.h` | ⚠️ parcial | 📏 norm ✓ |
