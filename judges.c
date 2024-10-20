#include <stdio.h>
#include <stdlib.h>

// 밀리웨이즈
// 이름:김영수,성별:남,소속:JYK 스튜디오,직함:음악 감독 및 프로듀서,전문분야:음악,메일:youngsu@outlook.com,전화:010-1234-5678
// 이름:이지영,성별:여,소속:DK 엔터테인먼트,직함:댄스 감독,전문분야:댄스,메일:jiyounghere@outlook.com,전화:010-2345-6789
// 이름:박민준,성별:남,소속:JM 엔터테인먼트,직함:보컬 감독,전문분야:보컬,메일:minjun@outlook.com,전화:010-3456-7890
// 이름:송현우,성별:남,소속:Starlight Entertainment,직함:비주얼 디렉터,전문분야:비주얼,메일:hyunwoo@outlook.com,전화:010-4567-8901
// 이름:박지영,성별:여,소속:음악평론가 협회,직함:음악 평론가,전문분야:음악 평론,메일:jiyoung@outlook.com,전화:010-5678-9012

int main()
{
    int num_judges;
    char project_name[10];
    char judges_array[100 * 1000];
    char buffer[1000];

    // 심사자 풀 입력
    printf("####################################\n");
    printf("#       심사자 풀 데이터 입력      #\n");
    printf("####################################\n");
    printf("> 참여 프로젝트: ");
    scanf("%99[^\n]", project_name);
    getchar();

    printf("> 심사 풀 인원: ");
    scanf("%d", &num_judges);
    getchar();

    printf("> 선발 멤버 수: 4\n");

    int judge_idx = 0;
    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("%d명의 심사자 정보 입력을 시작합니다.\n", num_judges);
    printf("++++++++++++++++++++++++++++++++++++\n");

    while (judge_idx < num_judges)
    {
        printf("*심사자 %d: ", judge_idx + 1);
        fgets(buffer, 1000, stdin);

        int length = 0;
        while (buffer[length] != '\0' && buffer[length] != '\n')
        {
            length++;
        }

        if (length == 0)
        {
            printf("입력 누락!\n");
            continue;
        }

        for (int k = 0; k < length; k++)
        {
            judges_array[judge_idx * 1000 + k] = buffer[k];
        }
        judges_array[judge_idx * 1000 + length] = '\0';
        judge_idx++;
    }

    printf("++++++++++++++++++++++++++++++++++++\n");
    printf("심사자 풀 입력이 끝났습니다.\n");
    printf("++++++++++++++++++++++++++++++++++++\n");

    char pool_check;
    printf("\n[%s] 심사자 풀을 확인할까요? ", project_name);
    scanf(" %c", &pool_check);
    getchar();

    if (pool_check == 'Y')
    {
        printf("####################################\n");
        printf("#       심사자 풀 데이터 출력      #\n");
        printf("####################################\n");
        for (int i = 0; i < num_judges; i++)
        {
            printf("[심사자 %d]\n", i + 1);

            // JSON 데이터 파싱
            int start = 0;
            for (int j = 0; j < 1000; j++)
            {
                if (judges_array[i * 1000 + j] == ',' || judges_array[i * 1000 + j] == '\0')
                {
                    for (int k = start; k < j; k++)
                    {
                        putchar(judges_array[i * 1000 + k]);
                    }
                    putchar('\n');
                    start = j + 1;
                    if (judges_array[i * 1000 + j] == '\0')
                        break;
                }
            }
            printf("-----------------------------------\n");
        }
    }
    else
    {
        printf("프로그램을 종료합니다.\n");
    }

    getchar();

    return 0;
}