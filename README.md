# Parcial de Tienda

## Descripción

Este repositorio contiene un projecto de **gestión de inventario** para una tienda pequeña, utilizando una **lista enlazada simple** en el lenguaje **C**.  
El programa permite registrar, buscar, actualizar, eliminar y listar productos a través de un **menú por consola**.

## Estructura del Repositorio

```
Parcial2C/
├── tienda.c           # Código fuente principal
├── tienda        # Binario generado al compilar
├── README.md          # Documentación del proyecto
└── ignore.gitignore       # Ignora binarios y archivos temporales
```

## Estructura de datos utilizada

```c
struct Node {
    int id;
    char nombre[40];
    int stock;
    struct Node* next;
}
```

Cada nodo representa un producto del inventario

## Compilación

Para compilar y ejecutar el archivo:

```bash
gcc tienda.c -o tienda
./tienda
```

### Funcionalidades
- Insertar al inicio: Agrega un producto nuevo al comienzo de la lista
- Insertar al Final: Agrega un producto nuevo al final de la lista
- Buscar por ID: Muestra la informacion (nombre, stock) de un producto por medio de su ID
- Actualizar Stock: Permite modificar el stock disponible de un producto previamente ingresado
- Eliminar por ID: Elimina un producto del inventario segun su ID
- Listar inventario: Muestra todos los productos registrados



## Ejemplos de Uso

### Menu Principal
Al ejecutar el programa, se muestra el siguiente menu:

```bash
========== MENU INVENTARIO ==========
1. Insertar producto al inicio
2. Insertar producto al final
3. Buscar producto por ID
4. Actualizar stock por ID
5. Eliminar producto por ID
6. Listar inventario completo
0. Salir
Seleccione una opción:
```

### Insertar productos
Se selecciona la opcion 1 (o 2), despues se ingresa la ID, el nombre del producto y cuantas unidades en stock existen (en el orden mencionado)

```bash
Seleccione una opción: 1
Ingrese ID: 101
Ingrese nombre: Leche
Ingrese stock: 20
Producto insertado al inicio.
```
### Buscar por ID
Se selecciona la opcion 3, despues se ingresa la ID del objeto a buscar, si existe el programa te muestra los resultados, si no es porque no esta ingresado

```bash
Seleccione una opción: 3
Ingrese ID a buscar: 101
Producto encontrado:
ID: 101
Nombre: Leche
Stock: 20
```

### Actualizar Stock
Se selecciona la opcion 4, luego se ingresa la ID del producto a modificar, y se ingresa el nuevo de unidades

```bash
Seleccione una opción: 4
Ingrese ID a actualizar: 101
Ingrese nuevo stock: 35
Stock actualizado. Nuevo stock: 35
```

### Eliminar Producto
Se selecciona la opcion 5 y se ingresa la ID a eliminar

```bash
Seleccione una opción: 5
Ingrese ID a eliminar: 101
Producto eliminado correctamente.
```

### Mostrar Inventario
Se seleeciona la opcion 6, y la aplicacion mostrara todos los objetos ingresados en el sistema

```bash
Seleccione una opción: 6
Inventario actual:
ID: 102 | Nombre: Pan | Stock: 50
ID: 103 | Nombre: Queso | Stock: 15
```
