
#include <stdio.h>
#include <string.h>

void main()
{ 
  enum cartype {
    SEDAN = 1,
    SUV = 2,
    TRUCK = 3,
    VAN = 4  
    };
    
    char *sedan[] = {"AVANTE", "SONATA", "MALIBU", "K5", "CAMRY", "GRANDEUR"};
    char *suv[] = {"TUCSON", "SPORTAGE", "SANTAFE", "KONA", "RAV4"};
    char *truck[] = {"RAM", "FORD", "PORTER", "MIGHTY", "BONGO"};
    char *van[] = {"SIENNA", "CARNIVAL", "PACIFICA", "ODYSSEY"};

    char choice[50];
    enum cartype carType;
    
    printf("차량 모델를 입력하세요 : ");
    scanf("%s", choice);
    
    for (int i = 0; i < sizeof(sedan) / sizeof(sedan[0]); i++){
        if (strcmp(choice, sedan[i]) == 0) {
            carType = SEDAN;
            break;
        }
    }
    for (int i = 0; i < sizeof(suv) / sizeof(suv[0]); i++){
        if (strcmp(choice, suv[i]) == 0) {
            carType = SUV;
            break;
        }
    }
    for (int i = 0; i < sizeof(truck) / sizeof(truck[0]); i++){
        if (strcmp(choice, truck[i]) == 0) {
            carType = TRUCK;
            break;
            
        }
    }
    for (int i = 0; i < sizeof(van) / sizeof(van[0]); i++){
        if (strcmp(choice, van[i]) == 0) {
            carType = VAN;
            break;
        }
    }
    
    switch (carType) {
        case SEDAN:
            printf("선택한 차량 종류는: SEDAN\n");
            break;
        case SUV:
            printf("선택한 차량 종류는: SUV\n");
            break;
        case TRUCK:
            printf("선택한 차량 종류는: TRUCK\n");
            break;
        case VAN:
            printf("선택한 차량 종류는: VAN\n");
            break;
        default:
            printf("잘못된 선택입니다.\n");
            break;
    }
    
}
