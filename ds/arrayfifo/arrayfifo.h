#ifndef __ARRAYFIFO_H__
#define __ARRAYFIFO_H__

typedef struct arrayfifo
{
	unsigned int capacity;
	unsigned int front, rear,size;
	unsigned int *buf;
}afifo_t;

void fifo_init(afifo_t *f, int capacity);
void fifo_free(afifo_t *f);


unsigned int isempty(afifo_t *f);
unsigned int isfull(afifo_t *f);
void fifo_in(afifo_t *f, unsigned int elem);
unsigned int fifo_pop(afifo_t *f);

unsigned int front(afifo_t *f);
unsigned int rear(afifo_t *f);

unsigned int fifo_read(afifo_t *f, unsigned int *buf, int nbytes);
unsigned int fifo_write(afifo_t *f, unsigned int *buf, int nbytes);

#endif
