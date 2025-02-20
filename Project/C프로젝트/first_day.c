#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINE 1024
#define MAX_REGION 50
#define YEARS 9  // 2015 ~ 2023

int main() {
    FILE *file;
    char line[MAX_LINE];
    char region[MAX_REGION][50];
    int total_population[MAX_REGION][YEARS], senior_population[MAX_REGION][YEARS], license_returns[MAX_REGION][YEARS];
    double senior_ratio[MAX_REGION][YEARS], return_ratio[MAX_REGION][YEARS];
    int count = 0;

    // 파일 열기
    file = fopen("C:\\Users\\user\\Desktop\\Project data\\Car_total.csv", "r");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 첫 줄(헤더) 스킵
    fgets(line, MAX_LINE, file);

    // 데이터 읽기
    while (fgets(line, MAX_LINE, file) != NULL && count < MAX_REGION) {
        sscanf(line, "%[^,],"
               "%d,%d,%d,%*d,%*d,%*d," "%d,%d,%d,%*d,%*d,%*d," "%d,%d,%d,%*d,%*d,%*d," 
               "%d,%d,%d,%*d,%*d,%*d," "%d,%d,%d,%*d,%*d,%*d," "%d,%d,%d,%*d,%*d,%*d," 
               "%d,%d,%d,%*d,%*d,%*d," "%d,%d,%d,%*d,%*d,%*d," "%d,%d,%d",
               region[count],
               &total_population[count][0], &senior_population[count][0], &license_returns[count][0],
               &total_population[count][1], &senior_population[count][1], &license_returns[count][1],
               &total_population[count][2], &senior_population[count][2], &license_returns[count][2],
               &total_population[count][3], &senior_population[count][3], &license_returns[count][3],
               &total_population[count][4], &senior_population[count][4], &license_returns[count][4],
               &total_population[count][5], &senior_population[count][5], &license_returns[count][5],
               &total_population[count][6], &senior_population[count][6], &license_returns[count][6],
               &total_population[count][7], &senior_population[count][7], &license_returns[count][7],
               &total_population[count][8], &senior_population[count][8], &license_returns[count][8]);
        count++;
    }
    fclose(file);

    // 연도별 최고/최저 비율 계산
    for (int year = 0; year < YEARS; year++) {
        char max_senior_region[50] = "", min_senior_region[50] = "";
        char max_return_region[50] = "", min_return_region[50] = "";
        double max_senior_ratio = 0.0, min_senior_ratio = 100.0;
        double max_return_ratio = 0.0, min_return_ratio = 100.0;

        for (int i = 0; i < count; i++) {
            // ?? 각 연도별 데이터 확인
//            printf("DEBUG: %d년 %s | 총인구: %d, 65세 이상: %d, 반납: %d\n",
//                   2015 + year, region[i], total_population[i][year], senior_population[i][year], license_returns[i][year]);

            // 고령 인구 비율 계산 (0 나누기 방지)
            if (total_population[i][year] > 0) {
                senior_ratio[i][year] = (double) senior_population[i][year] / total_population[i][year] * 100;
                if (senior_ratio[i][year] > max_senior_ratio) {
                    max_senior_ratio = senior_ratio[i][year];
                    strcpy(max_senior_region, region[i]);
                }
                if (senior_ratio[i][year] < min_senior_ratio) {
                    min_senior_ratio = senior_ratio[i][year];
                    strcpy(min_senior_region, region[i]);
                }
            }

            // 면허 반납 비율 계산 (0 나누기 방지 및 비정상 값 필터링)
            if (senior_population[i][year] > 0) {
                return_ratio[i][year] = (double) license_returns[i][year] / senior_population[i][year] * 100;
                
                // ?? 비정상적으로 높은 값 필터링
                if (return_ratio[i][year] > 100.0) {
                    printf("경고: %d년 %s 지역 반납 비율 비정상적 (%.2f%%)\n", 2015 + year, region[i], return_ratio[i][year]);
                    return_ratio[i][year] = 100.0;
                }
                
                if (return_ratio[i][year] > max_return_ratio) {
                    max_return_ratio = return_ratio[i][year];
                    strcpy(max_return_region, region[i]);
                }
                if (return_ratio[i][year] < min_return_ratio) {
                    min_return_ratio = return_ratio[i][year];
                    strcpy(min_return_region, region[i]);
                }
            }
        }

        // 연도별 출력
        printf("%d년 고령 인구 비율이 가장 높은 지역 : %s (%.4f%%)\n", 2015 + year, max_senior_region, max_senior_ratio);
        printf("%d년 고령 인구 비율이 가장 낮은 지역 : %s (%.4f%%)\n", 2015 + year, min_senior_region, min_senior_ratio);
        printf("%d년 고령 인구 비율 반납자 비율 높은 지역 : %s (%.4f%%)\n", 2015 + year, max_return_region, max_return_ratio);
        printf("%d년 고령 인구 비율 반납자 비율 낮은 지역 : %s (%.4f%%)\n\n", 2015 + year, min_return_region, min_return_ratio);
    }

    printf("2019 년도 65세 이상 운전면혀 소지자 중 반납비율 : (%.4f%%)\n", ((double)73293/3337165)*100);
    printf("2020 년도 65세 이상 운전면혀 소지자 중 반납비율 : (%.4f%%)\n", ((double)76002/3682632)*100);
    printf("2021 년도 65세 이상 운전면혀 소지자 중 반납비율 : (%.4f%%)\n", ((double)83997/4016538)*100);
    printf("2022 년도 65세 이상 운전면혀 소지자 중 반납비율 : (%.4f%%)\n", ((double)112942/4387358)*100);
    printf("2023 년도 65세 이상 운전면혀 소지자 중 반납비율 : (%.4f%%)\n", ((double)112896/4747426)*100);
    
    
    return 0;
}
