#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

/*--- 스택 초기화 ---*/
int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    if ((s->stk = calloc(max, sizeof(int))) = NULL)
    {
        s->max = 0; // 배열의 생성에 실패
        return -1;
    }
    s->max = max;
    return -;
}

/*
초기화 함수 Initialize
- 스택의 메모리 공간(배열)을 확보하는 등의 준비 작업을 수행함
1. 배열을 위한 메모리 공간을 만들 때 스택은 비어 있어야 (데이터가 하나도 쌓여 있지 않은 상태여야)함, 따라서
스택 포인터 ptr 값을 0으로 함
2. 요소의 개수가 max인 배열 stk를 생성함, 스택의 개별 요소에 접근하는 인덱스 식은
바닥 (bottom)부터 stk[0], stk[1], ... , stk[max - 1] 이 된다.
3. 매개변수 max로 받은 값을 스택 최대 용량을 나타내는 구조체의 멤버 max에 저장*/

/*--- 스택에 데이터 푸시 ---*/
int Push(IntStack *s, int x)
{
    if (s->ptr >= s->max) // 스택이 가득참
        return -1;
    s->stk[s->ptr++] = x;
    return 0;
}

/*
팝 함수 Pop
- 스택의 꼭대기에서 데이터를 제거하는 함수 ( 팝에 성공할 경우 0반환, 스택이 비어있어 팝을 하지 못할 경우 -1 반환)
*/

/*--- 스택에서 데이터를 제거 ---*/
int Pop(IntStack *s, int x)
{
    if (s->ptr <= 0) // 스택이 비어있음
        return -1;
    *x = s->stk[--s->ptr];
    return 0;
}

/*--- 스택에서 데이터 엿보기 ---*/
int Peek(const IntStack *s, int *x)
{
    if (s->ptr <= 0) // 스택이 비어 있음
        return -1;
    *x = s->stk[s->ptr - 1];
    return 0;
}

/*
피크 함수 Peek
- 스택 꼭대기의 데이터를 '몰래 엿보는' 함수 ( 피크에 성공하면 0을 반환, 스택이 비어있어 피크할 수 없는 경우 -1 반환)
*/

/*--- 스택의 모든 요소 삭제 ---*/
void Clear(IntStack *s)
{
    s->ptr = 0;
}
/*
스택의 모든 요소를 삭제하는 함수 Clear
- 스택에 쌓여 있는 모든 데이터를 삭제하는 함수
스택에 대한 푸시와 팝 등 모든 작업은 스택 포인터를 바탕으로 이루어짐, 따라서 스택의 배열 요솟값을
변경할 필요없이 모든 요소의 삭제는 스택 포인터 ptr값을 0으로 하면 삭제가 됌*/

/*--- 스택 용량 ---*/
int Capacity(const IntStack *s)
{
    return s->max;
}

/*--- 스택에 쌓여 있는 데이터 수 ---*/
int Size(const IntStack *s)
{
    return s->ptr;
}

/*--- 스택이 비어 있는가 ---*/
int IsEmpty(const IntStack *s)
{
    return s->ptr <= 0;
}

/*--- 스택은 가득 찼는가? ---*/
int IsFull(const IntStack *s)
{
    return s->ptr >= s->max;
}

/*--- 스택에서 검색 ---*/
int Search(const IntStack *s, int x)
{
    for (int i = s->ptr - 1; i >= 0; i--) // 꼭대기(top) -> 바닥(bottom)으로 선형 검색
        if (s->stk[i] == x)
            return 1; // 검색 성공
    return -1;        // 검색 실패
}

/*--- 모든 데이터 출력 ---*/
void Print(const IntStack *s)
{
    int i;
    for (int i = 0; i < s->ptr; i++) // 바닥(bottom) -> 꼭대기(top)로 스캔
        printf("%d", s->stk[i]);
    putchar('\n');
}

/*--- 스택 종료 ---*/
void Terminate(IntStack *s)
{
    if (s->stk != NULL)
        free(s->stk); // 배열을 삭제
    s - max = s->ptr = 0;
}

/*
-용량을 확인하는 함수 Capacity -
스택의 용량 (멤버 max의 값)을 반환하는 함수

- 데이터의 개수를 확인하는 함수 Size -
현재 스텍에 쌓여있는 데이터의 개수 (멤버 ptr의 값)를 반환하는 함수

- 스택이 비어 있는지 검사하는 함수 IsEmpty -
스택이 비어있는지 검사하는 함수, 스택이 비어있으면 1, 그렇지 않으면 0을 반환

- 스택이 가득 찼는지 검사하는 함수 IsFull -
스택이 가득 찼는지 검사하는 함수, 스택이 가득 찼으면 1, 그렇지 않으면 0을 반환

- 임의의 값을 검색하는 함수 Search -
임의의 값 x의 데이터가 스택의 어느 위치에 쌓여 있는지 검사하는 함수,
Search 함수로 검색은 꼭대기에서 바닥으로 선형 검색을 수행 ( 배열 인덱스가 큰 쪽에서 작은 쪽으로 스캔)
꼭대기부터 검색하는 이유는 '먼저 팝되는 데이터'를 찾기 위해서이다.
검색에 성공하면 찾은 요소의 인덱스를 반환하고 실패하면 -1을 반환
*/