#include "header.h"
//52장카드를 썩은뒤 위에서 부터 딜러 1장 플레이어 2장을 보여주며 시작한다.
//21을 넘기면 패배, 21에 최대한 가까운사람이 승리한다.


struct Card
{
    int number;
    int shape;
};

struct Card card_all[70];

struct Player
{
    struct Card card_player[35];
};

void shuffle() //단순한 카드 섞기 알고리즘 현재 위치에서 랜덤한 index의 값과 교환한다.
{
    srand(time(NULL));
    for(int i = 0; i < 70; i++)
    {
        int index = rand() % 70;
        struct Card temp = card_all[index];
        card_all[index] = card_all[i];
        card_all[i] = temp;
    }
}

void filldeck()
{
    int cnt = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            card_all[cnt].number = j;
            card_all[cnt].shape = i;
            cnt++;
        }
    }
}

int gameStart()
{
    char player_input[20];
    char name[10];
    int deal_total = 0, player_total = 0, card_cnt = 0;
    clear;
    Bar1;
    filldeck(); shuffle();

    printf("52장의 카드를 섞고 있습니다...\n");
    Sleep(1);

    printf("딜러 1장과 player2장을 보여줍니다...\n");
    Sleep(2);

    printf("\nDEALER : \n");

    int check_number = card_all[card_cnt].number + 1;
    int check_shape = card_all[card_cnt].shape + 1;
    printf("%d %d\n", check_number, check_shape);
    print_card(check_number, check_shape);
    deal_total += result_total(check_number);
    card_cnt++;

    Sleep(1);
    Bar2;
    printf("\nPlayer : \n");
    for(int i = 0; i < 2; i++)
    {
        int check_number = card_all[card_cnt].number + 1;
        int check_shape = card_all[card_cnt].shape + 1;
        printf("%d %d\n", check_number, check_shape);
        print_card(check_number, check_shape);
        player_total += result_total(check_number);
        card_cnt++;
    }

    Sleep(1);
    Bar1
    while(1)
    {
        if(player_total > 21)
        {
            hit(&deal_total, &player_total);
            victory_check(&deal_total, &player_total);
            break;
        }
        printf("dealer : %-3d player : %-3d\n", deal_total, player_total);
        printf("Hit or Stand(hit, stand) : ");
        scanf("%s", player_input);

        if(!strcmp("hit", player_input))
        {
            printf("hit!!\n");
            
            int check_number = card_all[card_cnt].number + 1;
            int check_shape = card_all[card_cnt].shape + 1;
            printf("%d %d\n", check_number, check_shape);
            print_card(check_number, check_shape);
            player_total += result_total(check_number);
            card_cnt++;
            continue;
        }
        if(!strcmp("stand", player_input))
        {
            printf("stand!!\n");
            stand(&deal_total, &player_total, &card_cnt);
            victory_check(&deal_total, &player_total);
            Bar1;
            break;
        }
    }
    return 0;
}

int victory_check(int *deal_total, int *player_total)
{
    if(*player_total == 21 && *deal_total == 21)
    {
        //딜러 버스크
        printf("\n동정!!!");
        printf("\n무승부 입니다!!!\n");
        reStart();
    }
    else if(*player_total > 21)
    {
        //딜러 버스크
        printf("\n플레이어 버스크!");
        printf("\n딜러의 승리!!!\n");
        reStart();
    }
    else if(*deal_total > 21)
    {
        //플레이어 버스크
        printf("\n딜러 버스크!");
        printf("\n플레이어의 승리!!!\n");
        reStart();
    }
    else if(21 - *deal_total < 21 - *player_total)
    {
        //21 - deal_total를 뺀게 21 - player_total 이것보다 작다면 딜러의 승리 반대시 플레이어 승리
        printf("\n딜러의 승리!!!\n");
        reStart();
    }
    else if(21 - *deal_total > 21 - *player_total)
    {
        printf("\n플레이어의 승리!!!\n");
        reStart();
    }
        
    return 0;

}

int hit(int *deal_total, int *player_total)
{
    Sleep(2);
    clear;
    Bar1;
    printf("          result\n");
    Bar2;
    printf("dealer : %-3d player : %-3d\n", *deal_total, *player_total);
    return 0;
}

int stand(int *deal_total, int *player_total, int *card_cnt)
{
    clear;
    Bar1;
    if(*deal_total < 21)
    {
        printf("Dealer : \n");
        while(*deal_total < 21)
        {
            int check_number = card_all[*card_cnt].number + 1;
            int check_shape = card_all[*card_cnt].shape + 1;
            printf("%d %d\n", check_number, check_shape);
            print_card(check_number, check_shape);
            *deal_total += result_total(check_number);
            *card_cnt++;
            Sleep(1);
        }
    }
    Sleep(4);
    clear;
    Bar1;
    printf("          result\n");
    Bar2;
    printf("dealer : %-3d player : %-3d", *deal_total, *player_total);
    return 0;
}

int result_total(int check_number)
{
    int result = 0;
    if(check_number > 10)
        return 10;
    else
        return check_number;
}

void print_card(int check_number, int check_shape)
{
    if(check_shape == 1)
        {
            if(check_number == 1)
                ACE(1);
            if(check_number == 2)
                TWO(1);
            if(check_number == 3)
                THREE(1);
            if(check_number == 4)
                FOUR(1);
            if(check_number == 5)
                FIVE(1);
            if(check_number == 6)
                SIX(1);
            if(check_number == 7)
                SEVEN(1);
            if(check_number == 8)
                EIGHT(1);
            if(check_number == 9)
                NINE(1);
            if(check_number == 10)
                TEN(1);
            if(check_number == 11)
                ELEVEN(1);
            if(check_number == 12)
                TWELVE(1);
            if(check_number == 13)
                THIRTEEN(1);
        }
        else if(check_shape == 2)
        {
            if(check_number == 1)
                ACE(2);
            if(check_number == 2)
                TWO(2);
            if(check_number == 3)
                THREE(2);
            if(check_number == 4)
                FOUR(2);
            if(check_number == 5)
                FIVE(2);
            if(check_number == 6)
                SIX(2);
            if(check_number == 7)
                SEVEN(2);
            if(check_number == 8)
                EIGHT(2);
            if(check_number == 9)
                NINE(2);
            if(check_number == 10)
                TEN(2);
            if(check_number == 11)
                ELEVEN(2);
            if(check_number == 12)
                TWELVE(2);
            if(check_number == 13)
                THIRTEEN(2);
        }
        else if(check_shape == 3)
        {
            if(check_number == 1)
                ACE(3);
            if(check_number == 2)
                TWO(3);
            if(check_number == 3)
                THREE(3);
            if(check_number == 4)
                FOUR(3);
            if(check_number == 5)
                FIVE(3);
            if(check_number == 6)
                SIX(3);
            if(check_number == 7)
                SEVEN(3);
            if(check_number == 8)
                EIGHT(3);
            if(check_number == 9)
                NINE(3);
            if(check_number == 10)
                TEN(3);
            if(check_number == 11)
                ELEVEN(3);
            if(check_number == 12)
                TWELVE(3);
            if(check_number == 13)
                THIRTEEN(3);
        }
        else if(check_shape == 4)
        {
            if(check_number == 1)
                ACE(4);
            if(check_number == 2)
                TWO(4);
            if(check_number == 3)
                THREE(4);
            if(check_number == 4)
                FOUR(4);
            if(check_number == 5)
                FIVE(4);
            if(check_number == 6)
                SIX(4);
            if(check_number == 7)
                SEVEN(4);
            if(check_number == 8)
                EIGHT(4);
            if(check_number == 9)
                NINE(4);
            if(check_number == 10)
                TEN(4);
            if(check_number == 11)
                ELEVEN(4);
            if(check_number == 12)
                TWELVE(4);
            if(check_number == 13)
                THIRTEEN(4);
        }
}

void reStart()
{
    char input[20];

    printf("다시 하시겠습니까?(y, n)");
    scanf("%s", input);

    if(!strcmp("y", input))
        main_menu();
    else if(!strcmp("n", input))
        exit(1);
}

int main()
{
    main_menu();
    return 0;
}
