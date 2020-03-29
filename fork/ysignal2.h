#include "csapp.h"

void handler2(int sig)
{
    pid_t pid;

    while (pid = waitpid(-1, NULL, 0) > 0)
    {
        printf("Handler reaped child: %d\n", (int)pid);
    }
    unix_error("handler2 error");
    Sleep(2);
    return;
}

int ysignal2() {
    PRINT_FUNC;
    int i,n;
    char buf[MAXBUF];

    if(Signal(SIGCHLD, handler2) == SIG_ERR) unix_error("signal error");
    for (i = 0; i < 5; i++) {
        if (Fork() == 0) {
            printf("Hello from child %d, circle %d\n", (int)getpid(), i);
            Sleep(1);
            exit(0);
        }
    }

    if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0) unix_error("read error");

    printf("Parent processing input\n");
    while(1); 

    return 0;
}