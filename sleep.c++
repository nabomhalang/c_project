#include "header.h"

void Sleep(int a_second)
{
    clock_t start_clk = clock();

    a_second--;
    while(1) {
        if ((clock() - start_clk)/CLOCKS_PER_SEC > a_second) break;
    }
}