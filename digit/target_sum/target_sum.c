#include <stdlib.h>
#include <string.h>
#include "target_sum.h"

  
int hasArrayTwoCandidates(int A[], int arr_size, int sum) 
{ 
    int l, r; 
  
    /* Sort the elements */
    quickSort(A, 0, arr_size - 1); 
  
    /* Now look for the two candidates in the sorted  
       array*/
    l = 0; 
    r = arr_size - 1; 
    while (l < r) { 
        if (A[l] + A[r] == sum) 
            return 1; 
        else if (A[l] + A[r] < sum) 
            l++; 
        else // A[i] + A[j] > sum 
            r--; 
    } 
    return 0; 
} 
  
/* FOLLOWING FUNCTIONS ARE ONLY FOR SORTING  
    PURPOSE */
void exchange(int* a, int* b) 
{ 
    int temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  
int partition(int A[], int si, int ei) 
{ 
    int x = A[ei]; 
    int i = (si - 1); 
    int j; 
  
    for (j = si; j <= ei - 1; j++) { 
        if (A[j] <= x) { 
            i++; 
            exchange(&A[i], &A[j]); 
        } 
    } 
    exchange(&A[i + 1], &A[ei]); 
    return (i + 1); 
} 
  
/* Implementation of Quick Sort 
A[] --> Array to be sorted 
si  --> Starting index 
ei  --> Ending index 
*/
void quickSort(int A[], int si, int ei) 
{ 
    int pi; /* Partitioning index */
    if (si < ei) { 
        pi = partition(A, si, ei); 
        quickSort(A, si, pi - 1); 
        quickSort(A, pi + 1, ei); 
    } 
}


