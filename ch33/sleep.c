#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void sig_alarm(int signo){

}

unsigned int cus_sleep(unsigned int nsecs){
    struct sigaction newact, oldact;
    unsigned int unslept;

    newact.sa_handler = sig_alarm;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    sigaction(SIGALRM, &newact, &oldact);

    alarm(nsecs);

    pause();

    unslept = alarm(0);
    sigaction(SIGALRM, &oldact, NULL);

    return unslept;
}

int main(void){
    while (1){
        cus_sleep(2);
        printf("Two seconds passed\n");
    }

    return 0;
}
