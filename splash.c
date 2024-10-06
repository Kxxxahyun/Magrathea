#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    char date[11];

    // 날짜
    printf("[현재 날짜를 \"yyyy-mm-dd\" 형식으로 입력하세요]: ");
    scanf("%s", date);

    // 이름
    printf("[당신의 이름을 입력하세요]: ");
    scanf(" %[^\n]", name);

    printf("**입력이 정상적으로 처리되었습니다.**\n");

    // 3초 대기
    sleep(3);
    system("cls");

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

    for (int i = 1; i <= 5; i++)
    {
        // 왼쪽 삼각형
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }

        // 문구
        if (i == 1)
        {
            printf("                         [마그라테아 ver 0.1]                               ");
        }
        else if (i == 2)
        {
            printf("       풀 한 포기 없는 황무지에서 반짝이는 행성을 만들어내는 곳 마그라테아, ");
        }
        else if (i == 3)
        {
            printf("    사람들이 보지 못하는 잠재력을 찾고 전문가의 손길을 더해 보석을 빚는 곳, ");
        }
        else if (i == 4)
        {
            printf("      마그라테아에 오신걸 환영합니다.                                       ");
        }
        else if (i == 5)
        {
            printf("                                                                            ");
        }

        // 역삼각형
        for (int j = 5; j >= i; j--)
        {
            printf("*");
        }

        printf("\n");
    }

    printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("[사용자]: %s                                   [실행 시간]: %s\n", name, date);
    printf("==================================================================================\n");

    getchar();
    getchar();

    return 0;
}
