
#include "arrayfifo.h"
#include <stdlib.h>


void fifo_init(afifo_t *f, int capacity){
  f->capacity = capacity;
  f->front = 0;
  f->size = 0;
  f->rear = capacity - 1;
  f->buf = malloc(capacity*sizeof(int));
}

void fifo_free(afifo_t *f){
  free(f->buf);
}

// fifo is full when size becomes equal to the capacity
unsigned int isempty(afifo_t *f){
  return (f->size == 0);
}

// fifo is empty when size is 0
unsigned int isfull(afifo_t *f){
  return (f->size == f->capacity);	
}

// function to add an elem to the fifo
// it changes rear and size
void fifo_in(afifo_t *f, unsigned int elem){
  if(isfull(f)) return ;

  f->rear = (f->rear + 1) % f->capacity;
  f->buf[f->rear] = elem;
  f->size = f->size + 1;	
}

// function to remove an elem from fifo front
// it changes front and size 
unsigned int fifo_pop(afifo_t *f){
  if(isempty(f)) return 0xf0000000;

  unsigned int elem = f->buf[f->front];
  f->front = (f->front + 1) % f->capacity;
  f->size = f->size - 1;
  return elem;
}

// Function to get front of fifo 
unsigned int front(afifo_t *f) 
{ 
    if(isempty(f)) return 0xf0000000;  
    return f->buf[f->front]; 
} 
  
// Function to get rear of fifo
unsigned int rear(afifo_t *f)
{ 
    if(isempty(f)) return 0xf0000000; 
    return f->buf[f->rear]; 
}

unsigned int fifo_read(afifo_t *f, unsigned int *buf, int nbytes){



}

unsigned int fifo_write(afifo_t *f, unsigned int *buf, int nbytes){


	
}