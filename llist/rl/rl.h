#ifndef __RL_H__
#define __RL_H__


typedef struct LinkedListNode{
  unsigned int val;
  struct LinkedListNode* next;
}LinNode;

typedef struct LinkedListNode* LinHead;

unsigned int reverseDecNumDigit(unsigned int);
LinHead initLinkedList(unsigned int);
LinHead reverseLinkedList(LinHead,char);
void dump(LinHead);

LinHead recursive_reverseLinkedList(LinHead);
LinHead loop_reverseLinkedList(LinHead);

unsigned int LinkedListLength(LinHead lh);
#endif
