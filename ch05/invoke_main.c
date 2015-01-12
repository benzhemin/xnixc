#include <stdio.h>
#include <stdlib.h>

int main(void);

void invoke_main(){
    printf("invoke main!\n");
    int main_res = main();
    printf("after invoke main_res:%d\n", main_res);
}

int main(void){
    static int count = 0;
    if(count == 0){
        count++;
        invoke_main();
    }

    return 1;
}
