#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static pthread_mutex_t lock;
pthread_t thr;

void *test(void *args){
    pthread_mutex_lock(&lock);
    printf("thread test \n");
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(void){
    pthread_mutex_init(&lock, NULL);
    pthread_mutex_lock(&lock);

    printf("main lock\n");
    pthread_create(&thr, NULL, test, NULL);

    sleep(3);
    printf("main unlock\n");

    pthread_mutex_unlock(&lock);

    sleep(2);

    pthread_join(thr, NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}
