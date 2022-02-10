#include "Util.h"

int Util::pow(int number, int p)
{
    int r = number;
    for(int i = 0; i < p; i++)
    {
        r = r * 10;
    }
    return r;
}
float Util::pow(float number, int p)
{
    float r = number;
    for(int i = 0; i < p; i++)
    {
        r = r * 10;
    }
    return r;
}

int Util::len(char* s)
{
    int l = 0;
    while (s[l] != '\0')
    {
        l++;
    }
    return l;
}
int Util::len(int i)
{
    int l = 0;
    int r = 0;
    while (l < i+1)
    {
        if(l == 0) {
            l = 1;
        }
        l = l * 10;
        r++;
    }
    return r;
}
int Util::len(float i)
{
    int l = 0;
    int r = 0;
    while (l < i+1)
    {
        if(l == 0) {
            l = 1;
        }
        l = l * 10;
        r++;
    }
    return r;
}

void Util::toChar(char* destination, int number)
{
    int lenNumber = len(number);
    char temp[lenNumber + 1]; // + 1 for \0
    int positon = lenNumber - 1; // - 1 for char start from 0, not 1
    for(int i = 1; i < number; i = i * 10)
    {
        temp[positon] = (number / i % 10) + '0';
        positon--;
    }
    // copy to the destination
    int lenTemp = len(temp);
    for (int i = 0; i < lenTemp; i++)
    {
        destination[i] = temp[i];
    }
    destination[lenTemp] = '\0';
}
void Util::toChar(char* destination, float f, int presision = 2)
{
    int number; // full number whiout decimals
    float floatDecimals = f; // only decimals 0.23

    number = f; // c++ automatically remove the decimals
    floatDecimals = f - number; // Remove the normal number and only get decimals, if f go after number will get negative numbers

    int numberDecimals = pow(floatDecimals, presision);

    char charNumber[len(number)];
    char charDecimals[len(numberDecimals)];

    toChar(charNumber, number);
    toChar(charDecimals, numberDecimals);

    char temp[len(charNumber) + 1 + len(charDecimals)]; // +1 for '.'

    joinChars(temp, charNumber, ".");
    joinChars(temp, temp, charDecimals);
    int lenTemp = len(temp);
    for(int i = 0; i < lenTemp; i++)
    {
        destination[i] = temp[i];
    }
    destination[lenTemp] = '\0';
}

void Util::joinChars(char* destination, char* char1, char* char2)
{
    int lenChar1 = len(char1);
    int lenChar2 = len(char2);
    char temp[lenChar1+lenChar2];
    for(int i = 0; i < lenChar1; i++)
    {
        temp[i] = char1[i];
    }
    for(int i = 0; i < lenChar2; i++)
    {
        temp[lenChar1+i] = char2[i];
    }
    int lenTemp = len(temp);
    for(int i = 0; i < lenTemp; i++)
    {
        destination[i] = temp[i];
    }
    destination[lenChar1+lenChar2] = '\0';
}
