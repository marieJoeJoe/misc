#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "arrayfifo.h"

#define COUNT 1000


int main(int argc, char* argv[])
{
  int src_data[COUNT];

  afifo_t at; 
  fifo_init(&at,1000);

  int i;

  for( i = 0; i < COUNT / 160; i++ )
  {
     //srand(time(NULL));
     src_data[i] = rand();
     printf("%d\n",src_data[i] );
     fifo_in(&at, src_data[i]); 
  }
  printf("-----------fifo------------------\n");
  printf("%u\n", front(&at) );
  fifo_pop(&at);
  printf("%u\n", front(&at) );
  fifo_pop(&at);
  printf("%u\n", front(&at) );
  fifo_pop(&at);
  printf("%u\n", front(&at) );
  return 0;
}
