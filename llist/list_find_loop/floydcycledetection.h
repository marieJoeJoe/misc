/*Floyd Cycle Detection Algorithm header*/
#ifndef __FLOYDCYCLEDETECTION_H__
#define __FLOYDCYCLEDETECTION_H__

#include "list.h"



LinHead ListFowardXstep(LinHead lh, unsigned int nstep);

unsigned int FloydCycleDetection(LinHead lh, unsigned int slowstep, unsigned int faststep);

#endif