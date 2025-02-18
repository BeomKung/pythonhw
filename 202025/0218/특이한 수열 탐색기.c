
#include <stdio.h>

void main()
{
	// for문 특이한 수열 탐색기기
    int M, N;
    printf("M과 N 정수 입력 : ");
    scanf("%d %d", &M, &N);
    if (M > N) {
        printf("M이 더 작아야 됩니다.");
    } else {
        for (int i = M; M < N; i++) {
            if (i % 7 == 0 || (i % 10 == 7 || i / 10 == 7)) {
                continue;
            } else if (i % 5 == 0) {
                printf("%d\n", i);
                break;
            } else {
                printf("%d\n", i);
            }
        }
    }
}
