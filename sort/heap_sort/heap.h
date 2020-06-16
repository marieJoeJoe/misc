#ifndef __HEAP_H___
#define __HEAP_H___


typedef unsigned int ElementType;

struct Heap;

typedef struct Heap *PriorityQueue;

PriorityQueue Initialize(unsigned int MaxElements);
void Destory(PriorityQueue H);
void MakeEmpty(PriorityQueue H);


void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);



int isEmpty(PriorityQueue H);
int isFull(PriorityQueue H);

struct Heap{
    unsigned int capacity;
    unsigned int size;
    ElementType *Elements;
};









#endif
