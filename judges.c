#include <stdio.h>
#include <stdlib.h>

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

    return 0;
}