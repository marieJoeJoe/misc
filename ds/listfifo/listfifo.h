#ifndef __LISTFIFO_H__
#define __LISTFIFO_H__


typedef struct linkedlist
{
	struct linkedlist* next;
	unsigned int data;
}ll_t;


typedef struct linkedlistfifo
{
	ll_t *front, *rear;
}llfifo_t;

llfifo_t* llfifo_init();
void llfifo_newNode(llfifo_t *f,unsigned int k);

void llfifo_enqueue(llfifo_t *f,unsigned int k);
void llfifo_dequeue(llfifo_t *f,unsigned int* k);

#endif
