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
