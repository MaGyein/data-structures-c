#include <stdio.h>
#include <stdlib.h>
#include "queue_linked_list.h"

Queue* create_queue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

void enqueue(Queue* queue, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (queue->rear != NULL)
        queue->rear->next = new_node;
    else
        queue->front = new_node;

    queue->rear = new_node;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (is_empty(queue)) {
        printf("Empty!\n");
        return -1;
    }

    Node* temp = queue->front;
    int value = temp->data;

    queue->front = temp->next;
    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    queue->size--;

    return value;
}

int is_empty(Queue* queue) {
    return (queue->size == 0);
}

int get_size(Queue* queue) {
    return queue->size;
}

void free_queue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(queue);
}
