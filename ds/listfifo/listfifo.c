
#include "listfifo.h"
#include <stdlib.h>

llfifo_t* llfifo_init()
{
  llfifo_t *temp = (llfifo_t*)malloc(sizeof(llfifo_t));
  temp->front = temp->rear = NULL;
  return temp;
}

void llfifo_newNode(llfifo_t *f,unsigned int k)
{
  ll_t nNode = (ll_t*)malloc(sizeof(ll_t));

}

void llfifo_enqueue(llfifo_t *f,unsigned int k)
{


}
void llfifo_dequeue(llfifo_t *f,unsigned int* k)
{


}