#include "rl.h"
#include <stdio.h>
#include <stdlib.h>

#define pr_info(fromat, ...) do{ printf("[%s]:"fromat, __FUNCTION__, ##__VA_ARGS__); }while (0)

unsigned int reverseDecNumDigit(unsigned int fwn){

    unsigned int rvn  = 0;
    unsigned int ifwn = fwn;
    unsigned int assign_flag = 0;

    while ((0 != ifwn/10)||(0!=ifwn%10)) {
      /* code */
      assign_flag = ifwn/10;
      rvn += ifwn%10;
      ifwn /= 10;
      if(0 != assign_flag) rvn *= 10;
      //pr_info("%d\n", rvn);
    }
    //pr_info("%d\n", rvn);
    return rvn;
}

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


LinHead reverseLinkedList(LinHead lh, char func)
{

  if(NULL == lh){
    pr_info("lh pointer to NULL\n");
    return lh;
  }
  if('l' == func){
    return loop_reverseLinkedList(lh);
  }else if('r' == func){
    return recursive_reverseLinkedList(lh);
  }else{
    pr_info("func name error !\n");
    return lh;
  }
}

LinHead recursive_reverseLinkedList(LinHead lh)
{
  //static int cnt = 0;
  if((NULL == lh)||(NULL == lh->next)) return lh;
  //pr_info("%d\n",cnt++);
  LinNode * newHead = recursive_reverseLinkedList(lh->next);
  lh->next->next = lh;
  lh->next = NULL;
  return newHead;
}

LinHead loop_reverseLinkedList(LinHead lh)
{

  if((NULL == lh)||(NULL == lh->next))
  {
    return lh;
  }

  LinNode * pcurr = lh->next;
  LinNode * pret = lh;
  pret->next = NULL;

  while(pcurr){
    LinNode* temp = pcurr;
    pcurr = pcurr->next;
    temp->next = pret;
    pret = temp;
  }
  return pret;
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
