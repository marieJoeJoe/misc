#include <stdio.h>
#include "s2i.h"


int main(int argc,char* argv[])
{
  //char *src_str = "hello world";
  char *str1="121890";
  char *str2="-1890";
  char *str3="001890";
  printf("%d\n", string2integer(str1));
  printf("%d\n", string2integer(str2));
  printf("%d\n", string2integer(str3));
  return 0;
}
