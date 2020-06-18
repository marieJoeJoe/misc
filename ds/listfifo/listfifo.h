#ifndef __LISTFIFO_H__
#define __LISTFIFO_H__


typedef struct llnode
{
	struct llnode* next;
	unsigned int data;
}node_t;


typedef struct fifo
{
	node_t *front;
	node_t *rear;
}fifo_t;

node_t* newNode(unsigned int);

fifo_t* create_fifo(void);

void enqueue(fifo_t*, unsigned int);

void dequeue(fifo_t*, unsigned int*) ;


#endif
