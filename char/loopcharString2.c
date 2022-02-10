#include "stdio.h"

int main()
{
    char* message = (char*) "Hello World!\0";

    for (int i = 0; message[i] != '\0'; i++)
    {
        printf("%c", message[i]);
    }
    
    printf("\n");
    return 0;
}