#include "header.h"

int main_menu()
{
    int input = 0;
    int error_cnt = 0;
    while(1)
    {
        clear;
        Bar1;
        printf("         BLACKJACK\n");
        printf("1. 게임시작\n");
        printf("2. 게임 설명\n");
        printf("3. 나가기\n");
        Bar1;
        printf("Input : ");
        scanf("%d", &input);

        if (error_cnt > 40)
        {
            printf("이 정도면 일부러 그러는 거다");
            exit(1);
        }
        else if(input == 1)
        {
            gameStart();
            break;
        }
        else if(input == 2)
        {
            gameExplain();
            break;
        }
        else if(input == 3)
        {
            printf("안녕~~");
            exit(1);
        }
        else
        {
            error_cnt++;
        }
    }
    
    return 0;
}

int gameExplain()
{
    clear;
    Bar1;
    printf("         BLACKJACK\n");
    printf("자신의 카드의 총합이 21에 가까우면 이기는 게임입니다.\n");
    Bar1;
    Sleep(4);
    clear;
    Bar1;
    printf("게임시작시 딜러 1장과 플레이어 2장을 보여줍니다.\n");
    printf("각 카드들을 보고 난후 hit 또는 stand를 정할 수 있습니다.\n");
    printf("hit는 카드 한장을 더 받는 것, stand는 멈추는 것 입니다.\n");
    Bar1;
    Sleep(8);
    clear;
    Bar1;
    printf("stand시 딜러는 21이 넘지 않을때 까지 카드를 계속해서 뽑습니다.\n");
    printf("J, Q, K는 모두 10으로 계산합니다.\n");
    printf("그 후 21과 비교하며 게임이 끝납니다.\n");
    Bar1;
    Sleep(7);
    main_menu();
    return 0;
}
