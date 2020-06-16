#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "heapsort.h"


#define ARR_CNT 0x60

int main(int argc, char* argv[])
{
  unsigned int r_arr[ARR_CNT] = {0};

  initRandomArr(r_arr,ARR_CNT);

  dumpArr(r_arr,ARR_CNT,0x10);

  heapsort(r_arr,ARR_CNT);

  dumpArr(r_arr,ARR_CNT,0x10);

  return 0;
}
