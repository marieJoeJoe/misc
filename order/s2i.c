#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "s2i.h"

#define pr_info(fromat, ...) do{ printf("[%s]:"fromat, __FUNCTION__, ##__VA_ARGS__);}while (0)

/* order of src */
void max_min_position(double* src, int * pos_vaild,int* min, int* mid, int* max, int* pmin, int* pmid, int* pmax, int len)
{
   int i = 0;
   int minpos = 1;
   int maxpos = 1;
   double max_val, min_val;

   int real_pos[3] = {0,0,0};
   int j, k;
   for (j=0, k=0 ; j < 4; j++)
   {
	   if(1 == pos_vaild[j]) real_pos[k++]= j + 1;
   }
   max_val = *src;
   min_val = *src;
   while (i < len)
   {
      if(*(src+i) > max_val)
      {
         max_val = *(src + i);
         maxpos = i+1;
      }
      if(*(src+i) < min_val)
      {
         min_val = *(src + i);
         minpos = i+1;
      }
      i++;
   }
   *max = maxpos;
   *min = minpos;
   *mid = 6 -maxpos - minpos;
   *pmax = real_pos[maxpos-1];
   *pmin = real_pos[minpos-1];
   *pmid = real_pos[6 -maxpos - minpos -1];

}
