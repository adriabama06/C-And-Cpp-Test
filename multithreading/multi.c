#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

#define NUM_THREADS 2

void *PrintHello(void *threadid) {
   long tid = (long) threadid;

   printf("Hello World! Thread ID, %d\n", tid);
   
   pthread_exit(NULL);
   // or return NULL;
}

int main () {
    pthread_t threads[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++ ) {
        printf("main() : creating thread, %d\n", i);
        
        int err = pthread_create(&threads[i], NULL, PrintHello, (void *) i);
        
        if(err) {
            printf("Error creating thread, %d\n", err);
            return 1;
        }
   }
   pthread_exit(NULL);
}