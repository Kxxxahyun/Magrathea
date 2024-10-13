#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JUDGES 6
#define MAX_INFO_SIZE 1000

// 밀리웨이즈
// 이름:김영수,성별:남,소속:JYK 스튜디오,직함:음악 감독 및 프로듀서,전문분야:음악,메일:youngsu@outlook.com,전화:010-1234-5678
// 이름:이지영,성별:여,소속:DK 엔터테인먼트,직함:댄스 감독,전문분야:댄스,메일:jiyounghere@outlook.com,전화:010-2345-6789
// 이름:박민준,성별:남,소속:JM 엔터테인먼트,직함:보컬 감독,전문분야:보컬,메일:	minjun@outlook.com,전화:010-3456-7890
// 이름:송현우,성별:남,소속:Starlight Entertainment,직함:비주얼 디렉터,전문분야:비주얼,메일:hyunwoo@outlook.com,전화:010-4567-8901
// 이름:박지영,성별:여,소속:음악평론가 협회,직함:음악 평론가,전문분야:음악 평론,메일:jiyoung@outlook.com,전화:010-5678-9012

int main()
{
    int num_judges;
    char project_name[100];
    char judges_array[MAX_JUDGES * MAX_INFO_SIZE];
    char buffer[MAX_INFO_SIZE];

    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력     #\n");
    printf("####################################\n");
    printf("> 참여 프로젝트: ");
    scanf("%99[^\n]", project_name);
    getchar();

    printf("> 심사 풀 인원: ");
    scanf("%d", &num_judges);
    getchar();

    printf("> 선발 멤버 수: 4\n");
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", num_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 풀 입력
    int i = 0;
    while (i < num_judges)
    {
        printf("*심사자 %d: ", i + 1);
        scanf(" %[^\n]", buffer);
        getchar();

        strncpy(judges_array + i * MAX_INFO_SIZE, buffer, MAX_INFO_SIZE - 1);
        judges_array[(i + 1) * MAX_INFO_SIZE - 1] = '\0';
        i++;
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    // 심사자 풀 출력
    char pool_check;
    printf("\n[%s] 심사자 풀을 확인할까요? ", project_name);
    scanf(" %c", &pool_check);
    getchar();

    if (pool_check == 'Y')
    {
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력     #\n");
        printf("####################################\n");
        for (int i = 0; i < num_judges; i++)
        {
            printf("[심사자 %d]\n", i + 1);
            char temp[MAX_INFO_SIZE];
            strncpy(temp, judges_array + i * MAX_INFO_SIZE, MAX_INFO_SIZE - 1);
            temp[MAX_INFO_SIZE - 1] = '\0';
            char *token = strtok(temp, ",");
            while (token != NULL)
            {
                printf("%s\n", token);
                token = strtok(NULL, ",");
            }
            printf("-----------------------------------\n");
        }
    }
    else
    {
        printf("프로그램을 종료합니다.\n");
    }

    getchar();
    getchar();

    return 0;
}
