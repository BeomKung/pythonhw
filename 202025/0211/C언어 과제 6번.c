
// 등급 계싼기
int score;
char grade;
float bonus;
printf("점수를 입력해주세요 :");
scanf("%d", &score);

if (score >= 90){
    grade = 'A';
    bonus = score * 0.1;
}
else if (score >= 80){
    grade = 'B';
    bonus = score * 0.05;
}
else if (score >= 70){
    grade = 'C';
}
else if (score >= 60){
    grade = 'D';
}
else {
    grade = 'F';
}

printf("등급: %c 등급\n", grade);
if (bonus > 0) {
    printf("보너스: %.2f\n", bonus);
} 
else {
    printf("보너스: 없음\n");
}
