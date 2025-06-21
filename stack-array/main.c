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
