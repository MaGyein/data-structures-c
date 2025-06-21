#include <stdio.h>
#include "stack_linked_list.h"

int main() {
    Stack* s = create_stack();

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("Top: %d\n", peek(s));   // stack의 탑노드 확인

    while (!is_empty(s)) {          // stack 비우기
        int value = pop(s);
        printf("%d \n", value);
    }

    pop(s);             // 빈 스택에서 pop() 에러 확인
    peek(s);            // 빈 스택에서 peek() 에러 확인

    free_stack(s);      // 메모리 해제
    return 0;
}
