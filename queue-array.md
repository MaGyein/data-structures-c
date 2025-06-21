# 배열 기반 큐(원형 큐)

## 개념

- FIFO(First-in-First-out) 구조로, 들어간 순서대로 출력되는 구조이며 일상생활의 줄 서기 등과 같은 예시가 있다.
- 일반 큐의 경우 dequeue가 진행된 배열의 공간을 사용할 수 없다는 단점이 발생한다
- 이를 보완한 것이 원형 큐이다.
- 원형 큐의 경우 출력할 인덱스를 담당하는 head와 입력될 인덱스를 담당하는 tail을 사용하여 인덱스와 상관없이 배열의 크기 내에서 공간을 활용할 수 있다.

## 구현된 기능

- 큐 생성
- 데이터 삽입/제거 및 반환
- 현재 큐의 용량 확인
- 빈 배열/가득 찬 배열 확인
- 메모리 해제

queue_array.h
```c
#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include<stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct {						// 큐에 사용할 변수들을 모아놓은 구조체 선언
	int* arr;							// 사용할 배열
	int capacity, numItems;				// 배열의 크기와 원소의 개수
	int head, tail;						// 원형 큐를 구성하기 위한 가장 앞 인덱스 head, 가장 뒷 인덱스 tail 변수
}queue;

void generateQueue(queue* q);			// 큐 생성
void enqueue(queue* q, int n);			// 데이터 삽입
int dequeue(queue* q);					// 데이터 제거
bool isEmpty(queue* q);					// 빈 큐인지 확인
bool isFull(queue* q);					// 가득 찬 큐인지 확인
void showCapacity(queue* q);			// 현재 큐의 용량 확인
void freeQueue(queue* q);				// 동적 할당 받은 큐 메모리 해제

#endif
```

queue_array.c
```c
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
