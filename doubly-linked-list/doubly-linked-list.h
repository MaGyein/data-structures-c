#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct DoublyLinkedList {
    Node* head;
    Node* tail;
} DoublyLinkedList;

DoublyLinkedList* create_list();
void insert_front(DoublyLinkedList* list, int data);
void insert_back(DoublyLinkedList* list, int data);
void delete_front(DoublyLinkedList* list);
void delete_back(DoublyLinkedList* list);
Node* search(DoublyLinkedList* list, int target);
void print_forward(DoublyLinkedList* list);
void print_backward(DoublyLinkedList* list);
void free_list(DoublyLinkedList* list);

#endif
