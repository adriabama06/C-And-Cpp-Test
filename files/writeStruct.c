#include <stdio.h>

int len(char* s)
{
    int l = 0;
    while (s[l] != '\0')
    {
        l++;
    }
    return l;
}

struct UserStruct
{
    char* username;
    char* realname;
    int age;
};

// https://stackoverflow.com/questions/3274980/saving-a-c-struct-with-a-char-string-into-a-file
int main()
{
    struct UserStruct u;

    u.username = "adriabama06";
    u.realname = "Adria";
    u.age = 99; // what is my real age ?

    FILE *file;

    file = fopen("data.txt", "wb");

    int usernameLen = len(u.username);
    int realnameLen = len(u.realname);

    fwrite(&usernameLen, sizeof(int), 1, file);
    fwrite(u.username, usernameLen, 1, file);

    fwrite(&realnameLen, sizeof(int), 1, file);
    fwrite(u.realname, realnameLen, 1, file);

    fwrite(&u.age, sizeof(int), 1, file);

    fclose(file);

    return 0;
}
