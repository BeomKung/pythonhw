#include <stdio.h>

void main()
{   
    // 삽입정렬렬
    int num[5];
    int tmp = 0;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &num[i]);
        printf("삽입할 요소 %d\n", num[i]);
        
        int j = i;
        
        while (j > 0 && num[j - 1] > num[j]) {
            tmp = num[j];
            num[j] = num[j - 1];
            num[j - 1] = tmp;
            j--;
        }
        
        printf("현재 정렬된 부분: ");
        for (int k = 0; k <= i; k++) {
            printf("%d ", num[k]);
        }
        printf("\n");
    }
}
