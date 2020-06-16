
#include <stdio.h>
#include "int2roman.h"

int main(int argc, char* argv[])
{

  //"III"
  printf("%s\n",intToRoman(3));
  //"IV"
  printf("%s\n",intToRoman(4));
  //"IX"
  printf("%s\n",intToRoman(9));
  //"LVIII"
  printf("%s\n",intToRoman(58));
  //"MCMXCIV"
  printf("%s\n",intToRoman(1994));

  return 0;
}
