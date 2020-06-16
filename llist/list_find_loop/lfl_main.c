#include <stdio.h>
#include "list.h"
#include "floydcycledetection.h"

int main(int argc, char* argv[])
{
  LinHead lh = initLinkedList(1298845124);

  //dump(lh);

  makeloop(lh,7);
  
  //dumploopll(lh);

  printf("%u\n", FloydCycleDetection(lh,2,3));

  LinHead rlh = getRandomLinkedList(100);

  //dump(rlh);

  makeloop(rlh,30);

  printf("%u\n", FloydCycleDetection(rlh,1,2));

  return 0;
}
