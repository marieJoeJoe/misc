#include <stdio.h>


int singleNumber(int* nums, int numsSize);


int main(int argc, char* argv[])
{
/*
Input: [2,2,1]
Output: 1

Input: [4,1,2,1,2]
Output: 4
*/

  int sdata0[] = {2,2,1};
  int sdata1[] = {4,1,2,1,2};
  printf("test0 %s\n", 
  	(1 == singleNumber(sdata0,sizeof(sdata0)/sizeof(sdata0[1]))) ?"passed":"failed");
  printf("test1 %s\n", 
  	(4 == singleNumber(sdata1,sizeof(sdata1)/sizeof(sdata1[1]))) ?"passed":"failed");


  return 0;
}

int singleNumber(int* nums, int numsSize){
    
  int n = nums[0];
  for(int i = 1; i<numsSize; i++){
      n ^= nums[i];
  }
    
  return n;
}
