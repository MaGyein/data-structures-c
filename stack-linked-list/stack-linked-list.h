#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Stack* create_stack();
void push(Stack* stack, int data);
int pop(Stack* stack);
int peek(Stack* stack);
int is_empty(Stack* stack);
void free_stack(Stack* stack);

#endif
