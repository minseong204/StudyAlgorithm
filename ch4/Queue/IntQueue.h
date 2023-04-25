/*
큐 구조체 IntQueue
- 큐를 관리하는 구조체로, 아래와 같이 5개의 멤버로 구성

1. 큐로 사용할 배열 (que)
인큐하는 데이터를 저장하기 위한 큐로, 사용할 배열의 첫 번째 요소에 대한 포인터
2. 큐의 최대 용량 (max)
큐의 최대 용량을 저장하는 int형 멤버로, 이 값은 배열 que에 저장할 수 있는 최대 요소의 개수와 같음
3. 프런트 (front)
인큐하는 데이터 가운데 첫 번째 요소의 인덱스를 저장하는 멤버
4. 리어 (rear)
인큐한 데이터 가운데 맨 나중에 넣은 요소의 하나 뒤에 인덱스를 저장하는 멤버
5. 현재 데이터 개수 (num)
큐에 쌓아 놓은 데이터 수를 나타내는 멤버, 큐가 비어 있을 때 num은 0이고, 가득 찼을 때는 num과 max의
값이 같다.

front와 rear의 값이 같은 경우 큐가 비어있는지, 가득 찼는지 구별할 수 없는 상황을 피하기 위해
num이라는 변수로 확인
*/

/*int 형 큐  IntQueue(헤더파일)*/
#ifndef ___IntQueue
#define ___IntQueue

/*--- 큐를 구현하는 구조체 ---*/
typedef struct
{
    int max;   // 큐의 최대 용량
    int num;   // 현재의 요소 개수
    int front; // 프런트
    int rear;  // 리어
    int *que;  // 큐의 맨 앞 요소에 대한 포인터
} IntQueue;

/*--- 큐 초기화 ---*/
int Initialize(IntQueue *q, int max);

/*--- 큐에 데이터를 인큐 ---*/
int Enque(IntQueue *q, int x);

/*--- 큐에 데이터를 디큐 ---*/
int Deque(IntQueue *q, int *x);

/*--- 큐에서 데이터를 피크 ---*/
int Peek(const IntQueue *q, int *x);

/*--- 모든 데이터를 삭제 ---*/
void Clear(IntQueue *q);

/*--- 큐의 최대 용량 ---*/
int Capacity(const IntQueue *q);

/*--- 큐에 저장된 데이터 개수 ---*/
int Size(const IntQueue *q);

/*--- 큐가 비어 있는가? ---*/
int IsEmpty(const IntQueue *q);

/*--- 큐가 가득 찼는가? ---*/
int IsFull(const IntQueue *q);

/*--- 큐에서 검색 ---*/
int Search(const IntQueue *q, int x);

/*--- 모든 데이터 출력 ---*/
void Print(const IntQueue *q);

/*--- 큐 종료 ---*/
void Terminate(IntQueue *q);
#endif