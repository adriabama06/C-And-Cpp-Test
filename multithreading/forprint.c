#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int currentT = 0;

int isLogEnabled = 0;

void* toPrint(void* currentNumber)
{
    long long num = (long long) currentNumber;

    for(long long int i = num; i >= 0; i--) {}

    if(isLogEnabled) {
        printf("Thread (%d) say: %lld\n", currentT, num);
    }

    pthread_exit(NULL);
}

int main(int argc, const char *argv[])
{
    if(argc <= 1) {
        printf("Set number of threads\n");
        return -1;
    }
    if(argc <= 2) {
        printf("Set number of loop\n");
        return -1;
    }

    int t = atoi(argv[1]);
    long long int l = atoi(argv[2]);

    if(argc >= 3) {
        isLogEnabled = atoi(argv[3]);
    }

    const int NUM_THREADS = t;
    
    pthread_t threads[NUM_THREADS];
    

    for(long long int i = 0; i < l; i++) {
        int err = pthread_create(&threads[currentT], NULL, toPrint, (void *) i);

        if(err) {
            printf("Error creating thread, %d\n", err);
            return 1;
        }

        pthread_join(threads[currentT], NULL); // wait for thread end or else all will be going to run with not order

        if(currentT == NUM_THREADS) {
            currentT = -1;
        }
        currentT++;
   }

    return 0;
}