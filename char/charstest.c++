#include <iostream>

int main()
{
    char *some[2] = {"ab", "cd"};
    for(int i = 0; i < sizeof(some)/sizeof(some[0]); i++) {
        std::cout << i << std::endl;
    }
    std::cout << some[0] << std::endl;
    std::cout << some[1] << std::endl;
}