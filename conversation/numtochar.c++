#include <iostream>

/*int main()
{
    //printf("A: %3d B: %6.2f\n", f, f + 0.15);
    float num = 5.25;
    std::cout << sizeof(num) << std::endl;
    char numchar[sizeof(num)];
    sprintf(numchar, "%f", num);
    char some[10];
    int i = 0;
    int max = 255;
    while(i < max)
    {
        if(numchar[i] == '.') {
            std::cout << i << std::endl;
            std::cout << i+2 << std::endl;
            max = i+2;
        }
        some[i] = numchar[i];
        i++;
    }
    std::cout << some << std::endl;
}*/

void FloatToChar(float num, char* text, int precision = 2)
{
  char numchar[sizeof(num)];
  sprintf(numchar, "%f", num);
  int i = 0;
  int max = 255;
  while(i < max)
  {
      if(numchar[i] == '.') {
          max = i+precision;
      }
      text[i] = numchar[i];
      i++;
  }
  return;
}

int main()
{
    float example = 2.58;
    char* result;
    FloatToChar(example, result);
    std::cout << &result << std::endl;
    return 0;
}