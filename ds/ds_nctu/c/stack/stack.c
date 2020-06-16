
#include "stack.h"
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
     arr[i] = rand()%1000;
  }

}

void quicksort(unsigned int *arr, int nelm)
{
  //printf("[%s]\n",__FUNCTION__ );

  if( nelm <= 1 ) return;

  int store_idx = 0;
  int pivot_idx = 0;
  int pivot_val = arr[pivot_idx];
  //printf("[%s]:", __FUNCTION__);
  //dumpArr(arr,0x10,0x10);

  swap_val(&arr[pivot_idx], &arr[nelm-1]);
  //printf("[%s]:", __FUNCTION__);
  //dumpArr(arr,0x10,0x10);

  for (int i = 0; i < nelm- 1 ; ++i)
  {
    if (arr[i] <= pivot_val)
    {
      swap_val(&arr[store_idx], &arr[i]);
      store_idx += 1;
      //printf("%d\n",store_idx);
    }
  }

  //printf("[%s]:", __FUNCTION__);
  //dumpArr(arr,0x10,0x10);

  swap_val(&arr[nelm-1], &arr[store_idx]);
  //printf("[%s]:", __FUNCTION__);
  //dumpArr(arr,0x10,0x10);
  quicksort(arr, store_idx);
  quicksort(&arr[store_idx+1], nelm-store_idx-1);
}