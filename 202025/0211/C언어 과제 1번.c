int a, b, c;
scanf("%d %d %d", &a, &b, &c);

if (c == 0) {
    printf("0으로 나누기 ㄴㄴ\n");
} else {
    double result = (a + b) * c - (double)(a - b) / c;
    printf("%.2f\n", result);
}
}
