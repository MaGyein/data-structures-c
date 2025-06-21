#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

DoublyLinkedList* create_list() {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insert_front(DoublyLinkedList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = list->head;

    if (list->head != NULL)
        list->head->prev = new_node;
    else
        list->tail = new_node;
    list->head = new_node;
}

void insert_back(DoublyLinkedList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = list->tail;

    if (list->tail != NULL)
        list->tail->next = new_node;
    else
        list->head = new_node;

    list->tail = new_node;
}

void delete_front(DoublyLinkedList* list) {
    if (list->head == NULL) return;

    Node* temp = list->head;
    list->head = temp->next;

    if (list->head != NULL)
        list->head->prev = NULL;
    else
        list->tail = NULL;

    free(temp);
}

void delete_back(DoublyLinkedList* list) {
    if (list->tail == NULL) return;

    Node* temp = list->tail;
    list->tail = temp->prev;

    if (list->tail != NULL)
        list->tail->next = NULL;
    else
        list->head = NULL;

    free(temp);
}

Node* search(DoublyLinkedList* list, int target) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == target)
            return current;
        current = current->next;
    }
    return NULL;
}

void print_forward(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void print_backward(DoublyLinkedList* list) {
    Node* current = list->tail;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

void free_list(DoublyLinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
