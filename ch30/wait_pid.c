#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
    pid_t   pid;
    pid = fork();

    if (pid < 0){
        perror("fork failed");
    }

    if (pid == 0){
        int i;
        for(i=300; i>0; i--){
            printf("This is the child\n");
            sleep(1);
        }
        exit(3);
    }else{
        int stat_val;
        waitpid(pid, &stat_val, 0);

        if (WIFEXITED(stat_val))
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else if (WIFSIGNALED(stat_val))
            printf("Child terminated abnormally, signal %d\n", WTERMSIG(stat_val));
    }
    return 0;
}
