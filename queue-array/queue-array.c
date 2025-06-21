#include<stdio.h>
#include<stdlib.h>
#include "queue_array.h"

void generateQueue(queue* q, int size) {
	q->arr = malloc(sizeof(int) * size);			// size 크기의 정수형 큐 공간 설정
	q->capacity = size;	
	q->numItems = 0;								// 초기 큐의 원소 개수 0개
	q->head = 0;									// head와 tail 설정
	q->tail = size-1;
}

void enqueue(queue* q, int n) {
	if (isFull(q)) {								// overflow인지 확인
		printf("Overflow!\n");
		return;
	}
	else {
		q->tail = (q->tail + 1) % q->capacity;		// tail을 인덱스로 사용하여 데이터 삽입
		q->arr[q->tail] = n;						// 원형 큐의 특성인 인덱스 번호와 상관없이 비어있다면 계속 삽입할 수 있음을 활용
		q->numItems++;								// 큐의 원소 개수 증가
	}
}

int dequeue(queue* q) {
	if (isEmpty(q)) {								// underflow 확인
		printf("Underflow!\n");
		return -1;
	}
	else {
		int tmp = q->arr[q->head];					// FIFO 구조인 큐의 원소 출력을 위한 임시 변수
		q->numItems--;								// 큐의 원소 개수 감소
		q->head = (q->head + 1) % q->capacity;		// 가장 앞 원소가 출력되므로 다음 인덱스로 head 변경
		return tmp;									// 가장 앞 원소 출력
	}
}

bool isEmpty(queue* q) {
	return q->numItems == 0;						// 큐의 원소 개수가 0개이면 true, 아니면 false
}

bool isFull(queue* q) {
	return q->numItems == q->capacity;				// 큐의 원소 개수가 배열의 크기와 같다면 true, 아니면 false
}

void showCapacity(queue* q) {
	printf("%d/%d\n", q->numItems, q->capacity);	// 큐의 현재까지의 용량 확인
}

void freeQueue(queue* q) {							// 동적 할당 받은 메모리 공간 반환
	free(q->arr);
	q->arr = NULL;
}
