#include <iostream>

void format(char* destination, int number)
{
    char t[sizeof(number)];
    if(number >= 100) {
        t[0] = (number / 100 % 10) + '0';
        t[1] = (number / 10 % 10) + '0';
        t[2] = (number % 10) + '0';
    } else if(number >= 10) {
        t[0] = (number / 10 % 10) + '0';
        t[1] = (number % 10) + '0';
    } else {
        t[0] = (number % 10) + '0';
    }
    for (int i = 0; i < sizeof(t); i++)
    {
        destination[i] = t[i];
    }
    destination[sizeof(t)] = '\0';
}

size_t string_length(char* s)
{
    size_t i = 0;
    while (*s++ != '\0') {
        ++i;
    }
    return i;
}


void joinChars(char* dest, char* char1, char* char2)
{
    size_t len1 = string_length(char1);
    size_t len2 = string_length(char2);
    char* t = new char(len1+len2+1);
    for(size_t i = 0; i < len1; i++) {
        t[i] = char1[i];
    }
    for(size_t i = 0; i < len2; i++) {
        t[len1+i] = char2[i];
    }
    t[len1 + len2] = '\0'; // '\0' is caracter at end of char array, i user new char(), when use this and join lost '\0', and need add
    for (int i = 0; i < string_length(t)+1; i++)
    {
        dest[i] = t[i];
    }
    dest[string_length(t)+1] = '\0';
}

int main()
{
    float number = 1;
    int ex = (int) number;

    char text[sizeof(ex)+1];
    format(text, ex);

    std::cout << text << std::endl;
    
    char* extension = " C"; // tambien sirbe char extension[3] = " C";

    char res[string_length(text)+string_length(extension)+1];
    joinChars(res, text, extension);

    std::cout << res << " - " << sizeof(res) << std::endl;
    return 0;
}