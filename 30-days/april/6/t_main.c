#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
  char *original;
  char *sorted;
}Pair;

int cmpChar(const void* a, const void* b);
int cmpPair(const void* a, const void* b);
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes);



/*
  Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
  Output:
  [
    ["ate","eat","tea"],
    ["nat","tan"],
    ["bat"]
  ]
*/

int main(int argc, char* argv[])
{

  char *Input[] = {"eat", "tea", "tan", "ate", "nat", "bat"};

  int rtSize;
  int rtcSize[6][1];
  char*** rt = groupAnagrams( Input, 6, &rtSize, (int **)rtcSize);

  //printf("%d\n", rtSize );

  for(int i = 0 ; i<rtSize; i++){
    //printf("%d\n", rtcSize[i][0] );
  }

  printf("%s\n", rt[0][0] );
  printf("%s\n", rt[1][0] );
  printf("%s\n", rt[1][1] );
  printf("%s\n", rt[1][2] );
  printf("%s\n", rt[2][0] );
  printf("%s\n", rt[2][1] );

  return 0;
}







int cmpChar(const void* a, const void* b){
    return *(const char*)a - *(const char*)b;
}

int cmpPair(const void* a, const void* b){
    const Pair* pa = (const Pair*)a;
    const Pair* pb = (const Pair*)b;
    return strcmp( pa->sorted, pb->sorted );
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
  
    Pair* pairs = malloc(sizeof(Pair)*strsSize);
    
    for(int i = 0; i < strsSize; i++){
        char *sorted_str = malloc(strlen(strs[i])+1);
        strcpy(sorted_str, strs[i]);
        qsort(sorted_str, strlen(strs[i]),1,cmpChar);
        
              
        pairs[i].original = strs[i];
        pairs[i].sorted = sorted_str;
        
    }
    
    qsort(pairs, strsSize, sizeof(Pair), cmpPair);
    
    char *** rt = NULL;
    *returnSize = 0;    
    *returnColumnSizes = NULL;

    for(int i = 0; i<strsSize; i++ )
    {
        if(i == 0 || strcmp(pairs[i].sorted, pairs[i-1].sorted) != 0)
        {
            int lastGroupIndex = *returnSize;
            rt = realloc(rt, sizeof(char**)*(*returnSize+1));
            rt[lastGroupIndex] = malloc(sizeof(char*));
            rt[lastGroupIndex][0] = pairs[i].original;
            
            (*returnSize)++;
            *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int)*(*returnSize));
            (*returnColumnSizes)[lastGroupIndex] = 1;
        }
        else{
            int lastGroupIndex = *returnSize - 1;
            int lastGroupSize = (*returnColumnSizes)[lastGroupIndex];
            rt[lastGroupIndex] = realloc(rt[lastGroupIndex], sizeof(char*)*(lastGroupSize+1));
            rt[lastGroupIndex][lastGroupSize] = pairs[i].original;
            (*returnColumnSizes)[lastGroupIndex] = lastGroupSize + 1;
        }
        
        
    }
        
    return rt;
}