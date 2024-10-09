#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 6
#define MAX_INFO_SIZE 2200

int main()
{
    char candidate01[MAX_INFO_SIZE], candidate02[MAX_INFO_SIZE], candidate03[MAX_INFO_SIZE], candidate04[MAX_INFO_SIZE], candidate05[MAX_INFO_SIZE], candidate06[MAX_INFO_SIZE];
    char *candidates[MAX_CANDIDATES] = {candidate01, candidate02, candidate03, candidate04, candidate05, candidate06};

    const char *member_info[11] = {"성명", "생일(YYYY/MM/DD 형식)", "성별(여성이면 F 또는 남성이면 M)", "메일 주소", "국적", "BMI", "주 스킬", "보조 스킬", "한국어 등급(TOPIK)", "MBTI", "소개"};

    int candidate_number = 0;

    // 데이터 입력
    printf("####################################\n");
    printf("     오디션 후보자 데이터 입력\n");
    printf("####################################\n");
    while (candidate_number < MAX_CANDIDATES)
    {
        printf("=================================\n");
        printf("%d 번째 후보자의 정보를 입력합니다.\n", candidate_number + 1);
        printf("---------------------------------\n");

        for (int i = 0; i < 11; i++)
        {
            printf("%d. %s: ", i + 1, member_info[i]);
            fgets(candidates[candidate_number] + (i * 200), 200, stdin);
            strtok(candidates[candidate_number] + (i * 200), "\n");
        }

        candidate_number++;
    }

    // 데이터 출력
    printf("\n####################################\n");
    printf("     오디션 후보자 데이터 조회\n");
    printf("####################################\n");
    for (int i = 0; i < MAX_CANDIDATES; i++)
    {
        char *current_candidate = candidates[i];
        char gender[10];

        if (strcmp(current_candidate + 400, "F") == 0)
        {
            strcpy(gender, "여");
        }
        else if (strcmp(current_candidate + 400, "M") == 0)
        {
            strcpy(gender, "남");
        }

        printf("===============================================================================================================\n");
        printf("성  명 | 생   일      | 성별   | 메   일               | 국적 | BMI  | 주스킬 | 보조스킬 | TOPIK | MBTI |\n");
        printf("===============================================================================================================\n");

        printf("%-6s | %-14s | %-3s | %-20s | %-4s | %-4s | %-6s | %-7s | %-5s | %-4s |\n",
               current_candidate, current_candidate + 200, gender, current_candidate + 600, current_candidate + 800, current_candidate + 1000, current_candidate + 1200, current_candidate + 1400, current_candidate + 1600, current_candidate + 1800);
        printf("----------------------------------------------------------------------------------------------------------------\n");
        printf("%s\n", current_candidate + 2000);
        printf("----------------------------------------------------------------------------------------------------------------\n");
    }

    getchar();
    return 0;
}