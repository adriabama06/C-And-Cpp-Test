#include <iostream>

int main()
{
    char* some = "some";
    char* one = "one";
    char tojoin[sizeof(some)+sizeof(one)];
    for(int i = 0; i < sizeof(some); i++) {
        tojoin[i] = some[i];
    }
    for(int i = 0; i < sizeof(one); i++) {
        tojoin[sizeof(some)+i] = one[i];
    }
    std::cout << tojoin << std::endl;
    return 0;
}