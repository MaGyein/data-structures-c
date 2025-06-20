# 배열 기반 스택

## 개념

- LIFO(Last-in-First-out) 구조로, 나중에 들어간 것이 먼저 나오는 구조이며 브라우저 뒤로 가기와 같은 예시가 있다.
- 배열을 기반으로 구현할 때는 입/출력이 모두 배열의 입력된 마지막 인덱스를 활용하면 되기 때문에 하나의 변수로 다룰 수 있다.

## 구현된 기능

- 스택 생성
- 데이터 삽입/제거 및 반환
- 최상단 확인
- 빈 배열/가득 찬 배열 확인
- 메모리 해제


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


#include "stack_array.h"
#include<stdio.h>
#include<stdlib.h>

void generateStack(stack* s, int size) {
	s->arr = malloc(sizeof(int) * size);		// 정수형 크기 할당
	if (s->arr == NULL) {						// 동적 할당 정상 작동 확인
		printf(stderr, "Error\n");
		return;
	}
	s->top = -1;								// 스택의 탑 인덱스를 찾기 위한 설정
	s->capacity = size;							// size 만큼의 배열 크기 생성
}

void push(stack* s, int n) {
	if (isFull(s)) {							// overflow 조건문
		printf("Overflow!\n");
		return;
	}
	else {										// top 변수를 이용하여 스택에 n push
		s->arr[++(s->top)] = n;
	}
}

int pop(stack* s) {								
	if (isEmpty(s)) {							// underflow 조건문
		printf("Underflow!\n");
		return -1;
	}
	else {										// 스택의 가장 마지막에 있는 원소 pop
		return s->arr[(s->top)--];
	}
}

int peek(stack* s) {						
	if (isEmpty(s)) {							// 빈 스택인지 확인
		printf("Empty\n");
		return -1;
	}
	else {
		return s->arr[s->top];					// 스택의 가장 마지막에 있는 원소 출력
	}
}

bool isEmpty(stack* s) {
	return s->top == -1;						// 비어있는 스택인지 확인
}

bool isFull(stack* s) {
	return s->top == s->capacity - 1;			// 스택의 공간이 가득 찼는지 확인
}

void freeStack(stack* s) {
	free(s->arr);								// 동적 할당 받은 공간 반환
	s->arr = NULL;
}


#include "stack_array.h"
#include<stdio.h>

int main() {
	stack s;
	int size = 0;
	scanf("%d", &size);
	generateStack(&s, size);	// 동적 배열(스택) 생성

	for (int i = 1; i <= size + 1; i++) {	// push(), isFull() 기능, overflow 테스트
		push(&s, i * 5);
	}

	printf("%d\n", peek(&s));	// peek() 기능 테스트

	while (!isEmpty(&s)) {	// pop(), isEmpty() 기능 테스트
		printf("%d ", pop(&s));
	}
	printf("\n");

	printf("%d\n", peek(&s));	// peek() 기능 테스트
	printf("%d ", pop(&s));	// underflow 테스트

	freeStack(&s);	// 메모리 해제
	return 0;
}
