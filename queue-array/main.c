#include <stdio.h>
#include "queue_array.h"

int main() {
    queue q;

    int size = 10;
    generateQueue(&q, size);        // 큐 생성

    for (int i = 1; i <= size; i++) {
        enqueue(&q, i * 3);
        
    }
    showCapacity(&q);
    enqueue(&q, 100); // overflow 테스트

    for (int i = 0; i < size; i++) {
        int val = dequeue(&q);               
    }
    showCapacity(&q);           // 용량 확인

    dequeue(&q);           // underflow 테스트

    freeQueue(&q);      // 메모리 해제
    return 0;
}
