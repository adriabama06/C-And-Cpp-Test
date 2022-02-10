// why exist Util.hpp ?
// arduino have errors importing C/C++ libraries and I made it from 0

namespace Util
{
    int pow(int number, int p);
    float pow(float number, int p);

    int len(char* s);
    int len(int i);
    int len(float i);

    void toChar(char* destination, int number);
    void toChar(char* destination, float f, int presision = 2);

    void joinChars(char* destination, char* char1, char* char2);
} // namespace Util
