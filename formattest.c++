//#include <iostream> Remember HPP (Headers for c++) includes automatic all in hpp
#include "Util.hpp"

using namespace Util;

int pow(int number, int p)
{
    int r = number;
    for (int i = 0; i < p; i++)
    {
        r = r * 10;
    }
    
    return r;
}

int main()
{
  char* ab = "ab";
  char* cd = "cd";
  
  char res[len(ab)+len(cd)];
  joinChars(res, ab, cd);
  std::cout << res << " - " << sizeof(res) << " - " << len(res) << std::endl;

  int num = 23;
  char text[len(num)];
  format(text, num);
  std::cout << text << " - " << sizeof(text) << " - " << len(text) << std::endl;
  std::cout << std::endl;
  char extension[3] = " C";
  char join[len(text)+len(extension)];
  joinChars(join, text, extension);
  std::cout << join << " - " << sizeof(join) << " - " << len(join) << std::endl;

  char last[len(join)+len(res)];
  joinChars(last, join, res);
  std::cout << last << " - " << sizeof(last) << " - " << len(last) << std::endl;
  return 0;
}