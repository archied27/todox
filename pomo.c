#include <stdio.h>
#include <time.h>

void startTimer(int t)
{
    clock_t stop;
    while (t>0)
    {
        if(t<60)
            if(t<10)
                printf("\r%ds     ", t);
            else
                printf("\r%ds    ", t);
        else
            if(t%60<10)
                printf("\r%dm %ds ", t/60, t%60);
            else
                printf("\r%dm %ds", t/60, t%60);
        fflush(stdout);

        stop = clock() + CLOCKS_PER_SEC;
 
        while (clock() < stop) {}
        t--;
    }

    printf("\rTime is up!\n");
    return;
}