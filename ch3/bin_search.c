/*이게 존나 중요함 씨발*/
/*이진 검색*/
/*이진 검색 (binary search)는 요소가 오름차순 또는 내림차순으로 정렬된 배열에서 검색하는 알고리즘
n개의 요소가 오름차순으로 늘어선 배열 a에서 키를 이진 검색으로 검색하는 과정을 일반적인 방법으로 표현했을 때가 
아래의 코드임
검색 범위의 맨 앞 인덱스를 pl, 맨 끝 인덱스를 pr, 중앙 인덱스를 pc라고 했을 때 검색을 시작할 때는
pl은 0, pr은 n-1, pc는 (n-1)/2로 초기화 함으로써 이진 검색을 한단계씩 진행할때마다 
검색 범위가 반으로 좁혀지고, 검사한 요소를 하나씩 제외시키는 선형 검색과는 다르게 이진 검색은 검색할 요소 a[pc]
가 해당 단게에서 다음에 검색할 범위의 중간 지점으로 단숨에 이동함*/

/*하지만 아래의 코드는 시간복잡도가 높은 경우이다. 버전 1이 제일 시간복잡도가 높을 때이고, 버전이 업그레이드 
될수록 시간 복잡도는 낮아진다 시간복잡도는 O(n)으로 표현하며 시간 복잡도가 낮을 수록 좋은 프로그램이다*/

#include <stdio.h>
#include <stdlib.h>

/*--- 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 이진 검색 ---*/
int bin_search(const int a[], int n, int key)
{
    int pl = 0;     // 검색 범위 맨 앞의 인덱스
    int pr = n - 1; // 검색 범위 맨 끝의 인덱스

    do
    {
        int pc = (pl + pr) / 2; // 검색 범위 한가운데의 인덱스
        if (a[pc] == key)       // 검색 성공
            return pc;
        else if (a[pc] < key)
            pl = pc + 1; // 검색 범위를 뒤쪽 절반으로 좁힘
        else
            pl = pc - 1; // 검색 범위를 앞쪽 절반으로 좁힘
    } while (pl <= pr);
    return -1; // 검색 실패
}

int main(void)
{
    int nx, ky;

    puts("이진 검색");
    printf("요소 개수 : ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    printf("오름차순으로 입력하세요.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for (int i = 1; i < nx; i++)
    {
        do
        {
            printf("x[%d]: ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]); // 바로 앞의 값보다 작으면 다시 입력
    }

    printf("검색 값: ");
    scanf("%d", &ky);
    int idx = bin_search(x, nx, ky); // 배열 x에서 값이 ky인 요소를 이진 검색
    if (idx == -1)
        puts("검색에 실패했습니다.");
    else
        printf("%d는(은) x[%d]에 있습니다.\n", ky, idx);
    free(x); //   배열 x를 해제

    return 0;
}