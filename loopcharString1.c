#include "stdio.h"

int main()
{
    char* message = (char*) "Hello World!\0";

    int i = 0;
    char m = message[i];
    while (m != '\0')
    {
        printf("%c", m);
        i++;
        m = message[i];
    }
    
    printf("\n");
    return 0;
}