#include <stdio.h>

void main()
{
    // 1부터 N까지 출력
    int n;
    printf("숫자를 입력해주세요 : ");
    scanf("%d", &n);
    int i = 1;
    while (i <= n) {
        printf("%d ", i);
        i = i + 1;
    }
}
