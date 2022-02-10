#include <iostream>

namespace Util
{
    int pow(int number, int p);
    float pow(float number, int p);

    size_t len(char* s);
    size_t len(int i);
    size_t len(float i);

    void toChar(char* destination, int number);
    void toChar(char* destination, float f, int presision);

    void joinChars(char* destination, char* char1, char* char2);

    void CopyTo(char* destination, char* c);
} // namespace Util
