# 연결 리스트 기반 스택

## 개념
- 스택에 관한 개념은 배열 기반 스택에서 설명했으므로 패스
- 배열에서는 인덱스를 기준으로 했다면 연결 리스트에서는 Node를 기준으로 함
- 이때 가장 마지막에 연결한 Node를 topNode로 지정하여 다룬다.
- push() => topNode의 next를 삽입하는 Node로 연결하고, 삽입된 Node를 topNode로 재지정하여 연결한다.
- pop() => topNode를 반환하며 topNode가 가리키던 Node로 topNode를 재지정하여 연결한다/
