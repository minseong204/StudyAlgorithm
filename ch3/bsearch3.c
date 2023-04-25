/*[버전3] bsearch 함수를 사용한 구조체 배열에서의 검색*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef 키워드를 사용함으로서 구조체를 익명구조체로 선언
typedef struct {
    char name[10];      // 이름
    int height;     // 키
    int weight;     // 몸무게
} Human;            // 구조체 별칭 지정

/*=== Human형의 비교 함수 (오름차순으로 이름 정렬) ---*/
int npcmp(const Human *x, const Human *y)
{
    return strcmp(x->name, y->name);
}

int main(void)
{
    Human x[] = {           // 배열 요소는 이름의 오름차순으로
        {"김정우", 179, 78},            // 정렬 되어있어야한다.
        {"박범찬", 182, 83},
        {"박지유", 181, 92},
        {"변진모", 178, 72},
        {"조민성", 191, 85},
        {"최선재", 184, 78},
    };
    int nx = sizeof(x) / sizeof(x[0]);      // 배열 x의 요소 개수
    int retry;
    puts("이름으로 검색합니다.");
    do {
        Human temp;
        printf("이름: ");
        scanf("%s", temp.name);
        Human *h = bsearch(&temp, x, nx, sizeof(Human),
        (int(*)(const void *, const void *)) npcmp);
        if(p== NULL)
            puts("검색에 실패하였습니다.");
        else {
            puts("검색 성공!!!!!! 아래 요소를 찾았습니다.");
            printf("x[%d]: %s %dcm %dkg\n", (int)(p-x), p->name, p->height, p-> weight);
        }
        printf("다시 검색할까요? (1) 예 / (2) 아니오: ");
        scanf("%d", &retry);
    }while (retry == 1);

    return 0;
}


/*
strcmp함수가 반환하는 값
1. x-> name 쪽이 작으면 (알파벳 순서의 앞쪽이면) 음수
2. x->name과 y->name이 같으면 0
3. x->name 쪽이 크면 (알파벳 순서의 뒤쪽이면) 양수
*/

/*
strcmp 함수에 대해
헤더 파일 : #include <string.h>
형식 : int strcmp(const char *s1, const char *s2);
해설 : s1, s2가 가리키는 문자열의 대소 관계를 비교, 처음부터 순서대로 한 문자씩 unsigned char형 값으로 비교
반환 값 : 문자열이 같으면 0, s1이 s2보다 크면 양의 정수, 작으면 음의 정숫값을 반환
예) strcmp("STRING", "STRING");       > 이러면 반환값 0
    strcmp("STRING", "STRIKE");      > 이러면 반환값은 0이 아닌 값*/