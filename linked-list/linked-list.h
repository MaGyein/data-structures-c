#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

LinkedList* create_list();
void insert_front(LinkedList* list, int data);
void insert_back(LinkedList* list, int data);
void delete_front(LinkedList* list);
void delete_back(LinkedList* list);
Node* search(LinkedList* list, int target);
void print_list(LinkedList* list);
void free_list(LinkedList* list);

#endif
