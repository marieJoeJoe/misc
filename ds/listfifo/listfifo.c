
#include "listfifo.h"
#include <stdlib.h>


node_t* newNode(unsigned int k){
  node_t *temp = (node_t*)malloc(sizeof(node_t));
  temp->data = k;
  temp->next = NULL;
  return temp;
}

fifo_t* create_fifo(void){
  fifo_t* q = (fifo_t*)malloc(sizeof(fifo_t));
  q->front = NULL;
  q->rear = NULL;
  return q;
}

void enqueue(fifo_t* q, unsigned int k){

  node_t* temp = newNode(k);

  if(NULL == q->rear){
    q->front = temp;
    q->rear = temp;
    return;
  }
  q->rear->next = temp;
  q->rear = temp;
}

void dequeue(fifo_t* q,unsigned int *e){

  if(q->front == NULL) return;

  node_t* temp = q->front;

  *e = temp->data;

  q->front = q->front->next;

  if(q->front == NULL) q->rear=NULL;

  free(temp);
}

