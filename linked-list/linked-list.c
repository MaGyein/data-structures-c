#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

LinkedList* create_list() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void insert_front(LinkedList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

void insert_back(LinkedList* list, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    Node* temp = list->head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

void delete_front(LinkedList* list) {
    if (list->head == NULL) return;

    Node* temp = list->head;
    list->head = list->head->next;
    free(temp);
}

void delete_back(LinkedList* list) {
    if (list->head == NULL) return;

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return;
    }

    Node* temp = list->head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}

Node* search(LinkedList* list, int target) {
    Node* current = list->head;
    while (current != NULL) {
        if (current->data == target)
            return current;
        current = current->next;
    }
    return NULL;
}

void print_list(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_list(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}
