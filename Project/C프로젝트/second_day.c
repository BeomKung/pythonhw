#include <stdio.h>      // 표준 입출력 함수 사용을 위한 헤더
#include <stdlib.h>     // 표준 라이브러리 함수(예: exit, atof) 사용을 위한 헤더
#include <string.h>     // 문자열 처리 함수 사용을 위한 헤더
#include <ctype.h>      // 문자 처리 함수(isspace) 사용을 위한 헤더

// 상수 정의
#define MAX_YEARS 5        // 데이터에 포함된 연도 수 (2019 ~ 2023)
#define MAX_AGE_GROUPS 6   // 연령대 수 (18-29세, 30-39세, 40-49세, 50-59세, 60-64세, 65세 이상)
#define START_YEAR 2019    // 데이터의 시작 연도

// 연령대별 데이터를 저장하기 위한 구조체 정의
typedef struct {
    char age_group[20];                 // 연령대 이름 (예: "18-29세")
    double license_holders[MAX_YEARS];  // 각 연도별 면허 소지자 수
    double accident_count[MAX_YEARS];   // 각 연도별 사고 건수
    double fatalities[MAX_YEARS];       // 각 연도별 사망자 수
} AgeData;

// trim 함수: 문자열의 앞뒤 공백(스페이스, 탭 등)을 제거하여 반환합니다.
char* trim(char *str) {
    // 문자열의 시작 부분에서 공백을 건너뜁니다.
    while(isspace((unsigned char)*str)) str++;
    // 문자열이 모두 공백이라면 그대로 반환합니다.
    if(*str == 0) return str;
    // 문자열의 끝으로 포인터를 이동합니다.
    char *end = str + strlen(str) - 1;
    // 끝 부분부터 거꾸로 이동하며 공백을 건너뜁니다.
    while(end > str && isspace((unsigned char)*end)) end--;
    // 마지막 유효 문자의 다음 위치에 null 문자('\0')를 삽입하여 문자열을 종료합니다.
    *(end+1) = '\0';
    return str; // 공백이 제거된 문자열 포인터를 반환합니다.
}

// readDataFromCSV 함수: CSV 파일에서 데이터를 읽어 AgeData 배열에 저장합니다.
// CSV 파일은 첫 번째 행은 헤더(열 제목), 
// 두 번째 행은 사망자 수, 세 번째 행은 면허 소지자 수, 네 번째 행은 사고 건수를 포함합니다.
// 각 행의 첫 번째 열은 해당 행의 제목(예: "전국 연령대 사망자수")이므로 건너뜁니다.
void readDataFromCSV(const char *filename, AgeData data[], int size) {
    // 모든 AgeData 구조체의 숫자 데이터를 0.0으로 초기화합니다.
    for (int i = 0; i < size; i++)
        for (int y = 0; y < MAX_YEARS; y++)
            data[i].license_holders[y] = data[i].accident_count[y] = data[i].fatalities[y] = 0.0;

    // CSV 파일을 읽기 모드("r")로 엽니다.
    FILE *fp = fopen(filename, "r");
    if (!fp) { 
        // 파일 열기에 실패하면 에러 메시지를 출력하고 프로그램을 종료합니다.
        printf("파일을 열 수 없습니다: %s\n", filename);
        exit(1);
    }

    char line[1024];  // 파일의 한 줄을 저장할 버퍼
    int row = 0;      // 현재 읽은 행 번호를 저장하는 변수

    // 파일의 모든 줄을 한 줄씩 읽습니다.
    while (fgets(line, sizeof(line), fp)) {
        // 읽은 줄의 끝에 있는 개행 문자('\n') 또는 캐리지 리턴('\r')을 제거합니다.
        line[strcspn(line, "\r\n")] = '\0';

        // 첫 번째 행은 헤더(열 제목)로 사용되므로 건너뜁니다.
        if (row == 0) { 
            row++;
            continue;
        }

        // strtok 함수를 사용하여 줄을 ',' 구분자로 토큰화합니다.
        char *token = strtok(line, ",");
        int col = 0;  // 현재 열 번호를 저장하는 변수

        // 해당 줄의 모든 토큰(열 데이터)에 대해 반복합니다.
        while (token != NULL) {
            // 토큰의 앞뒤 공백을 제거합니다.
            token = trim(token);
            // 첫 번째 열(토큰 번호 0)은 행 제목이므로 건너뜁니다.
            if (col >= 1) {
                // col-1을 기준으로 연령대 인덱스와 연도 인덱스를 계산합니다.
                // 예: col=1이면 (col-1)=0 -> age_idx = 0 % 6 = 0, year_idx = 0 / 6 = 0.
                int age_idx = (col - 1) % MAX_AGE_GROUPS;
                int year_idx = (col - 1) / MAX_AGE_GROUPS;
                // 토큰 문자열을 실수형(double) 값으로 변환합니다.
                double value = atof(token);
                // 각 행(row)에 따라 해당 값을 구조체의 올바른 필드에 저장합니다.
                if (row == 1)         data[age_idx].fatalities[year_idx] = value;      // 두 번째 행: 사망자 수
                else if (row == 2)    data[age_idx].license_holders[year_idx] = value; // 세 번째 행: 면허 소지자 수
                else if (row == 3)    data[age_idx].accident_count[year_idx] = value;    // 네 번째 행: 사고 건수
            }
            // 다음 토큰을 가져옵니다.
            token = strtok(NULL, ",");
            // 열 번호를 증가시킵니다.
            col++;
        }
        // 한 행 처리가 끝나면 행 번호를 증가시킵니다.
        row++;
    }
    // 파일을 닫습니다.
    fclose(fp);
}

// accident_rate_per_license 함수: 주어진 연도에 대해 "면허 소지자수 대비 사고 건수"를 계산하여 출력합니다.
void accident_rate_per_license(AgeData data[], int size, int year_index) {
    // 출력 헤더: 해당 연도를 표시합니다.
    printf("\n[전국 면허 소지자수 대비 사고 건수 - %d년]\n", START_YEAR + year_index);
    // 각 연령대에 대해 반복합니다.
    for (int i = 0; i < size; i++) {
        // 현재 연령대의 해당 연도 면허 소지자 수와 사고 건수를 가져옵니다.
        double license = data[i].license_holders[year_index];
        double accidents = data[i].accident_count[year_index];
        // 데이터가 0이면 "데이터 없음"을 출력합니다.
        if (license == 0 || accidents == 0)
            printf("%s: 데이터 없음\n", data[i].age_group);
        else
            // 그렇지 않으면 사고율을 계산하여 퍼센트(%)로 출력합니다.
            printf("%s: %.2f%%\n", data[i].age_group, (accidents / license) * 100);
    }
}

// fatality_rate_per_accident 함수: 주어진 연도에 대해 "사고 건수 대비 사망자 수"를 계산하여 출력합니다.
void fatality_rate_per_accident(AgeData data[], int size, int year_index) {
    // 출력 헤더: 해당 연도를 표시합니다.
    printf("\n[전국 연령대별 사고 건수 대비 사망자 수 - %d년]\n", START_YEAR + year_index);
    // 각 연령대에 대해 반복합니다.
    for (int i = 0; i < size; i++) {
        // 현재 연령대의 해당 연도 사고 건수와 사망자 수를 가져옵니다.
        double accidents = data[i].accident_count[year_index];
        double fatal = data[i].fatalities[year_index];
        // 데이터가 0이면 "데이터 없음"을 출력합니다.
        if (accidents == 0 || fatal == 0)
            printf("%s: 데이터 없음\n", data[i].age_group);
        else
            // 그렇지 않으면 사망률을 계산하여 퍼센트(%)로 출력합니다.
            printf("%s: %.2f%%\n", data[i].age_group, (fatal / accidents) * 100);
    }
}

// main 함수: 프로그램의 시작점입니다.
int main() {
    // MAX_AGE_GROUPS 크기의 AgeData 배열을 선언합니다.
    AgeData age_data[MAX_AGE_GROUPS];
    // 미리 정의된 연령대 이름 배열입니다.
    const char *ageGroupNames[MAX_AGE_GROUPS] = {"18-29세", "30-39세", "40-49세", "50-59세", "60-64세", "65세 이상"};
    // 각 AgeData 구조체의 age_group 필드에 미리 정의된 이름을 복사합니다.
    for (int i = 0; i < MAX_AGE_GROUPS; i++)
        strcpy(age_data[i].age_group, ageGroupNames[i]);

    // CSV 파일 경로를 지정합니다.
    const char *filepath = "C:\\Users\\user\\Desktop\\Project data\\Data_Total_c.csv";
    // CSV 파일로부터 데이터를 읽어 age_data 배열에 저장합니다.
    readDataFromCSV(filepath, age_data, MAX_AGE_GROUPS);

    // ① 먼저, 모든 연도(2019~2023)에 대해 "면허 소지자수 대비 사고 건수"를 출력합니다.
    for (int year = 0; year < MAX_YEARS; year++)
        accident_rate_per_license(age_data, MAX_AGE_GROUPS, year);

    // ② 그 후, 모든 연도에 대해 "사고 건수 대비 사망자 수"를 출력합니다.
    for (int year = 0; year < MAX_YEARS; year++)
        fatality_rate_per_accident(age_data, MAX_AGE_GROUPS, year);

    return 0;  // 프로그램 정상 종료
}
