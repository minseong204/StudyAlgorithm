/*선형 검색*/
#include <stdio.h>
#include <stdlib.h>

/*--- 요소의 개수가 n인 배열 a에서 key와 일치하는 요소를 선형 검색 ---*/
int search(const int a[], int n, int key)
{
    int i = 0;
    while (1) {
        if (i == n)
            return -1;
        if (a[i] == key)
            return i;
        i++;
    }
}

int main(void)
{
    int nx, ky;
    puts("선형 검색");
    printf("요소 개수: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    for(int i = 0; i < nx; i++){
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }
    printf("검색값 : ");
    scanf("%d", &ky);
    int idx = search(x, nx, ky);
    if(idx == -1)
        puts("검색에 실패하였습니다.");
    else
        printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);
    free(x);


    return 0;
}