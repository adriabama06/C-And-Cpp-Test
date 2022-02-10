#include <stdio.h>

int strLen(char* s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

int main()
{
    FILE *file;
    FILE *file_redable;

    file = fopen("myfile.txt", "w");

    file_redable = fopen("myfile.txt", "r");

    //fseek(file, 0, SEEK_SET); // make sure is at start of the file
    
    char *firstAdd = "Hello";
    const int firstAddLen = strLen(firstAdd);

    for (int i = 0; i < firstAddLen; i++)
    {
        char c = firstAdd[i];
        fwrite(&c, sizeof(c), 1, file);
    }

    fclose(file); // save the file
    file = fopen("myfile.txt", "a");

    printf("After write the current text is: ");

    for (int i = 0; i < 8; i++)
    {
        char t;
        fread(&t, 1, 1, file_redable);
        
        printf("%c", t);
    }

    printf("\n");

    char *lastText = " World";
    const int lastTextLen = strLen(lastText);

    for (int i = 0; i < lastTextLen; i++)
    {
        char c = lastText[i];
        fwrite(&c, sizeof(c), 1, file);
    }
    
    fclose(file);
    fclose(file_redable);
}

int main2()
{
    char text[50];
    FILE* file;

    file = fopen("myfile.txt", "a");
    
    fseek(file, 0, SEEK_SET); // make sure is at start of the file
    
    for (int i = 0; i < 50; i++)
    {
        char t;
        fread(&t, 1, 1, file);
        
        text[i] = t;
        if(i >= 1 && text[i-1] == t) {
            if(i >= 2 && text[i-2] == t) {
                text[i-1] = '\0';
                break;
            }
        }
    }

    printf("Here is: %s\n", text);

    const int len = 8;
    char texttoadd[len] = " world\0";

    for (int i = 0; texttoadd[i] != '\0'; i++)
    {
        char m = texttoadd[i];
        fwrite(&m, sizeof(m), 1, file);
    }

    fclose(file);

    return 0;
}