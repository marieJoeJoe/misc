#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "selsort.h"


#define ARR_CNT 0x20

int main(int argc, char* argv[])
{
  unsigned int r_arr[ARR_CNT] = {0};

  initRandomArr(r_arr,ARR_CNT);

  //dumpArr(r_arr,ARR_CNT,0x10);

  dump_selsort(r_arr,ARR_CNT);

  //dumpArr(r_arr,ARR_CNT,0x10);

  return 0;
}
