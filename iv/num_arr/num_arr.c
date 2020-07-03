#include <stdio.h>
#include <stdlib.h>
/*
nums = [-1, 0, 1, 2, -1, -4],

ans:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

typedef struct Vector {
  int row;
  int * arr;
}vec;


//free?
void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}


void sort(int*src, int *dst)
{

  for(int i = 0; i<3; i++){
   *(dst+i) = *(src+i);
  }

  if (dst[0] > dst[2]) swap(&dst[0], &dst[2]);
  if (dst[0] > dst[1]) swap(&dst[0], &dst[1]);
  if (dst[1] > dst[2]) swap(&dst[1], &dst[2]);

  //printf("[%s]%d,%d,%d\n",__FUNCTION__,dst[0],dst[1],dst[2]);
}

int checkArrEq(int* arr1,int* arr2 ){
  //eq
  int match = 1;
  int sa1[3],sa2[3];
  sort(arr1,sa1);
  sort(arr2,sa2);
  for(int i = 0; i<3; i++){
    if(sa1[i] != sa2[i]){
        match = 0;
	break;
    }
  }
  return match?1:0;
}


void cThreeUniqueSums(int *arr, int arrSize, vec* ans){

  if(NULL == ans || 0 != ans->row || arrSize < 3 || NULL == arr){
    printf("check params !!\n");
    return;
  }

  int i, j, k, l, tmpi=0, tmpj=0, pos = 0, arrVaild=0;

  int carr[3];
  int tarr[3];
  int *parr=NULL;

  for(i = arrSize; i > 1; i--){    
    tmpi = arr[i];
    for(j = i - 1; j > 0; j-- ){
      tmpj = tmpi + arr[j];
      for( k = j - 1; k>=0; k--){
        if(!(tmpj + arr[k])){
          arrVaild = 1;
	  for(l = ans->row; l>0; l--){
            tarr[0] = ans->arr[3*(l-1)+0];
	    tarr[1] = ans->arr[3*(l-1)+1];
            tarr[2] = ans->arr[3*(l-1)+2];
 
  	    carr[0] = arr[i];
	    carr[1] = arr[j];
            carr[2] = arr[k];
            if (checkArrEq(tarr,carr)){ 
              arrVaild = 0;
	    }
          }
          if(arrVaild){
            ans->row++;
            ans->arr = realloc(ans->arr, (ans->row)*3*sizeof(int));
	    pos = 3*(ans->row - 1);
            ans->arr[pos+0] = arr[i];
            ans->arr[pos+1] = arr[j];
            ans->arr[pos+2] = arr[k];
          }
        }
      }
    }
  }
}

int main(int argc, char argv[])
{

  int nums[6] = {-1, 0, 1, 2, -1, -4};

  vec ans;

  ans.row = 0;
  ans.arr = NULL;

  cThreeUniqueSums(nums,sizeof(nums)/sizeof(int),&ans);

  printf("[%d]\n",ans.row);

  for(int i = 0; i<ans.row; i++)
  {
    printf("[ %d , %d , %d ]\n",ans.arr[3*i],ans.arr[3*i+1],ans.arr[3*i+2]);
  }

#define SIZE 500
  unsigned int i;
  int rarr[SIZE];
  for( i = 0; i < SIZE; i++ )
  {
     rarr[i] = rand()%100 - 50;
     printf("[%d]\n",rarr[i]);
  }
  
  vec rans;
  rans.row = 0;
  rans.arr = NULL;

  cThreeUniqueSums(rarr,sizeof(rarr)/sizeof(int),&rans);

  printf("[%d]\n",rans.row);

  for(int i = 0; i<rans.row; i++)
  {
    printf("[ %d , %d , %d ]\n",rans.arr[3*i],rans.arr[3*i+1],rans.arr[3*i+2]);
  }

}
