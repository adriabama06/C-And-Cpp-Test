#include <iostream>
#include "Util.hpp"

void convert(char* dest, float f, int presision)
{
    int number; // full number
    float floatDecimal = f; // decimals
    
    number = f; // Get number
    floatDecimal = f - number; // Get decimals
    
    int intDecimals = Util::pow(floatDecimal, presision);

    char strNumber[Util::len(number)];
    char strDeciaml[Util::len(intDecimals)];

    Util::format(strNumber, number);
    Util::format(strDeciaml, intDecimals);

    char str[Util::len(strNumber)+1+Util::len(strDeciaml)];
    
    Util::joinChars(str, strNumber, ".");
    Util::joinChars(str, str, strDeciaml);

    //std::cout << str << " - " << Util::len(str) << std::endl;
    
    //std::cout << number << std::endl << intDecimals << std::endl;
    
    for(size_t i = 0; i < Util::len(str); i++)
    {
        dest[i] = str[i];
    }
    dest[Util::len(str)] = '\0';
}

int main()
{
    char t[5];
    float f = 35.2589F;
    convert(t, f, 2);
    std::cout << t << " - " << Util::len(t) << std::endl;
    return 0;
}