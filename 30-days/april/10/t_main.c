#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int *data;
    int *mins;
    int size;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack * s = malloc(sizeof(MinStack));
    s->data = NULL;
    s->mins = NULL;
    s->size = 0;
    return s;
}

void minStackPush(MinStack* obj, int x) {
  obj->data = realloc(obj->data,sizeof(int)*(obj->size+1));
  obj->mins = realloc(obj->mins,sizeof(int)*(obj->size+1));
  obj->data[obj->size] = x;
  if(0 == obj->size || obj->mins[obj->size - 1] > x){
      obj->mins[obj->size] = x;
  }else{
      obj->mins[obj->size] = obj->mins[obj->size-1];
  }
  obj->size++;
}

void minStackPop(MinStack* obj) {
  obj->size--;
}

int minStackTop(MinStack* obj) {
  return obj->data[obj->size-1];
}

int minStackGetMin(MinStack* obj) {
    return obj->mins[obj->size-1];
}

void minStackFree(MinStack* obj) {
  free(obj->data);
  free(obj->mins);
  free(obj);
}


typedef struct {
 int *data;
 int size;
}stack; 

stack* createStack(void){
  stack *s = malloc(sizeof(stack));
  s->data = NULL;
  s->size = 0;
  return s;
}

void destroyStack(stack *s){
  free(s->data);
  free(s);
}

void pushStack(stack *s, int x){
  s->data = realloc(s->data, sizeof(int)*(s->size+1));
  s->data[s->size] = x;
  s->size++;
}

void popStack(stack *s){
  s->size--;

}

int topStack(stack *s){
  return s->data[s->size-1];
}

void printStack(const stack *s){
  for(int i = 0; i< s->size; i++){
    printf("[%d]",s->data[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[])
{

  stack *s = createStack();

  pushStack(s,10);

  pushStack(s,-20);

  pushStack(s,30);

  pushStack(s,-40);

  pushStack(s,50);

  pushStack(s,-60);

  pushStack(s,70);

  printStack(s);

  destroyStack(s);
}
