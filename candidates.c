#include <stdio.h>
#include <stdlib.h>

int main()
{
    char candidate01[2200], candidate02[2200], candidate03[2200], candidate04[2200], candidate05[2200], candidate06[2200];
    char *candidates[6] = {candidate01, candidate02, candidate03, candidate04, candidate05, candidate06};

    const char *member_info[11] = {"성명", "생일(YYYY/MM/DD 형식)", "성별(여성이면 F 또는 남성이면 M)", "메일 주소", "국적", "BMI", "주 스킬", "보조 스킬", "한국어 등급(TOPIK)", "MBTI", "소개"};

    int candidate_number = 0;

    // 데이터 입력
    printf("####################################\n");
    printf("     오디션 후보자 데이터 입력\n");
    printf("####################################\n");
    while (candidate_number < 6)
    {
        printf("=================================\n");
        printf("%d 번째 후보자의 정보를 입력합니다.\n", candidate_number + 1);
        printf("---------------------------------\n");

        for (int i = 0; i < 11; i++)
        {
            printf("%d. %s: ", i + 1, member_info[i]);
            fgets(candidates[candidate_number] + (i * 200), 200, stdin);

            char *newline_pos = candidates[candidate_number] + (i * 200); // strtok 개행 없애기
            while (*newline_pos != '\0')
            {
                if (*newline_pos == '\n')
                {
                    *newline_pos = '\0';
                    break;
                }
                newline_pos++;
            }
        }

        candidate_number++;
    }

    // 데이터 출력
    printf("\n####################################\n");
    printf("     오디션 후보자 데이터 조회\n");
    printf("####################################\n");
    for (int i = 0; i < 6; i++)
    {
        char *current_candidate = candidates[i];
        char gender[10];

        // strcmp 비교하기
        char *gender_pointer = current_candidate + 400;
        int is_female = 1;
        while (*gender_pointer != '\0' && *gender_pointer == 'F')
        {
            is_female = 1;
            break;
        }
        while (*gender_pointer != '\0' && *gender_pointer == 'M')
        {
            is_female = 0;
            break;
        }

        // strcpy 문자열 복사하기
        if (is_female)
        {
            char *src = "여";
            char *dest = gender;
            while (*src)
            {
                *dest++ = *src++;
            }
            *dest = '\0';
        }
        else
        {
            char *src = "남";
            char *dest = gender;
            while (*src)
            {
                *dest++ = *src++;
            }
            *dest = '\0';
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
