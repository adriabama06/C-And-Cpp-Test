#include <stdio.h>

int main()
{
    FILE* f;

    f = fopen("miau.txt", "w");

    for (int i = 0; i < 50; i++)
    {
        char m = i + '0'/* 0 = 48 char */;
        fwrite(&m, sizeof(m), 1, f);
    }
}