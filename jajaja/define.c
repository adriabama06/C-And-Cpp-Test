#include <stdio.h>

#define test1

#define test2 1 // true

#define test3 0 // false

int main()
{
    int test1_ = 0;

    int test2_ = 0;

    int test3_ = 0;

    int test4_ = 0;
    
    #ifdef test1
        test1_ = 1;
    #endif

    #ifdef test2
        test2_ = 1;

        #if test2 == 1
            test2_ = 2;
        #endif
    #endif

    #ifdef test3
        test3_ = 1;

        #if test3 == 1
            test3_ = 2;
        #endif
    #endif

    #ifndef test4
        test4_ = -1;
    #endif

    printf("test1: %d\ntest2: %d\ntest3: %d\ntest4: %d\n", test1_, test2_, test3_, test4_);

    return 0;
}