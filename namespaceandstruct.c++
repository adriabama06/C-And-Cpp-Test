#include <iostream>

namespace exampleNsp
{
    struct namespaceandstruct
    {
        int temperature;
        int hum;  
    };
    struct namespaceandstruct status = {0, 0};
    void printState()
    {
        std::cout << status.temperature << "C - " << status.hum << "H%" << std::endl;
    };
}

int main()
{
    exampleNsp::printState();
    exampleNsp::status.temperature = 23;
    exampleNsp::status.hum = 55;
    exampleNsp::printState();
    return 0;
}