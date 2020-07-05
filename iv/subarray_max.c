#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
/*
 * nums = [-2,1,-3,4,-1,2,1,-5,4],
 * ans: 6
 * 
 *
 * $ gcc subarray_max.c -o subarray_max
 * $ ./subarray_max
 * timing:
 * n3 2147479975 1022031552(nsec)
 * n2 2147479975 1882806(nsec)
 * dp 2147479975 3071(nsec)
 * 
 * $ gcc -O1 subarray_max.c -o subarray_max
 * $ ./subarray_max 
 * timing:
 * n3 2147479975 289949670(nsec)
 * n2 2147479975 489650(nsec)
 * dp 2147479975 1095(nsec)
 * 
 * $ gcc -O2 subarray_max.c -o subarray_max
 * $ ./subarray_max 
 * timing:
 * n3 2147479975 331(nsec)
 * n2 2147479975 144(nsec)
 * dp 2147479975 6485(nsec)
 * 
 * $ gcc -O3 subarray_max.c -o subarray_max
 * timing:
 * n3 2147479975 389(nsec)
 * n2 2147479975 146(nsec)
 * dp 2147479975 24463(nsec)
 * 
 * $ gcc -Os subarray_max.c -o subarray_max
 * $ ./subarray_max 
 * timing:
 * n3 2147479975 179847753(nsec)
 * n2 2147479975 491018(nsec)
 * dp 2147479975 1128(nsec)
 * 
 * $ gcc subarray_max.c -o subarray_max
 * $ ./subarray_max 
 * timing:
 * n3 2147479975 1035497100(nsec)
 * n2 2147479975 1883279(nsec)
 * dp 2147479975 3043(nsec)
 *
 * */

//free?
long ts_to_long(struct timespec t);
void swap_val(int *a, int *b);

//O(arrSzie*arrSize*arrSize)
void subarray_max_n3(int *arr, int arrSize, int *max);

//O(arrSzie*arrSize)
void subarray_max_n2(int *arr, int arrSize, int *max);

//O(arrSzie)
void subarray_max_dp(int *arr, int arrSize, int *max);



int main(int argc, char argv[])
{
  //int a = 99, b = 74;

  //printf("a : %d, b : %d\n", a, b);

  //swap_val(&a, &b);

  //printf("a : %d, b : %d\n", a, b);

  int nums[9] = {-2,1,-3,4,-1,2,1,-5,4};

  int subarrayMax = 0;

  subarray_max_n3(nums,sizeof(nums)/sizeof(int),&subarrayMax);
  printf("func n3: %d\n",subarrayMax);
  subarray_max_n2(nums,sizeof(nums)/sizeof(int),&subarrayMax);
  printf("func n2: %d\n",subarrayMax);
  subarray_max_dp(nums,sizeof(nums)/sizeof(int),&subarrayMax);
  printf("func dp: %d\n",subarrayMax);

  unsigned int i = 0;

#define SIZE_MEASURE 50
  int rarr[SIZE_MEASURE];
  for( i = 0; i < SIZE_MEASURE; i++ )
  {
     rarr[i] = rand()%100 - 50;
     //printf("[%d]\n",rarr[i]);
  }

  subarray_max_n3(rarr,sizeof(rarr)/sizeof(int),&subarrayMax);
  printf("test n3: %d\n",subarrayMax);
  subarray_max_n2(rarr,sizeof(rarr)/sizeof(int),&subarrayMax);
  printf("test n2: %d\n",subarrayMax);
  subarray_max_dp(rarr,sizeof(rarr)/sizeof(int),&subarrayMax);
  printf("test dp: %d\n",subarrayMax);

#define SIZE_TIMING 1500
  int rarrt[SIZE_TIMING];
  for( i = 0; i < SIZE_MEASURE; i++ )
  {
     rarrt[i] = rand()%2000 - 1000;
     //printf("[%d]\n",rarr[i]);
  }

  struct timespec startn3, endn3, startn2, endn2, startdp, enddp;

  clock_gettime(CLOCK_MONOTONIC, &startn3);
  subarray_max_n3(rarrt,sizeof(rarrt)/sizeof(int),&subarrayMax);
  clock_gettime(CLOCK_MONOTONIC, &endn3); 
  
  clock_gettime(CLOCK_MONOTONIC, &startn2);
  subarray_max_n2(rarrt,sizeof(rarrt)/sizeof(int),&subarrayMax);
  clock_gettime(CLOCK_MONOTONIC, &endn2); 

  clock_gettime(CLOCK_MONOTONIC, &startdp);
  subarray_max_dp(rarrt,sizeof(rarrt)/sizeof(int),&subarrayMax);
  clock_gettime(CLOCK_MONOTONIC, &enddp); 

  printf("timing:\n");
  printf("n3 %d %lu(nsec)\n",subarrayMax,ts_to_long(endn3)-ts_to_long(startn3));
  printf("n2 %d %lu(nsec)\n",subarrayMax,ts_to_long(endn2)-ts_to_long(startn2));
  printf("dp %d %lu(nsec)\n",subarrayMax,ts_to_long(enddp)-ts_to_long(startdp));

}

long ts_to_long(struct timespec t) {
  return t.tv_sec * 1000000000 + t.tv_nsec;
}


void swap_val(int *a, int *b){
  //printf("a:%08x, b:%08x\n", *a, *b);
  *a ^= *b;
  //printf("a:%08x, b:%08x\n", *a, *b);
  *b ^= *a;
  //printf("a:%08x, b:%08x\n", *a, *b);
  *a ^= *b;
  //printf("a:%08x, b:%08x\n", *a, *b);
}

//O(arrSzie*arrSize*arrSize)
void subarray_max_n3(int *arr, int arrSize, int *max){

  int submax = INT_MIN;
  for(int i = 0; i<arrSize; i++){
    for(int j = i; j<arrSize; j++){
      int sum = 0;
      for(int k = i; k<=j; k++){
        sum += arr[k];
      }

      if(sum > submax){
        //printf("%d %d : %2d (%d)\n",i,j,sum,submax);
        submax = sum;
      }
    }
  }
  *max = submax;
}

//O(arrSzie*arrSize)
void subarray_max_n2(int *arr, int arrSize, int *max){

  int submax = INT_MIN;
  
  for(int i = 0; i<arrSize; i++){

    int sum = 0;

    for(int j = i; j<arrSize; j++){
      sum += arr[j];
      if(sum > submax){
        //printf("%d %d : %2d (%d)\n",i,j,sum,submax);
        submax = sum;
      }
    }
  }
  *max = submax;
}

//O(arrSzie)
void subarray_max_dp(int *arr, int arrSize, int *max){

  int local_max = 0, global_max = INT_MIN;

  for(int i = 0; i<arrSize; i++){
    local_max = ( arr[i] > ( local_max + arr[i] ) )?(arr[i]):(local_max + arr[i]);
    if(local_max > global_max){
      global_max = local_max;
    }
  }

  *max = global_max;
}


