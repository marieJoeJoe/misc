#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define pr_info(fromat, ...) do{ printf("[%s]:"fromat, __FUNCTION__, ##__VA_ARGS__); }while (0)

unsigned int LinkedListLength(LinHead lh)//get node count
{
    unsigned int k=0;
    while(lh)
    {
        k++;
        lh=lh->next;
    }
    return k;
}


LinHead getRandomLinkedList(unsigned int nc)
{


  LinHead rlist = (LinNode*)malloc(sizeof(LinNode));
  LinHead plist = rlist;
  unsigned int i;


  for( i = 0; i < nc; i++ )
  {
     //srand(time(NULL));
     plist->val = rand()%100;
     if( i != nc-1 ) plist->next = malloc(sizeof(LinNode));
     else plist->next = NULL;

     plist = plist->next;
  }

  return rlist;

}


LinHead initLinkedList(unsigned int in)
{

  //unsigned int deal = reverseDecNumDigit(in);
  unsigned int deal = in;
  LinHead lh = (LinHead)malloc(sizeof(LinNode));
  lh->next = NULL;
  LinNode* plhtail=lh;
  unsigned int ifwn = deal;
  unsigned int assign_flag = 0;

  while ((0 != ifwn/10)||(0!=ifwn%10)) {
    /* code */
    assign_flag = ifwn/10;
    plhtail->val = ifwn%10;
    ifwn /= 10;
    if(0 != assign_flag){
      plhtail->next = (LinNode*)malloc(sizeof(LinNode));
      plhtail = plhtail->next;
      //pr_info("MALLOC\n");
    }else{
      plhtail->next = NULL;
      //pr_info("BREAK\n");
      break;
    }
    //pr_info("%d\n", rvn);
  }

  return lh;
}

void dump(LinHead lh)
{
  pr_info("Len: %u\n",LinkedListLength(lh));
  LinNode *pl = lh;
  printf("head-> ");
  do{
    printf("%d ",pl->val);
    pl= pl->next;
  }while(NULL != pl);
  printf(" ->tail\n");

}

void dumploopll(LinHead lh)
{
  //pr_info("Len: %u\n",LinkedListLength(lh));
  LinNode *pl = lh;
  printf("head-> ");
  do{
    printf("%d ",pl->val);
    pl= pl->next;
  }while(NULL != pl);
  //printf(" ->tail\n");

}


void makeloop(LinHead lh, unsigned int pos){

  unsigned int nc = 0;

  if(( NULL == lh )||( (nc=LinkedListLength(lh)) < pos )){
    pr_info("node count less than pos || lh is NULL");
    return;
  }

  unsigned int op_pos = nc - pos + 1;

  LinNode *ppos = NULL;
  LinNode *tmp = lh;

  while(nc--){
    if( nc == op_pos ) ppos = tmp->next ;
    if( nc != 1 ) tmp = tmp->next;
  }

  tmp->next = ppos;
}

void breadloop(LinHead lh){

}