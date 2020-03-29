/* $begin waitpid2 */
#include "csapp.h"
#define N 5

int ywaitpid1()
{
    int status, i;
    pid_t pid[N], retpid;

    /* Parent creates N children */
    for (i = 0; i < N; i++)
        if ((pid[i] = Fork()) == 0)
        { /* Child */ //line:ecf:waitpid2:fork
            printf("hello child %d\n", i);
            sleep(5);
            exit(100 + i);
        }
    printf("hello parent\n");
    /* Parent reaps N children in order */
    i = 0;
    /*
    while ((retpid = waitpid(pid[i++], &status, 0)) > 0) { //line:ecf:waitpid2:waitpid
    	if (WIFEXITED(status))  printf("child %d terminated normally with exit status=%d\n",
    	    		   retpid, WEXITSTATUS(status));
    	else
    	    printf("child %d terminated abnormally\n", retpid);
    }
    */

    while (1)
    {
        i++;
        retpid = waitpid(-1, &status, 0);

        if (WIFEXITED(status))
            printf("child %d terminated normally with exit status=%d\n",
                   retpid, WEXITSTATUS(status));
        else
            printf("child %d terminated abnormally\n", retpid);
        
        if (retpid < 0) break;
    }

    printf("%d, %d, %d\n", retpid, pid[2], i);
    /* The only normal termination is if there are no more children */
    unix_error("waitpid error");

    return 0;
}
/* $end waitpid2 */
