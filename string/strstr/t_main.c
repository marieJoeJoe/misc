#include <stdio.h>
#include "strstr.h"


int main(int argc,char* argv[])
{

  char *X = "Techie Delight - Coding made easy";
  char *Y = "Co";

  printf("%s\n",strstr(X,Y));

  return 0;
}
