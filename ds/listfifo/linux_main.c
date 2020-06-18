#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "listfifo.h"

#define COUNT 30


int main(int argc, char* argv[])
{
  unsigned int src_data[COUNT];

  fifo_t *at = create_fifo();
  printf("%p\n",at );

  int i;

  for( i = 0; i < COUNT ; i++ ){
     //srand(time(NULL));
     src_data[i] = rand()%100;
     printf("%d\n",src_data[i] );
     enqueue(at, src_data[i]);

  }
  
  printf("------------------------\n");

  unsigned int ss;

  for(i = 0; i<COUNT; i++){
    dequeue(at,&ss); 
    printf("%d\n", ss );
  }

}
