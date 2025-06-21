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
