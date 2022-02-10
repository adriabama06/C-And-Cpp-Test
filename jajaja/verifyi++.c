#include "stdio.h"

int main()
{
    int i = 0;
    printf("%d\n", i); // 0
    printf("%d\n", ++i); // 1
    printf("%d\n", i++); // 1
    printf("%d\n", i);// 2
    
    return 0;
}