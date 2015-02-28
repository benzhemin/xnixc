#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define MAXNITEMS   1000000
#define MAXNTHREADS 100

int nitems;

struct{
    pthread_mutex_t     mutex;
    int                 buff[MAXNITEMS];
    int                 nput;
    int                 nval;
} shared = {
    PTHREAD_MUTEX_INITIALIZER
};

void *produce(void *);
void *consume(void *);

int main(int argc, char *argv[]){
    int     i, nthreads, count[MAXNTHREADS];
    pthread_t tid_produce[MAXNTHREADS], tid_consume;

    if (argc != 3){
        printf("usage:produce consume");
        exit(0);
    }

    nitems = atoi(argv[1]);
    nthreads = atoi(argv[2]);

    pthread_setconcurrency(nthreads);
    for(i=0; i<nthreads; ++i){
        count[i] = 0;
        pthread_create(&tid_produce[i], NULL, produce, &count[i]);
    }

    for(i=0; i<nthreads; i++){
        pthread_join(tid_produce[i], NULL);
        printf("count[%d]=%d\n", i, count[i]);
    }

    pthread_create(&tid_consume, NULL, consume, NULL);
    pthread_join(tid_consume, NULL);

    exit(0);
}

void *produce(void *arg){
    for(;;){
        pthread_mutex_lock(&shared.mutex);
        if (shared.nput >= nitems){
            pthread_mutex_unlock(&shared.mutex);
            return NULL;
        }

        shared.buff[shared.nput] = shared.nval;
        shared.nput++;
        shared.nval++;
        pthread_mutex_unlock(&shared.mutex);
        *((int *)arg) += 1;
    }
}

void *consume(void *arg){
    int i;
    for(i=0; i<nitems; i++){
        if (shared.buff[i] != i){
            printf("buff[%d] = %d\n", i, shared.buff[i]);
        }
    }
    return NULL;
}