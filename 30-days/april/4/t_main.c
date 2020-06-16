#include <stdio.h>

void moveZeros(int *nums, int numsSize);


int main(int argc, char* argv[])
{
/*
nums: [0, 3, 0, 12, 1],
nums: [3, 12, 1, 0, 0],
*/
  int s[] = {0, 3, 0, 12, 1};

  printf("\n");
  for(int i = 0; i< sizeof(s)/sizeof(s[0]); i++){
    printf("%d ", s[i]);
  }
  printf("\n");

  moveZeros(s,sizeof(s)/sizeof(s[0]));

  printf("\n");
  for(int i = 0; i< sizeof(s)/sizeof(s[0]); i++){
    printf("%d ", s[i]);
  }
  printf("\n");

  return 0;
}


void moveZeros(int *nums,int numsSize){

  int j = 0;
  for(int i = 0; i < numsSize; i++){
    if( nums[i] != 0 ){
        nums[j] = nums[i];
        j++;
    }
  }
  while(j<numsSize){
    nums[j] = 0;
    j++;
  }
}
