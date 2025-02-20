#include <stdio.h>

void main()
{   

  // int arr[5] = {64, 25, 12, 22, 11};
    // int i, j, temp;
    // int *p = arr;
    
    // for (i = 0; i < 5-1; i++) {
    //     printf("%d 회차 : ", i+1);
    //     for (j = i + 1; j < 5; j++) {
    //         if (*(p + i) > *(p + j)) {
    //             temp = *(p + i);
    //             *(p + i) = *(p + j);
    //             *(p + j) = temp;
    //         }
            
    //     }
    //     for(int k = 0; k < 5; k++){
    //             printf("%d ", arr[k]);
    //         }
    //     printf("\n");
        
    // }
    // printf("최종결과 : ");
    // for (i = 0; i < 5; i++) {
    //     printf("%d ", arr[i]);
    // }
    int arr[5] = {11, 35, 85, 22, 5}; 
    int *p;
    p = arr;
    printf("초기 : ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");
    for (int j = 0; j < 4; j++) {
        int Min = *(p + j);
        int tmp;
        
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
