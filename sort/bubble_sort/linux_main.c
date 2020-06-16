#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define COUNT 1000


int main(int argc, char* argv[])
{
  int src_data[COUNT];
  int i;
  for( i = 0; i < COUNT; i++ )
  {
     //srand(time(NULL));
     src_data[i] = rand();
  }

  return 0;
}
