#include <stdio.h>
#include "queue_linked_list.h"

int main() {
    Queue* q = create_queue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Size: %d\n", get_size(q));      // 현재 리스트의 크기 확인

    while (!is_empty(q)) {            // 전부 dequeue하여 비우기
        int value = dequeue(q);
        printf("%d\n", value);
    }

    dequeue(q);                      // 빈 큐인지 확인

    free_queue(q);                  // 메모리 해제
    return 0;
}
