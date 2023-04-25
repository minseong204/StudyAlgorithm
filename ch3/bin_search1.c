/*[버전 1] bsearch 함수를 사용해 오름차순으로 정렬된 배열을 이진 검색*/
#include <stdio.h>
#include <stdlib.h>

/*--- 정수를 비교하는 함수 (오름차순)*/
int int_cmp(const int *a, const int *b)
{
    if(*a<*b)
        return -1;
    else if (*a>*b)
        return 1
    else
        return 0;
}

int main(void)
{
    int nx, ky;
    puts("bsearch 함수를 사용하여 검색");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));           // 요소의 개수가 nx인 int형 배열을 생성

    printf("오름 차순으로 입력하세요.\n");
    scanf("%d", &x[0]);
    for(int i = 1; i<nx; i++)
    {
        do {
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
        }while (x[i]<x[i-1]);       // 바로 앞의 값보다 작으면 다시 입력
    }
    printf("검색값: ");
    scanf("%d", &ky);
    int *p= bsearch(
        &ky,                        // 검색값에 대한 포인터
        x,                          // 배열
        nx,                         // 요소의 개수
        sizeof(int),                // 요소의 크기
        (int(*)(const void *, const void *)) int_cmp        // 비교 함수
    );
    if (p == NULL)
        puts("검색에 실패하였습니다.");
    else   
        printf("%d은(는) x[%d]에 있습니다.\n", ky, (int)(p - x));
    free(x);                                                    // 배열 x를 해제
    return 0;
}
/*              bsearch함수의 특징 ( 이진 검색 알고리즘의 성질 )
특징 1 : 검색 대상의 배열은 항상 정렬되어 있어야 한다.
특징 2 : 검색하는 값과 같은 요소가 여러 개 존재하는 경우, 항상 가장 앞쪽에 있는 요소를 찾아내는건 아니다.
*/

/*
1. 첫번 째 인수로 전달하는 매개변수는 키값입니다(검색할 값이 저장된 객체에 대한 포인터). 이프로그램에서는
키값이 변수 ky에 저장되어 있으므로 &ky를 전달합니다.
2. 두 번째 인수로 전달하는 매개변수는 배열의 포인터입니다. 이 프로그램에서는 검색 대상인 배열 x의 포인터(x)
를 전달합니다.
3. 세 번째 인수로 전달하는 매개변수는 배열의 요소 개수입니다. 이 프로그램에서는 nx입니다.
4. 네 번째 인수로 전달하는 매개변수는 배열의 요소 크기입니다. 이 프로그램에선느 검색 대상인 배열 x의 요소의
자료형이 int형 이므로 sizeof(int)를 전달합니다.
5. 가장 복잡한 것이 다섯 번째 인수입니다. (5번째 줄부터 14번째 줄) 
*/
/*      비교함수 bsearch 함수의 반환값에 대한 설명
1. 첫 번째 인수가 가리키는 값이 더 작으면 음숫값을 반환합니다.
2. 첫 번째 인수가 가리키는 값과 두 번째 인수가 가리키는 값이 같으면 0을 반환합니다.
3, 첫 번째 인수가 가리키는 값이 더 크면 양숫값을 반환합니다.
*/
