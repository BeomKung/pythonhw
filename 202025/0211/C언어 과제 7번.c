
// 옷차림 추천 프로그램
double temp;
printf("현재 온도를 입력해주세요. :");
scanf("%lf", &temp);

if (temp >= 30.0) {
    printf("너무 더워요! 반팔과 반바지를 입으세요.");
}
else if (temp >= 25.0) {
    printf("따뜻한 날씨입니다! 가벼운 옷을 입으세요.");
}
else if (temp >= 15.0) {
    printf("선선한날씨입니다다! 가벼운 겉옷을 챙기세요");
}
else if (temp >= 5.0) {
    printf("조금 쌀쌀합니다! 따뜻한 옷을 입으세요");
}
else if (temp >= 0.0) {
    printf("매우 춥습니다! 두꺼운 외투를 꼭 입으세요");
}
else {
    printf("한파 경고! 패딩과 장갑, 모자를 착용하세요.");
}
