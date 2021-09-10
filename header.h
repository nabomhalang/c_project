#include <cstdio>
#include <stdlib.h>
#include<string.h>
#include <time.h>

#define Bar1 printf("==========================\n");
#define Bar2 printf("--------------------------\n");
#define clear system("clear");
#define MONEY 5000
#define CARD 52

int main_menu(); //메인 출력을 담당해 준다.
int gameStart(); // 게임 시작
int gameExplain(); //게임 설명
void reStart(); // 다시 게임 메뉴

void Sleep(int seconds); //sleep과 똑같은 기능
void shuffle(); //카드 섞는 코드
void filldeck(); //52장의 카드 채우기
void print_card(int check_number, int check_shape); //카드 프린트
int result_total(int check_number); //J, Q, K는 10으로 환산되기 때문에 그것들을 처리
int hit(int *deal_total, int *player_total); //hit시 나오는 코드 (카드 한장 뽑아 주는 것)
int stand(int *deal_total, int *player_total, int *cnt); //stand시 나오는 코드 (끝나고 판별하는 것)
int victory_check(int *deal_total, int *player_total); //stand 이후 판별하는 식 또는 플레이어가 버서크 일때 나오는 코드


//kind : 1 == 스페이드, 2 == 다이아, 3 == 클로버, 4 == 하트 
//카드 각각의 출력
void ACE(int kind);
void TWO(int kind);
void THREE(int kind);
void FOUR(int kind);
void FIVE(int kind);
void SIX(int kind);
void SEVEN(int kind);
void EIGHT(int kind);
void NINE(int kind);
void TEN(int kind);
void ELEVEN(int kind);
void TWELVE(int kind);
void THIRTEEN(int kind);