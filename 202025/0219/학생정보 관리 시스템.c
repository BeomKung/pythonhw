#include <stdio.h>

void main()
{  
  
  struct student {
          char name[30];
          int age;
          int grade;
      };
      struct student s;
      printf("학생 정보를 입력해주세요(이름 나이 학년 순으로) :");
      scanf("%s", s.name);
      scanf("%d", &s.age);
      scanf("%d", &s.grade);
      
      printf("학생 이름 : %s\n나이 : %d\n등급 : %d", s.name, s.age, s.grade);
}
