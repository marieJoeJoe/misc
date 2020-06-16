#include <stdio.h>
#include "roman2int.h"

int main(int argc, char* argv[])
{

  //3
  printf("%d\n",romanToInt("III"));
  //4
  printf("%d\n",romanToInt("IV"));
  //9
  printf("%d\n",romanToInt("IX"));
  //58
  printf("%d\n",romanToInt("LVIII"));
  //1994
  printf("%d\n",romanToInt("MCMXCIV"));

  return 0;
}
