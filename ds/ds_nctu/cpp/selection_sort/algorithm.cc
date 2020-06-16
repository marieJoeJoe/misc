
#include "calculator.h"


static inline void swap_val(unsigned int * l, unsigned int * r)
{
  unsigned int tmp = *l;
  *l = *r;
  *r = tmp;
}


void selectsortcalculator::algorithm(void){
// selection sort

  int i,j;
  for (int i=0; i < c_array_cnt; i++)
  {
    int min = i;
    for (j = i+1; j < c_array_cnt; ++j)
    {
      if (p_arr[j]<p_arr[min])
      {
        min = j;
      }
    }
    if (min != i) swap_val(&p_arr[min],&p_arr[i]);
  }
}