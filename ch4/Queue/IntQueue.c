/**/






/*int형 큐 IntQueue (소스파일)*/
#include <stdio.h>
#include <stdlib.h>
#include "IntQueue.h"

/*--- 큐 초기화 ---*/
int Initialize(IntQueue *q, int max)
{
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL)
    {
        q->max = 0; //  배열 생성에 실패
        return -1;
    }
    q->max = max;
    return 0;
}

/*
초기화 함수 Initialize
- 큐를 구현하기 위한 배열 생성 등의 준비 작업을 하는 함수
(첫번째 인수 q는 처리 대상인 큐 구조체 객체에 대한 포인터이며, 이후 대부분의 함수도 마찬가지)
큐를 처음 만들면 큐는 비어 있으므로 (데이터가 하나도 없는 상태) num, front, rear값을 모두 0으로 초기화
또 매개변수 max로 받은 '큐의 최대 용량'을 멤버 max에 저장
그리고 저장할 수 있는 요소의 개수가 max인 배열 que의 메모리 공간을 확보합니다
*/

/*--- 큐에 데이터를 인큐 ---*/
int Enque(IntQueue *q, int x)
{
    if (q->num >= q->max)
        return -1; //  큐가 가득 참
    else
    {
        q->num++;
        q->que[q->rear++] = x;
        if (q->rear == q->max)
            q->rear = 0;
        return 0;
    }
}
/*
인큐 함수 Enque
큐에 데이터를 인큐하는 함수
(인큐에 성공하면 0을 반환, 하지만 큐가 가득 차서 인큐할 수 없으면 -1반환)
*/

/*--- 큐에서 데이터를 디큐 ---*/
int Deque(IntQueue *q, int *x)
{
    if (q->num <= 0)
        return -1;
    else
    {
        q->num--;
        *x = q->que[q->front++];
        if (q->front == q->max)
            q->front = 0;
        return 0;
    }
}
/*
디큐 함수 Deque
큐에서 데이터를 디큐하는 함수
(디큐에 성공하면 0을 반환, 하지만 큐가 텅 비어 디큐할 수 없으면 -1 반환)
*/

/*--- 큐에서 데이터를 피크 ---*/
int Peek(const IntQueue *q, int *x)
{
    if (q->num <= 0) //  큐는 비어 있음
        return -1;
    *x = q->que[q->front];
    return 0;
}

/*--- 모든 데이터 삭제 ---*/
void Clear(IntQueue *q)
{
    q->num = q->front = q->rear = 0;
}

/*--- 큐의 최대 용량 ---*/
int Capacity(const IntQueue *q)
{
    return q->max;
}

/*--- 큐에 쌓여 있는 데이터 개수 ---*/
int Size(const IntQueue *q)
{
    return q->num;
}

/*--- 큐가 비어 있나요? ---*/
int IsEmpty(const IntQueue *q)
{
    return q->num <= 0;
}

/*--- 큐가 가득 찼나요? ---*/
int IsFull(const IntQueue *q)
{
    return q->num >= q->max;
}

/*--- 큐에서 검색 ---*/
int Search(const IntQueue *q, int x)
{
    for (int i = 0; i < q->num; i++)
    {
        int idx;
        if (q->que[idx = (i + q->front) % q->max] == x)
            return idx; //  검색 성공
    }
    return -1; //  검색 실패
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntQueue *q)
{
    for (int i = 0; i < q->num; i++)
        printf("%d", q->que[(i + q->front) % q->max]);
    putchar('\n');
}

/*--- 큐의 종료 ---*/
void Terminate(IntQueue *q)
{
    if (q->que != NULL)
        free(q->que); //   메모리 공간에 할당한 배열 해제
    q->max = q->num = q->front = q->rear = 0;
}

/*
피크 함수 Peek
맨 앞의 데이터(디큐에서 꺼낼 데이터)를 '몰래 엿보는' 함수
que[front]의 값을 출력
데이터를 꺼내지 않아 front, rear, num의 값이 변하지 않음

모든 데이터를 삭제하는 함수 Clear
현 재 큐의 모든 데이터를 삭제하는 함수
(인큐, 디큐는 num, front, rear 값을 바탕으로 값을 0으로 바꿈
실제 큐의 배열 요소의 값을 바꿀 필요 없음)

최대 용량을 확인하는 함수 Capacity
큐의 최대 용량을 반환 하는 함수(멤버 max값을 그대로 반환)

데이터 개수를 확인하는 함수 Size
현재 큐의 데이터 개수를 반환하는 함수 (멤버 num값을 그대로 반환)

큐가 비어있는지 판단하는 함수 IsEmpty
큐가 비어 있는지 판단하며, 비어 있으면 1, 그렇지 않으면 0을 반환

큐가 가득 찼는지 판단하는 함수 IsFull
큐가 가득 찼는지 판단하며, 가득 찼으면 1, 그렇지 않으면 0을 반환

검색 함수 Search
큐의 배열에서 x와 같은 데이터가 저장되어 있는 인덱스를 반환
검색에 성공하면 찾은 요소의 인덱스를 반환하고, 실패하면 -1을 반환
처음부터 선형 검색을 수행하여 검색의 시작 지점은 배열의 물리적인 첫 요소가 아니라 큐의 논리적인 첫 요소
현재 검색하는 위치의 인덱스를 구하는 식은 (i + q->front) % q->max

모든 데이터를 출력하는 함수 Print
Print 함수는 큐의 모든 데이터를 처음부터 끝까지 순서대로 출력하는 함수
(현재 검색하는 위치의 인덱스 계산 방법은 Search함수와 같음)

종료 함수 Terminate
메모리 공간에 할당한 배열 (큐)를 해제하는 함수

*/