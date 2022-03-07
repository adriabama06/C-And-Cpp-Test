#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    bool okMyBool; // by default is false (0)

    if(argc <= 1) {
        cout << "Please write if you like: TRUE or FALSE" << endl;
        return 1;
    }

    //string selected = argv[1]; // i don't like string in c/c++

    size_t tmp = strlen(argv[1]);

    char* selected = new char[tmp+1];

    for(int i = 0; i < tmp; i++) {
        selected[i] = tolower(argv[1][i]);
    }

    int option = 0;

    if(strcmp(selected, "true") == 0) {
        okMyBool = true;
        option = 1;
    } else if(strcmp(selected, "false") == 0) {
        okMyBool = false;
        option = 2;
    }

    if(option == 0) {
        cout << "Please write if you like: TRUE or FALSE" << endl;
        return 1;
    }

    if(okMyBool) {
        cout << "okMyBool is true" << endl;
    }

    if(!okMyBool) { // false -> true
        cout << "okMyBool is false" << endl;
    }
    
    return 0;
}