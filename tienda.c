#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    char nombre[40];
    int stock;
    struct Node* next;
};

// Puntero al inicio de la lista
struct Node* head = NULL;

// Función para el nuevo nodo
struct Node* createNode(int id, char nombre[], int stock) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = id;
    strcpy(newNode->nombre, nombre);
    newNode->stock = stock;
    newNode->next = NULL;
    return newNode;
}

// Insertar al inicio
void insertAtBeginning(int id, char nombre[], int stock) {
    struct Node* newNode = createNode(id, nombre, stock);
    newNode->next = head;
    head = newNode;
    printf("Producto insertado al inicio.\n");
}

// Insertar al final
void insertAtEnd(int id, char nombre[], int stock) {
    struct Node* newNode = createNode(id, nombre, stock);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Producto insertado al final.\n");
}

// Buscar producto por ID
void searchById(int id) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            printf("Producto encontrado:\n");
            printf("ID: %d\nNombre: %s\nStock: %d\n", temp->id, temp->nombre, temp->stock);
            return;
        }
        temp = temp->next;
    }
    printf("Producto con ID %d no encontrado.\n", id);
}

// Actualizar el stock por ID
void updateStock(int id, int newStock) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            temp->stock = newStock;
            printf("Stock actualizado. Nuevo stock: %d\n", newStock);
            return;
        }
        temp = temp->next;
    }
    printf("Producto con ID %d no encontrado.\n", id);
}

// Eliminar un producto por ID
void deleteById(int id) {
    struct Node *temp = head, *prev = NULL;
    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Producto con ID %d no encontrado.\n", id);
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Producto eliminado correctamente.\n");
}

// Lista del inventario
void listInventory() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("Inventario vacío.\n");
        return;
    }
    printf("\nInventario actual:\n");
    while (temp != NULL) {
        printf("ID: %d | Nombre: %s | Stock: %d\n", temp->id, temp->nombre, temp->stock);
        temp = temp->next;
    }
}

// Menú principal
void menu() {
    int option, id, stock;
    char nombre[40];

    do {
        printf("\n========== MENU INVENTARIO ==========\n");
        printf("1. Insertar producto al inicio\n");
        printf("2. Insertar producto al final\n");
        printf("3. Buscar producto por ID\n");
        printf("4. Actualizar stock por ID\n");
        printf("5. Eliminar producto por ID\n");
        printf("6. Listar inventario completo\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Ingrese ID: ");
                scanf("%d", &id);
                printf("Ingrese nombre: ");
                scanf(" %[^\n]", nombre);  // lee cadena con espacios
                printf("Ingrese stock: ");
                scanf("%d", &stock);
                insertAtBeginning(id, nombre, stock);
                break;
            case 2:
                printf("Ingrese ID: ");
                scanf("%d", &id);
                printf("Ingrese nombre: ");
                scanf(" %[^\n]", nombre);
                printf("Ingrese stock: ");
                scanf("%d", &stock);
                insertAtEnd(id, nombre, stock);
                break;
            case 3:
                printf("Ingrese ID a buscar: ");
                scanf("%d", &id);
                searchById(id);
                break;
            case 4:
                printf("Ingrese ID a actualizar: ");
                scanf("%d", &id);
                printf("Ingrese nuevo stock: ");
                scanf("%d", &stock);
                updateStock(id, stock);
                break;
            case 5:
                printf("Ingrese ID a eliminar: ");
                scanf("%d", &id);
                deleteById(id);
                break;
            case 6:
                listInventory();
                break;
            case 0:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (option != 0);
}

// Función principal
int main() {
    menu();
    return 0;
}