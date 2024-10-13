#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CANDIDATES 6
#define INFO_SIZE 7
#define NAME_SIZE 50

int main()
{
    char candidates[MAX_CANDIDATES * NAME_SIZE];
    int scoring_sheet[MAX_CANDIDATES * INFO_SIZE];
    char judge_name[10], expertise[10];
    char names[] = "박지연,Ethan Smith,Suphanan Wong,Helena Silva,Karolina Nowak,Liam Wilson";

    // char *token = strtok(names, ",");
    // for (int i = 0; i < MAX_CANDIDATES; i++)
    // {
    //     strncpy(&candidates[i * NAME_SIZE], token, NAME_SIZE - 1);
    //     candidates[(i + 1) * NAME_SIZE - 1] = '\0'; // Ensure null-terminated strings
    //     token = strtok(NULL, ",");
    // }

    while (1)
    {
        // 심사자 정보 입력
        printf("####################################\n");
        printf("#       오디션 심사 결과 입력     #\n");
        printf("####################################\n");
        printf("> 심사자 이름: ");
        scanf("%9s", judge_name);
        printf("> 전문 분야: ");
        scanf("%9s", expertise);
        getchar();
        printf("++++++++++++++++++++++++++++++++++++\n");

        // 후보자 점수 입력
        for (int i = 0; i < MAX_CANDIDATES; i++)
        {
            printf("후보자: %s\n", &candidates[i * NAME_SIZE]);
            int total = 0;
            for (int j = 0; j < INFO_SIZE - 2; j++)
            {
                int score;
                while (1)
                {
                    printf("%s 점수: ", j == 0 ? "음악 소양" : j == 1 ? "댄스"
                                                           : j == 2   ? "보컬"
                                                           : j == 3   ? "비주얼"
                                                                      : "전달력");
                    scanf("%d", &score);
                    if (score >= 10 && score <= 100)
                    {
                        scoring_sheet[i * INFO_SIZE + j] = score;
                        total += score;
                        break;
                    }
                    else
                    {
                        printf("잘못된 값입니다.\n");
                    }
                }
            }
            scoring_sheet[i * INFO_SIZE + (INFO_SIZE - 2)] = total;
            printf("------------------------------------\n");
        }

        // 제출 여부 묻기
        printf("++++++++++++++++++++++++++++++++++++\n");
        printf("입력을 모두 완료했습니다.\n");
        printf("입력하신 내용을 검토하세요!\n");
        printf("------------------------------------\n");
        for (int i = 0; i < MAX_CANDIDATES; i++)
        {
            printf("%s: %d\n", &candidates[i * NAME_SIZE], scoring_sheet[i * INFO_SIZE + (INFO_SIZE - 2)]);
        }
        printf("제출하시겠습니까? ");
        char submit;
        getchar();
        scanf("%c", &submit);
        if (submit == 'Y')
        {
            printf("***최종 제출을 완료했습니다.***\n");
            break;
            printf(">\n");
        }
        else
        {
            printf("***다시 처음부터 입력합니다.***\n");
            printf(">\n");
        }
    }

    // 후보자 점수 집계
    for (int i = 0; i < MAX_CANDIDATES - 1; i++)
    {
        for (int j = i + 1; j < MAX_CANDIDATES; j++)
        {
            if (scoring_sheet[i * INFO_SIZE + (INFO_SIZE - 2)] < scoring_sheet[j * INFO_SIZE + (INFO_SIZE - 2)])
            {
                for (int k = 0; k < INFO_SIZE; k++)
                {
                    int temp = scoring_sheet[i * INFO_SIZE + k];
                    scoring_sheet[i * INFO_SIZE + k] = scoring_sheet[j * INFO_SIZE + k];
                    scoring_sheet[j * INFO_SIZE + k] = temp;
                }
                char temp_name[NAME_SIZE];
                strncpy(temp_name, &candidates[i * NAME_SIZE], NAME_SIZE - 1);
                strncpy(&candidates[i * NAME_SIZE], &candidates[j * NAME_SIZE], NAME_SIZE - 1);
                strncpy(&candidates[j * NAME_SIZE], temp_name, NAME_SIZE - 1);
                candidates[(i + 1) * NAME_SIZE - 1] = '\0';
                candidates[(j + 1) * NAME_SIZE - 1] = '\0';
            }
        }
    }

    // 후보자 점수 출력
    printf("=======================================\n");
    printf("후보 선발 결과 집계 중 ...\n");
    printf("=======================================\n");
    printf("#########################################\n");
    printf("# 밀리웨이즈의 멤버가 된 걸 축하합니다! #\n");
    printf("#########################################\n");
    for (int i = 0; i < 4; i++)
    {
        printf("%d. %s\n", i + 1, &candidates[i * NAME_SIZE]);
    }
    printf(">\n");

    getchar();
    getchar();

    return 0;
}
