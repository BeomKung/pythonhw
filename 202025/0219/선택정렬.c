#include <stdio.h>

void main()
{   
    int arr[5] = {64, 25, 12, 22, 11};
    int *p;
    p = arr;
    printf("초기 : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
    for (int j = 0; j < 5; j++) {
        int Min = *(p + j);
        int tmp = j;
        
        for (int i = j; i < 5; i++) {
            if(*(p + i) < Min){
                Min = *(p + i);
                tmp = i;
            } 
        }
        
        *(p + tmp) = *(p + j);
        *(p + j) = Min;
        
        printf("%d 단계: ",j + 1);
        for (int i = 0; i < 5; i++) {
            printf("%d ", *(p + i));
        }
        printf("\n");
    }
}
