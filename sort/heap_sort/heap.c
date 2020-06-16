#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

#define MIN_PQ_SIZE 10


PriorityQueue Initialize(unsigned int MaxElementsNum) {
    PriorityQueue H;

    if(MaxElementsNum < MIN_PQ_SIZE) {
        printf("Priority queue size is too small!\n"); 
    }

    H = malloc(sizeof(struct Heap));

    if(NULL == H) {
        printf("Out of space!\n"); 
    }
    H->Elements = malloc((MaxElementsNum+1)*sizeof(ElementType));

    if(NULL == H->Elements) {
        printf("Out of space!\n"); 
    }
    H->capacity = MaxElementsNum;
    H->size = 0;
    H->Elements[0] = 0;
    return H;
}


void Insert(ElementType x, PriorityQueue H) {

	
  static unsigned int c =0;
  unsigned int i = 0;

  if(isFull(H)) {
    printf("PriorityQUeue is full\n");
    return;
  }

    printf("\ncc %d\n",c++);
    for(i = ++H->size; H->Elements[i/2] > x; i /= 2) {
        printf("\ni %d i/2 %d E[i/2] %d x %d size %d\n",i,i/2,H->Elements[i/2],x,H->size);
        H->Elements[i] = H->Elements[i/2]; 
        printf("\n[i/2] %d [i] %d\n",H->Elements[i/2],H->Elements[i]);
    }
    H->Elements[i] = x;

    for(i = 0 ; i<H->size+1;i++)
	    printf("i=%d: %d\t",i,H->Elements[i]);

}

ElementType DeleteMin(PriorityQueue H) {
    int i, child;
    ElementType MinElement, LastElement;

    if(isEmpty(H)) {
        printf("PriorityQUeue is empty\n");
    }


    MinElement = H->Elements[1];
    LastElement = H->Elements[H->size--];

    for(i =1; i*2 <= H->size; i = child) {
        child = i*2;
        if(child != H->size && H->Elements[child+1]
			      <H->Elements[child]) {
            child++;
	}
        if(LastElement>H->Elements[child]){
	    H->Elements[i] = H->Elements[child];
	} else {
	    break;
	}
    }
    H->Elements[i] = LastElement;
    return MinElement;
}


int isFull( PriorityQueue H )
{
	return H->size == H->capacity;
}
int isEmpty( PriorityQueue H )
{
	return H->size == 0;
}

