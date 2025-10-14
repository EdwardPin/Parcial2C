#include <stdio.h>
#include <stdlib.h>

struct Node {
    int id;
    char nombre[40];
    int stock;
    struct Node* next;
};