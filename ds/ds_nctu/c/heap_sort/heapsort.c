
#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>


static inline void swap_val(unsigned int * l, unsigned int * r)
{
    unsigned int tmp = *l;
    *l = *r;
    *r = tmp;
}


void dumpArr(unsigned int *arr, unsigned int nelm, unsigned int nclum)
{
    unsigned int i;

    for (i = 0; i < nelm; ++i)
    {
      if((0 == i )||( 0 != (i+1)%nclum)) printf("%04d ",arr[i]);
      else printf("%04d \n",arr[i]);
    }
    printf("\n");

}

void initRandomArr(unsigned int *arr, unsigned int nelm)
{

  if(NULL == arr){
    return ;
  }

  unsigned int i;
  for( i = 0; i < nelm; i++ )
  {
     arr[i] = rand()%1000;
  }

}

void heapsort(unsigned int *arr, int nelm)
{

}