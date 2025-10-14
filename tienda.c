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