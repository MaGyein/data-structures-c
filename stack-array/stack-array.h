#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include<stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct {						// 스택에 사용할 변수들을 모아놓은 구조체 선언
	int* arr;							// 사용할 배열
	int capacity;						// 배열의 크기
	int top;							// LIFO 구조의 스택에서 마지막 원소만 다루면 되는 특성을 활용한 변수
}stack;

void generateStack(stack* s, int capacity);	// 스택 생성
void push(stack* s, int n);				// 데이터 삽입
int pop(stack* s);						// 데이터 제거 및 반환
int peek(stack* s);						// 최상단 확인
bool isEmpty(stack* s);					// 빈 스택인지 확인
bool isFull(stack* s);					// 가득 찬 스택인지 확인
void freeStack(stack* s);				// 메모리 해제

#endif
