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
