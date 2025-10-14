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
void insertAtBeginning(int id, char name[], int stock) {
    struct Node* newNode = createNode(id, name, stock);
    newNode->next = head;
    head = newNode;
    printf("✅ Producto insertado al inicio.\n");
}

// Insertar al final
void insertAtEnd(int id, char name[], int stock) {
    struct Node* newNode = createNode(id, name, stock);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("✅ Producto insertado al final.\n");
}