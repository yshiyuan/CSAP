#include "waitpid1.h"
#include "kill.h"
#include "ysignal2.h"

int main() {
    //ywaitpid1();
    //ykill();
    //yKillSelf();
    //yAlarm();
    ysignal2();
    printf("main over\n");
    return 0;
}