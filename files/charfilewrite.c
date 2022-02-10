#include <stdio.h>

int main()
{
    char* msg = (char*) "Hello World!\0";
    FILE* f;

    f = fopen("miau.txt", "w");
    
    for (size_t i = 0; msg[i] != '\0'; i++)
    {
        char m = msg[i];
        fwrite(&m, sizeof(m), 1, f);
    }
    printf("File writed\n");
}