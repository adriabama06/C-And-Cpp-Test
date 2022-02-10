#include "Util.hpp"

int main()
{
    char end[34];
    Util::toChar(end, (float) 23.55, 1);
    std::cout << end << std::endl;
    return 0;
}