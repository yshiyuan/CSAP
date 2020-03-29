#include "csapp.h"

int yKill()
{
    PRINT_FUNC;
    pid_t pid;
    if ((pid = Fork()) == 0)
    {
        Pause();
        printf("control should never reach here!\n");
        exit(0);
    }
    Kill(pid, SIGKILL);
    exit(0);
}

int yKillSelf()
{
    PRINT_FUNC;
    pid_t pid = getpid();
    Kill(pid, SIGKILL);
    printf("never go here");
    return 0;
}

void handler(int sig)
{
    printf("sig = %d\n", sig);
    static int beeps = 0;
    if (sig == SIGINT) {
        printf("Caught SIGINT\n");
        exit(0);
    }
    printf("BEEP\n");
    if (++beeps < 5)
        Alarm(5);
    else {
        printf("BOOM!\n");
        exit(0);
    }
}

int yAlarm()
{
    PRINT_FUNC;
    Signal(SIGALRM, handler);
    Signal(SIGINT, handler);
    Alarm(1);
    int loop = 0;
    while (1)
    {
        printf("loop:%d\n", ++loop);
        sleep(1);
        /* code */
    }
    exit(0); 
}