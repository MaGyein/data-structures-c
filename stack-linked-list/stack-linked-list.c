#include <stdio.h>
#include <stdlib.h>
#include "stack_linked_list.h"

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(Stack* stack) {
    if (is_empty(stack)) {
        printf("Empty!\n");
        return -1;
    }

    Node* temp = stack->top;
    int value = temp->data;

    stack->top = temp->next;
    free(temp);
    return value;
}

int peek(Stack* stack) {
    if (is_empty(stack)) {
        printf("Empty!\n");
        return -1;
    }
    return stack->top->data;
}

int is_empty(Stack* stack) {
    return (stack->top == NULL);
}

void free_stack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}
