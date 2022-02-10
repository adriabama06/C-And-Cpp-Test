#include <iostream>
#include <cstring>
//#include <sstream>

void format(char* destination, float number)
{
    std::string t = std::to_string(number); //converting number to a string
    const char *numchar = t.c_str();
    for(int i = 0; i < sizeof(numchar); ++i){
        destination[i] = numchar[i];
    }
}

void FloatToChar(char* toupdate, float number)
{
    char n[sizeof(number)];
    format(n, number);
    //std::sprintf(n, "%.1f", number);
    for(int i = 0; i < sizeof(n); ++i){
        toupdate[i] = n[i];
    }
}

void JoinChars(char* destination, char* char1, char* char2)
{
    char j[sizeof(char1) + sizeof(char2) + 1];
    std::strcat(j, char1);
    std::strcat(j, char2);
    for(int i = 0; i < sizeof(j); ++i){
        destination[i] = j[i];
    }
}

int main()
{
    float temperature = 35.80;
    char temperatureToChar[sizeof(temperature)+1];
    FloatToChar(temperatureToChar, temperature);
    std::cout << temperatureToChar << std::endl;

    char extension[3] = " C";
    char t[sizeof(temperatureToChar)+sizeof(extension)];
    JoinChars(t, temperatureToChar, extension);
    std::cout << t << std::endl;
}

//int main()
//{
//    float temperature = 35.80;
//    char temperatureToChar[sizeof(temperature)];
//    std::sprintf(temperatureToChar, "%.1f", temperature);
//    char extension[3] = " C";
//    char t[sizeof(temperatureToChar)+sizeof(extension)];
//    std::strcat(t, temperatureToChar);
//    std::strcat(t, extension);
//    std::cout << t << std::endl;
//    return 0;
//}