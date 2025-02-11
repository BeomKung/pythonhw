int a, b, c;
scanf("%d %d %d", &a, &b, &c);

if (c == 0) {
    printf("0으로 나누기 ㄴㄴ\n");
} else {
    int result = (a + b) * c - (a - b) / c;
    printf("%d\n", result);
}
