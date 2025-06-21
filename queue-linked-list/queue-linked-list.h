#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* create_queue();
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int is_empty(Queue* queue);
int get_size(Queue* queue);
void free_queue(Queue* queue);

#endif
