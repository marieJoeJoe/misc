#include <stdio.h>

#include "maximumsubarray.h"


int main(int argc, char* argv[])
{
/*
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
*/

  int sdata0[] = {-2,1,-3,4,-1,2,1,-5,4};
  printf("test0 %s\n", 
  	(6 == maxSubArrayG(sdata0,sizeof(sdata0)/sizeof(sdata0[1]))) ?"passed":"failed");

  return 0;
}
