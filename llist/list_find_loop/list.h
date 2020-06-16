#ifndef __LIST_H__
#define __LIST_H__


typedef struct LinkedListNode{
  unsigned int val;
  struct LinkedListNode* next;
}LinNode;

typedef struct LinkedListNode* LinHead;

LinHead initLinkedList(unsigned int);

void dump(LinHead);
void dumploopll(LinHead lh);

unsigned int LinkedListLength(LinHead lh);

void makeloop(LinHead lh, unsigned int pos);

void breadloop(LinHead lh);

LinHead getRandomLinkedList(unsigned int nc);

#endif
