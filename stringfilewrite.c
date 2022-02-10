#include <stdio.h>

// https://www.programiz.com/c-programming/c-file-input-output

int main()
{
    char* msg = (char*) "Hello World!\0";
    FILE* f;

    f = fopen("miau.txt", "w");
    
    
    fprintf(f, "%s", msg);
    
    
    printf("File writed\n");
}