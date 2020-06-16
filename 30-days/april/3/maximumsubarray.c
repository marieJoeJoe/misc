
#include "maximumsubarray.h"
#include <stdio.h>
#include <stdlib.h>

int maxSubArrayG(int* nums,int numSize){ 
  
  int max = nums[0];

  //printf("i j : sum\n------------\n");

  for(int i = 0; i< numSize; i++){

    int sum = 0;

    for(int j = i; j< numSize; j++){

      sum += nums[j];

      if(sum > max){

        max = sum;

      }
      //printf("%d %d: %2d (%d)\n", i, j, sum, max);
    }
  }
  return max;
}
int maxSubArrayDP(int* nums,int numSize){ 
  
  int max = nums[0];

  return max;
}