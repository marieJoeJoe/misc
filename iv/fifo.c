#include <stdio.h>
#include <stdlib.h>


struct fifo{
 int cap;
 int front; 
 int size;
 int rear;
 int *buf;
};


void fifo_init(struct fifo * f, int cap){
  f->cap = cap;
  f->front = 0;
  f->size = 0;
  f->rear = cap - 1;
  f->buf = (int*)malloc(cap*sizeof(int));
} 

void fifo_free(struct fifo * f){
  free(f->buf);
}

int isfull(struct fifo * f){
  return (f->size == f->cap);
}

int isempty(struct fifo * f){
  return (f->size == 0);
}

int enqueue(struct fifo * f, int elem){
  if(isfull(f)) return -1;

  f->rear = (f->rear + 1)%f->cap;
  f->buf[f->rear] = elem;
  f->size += 1;
  return 0;
}

int dequeue(struct fifo * f, int * elem){
  if(isempty(f)) return -1;

  *elem = f->buf[f->front];
  f->front = (f->front + 1)%f->cap;
  f->size -= 1;
  return 0;
}



int main(int argc, char* argv[])
{
  int src_data[10] = {2,4,-5,7,9,-11,34,5,6,-77};

  struct fifo at; 

  fifo_init(&at,10);

  int i;

  for( i = 10; i > 0 ; i-- )
  {
     printf("%d\n",src_data[i-1] );
     enqueue(&at, src_data[i-1]); 
  }

  int ss;
  printf("\n-----------------------------\n");

  for( i = 0; i < 10 ; i++ )
  {
    dequeue(&at, &ss);
    printf("%d\n",ss );
  }

  return 0;

}
