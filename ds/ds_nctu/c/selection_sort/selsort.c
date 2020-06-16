
#include "selsort.h"
#include <stdio.h>
#include <stdlib.h>


void swap_val(unsigned int * l, unsigned int * r)
{
    unsigned int tmp = *l;
    *l = *r;
    *r = tmp;
}


void dumpArr(unsigned int *arr, unsigned int nelm, unsigned int nclum)
{
    unsigned int i,j;

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
     //srand(time(NULL));
     arr[i] = rand()%1000;
  }

}

void selsort(unsigned int *arr, unsigned int nelm)
{
  int i, j ;
  for (i=0; i<nelm; i++)
  {
    int min = i;
    for (j = i+1; j < nelm; ++j)
    {
      if (arr[j]<arr[min])
      {
        min = j;
      }
    }
    if (min != i) swap_val(&arr[min],&arr[i]);
  }
}

void dump_selsort(unsigned int *arr, unsigned int nelm)
{
  int i, j ;
  for (i=0; i<nelm; i++)
  {
    dumpArr(arr,nelm,0xffffff);
    int min = i;
    for (j = i+1; j < nelm; ++j)
    {
      if (arr[j]<arr[min])
      {
        min = j;
      }
    }
    if (min != i) swap_val(&arr[min],&arr[i]);
  }
}