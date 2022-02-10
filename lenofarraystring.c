#include "stdio.h"

int strLen(char* s)
{
    int l = 0;
    while (s[l] != '\0')
    {
        l++;
    }
    return l;
}

int main()
{
    char* messages[2] = {(char*) "Hello World", (char*) "adriabama06"};

    int len = (sizeof(messages)/sizeof(messages[0]));

    printf("Len of messages: %d\n", len);

    for (int i = 0; i < len; i++)
    {
        char *message = messages[i];
        printf("Message: %d - ", i);
        for (int k = 0; k < strLen(message); k++)
        {
            char m = message[k];

            printf("%c", m);
        }
        printf("\n");
    }
    

    return 0;
}