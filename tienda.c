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

// Actualizar stock por ID
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