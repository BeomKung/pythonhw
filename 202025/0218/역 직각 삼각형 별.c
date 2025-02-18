#include <stdio.h>

void main()
{
//역 직각 삼각형 별
    printf("숫자를 입력해주세요 : ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n - i ; j++) {
            printf("*");
        }
        printf("\n");
    }
}
