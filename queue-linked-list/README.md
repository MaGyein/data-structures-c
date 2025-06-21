# 연결 리스트 기반 큐

## 개념
- 큐에 대한 설명은 배열 기반 큐에서 설명했으므로 생략
- 크기와 인덱스가 정해져있는 배열과 달리, 서로의 주소로 연결하는 연결 리스트는 원형 큐를 구현할 때 마지막 노드인 tail 하나로 삽입과 제거 모두 다룰 수 있음
- enqueue() => 스택과 마찬가지로 tail의 next를 새 Node의 next로 지정하고 tail의 next를 새 Node로 연결하며 tail을 새 Node로 새롭게 지정하면 된다.
- dequeue() => tail의 next를 반환하고 tail의 next의 next와 tail을 연결한다.
