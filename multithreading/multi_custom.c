#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void *PrintHello(void *threadid) {
   long tid = (long) threadid;

   printf("Hello World! Thread ID, %d\n", tid);
   
   pthread_exit(NULL);
   // or return NULL;
}

int main(int argc, const char *argv[]) {
    if(argc <= 1) {
        printf("Set number of thread\n");
        return -1;
    }

    int n = atoi(argv[1]);

    const int NUM_THREADS = n;
    pthread_t threads[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++ ) {
        printf("main() : creating thread, %d\n", i);
        
        int err = pthread_create(&threads[i], NULL, PrintHello, (void *) i);
        
        if(err) {
            printf("Error creating thread, %d\n", err);
            return 1;
        }

        pthread_join(threads[i], NULL); // wait for thread end or else all will be going to run with not order
   }
   // pthread_exit(NULL); // kill all threads
   return 0;
}