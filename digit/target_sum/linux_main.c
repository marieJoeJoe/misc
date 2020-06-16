
#include <stdio.h>
#include "target_sum.h"
#define MAX 100000 
  
void printPairs(int arr[], int arr_size, int sum) 
{ 
    int i, temp; 
    int s[MAX] = { 0 }; /*initialize hash set as 0*/
  
    for (i = 0; i < arr_size; i++) { 
        temp = sum - arr[i]; 
        if (s[temp] == 1) 
            printf("Pair with given sum %d is (%d, %d) \n", 
                   sum, arr[i], temp); 
        s[arr[i]] = 1; 
    } 
} 
  
/* Driver program to test above function */
int main() 
{ 
    int A[] = { 1, 4, 45, 6, 10, 8 }; 
    int n = 16; 
    int arr_size = sizeof(A) / sizeof(A[0]); 
  
    printPairs(A, arr_size, n); 
  
    return 0; 
} 
