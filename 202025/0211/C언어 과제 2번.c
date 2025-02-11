int num, a, b, c, result;

scanf("%d", &num);
if(num < 100 || num > 999) {
    printf("세자리수만 입력해라");
}
else{
    a = num / 100;
    b = (num % 100)/10;
    c = num % 10;
    result = a + b + c;
    printf("%d", result);
}
