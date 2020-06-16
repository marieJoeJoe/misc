
#include "calculator.h"
#include <cstdio>
#include <cstdlib>


void calculator::initRandomArr()
{
  if(NULL == p_arr){
    return ;
  }

  for(unsigned int i = 0; i < c_array_cnt; i++ )
  {
     p_arr[i] = rand()%1000;
  }

}

void calculator::dataListing(unsigned int nclum)
{

    for (unsigned int i = 0; i < c_array_cnt; ++i)
    {
      if((0 == i )||( 0 != (i+1)%nclum)) printf("%04x ",p_arr[i]);
      else printf("%04x \n",p_arr[i]);
    }
    printf("\n");

}

void swap_val(unsigned int * l, unsigned int * r)
{
    unsigned int tmp = *l;
    *l = *r;
    *r = tmp;
}