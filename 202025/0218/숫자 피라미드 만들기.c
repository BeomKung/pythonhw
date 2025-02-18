#include <stdio.h>

void main()
{
//숫자 피라미드 만들기
    int n;
    printf("숫자를 입력해주세요 : ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++){
            printf(" ");
        }
        for (int j = 1; j <= i; j++){
            printf("%d ", j);
        }
        printf("\n");
        
    }
}
