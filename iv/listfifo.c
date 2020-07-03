#include "list.h"


typedef struct listNode
{
  struct list_head head;
  int data;
}node_t;

typedef struct queue
{
  node_t *front;
  node_t *rear;
}queue_t;

node_t* newNode(unsigned int);

queue_t* create_fifo(void);

void enqueue(queue_t*, unsigned int);

void dequeue(queue_t*, unsigned int*);











int main(int argc, char argv[])
{



  return 0;

}

node_t* newNode(unsigned int data)
{


}

queue_t* create_fifo(void)
{


}

void enqueue(queue_t* q, unsigned int data)
{


}

void dequeue(queue_t* q, unsigned int* data)
{


}

