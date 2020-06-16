/*Floyd Cycle Detection Algorithm*/

#include "floydcycledetection.h"
#include <stdio.h>

LinHead ListFowardXstep(LinHead lh, unsigned int nstep)
{
  LinHead pln = lh;

  while(nstep--)
  {
  	if(NULL != pln) pln = pln->next;
  }

  return pln;

}


unsigned int FloydCycleDetection(LinHead lh, unsigned int slowstep, unsigned int faststep)
{

  if(slowstep > faststep){
  	printf("faststep less than slowstep\n");
  	return 0xff;
  }

  int slow_step = slowstep;
  int fast_step = faststep;

  LinHead pslow = lh;
  LinHead pfast = lh;

  do
  {
    pslow = ListFowardXstep(pslow,slow_step);
    pfast = ListFowardXstep(pfast,fast_step);
    //printf("slow %p %d fast %p %d\n", pslow, pslow->val, pfast, pfast->val);
    if ((NULL != pfast)&&(NULL != pslow)&&(0 == (pslow - pfast))){ 
        //printf("%d %lu\n",pslow == pfast,pslow - pfast);
    	return 1;
    }; 

  }while((NULL != pfast)||(NULL != pslow));

  return 0;

}