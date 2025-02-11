//if문 문제
    // 특별한 숫자 판별기기
    int num, a, b, c, result;
    
    printf("숫자를 입력하세요 (0 ~ 999): ");
    scanf("%d", &num);

    if (num < 0 || num > 999) {
        printf("범위 안의 숫자를 입력해주세요\n");
    } 
    else if (num < 10) {  // 한 자리 수
        if ((num % 3 == 0) && (num % 2 == 1)) {
            printf("특별한 숫자입니다\n");
        } 
        else if (num % 7 == 0) {
            printf("특별한 숫자입니다\n");
        } 
        else {
            printf("특별한 숫자가 아닙니다\n");
        }
    } 
    else if (num < 100) {  // 두 자리 수
        a = num / 10;
        b = num % 10;
        result = a + b;

        if ((num % 3 == 0) && (num % 2 == 1)) {
            printf("특별한 숫자입니다\n");
        } 
        else if (result % 7 == 0) {
            printf("특별한 숫자입니다\n");
        } 
        else if (a > b) {
            printf("특별한 숫자입니다\n");
        } 
        else {
            printf("특별한 숫자가 아닙니다\n");
        }
    } 
    else {  // 세 자리 수
        a = num / 100;       // 백의 자리
        b = (num % 100) / 10; // 십의 자리
        c = num % 10;        // 일의 자리
        result = a + b + c;

        if ((num % 3 == 0) && (num % 2 == 1)) {
            printf("특별한 숫자입니다\n");
        } 
        else if (result % 7 == 0) {
            printf("특별한 숫자입니다\n");
        } 
        else if (a > c) {
            printf("특별한 숫자입니다\n");
        } 
        else {
            printf("특별한 숫자가 아닙니다\n");
        }
    }
