#include <stdio.h>
#include "rl.h"

int main(int argc, char* argv[])
{
  printf("%d\n",reverseDecNumDigit(120398));

  printf("%d\n",reverseDecNumDigit(9120398));

  LinHead lh1 = initLinkedList(9120398);
  dump(lh1);

  LinHead lnlh = reverseLinkedList(lh1,'l');
  dump(lnlh);

  LinHead lh2 = initLinkedList(1549854131);
  dump(lh2);
  LinHead rnlh = reverseLinkedList(lh2,'r');
  dump(rnlh);

  return 0;
}
